#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int search(int a, int* b)
{//查找数组b中是否有a的存在
	for (int i = 1; i <= 100; i++)
		if (b[i] == a)
			return true;
	return false;
}
int main()
{
	int a;
	int b[101];
	int i = 1;
	FILE* fp;
	//打开input.txt文件
	fp = fopen("..\\..\\input\\input.txt", "w");
	if (fp == NULL)
	{
		printf("error");
		exit(0);
	}
	for (int n = 0; n <= 100; n++)
		b[n] = 0;
	//b数组用于存储将要输出到input.txt文件的结果
	while (i <= 100)
	{
		a = rand();
		if (a > 0 && search(a, b) == false)
		{//如果该随机数为正数，且a不在数组b中，则说明a为与已产生的数互异的一个正整数，加入b数组
			b[i] = a;
			i++;
		}
	}
	for (i = 1; i <= 100; i++)
		fprintf(fp, "%d ", b[i]);
	//输出结果
	fclose(fp);
}