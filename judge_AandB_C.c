/* ��������[-231, 231]�ڵ�3������A��B��C�����ж�A+B�Ƿ����C */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int judge(double a, double b, double c)
{
	return ((a - b) / 2 + b) > (c / 2);
}

int main()
{
	double a = 0, b = 0, c = 0;
	int n = 0, i = 0;

	scanf("%d", &n);
	for (; n > 0; n--) {
		scanf("%lf%lf%lf", &a, &b, &c);
		if (judge(a, b, c))
			printf("Case #%d: true\n", ++i);
		else
			printf("Case #%d: false\n", ++i);
	}

	return 0;
}