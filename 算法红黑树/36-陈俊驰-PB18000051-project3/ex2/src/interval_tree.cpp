#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<chrono>
using namespace std;
using namespace chrono;
enum COLOR {
	red, black
};
struct interval {
	int low;
	int high;
};
struct intnode {
	enum COLOR color;
	interval inter;
	int max;
	intnode* left;
	intnode* right;
	intnode* p;
};

struct inttree {
	intnode* root;
	intnode* nil;
};
int max(int a, int b, int c)
{//找出三者最大值
	if (a >= b && a >= c)
		return a;
	else if (b >= a && b >= c)
		return b;
	else if (c >= a && c >= b)
		return c;
}
void maintain(inttree* T, intnode* x)
{//维护x结点的max值
	if (x != T->nil)
		x->max = max(x->inter.high, x->left->max, x->right->max);
}
void left_rotate(inttree* T, intnode* x)
{//左旋
	intnode* y = x->right;//定义y
	x->right = y->left;//使y的左子树成为x的右子树
	if (y->left != T->nil)
		y->left->p = x;
	y->p = x->p;//y的父亲更改为x的父亲
	if (x->p == T->nil)
		T->root = y;
	else if (x == x->p->left)
		x->p->left = y;
	else
		x->p->right = y;
	y->left = x;//将x放到y的left
	x->p = y;//使y成为x的父亲
	maintain(T,x);
	maintain(T,y);
	//维护x和y的max
}

void right_rotate(inttree* T, intnode* x)
{//右旋，与左旋对称
	intnode* y = x->left;//定义y
	x->left = y->right;//使y的right子树成为x的left子树
	if (y->right != T->nil)
		y->right->p = x;
	y->p = x->p;//y的父亲更改为x的父亲
	if (x->p == T->nil)
		T->root = y;//x为根
	else if (x == x->p->left)
		x->p->left = y;
	else
		x->p->right = y;
	y->right = x;//将x放到y的right
	x->p = y;//使y成为x的父亲
	maintain(T, x);
	maintain(T, y);
	//维护x和y的max
}
void rb_insert_fixup(inttree* T,intnode* z)
{//插入红黑性质恢复
	intnode* y;
	while (z->p->color == red)
	{
		if (z->p == z->p->p->left)
		{
			y = z->p->p->right;
			if (y->color == red)
			{//对应课本情况1
				z->p->color = black;
				y->color = black;
				z->p->p->color = red;
				maintain(T, z->p);
				maintain(T, z->p->p);
				z = z->p->p;
			}
			else
			{
				if (z == z->p->right)
				{//对应课本情况2
					z = z->p;
					left_rotate(T, z);
				}//转换为情况3进行处理
				z->p->color = black;
				z->p->p->color = red;
				right_rotate(T, z->p->p);
			}
		}
		else
		{//z的父亲是一个右孩子，与z的父亲是一个左孩子相对称
			y = z->p->p->left;
			if (y->color == red)
			{
				z->p->color = black;
				y->color = black;
				z->p->p->color = red;
				maintain(T, z->p);
				maintain(T, z->p->p);
				z = z->p->p;
			}
			else
			{
				if (z == z->p->left)
				{
					z = z->p;
					right_rotate(T, z);
				}
				z->p->color = black;
				z->p->p->color = red;
				left_rotate(T, z->p->p);
			}
		}
	}
	T->root->color = black;
	while (z != T->nil)
	{//维护插入结点到根路径上的各结点的max
		maintain(T, z);
		z = z->p;
	}
}

void rb_insert(inttree* T, intnode* z)
{//红黑树插入
	intnode* y = T->nil;
	intnode* x = T->root;
	while (x != T->nil)
	{//按二叉搜索树规律找到插入位置
		x->max = (x->max > z->max ? x->max : z->max);//由于在插入的第一阶段要对每一个祖先修改，且只要将z.max与x.max比较即可
		y = x;
		if (z->inter.low< x->inter.low)
			x = x->left;
		else
			x = x->right;
	}
	//插入并着红色
	z->p = y;
	if (y == T->nil)// 空树 
		T->root = z;
	else if (z->inter.low < y->inter.low)
		y->left = z;
	else
		y->right = z;
	z->left = T->nil;
	z->right = T->nil;
	z->color = red;
	maintain(T,z);//对插入的zmax进行赋值
	rb_insert_fixup(T, z);//恢复红黑性质·
}
void rb_transplant(inttree* T, intnode* u, intnode* v)
{//移植
	if (u->p == T->nil)
		T->root = v;
	else if (u == u->p->left)
		u->p->left = v;
	else
		u->p->right = v;
	v->p = u->p;
	intnode* x = v->p;
	while (x != T->nil)
	{//维护x结点到根的max
		maintain(T, x);
		x = x->p;
	}
}

