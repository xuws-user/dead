#include<stdio.h>
#include<stdlib.h>

void set(float**& p, int M, int N)
{
	int i = 0, j = 0;
	p = new float* [M];
	for (i = 0; i < M; i++)
	{
		p[i] = new float[N];
	}
}
void average_row(float**& p, float* p_row, int M, int N)
{
	int i = 0, j = 0;
	float a = 0;
	for (i = 0; i < M; i++)
	{
		a = 0;
		for (j = 0; j < N; j++)
		{
			a += p[i][j];
		}
		p_row[i] = a / N;
	}
}
void average_col(float**& p, float* p_col, int M, int N)
{
	int i = 0, j = 0;
	float a = 0;
	for (j = 0; j < N; j++)
	{
		a = 0;
		for (i = 0; i < M; i++)
		{
			a += p[i][j];
		}
		p_col[j] = a / M;
	}
}
void delete_row(float**& p, int M, int N, float key_row)
{
	int i = 0, j = 0;
	for (i = key_row - 1; i < M - 1; i++)
	{
		for (j = 0; j < N; j++)
		{
			p[i][j] = p[i + 1][j];
		}
	}
}
void delete_col(float**& p, int M, int N, int key_col)
{
	int i = 0, j = 0;
	for (i = key_col - 1; i < N - 1; i++)
	{
		for (j = 0; j < M; j++)
		{
			p[j][i] = p[j][i + 1];
		}
	}
}
void multiplication(float**& p, float* x, float* ans, int M, int N)
{
	int i = 0, j = 0;
	for (i = 0; i < M; i++)
	{
		float a = 0;
		for (j = 0; j < N; j++)
		{
			a += p[i][j] * x[j];
		}
		ans[i] = a;
	}
}

int main()
{
	int M = 0, N = 0, i = 0, j = 0, key_row = 0, key_col = 0;
	printf("请输入行数\n");
	scanf_s("%d", &M);
	printf("请输入列数\n");
	scanf_s("%d", &N);
	float*(*p) = NULL;
	float* p_row = NULL;
	float* p_col = NULL;
	float* x = NULL;
	float* ans = NULL;
	x = new float[N];
	ans = new float[M];
	set(p, M, N);
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("请输入第%d行第%d列的数", i + 1, j + 1);
			scanf_s("%f", &p[i][j]);
		}
	}
	p_row = new float[M];
	average_row(p, p_row, M, N);
	for (i = 0; i < M; i++)
	{
		printf("第%d行平均值为%f\n", i + 1, p_row[i]);
	}
	p_col = new float[N];
	average_col(p, p_col, M, N);
	for (i = 0; i < N; i++)
	{
		printf("第%d列平均值为%f\n", i + 1, p_col[i]);
	}
	for (i = 0; i < M; i++)
	{
		printf("请输入M维向量X的第%d个值\n", i + 1);
		scanf_s("%f", &x[i]);
	}
	multiplication(p, x, ans, M, N);
	for (i = 0; i < M; i++)
	{
		printf("第%d个值为%f", i + 1, ans[i]);
	}
	printf("你要删除第几行数据?\n");
	scanf_s("%d", &key_row);
	delete_row(p, M, N, key_row);
	delete* p[M - 1];
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("第%d行第%d列得数为%f\n", i + 1, j + 1, p[i][j]);
		}
	}
	printf("请问你要删除第几列数据?\n");
	scanf_s("%d", &key_col);
	delete_col(p, M, N, key_col);
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("第%d行第%d列得数为%f\n", i + 1, j + 1, p[i][j]);
		}
	}
	return 0;
}