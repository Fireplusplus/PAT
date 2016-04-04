/* 根据输入的半径值，计算球的体积 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	double r = 0;

	while (scanf("%lf", &r) != EOF) {
		printf("%.3lf\n", 4.0/3*3.14*r*r*r);
	}

	return 0;
}