#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>



#define True 1
#define False 0
#define OK 1
#define Error 0 
#define INFEASIBLE -1
#define OVERFLOW -2
#define sigma 0.00000001
typedef int status;

typedef struct Polyn {
	double coef;
	int exp;
	struct Polyn* next;
}Polyn,*PolynLine;

status JudgeNull(PolynLine &L)
{
	if (L == nullptr)
		return True;
	else
		return False;
}//鉴定是否为空链表

status JudgeZero(double num_1, double num_2)
{
	if ((num_1 + num_2) <= sigma && (num_1 + num_2) >= (-sigma))
		return True;
	else
		return False;
}//鉴定两数（double）求和是否为0

status Insert(PolynLine &L, double in_coef, int in_exp)
{
	Polyn* p =L;
	Polyn* PNode;
	while ((p->next != nullptr)&&p->next->exp >in_exp)
	{
		p=p->next;
	}
	if (in_coef == 0)
		return OK;//为了防止加减法出现系数为零的情况
	if (p->next == nullptr || p->next->exp <in_exp)
	{
		PNode = (Polyn*)malloc(sizeof(Polyn));
		PNode->next=p->next;
		PNode->coef = in_coef;
		PNode->exp = in_exp;
		p->next = PNode;
		return OK;
	}//对于不存在相同指数且下一项指数小于输入数值的情况
	if (p->next->exp == in_exp)
	{
		if (JudgeZero(p->next->coef, in_coef) == True)
		{
			PNode = p->next;
			p->next = PNode->next;
			free(PNode);
			return OK;
		}
		else
		{
			p->next->coef += in_coef;
			return OK;
		}
	}//针对指数相同的情况
}//直接将数据插入,包含合并功能

double CountPolyn(PolynLine m, double x)
{
	Polyn* p;
	p = m;
	double res = 0;
	if (p->next == nullptr)
		return res;
	else
	{
		while (p->next != nullptr)
		{
			res += (p->next->coef)*pow(x, p->next->exp);
			p = p->next;
		}
		return res;
	}
}//由于求值的函数不返回值得，所以就造了个新函数

status CreatePolyn(PolynLine &L,FILE* fpin)
{
	double coef;
	int exp;
	printf("请以系数 指数的格式输入以创建多项式（当输入为0 0时退出）\n");
	if (L!=nullptr)
	{
		Polyn* mid = L;
		L = nullptr;
		free(mid);
	}
	L = (Polyn*)malloc(sizeof(Polyn));
	L->next = nullptr;
	while (True)
	{
		fscanf_s(fpin, "%lf%d", &coef, &exp);
		if (coef == 0.0&&exp == 0)
			break;
		if (coef == 0.0)
			continue;
		if (exp < 0)
		{
			printf("您好像输了一个负数，写多项式也要遵守基本法~~\n");
			continue;
		}
		Insert(L, coef, exp);
	}
	return OK;
}//创建一个多项式

status PrintPolyn(PolynLine L,FILE* fpout)
{
	Polyn* p = L;
	int i = 0;//i用于统计是否为第一项
	if (p == nullptr)
	{
		fprintf(fpout,"NULL\n");
		return OK;
	}
	if (p->next == nullptr)
	{
		fprintf(fpout,"0.0000\n");
		return OK;
	}
	while (p->next != nullptr)
	{
		if (p->next->coef < 0 || i == 0)
		{
			switch (p->next->exp)
			{
			case 0:fprintf(fpout,"%.4f", p->next->coef); break;
			case 1:fprintf(fpout,"%.4fx", p->next->coef); break;
			default:fprintf(fpout,"%.4fx^%d", p->next->coef, p->next->exp); break;
			}
		}
		if (p->next->coef > 0 && i != 0)
		{
			switch (p->next->exp)
			{
			case 0:fprintf(fpout,"+%.4f", p->next->coef); break;
			case 1:fprintf(fpout,"+%.4fx", p->next->coef); break;
			default:fprintf(fpout,"+%.4fx^%d", p->next->coef, p->next->exp); break;
			}
		}
		p = p->next;
		i++;
	}
	fprintf(fpout,"\n");
	return OK;
}//显示

