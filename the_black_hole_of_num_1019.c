/* 
 * ������һ����λ���ֲ���ȫ��ͬ��4λ����������������Ȱ�4�����ְ��ǵ��������ٰ��ǵݼ�����
 * Ȼ���õ�1�����ּ���2�����֣����õ�һ���µ����֡�һֱ�ظ���������
 * ���Ǻܿ��ͣ���С����ֺڶ���֮�Ƶ�6174��������������Ҳ��Kaprekar������
 * ���磬���Ǵ�6767��ʼ�����õ�
 * 7766 - 6677 = 1089
 * 9810 - 0189 = 9621
 * 9621 - 1269 = 8352
 * 8532 - 2358 = 6174
 * 7641 - 1467 = 6174
 * ... ...
 * �ָ�������4λ�����������д������ʾ����ڶ��Ĺ��̡�
 * �����ʽ��
 * �������һ��(0, 10000)�����ڵ�������N��
 * �����ʽ��
 * ���N��4λ����ȫ��ȣ�����һ���������N - N = 0000�������򽫼����ÿһ����һ���������
 * ֱ��6174��Ϊ����֣������ʽ��������ע��ÿ�����ְ�4λ����ʽ����� 
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