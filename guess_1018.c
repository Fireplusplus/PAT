/*
 * �ָ������˵Ľ����¼����ͳ��˫����ʤ��ƽ�������������Ҹ���˫���ֱ��ʲô���Ƶ�ʤ�����
 * �����ʽ��
 * �����1�и���������N��<=105������˫������Ĵ��������N�У�ÿ�и���һ�ν������Ϣ��
 * ���ס���˫��ͬʱ�����ĵ����ơ�C�������ӡ���J������������B������������1����ĸ����׷�����2�������ҷ����м���1���ո�
 * �����ʽ��
 * �����1��2�зֱ�����ס��ҵ�ʤ��ƽ�������������ּ���1���ո�ָ���
 * ��3�и���������ĸ���ֱ����ס��һ�ʤ�����������ƣ��м���1���ո�
 * ����ⲻΨһ�����������ĸ����С�Ľ�
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