status CopyPolyn(PolynLine fir, PolynLine &sec)
{
	Polyn* p, *mid ,*del;
	if (fir->next == nullptr)
	{
		p = sec;
		free(p);
		sec = (Polyn*)malloc(sizeof(Polyn));
		sec->next = nullptr;
	}
	else
	{
		mid = (Polyn*)malloc(sizeof(Polyn));
		mid->next = nullptr;
		p = fir;
		while (p->next != nullptr)
		{
			Insert(mid, p->next->coef, p->next->exp);
			p = p->next;
		}
		del = sec;
		sec = mid;
		free(del);
	}
	return OK;
}//复制

status PlusPolyn(PolynLine m1, PolynLine m2, PolynLine &m3)
{
	Polyn*p,*mid,*q;
	p = (Polyn*)malloc(sizeof(Polyn));
	p->next = nullptr;
	CopyPolyn(m1, p);
	q = m2;
	while (q->next != nullptr)
	{
		Insert(p, q->next->coef, q->next->exp);
		q = q->next;
	}
	mid = m3;
	m3 = p;
	free(mid);
	return OK;
}//加法

status MinusPolyn(PolynLine m1, PolynLine m2, PolynLine &m3)
{
	Polyn*p, *mid, *q;
	p = (Polyn*)malloc(sizeof(Polyn));
	p->next = nullptr;
	CopyPolyn(m1, p);
	q = m2;
	while (q->next != nullptr)
	{
		Insert(p, -(q->next->coef), q->next->exp);
		q = q->next;
	}
	mid = m3;
	m3 = p;
	free(mid);
	return OK;
}//减法

status MultiplyPolyn(PolynLine m1, PolynLine m2, PolynLine &m3)
{
	Polyn *p, *mid, *q, *res;
	p = m1;
	q = m2;
	res = (Polyn*)malloc(sizeof(Polyn));
	res->next = nullptr;
	if (q->next == nullptr || p->next == nullptr)
	{
		mid = m3;
		m3 = res;
		free(mid);
		return OK;
	}
	else
	{
		while (p->next != nullptr)
		{
			while (q->next != nullptr)
			{
				Insert(res, (p->next->coef)*(q->next->coef), (p->next->exp) + (q->next->exp));
				q = q->next;
			}
			q = m2;
			p = p->next;
		}
		mid = m3;
		m3 = res;
		free(mid);
		return OK;
	}
}//乘法

status EvaPolyn(PolynLine m, double x,FILE *fpout)
{
	Polyn* p;
	p = m;
	double res = 0;
	if (p->next == nullptr)
		fprintf(fpout,"%.4f\n", res);
	else
	{
		while (p->next != nullptr)
		{
			res += (p->next->coef)*pow(x, p->next->exp);
			p = p->next;
		}
		fprintf(fpout,"%.4f\n", res);
	}
	return OK;
}//计算结果                                                                                                                                                                                                                                                                                                                                                                                                                                                                             

status DestroyPolyn(PolynLine &m)
{
	Polyn* p;
	p = m;
	m = nullptr;
	free(p);
	return OK;
}//销毁

status ClearPolyn(PolynLine &m)
{
	Polyn*p;
	p = m->next;
	m->next = nullptr;
	free(p);
	return OK;
}//清空

status DiffPolyn(PolynLine m1, PolynLine &m2)
{
	Polyn *p, *mid, *res;
	p = m1;
	res = (Polyn*)malloc(sizeof(Polyn));
	res->next = nullptr;
	if (p->next == nullptr)
	{
		mid = m2;
		m2 = res;
		free(mid);
		return OK;
	}
	else
	{
		while (p->next != nullptr)
		{
			if (p->next->exp == 0)
				;
			else
			{
				Insert(res, (p->next->exp*p->next->coef), (p->next->exp - 1));
			}
			p = p->next;
		}
		mid = m2;
		m2 = res;
		free(mid);
		return OK;
	}
}//微分

status IndefIntegralPolyn(PolynLine m1, PolynLine&m2)
{
	Polyn *p, *mid, *res;
	p = m1;
	res = (Polyn*)malloc(sizeof(Polyn));
	res->next = nullptr;
	if (p->next == nullptr)
	{
		mid = m2;
		m2 = res;
		free(mid);
		return OK;
	}
	else
	{
		while (p->next != nullptr)
		{
			Insert(res, (p->next->coef) / (p->next->exp + 1), (p->next->exp + 1));
			p = p->next;
		}
		mid = m2;
		m2 = res;
		free(mid);
		return OK;
	}
}//不定积分

