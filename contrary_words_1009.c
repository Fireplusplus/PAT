/* ����һ��Ӣ�Ҫ�����д���򣬽��������е��ʵ�˳��ߵ���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define N 81

int main()
{
	char words[N] = {0};
	int i = 0, j = 0;

	while ((words[i++] = getchar()) != '\n')
		;
	words[i - 1] = 0;
	for (i = i - 2; i >= 0; i--) {

		if (i == 0 || words[i - 1] == ' ') {
			if(i != 0)
				words[i - 1] = 0;
			j = i;
			while (words[j] != 0) {
				printf("%c", words[j++]);
			}
			if (i != 0)
				printf(" ");
		}
	}


	return 0;
}