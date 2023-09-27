#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
int Inte(char A[], char B[])//收入整数
{
	int i = 0;
	while (A[i] >= '0' && A[i] <= '9')
	{
		B[i] = A[i];
		i++;
	}
	return i;
}
void Double(char A[], char C[], int i)//收入小数
{
	i += 1;
	int j = 0;
	while (A[i] >= '0' && A[i] <= '9')
	{
		C[j++] = A[i++];
	}
}
void trans_i(char inte[], int i)//转换整数为二进制
{
	int c = 0;
	while (i)
	{
		inte[c] = i % 2 + '0';
		i /= 2;
		c++;
	}
}
void trans_d(char dou[], double i)//转化小数为二进制
{
	int c = 0;
	for(int n=20;n>0;n--)
	{
		if (i * 2 >= 1)
		{
			dou[c] = 1+'0';
			i = i * 2 - 1;
		}
		else
		{
			dou[c] = 0+'0';
			i *= 2;
		}
		c++;
	}
}
int Der(int x)//判断小数位数
{
	int n = 0;
	while (x)
	{
		x /= 10;
		n++;
	}
	return n;
}
char* inversion(char* a, char* b)
{
	char* p = a;
	int n = 0;
	while (*b++)
	{
		n++;
	}
	b -= 2;
	for (int j=0; j <n; j++)
	{
		*a++ = *b--;
	}
	return p;
}
int main()
{
	int i = 0;
	int j = 0;
	int h = 0;
	int k = 0;
	int h_n = 0;
	char L = 0;
	char A[128];
	int n_double;
	int d_n = 0;
	char inte[128] = { 0 };
	char dou[128] = { 0 };
	char inte_16[128] = { 0 };
	char space[128] = { 0 };
	char dou_16[128] = { 0 };
	int Z=0;
	int X=0;
	double x=0;
	int Z_16;
	int o = 0;
	scanf("%s", A);
	i = Inte(A, inte);
	Double(A, dou, i);
	Z = atoi(inte);
	X = atoi(dou);
	n_double = Der(X);
	x = X / pow(10, n_double);
	trans_i(inte, Z);
	trans_d(dou, x,n_double);
	while (inte[j])   //二进制转十六
	{
		if (k == 4)
		{
			k = 0;
			inte_16[h] += '0';
			h++;
			continue;
		}
		inte_16[h] += (inte[j] - '0') * pow(2, k);
		k++;
		j++;
	}
	inte_16[h] += '0';
	while (inte_16[h_n])//整数十六进制规范化
	{
		if (inte_16[h_n] > '9')
		{
			L = inte_16[h_n] - '9';
			inte_16[h_n] = 'A' + L - 1;
		}
		h_n++;
	}
	k = 3;
	h = 0;
	while (dou[o])//小数二进制转十六
	{
		if (k == 0)
		{
			k = 4;
			dou_16[h] += '0';
			h++;
			continue;
		}
		dou_16[h] += (dou[o] - '0') * pow(2, k);
		k--;
		o++;
	}
	dou_16[o] += '0';
	while (dou_16[d_n])//小数十六规范化
	{
		if (dou_16[d_n] > '9')
		{
			L = dou_16[d_n] - '9';
			dou_16[d_n] = 'A' + L - 1;
		}
		d_n++;
	}
	printf("%s", inversion(space,inte_16));
	putchar('.');
	printf("%s", dou_16);

	return 0;
}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<ctype.h>
//#include<math.h>
//int Inte(char A[], char B[])
//{
//	int i = 0;
//	while (A[i] > '0' && A[i] < '9')
//	{
//		B[i] = A[i];
//		i++;
//	}
//	return i;
//}
//void Double(char A[], char C[],int i)
//{
//	i += 1;
//	int j = 0;
//	while (A[i] > '0' && A[i] < '9')
//	{
//		C[j++] = A[i++];
//	}
//}
//void trans_i(char inte[], int i)
//{
//	char* p = inte;
//	int c = 0;
//	while (i)
//	{
//		inte[c] = i % 2+'0';
//		i /= 2;
//		c++;
//	}
//}
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int h = 0;
//	int k = 0;
//	char A[128];
//	char inte[128] = { 0 };
//	char dou[128] = { 0 };
//	char inte_16[128] = { 0 };
//	int Z;
//	int X;
//	scanf("%s", A);
//	i=Inte(A, inte);
//	Double(A, dou, i);
//	Z = atoi(inte);
//	X = atoi(dou);
//	trans_i(inte, Z);
//	while (inte[j])
//	{
//		if (k == 4)
//		{
//			k = 0;
//			h++;
//		}
//		inte_16[h] += inte[j] * pow(16, k);
//		k++;
//		j++;
//	}
//	printf("%s", inte_16);
//	return 0;
//
//}
//#include <stdio.h>
//#include<stdlib.h>
//#include<math.h>
//char* str_na(char*a,char*b,int na)
//{
//	int n_sum = 0;
//	int n_group = 0;
//	int n_space = 0;
//	int n_16_sum=0;
//	int n_tran = 0;
//	int n_rest = 0;
//	int n_groupsum = 0;
//	char* str_tmp=b;
//	while (na)
//	{
//		if (na % 2 == 1)
//		{
//			*a = '1';
//			
//		}
//		else
//		{
//			*a = '0';
//		}
//		a++;
//		na /= 2;
//		n_sum++;
//	}	
//	a -= n_sum;
//	n_group = n_sum / 4;
//	n_space = n_sum % 4;
//	n_tran = atoi(a);
//	n_groupsum = n_tran /pow(10,n_space) ;
//	n_rest = n_tran - n_groupsum * pow(10, n_space);
//	for (int n_group_tmp = 0; n_group_tmp < n_group; n_group_tmp++)
//	{
//		int i = 1;
//		int n16 = 0;
//		for (int n_number = 0; n_number < 4; n_number++)
//		{
//			n_16_sum += pow(16,n16)*(n_tran / pow(10, 4*n_group-i)-(n_tran/pow(10,4*n_group-i+1))*10);
//			n16++;
//			i++;
//		}
//		*b++ = n_16_sum;
//		n_16_sum = 0;
//	}
//	return str_tmp;
//}
//int version(int n)
//{
//	int n_number = 0;
//	while (n)
//	{
//		n_number++;
//		n /= 10;
//	}
//
//}
//int main()
//{
//	double xd;
//	scanf_s("%lf", &xd);
//	int xi = xd;
//	char A[128] = {"0"};
//	char B[128] = {"0"};
//	printf("%s", str_na(A,B,xi));
//	return 0;
//}