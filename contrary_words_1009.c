/* 给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出 */
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