status DefIntegralPolyn(PolynLine m, double x1, double x2,FILE *fpout)
{
	Polyn* p;
	double res;
	p = (Polyn*)malloc(sizeof(Polyn));
	p->next = nullptr;
	IndefIntegralPolyn(m, p);
	res = CountPolyn(p, x2) - CountPolyn(p, x1);
	fprintf(fpout,"%.4f\n", res);
	free(p);
	return OK;
}//定积分

status DivPolyn(PolynLine m1, PolynLine m2, PolynLine &m3)
{
	Polyn *p, *res, *mid, *del, *m, *n, *i;
	p = (Polyn*)malloc(sizeof(Polyn));
	p->next = nullptr;
	CopyPolyn(m1, p);
	mid = m2;
	res = (Polyn*)malloc(sizeof(Polyn));
	res->next = nullptr;
	if (mid->next == nullptr)
	{
		free(p);
		free(res);
		return Error;
	}
	if (p->next == nullptr)
		;
	else
	{
		while (p->next != nullptr)
		{
			if (p->next->exp >= mid->next->exp)
			{
				Insert(res, p->next->coef / mid->next->coef, p->next->exp - mid->next->exp);
				m = (Polyn*)malloc(sizeof(Polyn));
				m->next = nullptr;
				Insert(m, p->next->coef / mid->next->coef, p->next->exp - mid->next->exp);
				del = (Polyn*)malloc(sizeof(Polyn));
				del->next = nullptr;
				MultiplyPolyn(m, mid, del);
				MinusPolyn(p, del, p);
				free(m);
				free(del);
			}
			else
				break;
		}
	}//运用的是百度到的多项式除法的方法进行逐项运算
	i = m3;
	m3 = res;
	free(i);
	free(p);
	return OK;
}//除法

status ModPolyn(PolynLine m1, PolynLine m2, PolynLine &m3)
{
	Polyn *p, *res, *mid, *del, *m, *i;
	p = (Polyn*)malloc(sizeof(Polyn));
	p->next = nullptr;
	CopyPolyn(m1, p);
	mid = m2;
	res = (Polyn*)malloc(sizeof(Polyn));
	res->next = nullptr;
	if (mid->next == nullptr)
	{
		free(p);
		free(res);
		return Error;
	}
	if (p->next == nullptr)
		;
	else
	{
		while (p->next != nullptr)
		{
			if (p->next->exp >= mid->next->exp)
			{
				Insert(res, p->next->coef / mid->next->coef, p->next->exp - mid->next->exp);
				m = (Polyn*)malloc(sizeof(Polyn));
				m->next = nullptr;
				Insert(m, p->next->coef / mid->next->coef, p->next->exp - mid->next->exp);
				del = (Polyn*)malloc(sizeof(Polyn));
				del->next = nullptr;
				MultiplyPolyn(m, mid, del);
				MinusPolyn(p, del, p);
				free(m);
				free(del);
			}
			else
				break;
		}
	}
	Polyn* mcheng, *min;
	mcheng = nullptr;
	min = nullptr;
	MultiplyPolyn(res, m2, mcheng);
	MinusPolyn(m1, mcheng, min);
	i = m3;
	m3 = min;
	free(i);
	free(p);
	free(mcheng);
	free(res);
	return OK;
}//求模（和除法基本相同，只是最后多了一步计算余式的过程）

status RapidPowPolyn(PolynLine m1, PolynLine &m2, int n)
{
	if (n == 0)
	{
		m2 = (Polyn*)malloc(sizeof(Polyn));
		m2->next = nullptr;
		Insert(m2, 1, 0);
	}
	else
	{
		if (n % 2 == 0)
		{
			RapidPowPolyn(m1, m2, n / 2);
			MultiplyPolyn(m2, m2, m2);
		}
		else
		{
			RapidPowPolyn(m1, m2, (n - 1) / 2);
			MultiplyPolyn(m2, m2, m2);
			MultiplyPolyn(m1, m2, m2);
		}
	}
	return OK;
}//快速幂计算乘方

