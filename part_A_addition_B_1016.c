/* 
 * ������A�ġ�DA��Ϊ1λ���������֡�����Ϊ��A������DA��ɵ�������PA��
 * ���磺����A = 3862767��DA = 6����A�ġ�6���֡�PA��66����ΪA����2��6��
 * �ָ���A��DA��B��DB�����д�������PA + PB��
 * �����ʽ��
 * ������һ�������θ���A��DA��B��DB���м��Կո�ָ�������0 < A, B < 1010��
 * �����ʽ��
 * ��һ�������PA + PB��ֵ��  
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