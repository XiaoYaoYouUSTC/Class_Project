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
struct RBTnode {
	enum COLOR color;
	int key;
	RBTnode* left;
	RBTnode* right;
	RBTnode* p;
};

struct RBTtree {
	RBTnode* root;
	RBTnode* nil;
};

void left_rotate(RBTtree* T, RBTnode* x)
{//左旋
	RBTnode* y = x->right;//定义y
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
}

void right_rotate(RBTtree* T, RBTnode* x)
{//右旋，与左旋对称
	RBTnode* y = x->left;//定义y
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
}

void rb_insert_fixup(RBTtree* T, RBTnode* z)
{//插入红黑性质恢复
	RBTnode* y;
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
}

void rb_insert(RBTtree* T, RBTnode* z)
{//红黑树插入
	RBTnode* y = T->nil;
	RBTnode* x = T->root;
	while (x != T->nil)
	{//按二叉搜索树规律找到插入位置
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	//插入并着红色
	z->p = y;
	if (y == T->nil)// 空树 
		T->root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
	z->left = T->nil;
	z->right = T->nil;
	z->color = red;
	rb_insert_fixup(T, z);//恢复红黑性质·
}


void rb_transplant(RBTtree* T, RBTnode* u, RBTnode* v)
{//移植
	if (u->p == T->nil)
		T->root = v;
	else if (u == u->p->left)
		u->p->left = v;
	else
		u->p->right = v;
	v->p = u->p;
}

void rb_delete_fixup(RBTtree* T, RBTnode* x)
{
	RBTnode* w;
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
				x->p->color =black;
				w->right->color = black;
				left_rotate(T, x->p);
				x = T->root;
			}
		}
		else 
		{//x是右孩子的对称情况
			w = x->p->left;
			if (w->color == red) 
			{
				//将情况1转换为情况2.3.4
				w->color = black;
				x->p->color =red;
				right_rotate(T, x->p);
				w = x->p->left;
			}
			if (w->left->color == black && w->right->color == black)
			{
				//将情况2处理
				w->color =red;
				x = x->p;
			}
			else
			{
				if (w->left->color == black)
				{
					//将情况3转换为情况4
					w->right->color =black;
					w->color = red;
					left_rotate(T, w);
					w = x->p->left;
				}
				//对情况4处理
				w->color = x->p->color;
				x->p->color = black;
				w->left->color = black;
				right_rotate(T, x->p);
				x = T->root;
			}
		}
	}
	x->color = black;
}

RBTnode* tree_minimum(RBTtree* T, RBTnode* z )
{//找到以z为根的子树中的最小结点
	RBTnode* x = z, * y = z->left;
	if (z == T->nil)
		return NULL;
	while (y != T->nil)
	{//一直向左知道遇到nil
		x = y;
		y = y->left;
	}
	return x;
}

void rb_delete(RBTtree* T, RBTnode* z)
{//删除红黑树T中的结点z
	RBTnode* x, * y = z;
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
	if (y_original_color ==black)
		rb_delete_fixup(T, x);//恢复删除红黑性质
}
void inorder_tree_walk(RBTtree* T, RBTnode* x, FILE* fp)
{//中序遍历输出结果
	if (x != T->nil)
	{
		inorder_tree_walk(T, x->left, fp);
		fprintf(fp, "%d ", x->key);
		inorder_tree_walk(T, x->right, fp);
	}
}
RBTnode* search(RBTtree* T, int key,RBTnode* x)
{//对红黑树进行搜索找到的key值对应的结点
	if (x == T->nil || key == x->key)
		return x;
	if (key < x->key)
		return search(T, key,x->left);
	else
		return search(T, key, x->right);
}
int main()
{
	FILE* fpin = fopen("..\\..\\input\\input.txt", "r");
	FILE* fporder = fopen("..\\..\\output\\inorder.txt", "w");
	FILE* fptimeinser = fopen("..\\..\\output\\time1.txt", "w");
	FILE* fpdel = fopen("..\\..\\output\\delete_data.txt", "w");
	FILE* fptimedel = fopen("..\\..\\output\\time2.txt", "w");
	int n = 20;
	int input[101];
	int del[101];
	int i = 0;
	input[0] = 0;
	for (i = 1; i <= 100; i++)
	{
		fscanf(fpin, "%d", &input[i]);
	}
	RBTtree* T;
	RBTnode* z;
	//打开文件以及初始化变量。读入input.txt的数据
	for (n = 20; n <= 100; n = n + 20)
	{//对于20.40...100这五种情况进行处理
		T = (RBTtree*)malloc(sizeof(RBTtree));
		T->nil = (RBTnode*)malloc(sizeof(RBTnode));
		T->nil->color = black;
		T->nil->p = T->nil->left = T->nil->right = NULL;
		T->root = T->nil;
		//初始化树
		int i;
		auto start = system_clock::now();
		//开始计时
		for (i = 1; i <= n; i++)
		{//进行n个结点的插入操作
			z = (RBTnode*)malloc(sizeof(RBTnode));
			z->key = input[i];
			rb_insert(T, z);
		}
		auto end = system_clock::now();
		auto duration = duration_cast<nanoseconds>(end - start);
		//计算时间
		fprintf(fptimeinser, "对于%d规模花费了 %lf us\n", n, 1000000 * double(duration.count()) * nanoseconds::period::num / nanoseconds::period::den);
		fprintf(fporder, "规模为%d时中序遍历序列为：", n);
		inorder_tree_walk(T, T->root, fporder);
		fprintf(fporder, "\n");
		//对插入的时间及中序遍历结果输出
		int ndel = n / 4;
		int randnum;
		int key;
		RBTnode* tem=NULL;
		for (i = 1; i <= n; i++)
			del[i] = 0;
		//利用del数组来标识input中的第i个数据是否被删除，是为1
		fprintf(fpdel, "当规模为%d时删除节点关键字为：", n);
		i = 1;
		start = system_clock::now();
		//开始计时
		while (i <= ndel)
		{//删除ndel个结点
			randnum = rand() % (n+1);
			if (randnum <= 0 )
				continue;
			//获得1~n之间的随机数
			if (del[randnum] == 1)
				continue;
			else
			{//如果序号对应数值的结点未被删除则删除
				key = input[randnum];
				tem=search(T, key,T->root);
				rb_delete(T, tem);
				del[randnum] = 1;
				i++;
				fprintf(fpdel, "%d ", key);
			}
		}
		end = system_clock::now();
		duration = duration_cast<nanoseconds>(end - start);
		//计算时间
		fprintf(fptimedel, "对于%d规模删除花费了 %lf us\n", n, 1000000 * double(duration.count()) * nanoseconds::period::num / nanoseconds::period::den);
		fprintf(fpdel, "\n此时中序遍历序列为：");
		inorder_tree_walk(T, T->root, fpdel);
		fprintf(fpdel, "\n");
		//输出删除结果及时间
	}
}
	