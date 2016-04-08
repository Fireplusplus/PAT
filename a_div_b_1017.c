/*  
 * 本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。
 * 你需要输出商数Q和余数R，使得A = B * Q + R成立。
 * 输入格式：
 * 输入在1行中依次给出A和B，中间以1空格分隔。
 * 输出格式：
 * 在1行中依次输出Q和R，中间以1空格分隔 
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000

int main()
{
	char a[N] = {0};
	int b = 0;
	int len = 0, i = 0;
	int flag = 0, tmp = 0;
	scanf("%s%d", a, &b);
	len = strlen(a);
	for (i = 0; i < len; i++)
	{	
		tmp = tmp * 10 + a[i] - 48;
		if (tmp >= b)
		{
			printf("%d", tmp / b);
			flag = 1;
		}
		else if (flag)
			printf("0");
		else if (1 == len) 
		{
			printf("%d %d", tmp / b, tmp % b);
			return 0;
		}
		tmp %= b;
	}
	printf(" %d", tmp);
	system("pause");
	return 0;
}