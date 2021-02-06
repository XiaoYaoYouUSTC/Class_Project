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

void MERGE(int A[], int p, int q, int r)
{	//输入一个数组A[p,r],其中A[p,q]A[q+1,r]已经有序，将二者合并为一个有序数组
	int n1 = q - p + 1;
	int n2 = r - q;
	int* L = (int*)malloc((n1 + 2) * sizeof(int));
	int* R = (int*)malloc((n2 + 2) * sizeof(int));
	int i, j, k;
	//将数组数据拷贝下来
	for (i = 1; i <= n1; i++)
		L[i] = A[p + i - 1];
	for (j = 1; j <= n2; j++)
		R[j] = A[q + j];
	//设置哨兵
	L[n1 + 1] = 65536;
	R[n2 + 1] = 65536;
	i = 1; j = 1;
	//比较并将L和R中最小的元素按序抄入A[p,q]
	for (k = p; k <= r; k++)
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i = i + 1;
		}
		else
		{
			A[k] = R[j];
			j = j + 1;
		}
}

void Merge_Sort(int A[], int p, int r)
{
	//输入一个数组及其上下限，对该范围内的元素进行排序
	int q;
	if (p < r)
	{
		//在该范围合规的情况下，先对左右两部分分别排序
		q = (p + r) / 2;
		Merge_Sort(A, p, q);
		Merge_Sort(A, q + 1, r);
		//再对排序好的左右两部分进行合并
		MERGE(A, p, q, r);
	}
}


int main()
{
	//申请一系列文件指针，其中i为读入input.txt，o3到o18分别对应3到18的指数规模输出文件，time对应时间结果文件
	FILE* fp_i, * fp_o3, * fp_o6, * fp_o9, * fp_o12, * fp_o15, * fp_o18, * fp_time;
	int i, k;
	fp_i = fopen("..\\..\\input\\input.txt", "r");
	fp_o3 = fopen("..\\..\\output\\merge_sort\\result_3.txt", "w");
	fp_o6 = fopen("..\\..\\output\\merge_sort\\result_6.txt", "w");
	fp_o9 = fopen("..\\..\\output\\merge_sort\\result_9.txt", "w");
	fp_o12 = fopen("..\\..\\output\\merge_sort\\result_12.txt", "w");
	fp_o15 = fopen("..\\..\\output\\merge_sort\\result_15.txt", "w");
	fp_o18 = fopen("..\\..\\output\\merge_sort\\result_18.txt", "w");
	fp_time = fopen("..\\..\\output\\merge_sort\\time.txt", "w");
	

	//对应规模2^3
	//读取数据
	A3 = (int*)malloc((8 + 1) * sizeof(int));
	for (i = 1; i <= 8; i++)
	{
		fscanf(fp_i, "%d", &k);
		A3[i] = k;
	}
	//将文件指针重置到开始，为下次读取做准备
	fseek(fp_i, 0, SEEK_SET);
	//开始计时
	auto start = system_clock::now();
	//对2^3规模数据调用归并排序
	Merge_Sort(A3, 1,8);
	//结束计时，输出计时结果
	auto end = system_clock::now();
	auto duration = duration_cast<nanoseconds>(end - start);
	fprintf(fp_time, "对于2^3规模花费了 %lf us\n", 1000000 * double(duration.count()) * nanoseconds::period::num / nanoseconds::period::den);
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
		fscanf(fp_i, "%d", &k);
		A6[i] = k;
	}
	//将文件指针重置到开始，为下次读取做准备
	fseek(fp_i, 0, SEEK_SET);
	//开始计时
	start = system_clock::now();
	//对2^6规模数据调用归并排序
	Merge_Sort(A6, 1,64);
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
		fscanf(fp_i, "%d", &k);
		A9[i] = k;
	}
	//将文件指针重置到开始，为下次读取做准备
	fseek(fp_i, 0, SEEK_SET);
	//开始计时
	start = system_clock::now();
	//对2^9规模数据调用归并排序
	Merge_Sort(A9, 1,512);
	//结束计时，输出计时结果
	end = system_clock::now();
	duration = duration_cast<nanoseconds>(end - start);
	fprintf(fp_time, "对于2^9规模花费了 %lf us\n", 1000000 * double(duration.count()) * nanoseconds::period::num / nanoseconds::period::den);
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
		fscanf(fp_i, "%d", &k);
		A12[i] = k;
	}
	//将文件指针重置到开始，为下次读取做准备
	fseek(fp_i, 0, SEEK_SET);
	//开始计时
	start = system_clock::now();
	//对2^12规模数据调用归并排序
	Merge_Sort(A12, 1,4096);
	//结束计时，输出计时结果
	end = system_clock::now();
	duration = duration_cast<nanoseconds>(end - start);
	fprintf(fp_time, "对于2^12规模花费了 %lf us\n", 1000000 * double(duration.count()) * nanoseconds::period::num / nanoseconds::period::den);
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
		fscanf(fp_i, "%d", &k);
		A15[i] = k;
	}
	//将文件指针重置到开始，为下次读取做准备
	fseek(fp_i, 0, SEEK_SET);
	//开始计时
	start = system_clock::now();
	//对2^15规模数据调用归并排序
	Merge_Sort(A15, 1,32768);
	//结束计时，输出计时结果
	end = system_clock::now();
	duration = duration_cast<nanoseconds>(end - start);
	fprintf(fp_time, "对于2^15规模花费了 %lf us\n", 1000000 * double(duration.count()) * nanoseconds::period::num / nanoseconds::period::den);
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
		fscanf(fp_i, "%d", &k);
		A18[i] = k;
	}
	//将文件指针重置到开始，为下次读取做准备
	fseek(fp_i, 0, SEEK_SET);
	//开始计时
	start = system_clock::now();
	//对2^18规模数据调用归并排序
	Merge_Sort(A18,1, 262144);
	//结束计时，输出计时结果
	end = system_clock::now();
	duration = duration_cast<nanoseconds>(end - start);
	fprintf(fp_time, "对于2^18规模花费了 %lf us\n", 1000000 * double(duration.count()) * nanoseconds::period::num / nanoseconds::period::den);
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