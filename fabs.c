/* 求实数的绝对值 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M 0.00000001

int my_abs(const int  x)
{
	return x > 0 ? x : -x;
}
double my_fabs( double  x)
{
	return x > M ? x : -x;
}

int main(void)
{
	double b = 0.0;

	while (scanf("%lf", &b) != EOF) {
		printf("%.2lf\n", my_fabs(b));
	}

	system("pause");
	return	0;
}
//int a = 0;
//double b = 0.0;
//scanf("%lf", &b);
//printf("%lf", b);
//printf("%.2f\n", my_fabs(b));