/* ����һ���ٷ��Ƶĳɼ�t������ת���ɶ�Ӧ�ĵȼ�������ת���������£�
 * 90~100ΪA;
 * 80~89ΪB;
 * 70~79ΪC;
 * 60~69ΪD;
 * 0~59ΪE; 
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char judge(int grade)
{
	if (grade < 60 && grade >= 0)
		return 'E';
	if (grade < 70)
		return 'D';
	if (grade < 80)
		return 'C';
	if (grade < 90)
		return 'B';
	if (grade <= 100)
		return 'A';
	return 'F';
}
int main()
{
	int grade = 0;
	char ch;
	while (scanf("%d", &grade) != EOF) {
		if ((ch = judge(grade)) != 'F')
			printf("%c\n", ch);
		else
			printf("Score is error!\n");
	}

	system("pause");
	return 0;
}