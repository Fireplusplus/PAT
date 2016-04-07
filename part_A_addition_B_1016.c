/* 
 * 正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。
 * 例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。
 * 现给定A、DA、B、DB，请编写程序计算PA + PB。
 * 输入格式：
 * 输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。
 * 输出格式：
 * 在一行中输出PA + PB的值。  
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sum_d(int num1, int d_num1, int num2, int d_num2)
{
	int p_num1 = 0, p_num2 = 0;
	int rs1 = 0, rs2 = 0;

	while (num1 > 0) {
		if (num1 % 10 == d_num1)
			++p_num1;
		num1 /= 10;
	}
	while (num2 > 0) {
		if (num2 % 10 == d_num2)
			++p_num2;
		num2 /= 10;
	}
	for (p_num1; p_num1 > 0; p_num1--)
		rs1 += (d_num1 * pow(10, p_num1 - 1));
	for (p_num2; p_num2 > 0; p_num2--)
		rs2 += (d_num2 * pow(10, p_num2 - 1));

	return rs1 + rs2;
}

int main()
{
	int num1 = 0, num2 = 0;
	int d_num1 = 0, d_num2 = 0;
	int sum = 0;

	scanf("%d%d%d%d", &num1, &d_num1, &num2, &d_num2);
	sum = sum_d(num1, d_num1, num2, d_num2);
	printf("%d", sum);

	system("pause");
	return 0;
}