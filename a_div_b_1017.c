/*  
 * ����Ҫ�����A/B������A�ǲ�����1000λ����������B��1λ��������
 * ����Ҫ�������Q������R��ʹ��A = B * Q + R������
 * �����ʽ��
 * ������1�������θ���A��B���м���1�ո�ָ���
 * �����ʽ��
 * ��1�����������Q��R���м���1�ո�ָ� 
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