void rb_delete_fixup(inttree* T, intnode* x)
{//删除红黑性质维护
	intnode* w;
	while (x != T->root && x->color == black)
	{
		if (x == x->p->left)
		{
			w = x->p->right;
			if (w->color == red)
			{
				//将情况1转换为情况2.3.4
				w->color = black;
				x->p->color = red;
				left_rotate(T, x->p);
				w = x->p->right;
			}
			if (w->left->color == black && w->right->color == black)
			{
				//对情况2进行处理
				w->color = red;
				x = x->p;
				maintain(T, x);
			}
			else
			{
				if (w->right->color == black)
				{
					//将情况3转换为情况4
					w->left->color = black;
					w->color = red;
					right_rotate(T, w);
					w = x->p->right;
				}
				// 对情况4进行处理
				w->color = x->p->color;
				x->p->color = black;
				w->right->color = black;
				left_rotate(T, x->p);
				x = x->p;
				break;
			}
		}
		else
		{//x是右孩子的对称情况
			w = x->p->left;
			if (w->color == red)
			{
				//将情况1转换为情况2.3.4
				w->color = black;
				x->p->color = red;
				right_rotate(T, x->p);
				w = x->p->left;
			}
			if (w->left->color == black && w->right->color == black)
			{
				//将情况2处理
				w->color = red;
				x = x->p;
				maintain(T, x);
			}
			else
			{
				if (w->left->color == black)
				{
					//将情况3转换为情况4
					w->right->color = black;
					w->color = red;
					left_rotate(T, w);
					w = x->p->left;
				}
				//对情况4处理
				w->color = x->p->color;
				x->p->color = black;
				w->left->color = black;
				right_rotate(T, x->p);
				x = x->p;
				break;
			}
		}
	}
	x->color = black;
	while (x != T->nil)
	{//维护x结点到根的max
		maintain(T, x);
		x = x->p;
	}
}

intnode* tree_minimum(inttree* T, intnode* z)
{//找到以z为根的子树中的最小结点
	intnode* x = z, * y = z->left;
	if (z == T->nil)
		return NULL;
	while (y != T->nil)
	{//一直向左直到遇到nil
		x = y;
		y = y->left;
	}
	return x;
}

void rb_delete(inttree* T, intnode* z)
{//删除红黑树T中的结点z
	intnode* x, * y = z;
	enum COLOR y_original_color = y->color;
	if (z->left == T->nil)
	{//对于z的左子树为空
		x = z->right;
		rb_transplant(T, z, z->right);
	}
	else if (z->right == T->nil)
	{//对于z的右子树为空
		x = z->left;
		rb_transplant(T, z, z->left);
	}
	else
	{//对于z的左右子树均非空
		y = tree_minimum(T, z->right);
		y_original_color = y->color;
		x = y->right;
		if (y->p == z)
			x->p = y;
		else {
			rb_transplant(T, y, y->right);
			y->right = z->right;
			y->right->p = y;
		}
		rb_transplant(T, z, y);
		y->left = z->left;
		y->left->p = y;
		y->color = z->color;
	}

	if (y_original_color == black)
		rb_delete_fixup(T, x);//恢复删除红黑性质
	else
	{
		while (x != T->nil)
		{//对于没有调用rb_delete_fixup的情况维护x到根的max
			maintain(T, x);
			x = x->p;
		}
	}
}

