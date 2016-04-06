#define _CRT_SECURE_NO_WARNINGS
/* 令Pi表示第i个素数。现任给两个正整数M <= N <= 10000，请输出PM到PN的所有素数 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n)
{
	int i = 0;

	for (i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}
void print(int m, int n)
{
	int i = 0;
	int count_line = 0, count_prime = 0;
	for (i = 2; ; i++) {
		if ((is_prime(i) == 1) && ((++count_prime) >= m) && (count_prime <= n)) {
			printf("%d", i);
			if ((++count_line != 10) && (count_prime != n)) {
				printf(" ");
			}
			else {
				printf("\n");
				count_line = 0;
			}
		}
		if (count_prime == n)
			return;
	}

}

int main()
{
	int m = 0, n = 0;

	scanf("%d%d", &m, &n);
	print(m, n);

	system("pause");
	return 0;
}