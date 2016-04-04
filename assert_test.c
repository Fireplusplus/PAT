/* 
 * ����һϵ�����������밴Ҫ������ֽ��з��࣬���������5�����֣�
 * A1 = �ܱ�5����������������ż���ĺͣ�
 * A2 = ����5������1�����ְ�����˳����н�����ͣ�������n1-n2+n3-n4...��
 * A3 = ��5������2�����ֵĸ�����
 * A4 = ��5������3�����ֵ�ƽ��������ȷ��С�����1λ��
 * A5 = ��5������4��������������� 
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void A1(int num, int *a1, int *count_a1)
{
	if ((num % 10) == 0) {
		*a1 += num;
		(*count_a1)++;
	}	
}

void A2(int num, int *a2, int *count_a2, int *flag)
{
	if (num % 5 == 1) {
		*a2 += (*flag * num);
		(*count_a2)++;
		*flag = -(*flag);
	}
}

void A3(int num, int *a3, int *count_a3)
{
	if ((num % 5) == 2) {
		(*a3)++;
		(*count_a3)++;
	}
}
void A4(int num, int *a4, int *count_a4)
{
	if ((num % 5) == 3) {
		(*a4) += num;
		(*count_a4)++;
	}
}
void A5(int num, int *a5, int *count_a5)
{
	if ((num % 5) == 4) {
		*a5 = *a5 > num ? *a5 : num;
		(*count_a5)++;
	}
}
int main()
{
	int n = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, num = 0;
	int count_a1 = 0, count_a2 = 0, count_a3 = 0, count_a4 = 0, count_a5 = 0;
	int flag_A2 = 1;

	scanf("%d", &n);
	for (; n > 0; n--) {
		scanf("%d", &num);
		A1(num, &a1, &count_a1);
		A2(num, &a2, &count_a2, &flag_A2);
		A3(num, &a3, &count_a3);
		A4(num, &a4, &count_a4);
		A5(num, &a5, &count_a5);
	}
	if (count_a1 > 0)
		printf("%d ", a1);
	else
		printf("N ");

	if (count_a2 > 0)
		printf("%d ", a2);
	else
		printf("N ");

	if (count_a3 > 0)
		printf("%d ", a3);
	else
		printf("N ");

	if (count_a4 > 0)
		printf("%.1lf ", (double)a4 / count_a4);
	else
		printf("N ");

	if (count_a5 > 0)
		printf("%d", a5);
	else
		printf("N");

	return 0;
}