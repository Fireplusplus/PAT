#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int is_prime(int n)
{
	int i = 0;
	assert(n >= 2);
	for (i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;	//ÊÇËØÊý
}

int main()
{
	int n = 0, count = 0, i = 0, tmp = 1;

	while (scanf("%d", &n) != EOF) {
		for (i = 2; (i <= n); i++) {
			if (is_prime(i)) {
				if (i - tmp == 2)
					count++;
				tmp = i;
			}			
		}
		printf("%d\n", count);
	}

	system("pause");
	return 0;
}
