/* 
 * 给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，
 * 然后用第1个数字减第2个数字，将得到一个新的数字。一直重复这样做，
 * 我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。
 * 例如，我们从6767开始，将得到
 * 7766 - 6677 = 1089
 * 9810 - 0189 = 9621
 * 9621 - 1269 = 8352
 * 8532 - 2358 = 6174
 * 7641 - 1467 = 6174
 * ... ...
 * 现给定任意4位正整数，请编写程序演示到达黑洞的过程。
 * 输入格式：
 * 输入给出一个(0, 10000)区间内的正整数N。
 * 输出格式：
 * 如果N的4位数字全相等，则在一行内输出“N - N = 0000”；否则将计算的每一步在一行内输出，
 * 直到6174作为差出现，输出格式见样例。注意每个数字按4位数格式输出。 
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_same(int n, int *down, int *up)
{
	int i = 0;
	int tmp[4] = {0};
	int j = 0, k = 0;

	for (i = 0; i < 4; i++)
	{
		tmp[i] = n % 10;
		n /= 10;
	}
	if ((tmp[0] == tmp[1] && tmp[1] == tmp[2] && tmp[2] == tmp[3]) != 1) {
		for (i = 1; i < 4; i++) {
			for (j = 1; j < 4; j++) {
				if (tmp[j - 1] > tmp[j]) {
					k = tmp[j];
					tmp[j] = tmp[j - 1];
					tmp[j - 1] = k;
				}
			}
		}
		for (i = 0; i < 4; i++) {
			*up += tmp[i] * pow(10, 3 - i);
			*down += tmp[3 - i] * pow(10, 3 - i);
		}
		return 0;
	}
	else
		return 1;
}

int main()
{
	int n = 0;
	int down = 0, up = 0;

	scanf("%d", &n);
	if (n == 6174) {
		is_same(n, &down, &up);
		n = down - up;
		printf("%04d - %04d = %04d\n", down, up, n);
		return 0;
	}
	while (n != 6174) {
		if (!is_same(n, &down, &up)) {
			n = down - up;
			printf("%04d - %04d = %04d\n", down, up, n);
			down = 0;
			up = 0;
		}
		else {
			printf("%d - %d = 0000", n, n);
			break;
		}
	}
	
	system("pause");
	return 0;
}