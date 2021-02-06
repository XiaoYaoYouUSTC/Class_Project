#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	FILE* fp;
	//打开input.txt文件
	fp=fopen( "..\\..\\input\\input.txt", "w");
	if (fp == NULL)
	{
		printf("error");
		exit(0);
	}
	int i;
	int count;
	count = pow(2, 18);
	//生成并写入2^18个随机数
	for (i = 1; i <= count; i++)
		fprintf(fp, "%d\n", rand());
	fclose(fp);
}