status ComDivPolyn(PolynLine m1, PolynLine m2, PolynLine &m3)
{
	Polyn *p, *q, *mid, *ave;
	double n;
	p = nullptr;
	q = nullptr;
	CopyPolyn(m1,p);
	CopyPolyn(m2,q);
	mid = nullptr;
	if (p->next == nullptr || q->next == nullptr)
	{
		free(p);
		free(q);
		return Error;
	}
	while (p->next!=nullptr)
	{
		ModPolyn(q, p, mid);
		free(q);
		q = p;
		p = mid;
		mid = nullptr;
	}
	ave = q;
	n = q->next->coef;
	while (ave->next != nullptr)
	{
		ave->next->coef = ave->next->coef / n;
		ave = ave->next;
	}
	mid = m3;
	m3 = q;
	free(mid);
	free(p);
	return OK;
}

status ComMulPolyn(PolynLine m1, PolynLine m2, PolynLine &m3)
{
	Polyn *p, *q, *res, *mid,*ave;
	double n;
	p = (Polyn*)malloc(sizeof(Polyn));
	p->next = nullptr;
	q = (Polyn*)malloc(sizeof(Polyn));
	q->next = nullptr;
	res = (Polyn*)malloc(sizeof(Polyn));
	res->next = nullptr;
	MultiplyPolyn(m1, m2, p);
	ComDivPolyn(m1, m2, q);
	DivPolyn(p, q, res);
	ave = res;
	n = res->next->coef;
	while (ave->next != nullptr)
	{
		ave->next->coef = ave->next->coef / n;
		ave = ave->next;
	}
	mid = m3;
	m3 = res;
	free(mid);
	free(p);
	free(q);
	return OK;
}

