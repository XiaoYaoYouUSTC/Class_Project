#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<chrono>

using namespace std;
using namespace chrono;

//在堆中申请一系列指针，为之后申请存储元素的空间作准备
int* A3, * A6, * A9, * A12, * A15, * A18;

//为了方便书写与阅读，数组下标均从1开始使用

void Insert_Sort(int a[], int n)
{//插入排序，其中a[]为所要排序的数组，n为数据量，通过main函数传入
	int i, j, key;
	for (j = 2; j <= n; j++)
	{
		key = a[j];
		//将a[j]插入到已排序的序列a[1...j-1]
		for (i = j - 1; i > 0; i--)
			if (a[i] > key)
				//将每一个比a[j]大的右移一位，直到找到一个key介于左右两元素大小之间的
				a[i + 1] = a[i];
			else
				break;
		a[i + 1] = key;
	}
}


int main()
{
	//申请一系列文件指针，其中i为读入input.txt，o3到o18分别对应3到18的指数规模输出文件，time对应时间结果文件
	FILE* fp_i, * fp_o3, * fp_o6, * fp_o9, * fp_o12, * fp_o15, * fp_o18, * fp_time;
	int i,  k;
	fp_i = fopen("..\\..\\input\\input.txt", "r");
	fp_o3 = fopen("..\\..\\output\\insert_sort\\result_3.txt", "w");
	fp_o6 = fopen("..\\..\\output\\insert_sort\\result_6.txt", "w");
	fp_o9 = fopen("..\\..\\output\\insert_sort\\result_9.txt", "w");
	fp_o12 = fopen("..\\..\\output\\insert_sort\\result_12.txt", "w");
	fp_o15 = fopen("..\\..\\output\\insert_sort\\result_15.txt", "w");
	fp_o18 = fopen("..\\..\\output\\insert_sort\\result_18.txt", "w");
	fp_time = fopen("..\\..\\output\\insert_sort\\time.txt", "w");
	

	//对应规模2^3
	//读取数据
	A3 = (int*)malloc((8 + 1) * sizeof(int));
	for (i = 1; i <= 8; i++)
	{
		fscanf(fp_i, "%d",&k);
		A3[i] = k;
	}
	//将文件指针重置到开始，为下次读取做准备
	fseek(fp_i, 0, SEEK_SET);
	//开始计时
	auto start = system_clock::now();
	//对2^3规模数据调用插入排序
	Insert_Sort(A3, 8);
	//结束计时，输出计时结果
	auto end = system_clock::now();
	auto duration = duration_cast<nanoseconds>(end - start);
	fprintf(fp_time, "对于2^3规模花费了 %lf us\n", 1000000*double(duration.count()) * nanoseconds::period::num / nanoseconds::period::den);
	//输出排序结果
	for (i = 1; i <= 8; i++)
	{
		fprintf(fp_o3, "%d\n", A3[i]);
	}
	//释放分配的空间
	free(A3);


	//对应规模2^6
	//读取数据
	A6 = (int*)malloc((64 + 1) * sizeof(int));
	for (i = 1; i <= 64; i++)
	{
		fscanf(fp_i, "%d",&k);
		A6[i] = k;
	}
	//将文件指针重置到开始，为下次读取做准备
	fseek(fp_i, 0, SEEK_SET);
	//开始计时
	start = system_clock::now();
	//对2^6规模数据调用插入排序
	Insert_Sort(A6, 64);
	//结束计时，输出计时结果
	end = system_clock::now();
	duration = duration_cast<nanoseconds>(end - start);
	fprintf(fp_time, "对于2^6规模花费了 %lf us\n", 1000000 * double(duration.count()) * nanoseconds::period::num / nanoseconds::period::den);
	//输出排序结果
	for (i = 1; i <= 64; i++)
	{
		fprintf(fp_o6, "%d\n", A6[i]);
	}
	free(A6);


	//对应规模2^9
	//读取数据
	A9 = (int*)malloc((512 + 1) * sizeof(int));
	for (i = 1; i <= 512; i++)
	{
		fscanf(fp_i, "%d",&k);
		A9[i] = k;
	}
	//将文件指针重置到开始，为下次读取做准备
	fseek(fp_i, 0, SEEK_SET);
	//开始计时
	start = system_clock::now();
	//对2^9规模数据调用插入排序
	Insert_Sort(A9, 512);
	//结束计时，输出计时结果
	end = system_clock::now();
	duration = duration_cast<nanoseconds>(end - start);
	fprintf(fp_time, "对于2^9规模花费了 %lf us\n", 1000000*double(duration.count()) * nanoseconds::period::num / nanoseconds::period::den);
	//输出排序结果
	for (i = 1; i <= 512; i++)
	{
		fprintf(fp_o9, "%d\n", A9[i]);
	}
	free(A9);


	//对应规模2^12
	//读取数据
	A12 = (int*)malloc((4096 + 1) * sizeof(int));
	for (i = 1; i <= 4096; i++)
	{
		fscanf(fp_i, "%d",&k);
		A12[i] = k;
	}
	//将文件指针重置到开始，为下次读取做准备
	fseek(fp_i, 0, SEEK_SET);
	//开始计时
	start = system_clock::now();
	//对2^12规模数据调用插入排序
	Insert_Sort(A12, 4096);
	//结束计时，输出计时结果
	end = system_clock::now();
	duration = duration_cast<nanoseconds>(end - start);
	fprintf(fp_time, "对于2^12规模花费了 %lf us\n", 1000000*double(duration.count()) * nanoseconds::period::num / nanoseconds::period::den);
	//输出排序结果
	for (i = 1; i <= 4096; i++)
	{
		fprintf(fp_o12, "%d\n", A12[i]);
	}
	free(A12);


	//对应规模2^15
	//读取数据
	A15 = (int*)malloc((32768 + 1) * sizeof(int));
	for (i = 1; i <= 32768; i++)
	{
		fscanf(fp_i, "%d",&k);
		A15[i] = k;
	}
	//将文件指针重置到开始，为下次读取做准备
	fseek(fp_i, 0, SEEK_SET);
	//开始计时
	start = system_clock::now();
	//对2^15规模数据调用插入排序
	Insert_Sort(A15, 32768);
	//结束计时，输出计时结果
	end = system_clock::now();
	duration = duration_cast<nanoseconds>(end - start);
	fprintf(fp_time, "对于2^15规模花费了 %lf us\n", 1000000*double(duration.count()) * nanoseconds::period::num / nanoseconds::period::den);
	//输出排序结果
	for (i = 1; i <= 32768; i++)
	{
		fprintf(fp_o15, "%d\n", A15[i]);
	}
	free(A15);


	//对应规模2^18
	//读取数据
	A18 = (int*)malloc((262144 + 1) * sizeof(int));
	for (i = 1; i <= 262144; i++)
	{
		fscanf(fp_i, "%d",&k);
		A18[i] = k;
	}
	//将文件指针重置到开始，为下次读取做准备
	fseek(fp_i, 0, SEEK_SET);
	//开始计时
	start = system_clock::now();
	//对2^18规模数据调用插入排序
	Insert_Sort(A18, 262144);
	//结束计时，输出计时结果
	end = system_clock::now();
	duration = duration_cast<nanoseconds>(end - start);
	fprintf(fp_time, "对于2^18规模花费了 %lf us\n", 1000000*double(duration.count()) * nanoseconds::period::num / nanoseconds::period::den);
	//输出排序结果
	for (i = 1; i <= 262144; i++)
	{
		fprintf(fp_o18, "%d\n", A18[i]);
	}
	free(A18);

	fclose(fp_i);
	fclose(fp_o3);
	fclose(fp_o6);
	fclose(fp_o9);
	fclose(fp_o12);
	fclose(fp_o15);
	fclose(fp_o18);
	fclose(fp_time);
}