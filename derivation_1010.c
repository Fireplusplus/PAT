/* 设计函数求一元多项式的导数。（注：xn（n为整数）的一阶导数为n*xn-1。） */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void derivation(int coe, int index, int * d_coe, int * d_index)
{
	*d_coe = coe * index;
	*d_index = index - 1;
}

int main()
{
	int coe, index = 0;
	int d_coe = 0, d_index = 0;
	while (scanf("%d%d", &coe, &index) != EOF)
	{	
		if (d_coe != 0 && d_index != 0)
			printf(" ");
		derivation(coe, index, &d_coe, &d_index);
		if (d_coe != 0)
			printf("%d %d", d_coe, d_index);
	}

	system("pause");
	return 0;
}