int main()
{
	int i, fun, num, judge, m1, m2, m3, n;
	double x, x1, x2;
	FILE *fpin, *fpout;
	fpin = fopen("polyn.in", "r");
	fpout = fopen("polyn.out", "w");
	PolynLine PolynList[10];
	Polyn* mid;
	Polyn* p;
	for (i = 0; i <= 9; i++)
	{
		PolynList[i] = nullptr;
	}//申请指针数组
	printf("亲，欢迎光临，小店的宝贝请随便看看(๑╹ヮ╹๑)ﾉ\n ");
	printf("嘤嘤嘤，亲，您看中了哪款宝贝了呢？看中就输入对应的数字用用看吧！\n");
	printf("我们有10款多项式分别为0~9号，任您挑选\n");
	while (true)
	{
		printf("请问您想使用哪个功能呐？\n");
		//我知道下一句话很长很长，实在懒得多打printf了，啾（尝试卖萌博得同情）
		printf("0:当然是选择退出啦\n1：创建一个传说级的多项式\n2：打印您的杰作\n3：分身复制之术\n4：当然是加在一起合体啦\n5：我要让他们自相残杀，一个减去另一个\n6：乘起来吧（中二病消退）\n7：展（计）现（算）它的法（数）力（值）\n8：销毁它\n9：清空它\n10:求微分\n11:求不定积分\n12:求定积分\n13：找出他们最大的相同（最大公因式）\n14:找出他们的最小公倍式\n15：做一个宏大的除法（写这个可晕死我了）\n16：做一个诡异的求模\n17:求乘方啦\n");
		fscanf_s(fpin, "%d", &fun);
		if (fun == 0)
			break;
		switch (fun)
		{
		case 1:
		{
			printf("请问您想创建哪个位置的多项式呢？\n");
			fscanf_s(fpin, "%d", &num);
			judge = CreatePolyn(PolynList[num], fpin);
			if (judge == OVERFLOW)
				printf("申请内存出现了错误，我希望你看不到这句话\n");
		} break;
		case 2:
		{
			printf("请问您想打印哪个位置的多项式呢？\n");
			fscanf_s(fpin, "%d", &num);
			PrintPolyn(PolynList[num], fpout);
		}break;
		case 3:
		{
			printf("请问您想复制哪个位置的多项式？请问您想将它复制到哪个位置上呢\n");
			fscanf_s(fpin, "%d%d", &m1, &m2);
			CopyPolyn(PolynList[m1], PolynList[m2]);
		}break;
		case 4:
		{
			printf("请问您想要将哪两个多项式加起来呢？请问您想将结果储存在哪里呢\n");
			fscanf_s(fpin, "%d%d%d", &m1, &m2, &m3);
			PlusPolyn(PolynList[m1], PolynList[m2], PolynList[m3]);
		}break;
		case 5:
		{
			printf("请问您想要让哪个多项式减去哪个多项式？请问您想将结果储存在哪里呢？\n");
			fscanf_s(fpin, "%d%d%d", &m1, &m2, &m3);
			MinusPolyn(PolynList[m1], PolynList[m2], PolynList[m3]);
		}break;
		case 6:
		{
			printf("请问您想将哪两个多项式乘起来呢？请问您想将结果储存在哪里呢\n");
			fscanf_s(fpin, "%d%d%d", &m1, &m2, &m3);
			MultiplyPolyn(PolynList[m1], PolynList[m2], PolynList[m3]);
		}break;
		case 7:
		{
			printf("请问您想计算哪个多项式的值？请问您的x值是多少？\n");
			fscanf_s(fpin, "%d%lf", &num, &x);
			EvaPolyn(PolynList[num], x, fpout);
		}break;
		case 8:
		{
			printf("请问您想销毁哪个多项式\n");
			fscanf_s(fpin, "%d", &num);
			DestroyPolyn(PolynList[num]);
		}break;
		case 9:
		{
			printf("请问您想清空哪个多项式\n");
			fscanf_s(fpin, "%d", &num);
			ClearPolyn(PolynList[num]);
		}break;
		case 10:
		{
			printf("请问您想求哪个多项式的微分?储存在哪个位置?\n");
			fscanf_s(fpin, "%d%d", &m1, &m2);
			DiffPolyn(PolynList[m1], PolynList[m2]);
		}break;
		case 11:
		{
			printf("请问您想对哪个多项式求不定积分？结果存储在哪个位置呢？\n");
			fscanf_s(fpin, "%d%d", &m1, &m2);
			IndefIntegralPolyn(PolynList[m1], PolynList[m2]);
		}break;
		case 12:
		{
			printf("请问您想对哪个多项式求定积分？积分下限是什么？上限是什么？\n");
			fscanf_s(fpin, "%d%lf%lf", &num, &x1, &x2);
			DefIntegralPolyn(PolynList[num], x1, x2, fpout);
		}break;
		case 13:
		{
			printf("请问您想求哪两个多项式的最大公约式？放在哪里？\n");
			fscanf_s(fpin, "%d%d%d", &m1, &m2, &m3);
			ComDivPolyn(PolynList[m1], PolynList[m2], PolynList[m3]);
		}break;
		case 14:
		{
			printf("请问您想求哪两个多项式的最小公倍式？放在哪里？\n");
			fscanf_s(fpin, "%d%d%d", &m1, &m2, &m3);
			ComMulPolyn(PolynList[m1], PolynList[m2], PolynList[m3]);
		}break;
		case 15:
		{
			printf("请问被除式是哪个呢？除式是哪个呢？您想将结果放到哪里呢？\n");
			fscanf_s(fpin, "%d%d%d", &m1, &m2, &m3);
			DivPolyn(PolynList[m1], PolynList[m2], PolynList[m3]);
		}break;
		case 16:
		{
			printf("请问被除式是哪个呢？除式是哪个呢？您想将模放到哪里呢？\n");
			fscanf_s(fpin, "%d%d%d", &m1, &m2, &m3);
			ModPolyn(PolynList[m1], PolynList[m2], PolynList[m3]);
		}break;
		case 17:
		{
			printf("请问您想求哪个多项式的乘方呢？放在哪个位置呢？幂是多少次？\n");
			fscanf_s(fpin, "%d%d%d", &m1, &m2, &n);
			RapidPowPolyn(PolynList[m1], p, n);
			CopyPolyn(p, PolynList[m2]);
			free(p);
		}break;
		}//循环获得功能需求
	}
	for (i = 0; i <= 9; i++)
	{
		mid = PolynList[i];
		PolynList[i] = nullptr;
		free(mid);
	}//清空掉所有的空间
	fclose(fpin);
	fclose(fpout);
	return 0;
}
