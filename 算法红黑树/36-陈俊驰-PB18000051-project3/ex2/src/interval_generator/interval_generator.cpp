#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int search(int a, int* b)
{//查找数组b中是否有a的存在
	for (int i = 1; i <= 30; i++)
		if (b[i] == a)
			return true;
	return false;
}
int main()
{
	int a,b;
	int left[31];
	int right[31];
	int i = 1;
	FILE* fp;
	//打开input.txt文件
	fp = fopen("..\\..\\input\\input.txt", "w");
	for (int n = 0; n <= 30; n++)
	{//初始化left和right数组，分别用于存储区间的左右端点
		left[n] = 123;
		right[n] = 123;
	}
	//left和right数组用于存储将要输出到input.txt文件的结果
	i = 1;
	while (i <= 30)
	{
		a = rand()%51;
		if (search(a, left))//保证不存在相同左端点
			continue;
		if (a >= 0 && a < 25)
		{//对于取自[0,25]的区间
			b = rand() % 26;
			while (b <= a)
			{//保证b大于a
				b = rand() % 26;
			}
			left[i] = a;
			right[i] = b;
			i++;
		}
		else if (a >= 30 && a < 50)
		{//对于取自[30,50]的区间
			b = rand() % 21 + 30;
			while (b <= a)
			{
				b = rand() % 21 + 30;
			}
			left[i] = a;
			right[i] = b;
			i++;
		}
		else
			continue;
		

	}
	for (i = 1; i <= 30; i++)
	{
		fprintf(fp, "%d %d\n",left[i],right[i]);
	}
	//输出结果
	fclose(fp);
}