void inorder_tree_walk(inttree* T, intnode* x, FILE* fp)
{//中序遍历输出结果
	if (x != T->nil)
	{
		inorder_tree_walk(T, x->left, fp);
		fprintf(fp, "%d %d %d\n", x->inter.low,x->inter.high,x->max);
		inorder_tree_walk(T, x->right, fp);
	}
}
void check(inttree* T, intnode* x)
{//通过中序遍历各结点并检测其max值是否符合规律
	if (x != T->nil)
	{
		check(T, x->left);
		if (x->max != max(x->inter.high, x->left->max, x->right->max))
		{
			printf("key %d error", x->inter.low);
		}
		check(T, x->right);
	}
}

int overlap(interval x, interval y)
{//检测区间x与y是否重叠
	if (x.low<=y.high && x.high>=y.low)
		return 1;
	else
		return 0;
}
void interval_search(inttree* T, interval i,FILE* fp)
{//搜索T中与区间i重叠的结点
	intnode* x = T->root;
	while (x != T->nil && !overlap(i, x->inter))
	{//利用max进行搜索
		if (x->left != T->nil && x->left->max >= i.low)
			x = x->left;
		else
			x = x->right;
	}
	//输出结果
	if (x == T->nil)
		fprintf(fp, "Null\n");
	else
		fprintf(fp,"%d %d\n",x->inter.low,x->inter.high);
}
intnode* search(inttree* T, int key, intnode* x)
{//查找一个inter.low为key的结点
	if (x == T->nil || key == x->inter.low)
		return x;
	if (key < x->inter.low)
		return search(T, key, x->left);
	else
		return search(T, key, x->right);
}
int main()
{
	FILE* fpin = fopen("..\\..\\input\\input.txt", "r");
	FILE* fpinorder = fopen("..\\..\\output\\inorder.txt", "w");
	FILE* fpdel = fopen("..\\..\\output\\delete_data.txt", "w");
	FILE* fpsearch = fopen("..\\..\\output\\search.txt", "w");
	int low[31];
	int high[31];
	int i, a;
	intnode* x;
	//打开文件并申请一些变量
	for (i = 1; i <= 30; i++)
		fscanf(fpin, "%d%d", &low[i], &high[i]);
	//读入输入的区间
	inttree* T = (inttree*)malloc(sizeof(inttree));
	T->nil = (intnode*)malloc(sizeof(intnode));
	T->nil->inter.high = T->nil->inter.low = NULL;
	T->nil->max = 0;
	T->nil->color = black;
	T->nil->p = T->nil->left = T->nil->right = NULL;
	T->root = T->nil;
	//初始化树
	for (i = 1; i <= 30; i++)
	{//构建并插入结点
		x = (intnode*)malloc(sizeof(intnode));
		x->inter.low = low[i];
		x->inter.high = high[i];
		rb_insert(T, x);
	}
	//check(T, T->root);//测试使用，检查max是否合规
	inorder_tree_walk(T, T->root, fpinorder);//中序遍历
	fprintf(fpdel, "删除的数据为：\n");
	for (i = 1; i <= 3; i++)
	{//随机删除三个区间
		a = rand() % 30+1;
		x = search(T, low[a], T->root);
		if (x == T->nil)
		{
			i = i - 1;
			continue;
		}
		fprintf(fpdel, "%d %d %d\n", x->inter.low, x->inter.high, x->max);
		rb_delete(T, x);
	}
	fprintf(fpdel,"中序遍历序列为：\n");
	//check(T, T->root);
	inorder_tree_walk(T, T->root, fpdel);
	interval s1; 
	for (i = 1; i <= 2; i++)
	{//随机生产查找两个区间
		s1.low = rand() % 50;
		while (true)
		{
			s1.high = rand() % 51;
			if (s1.high > s1.low)
				break;
		}
		fprintf(fpsearch, "第%d个搜索区间：%d %d\n", i, s1.low, s1.high);
		fprintf(fpsearch, "搜索结果为：");
		interval_search(T, s1, fpsearch);
	}
	//生成并查找一个取自(25,30)的区间
	s1.low = rand() % 3+26;
	while (true)
	{
		s1.high = rand() % 4 + 26;
		if (s1.high > s1.low)
			break;
	}
	fprintf(fpsearch, "第3个搜索区间：%d %d\n", s1.low, s1.high);
	fprintf(fpsearch, "搜索结果为：");
	interval_search(T, s1, fpsearch);
}