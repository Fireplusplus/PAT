/*
 * 现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。
 * 输入格式：
 * 输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，
 * 即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。
 * 输出格式：
 * 输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。
 * 第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。
 * 如果解不唯一，则输出按字母序最小的解
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int b1 = 0, c1 = 0, j1 = 0;
int b2 = 0, c2 = 0, j2 = 0;

int compare(char a, char b)
{
	if ((a == 'B') && (b == 'J'))
	{
		++j2;
		return -1;	
	}
	if ((a == 'J') && (b == 'B'))
	{
		++j1;
		return 1;
	}
	else if (a < b)
	{
		if (a == 'B')
			++b1;
		else if (a == 'J')
			++j1;
		else
			++c1;
		return 1;
	}
	else if (a > b)
	{
		if (b == 'B')
			++b2;
		else if (b == 'J')
			++j2;
		else
			++c2;
		return -1;
	}
	else
		return 0;
}

int main()
{
	int num = 0;
	char a = 0, b = 0;
	int cnt_a = 0, cnt_b = 0;
	int ret = 0;
	int max1 = 0, max2 = 0;

	scanf("%d", &num);
	while (num != 0)
	{	
		--num;
		getchar();
		scanf("%c %c", &a, &b);
		ret = compare(a, b);
		if (ret == 1)
			++cnt_a;
		else if (ret == -1)
			++cnt_b;
	}
	printf("%d %d %d\n", cnt_a, 10 - cnt_a - cnt_b, cnt_b);
	printf("%d %d %d\n", cnt_b, 10 - cnt_a - cnt_b, cnt_a);

	max1 = b1 > c1 ? b1 : c1;
	max1 = max1 > j1 ? max1 : j1;

	max2 = b1 > c1 ? b1 : c1;
	max2 = max1 > j1 ? max1 : j1;

	if (max1 == b1)
		printf("B ");
	else if (max1 == c1)
		printf("C ");
	else
		printf("J ");

	if (max2 == b2)
		printf("B");
	else if (max2 == c2)
		printf("C");
	else
		printf("J");

	system("pause");
	return 0;
}