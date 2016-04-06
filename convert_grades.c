/* 输入一个百分制的成绩t，将其转换成对应的等级，具体转换规则如下：
 * 90~100为A;
 * 80~89为B;
 * 70~79为C;
 * 60~69为D;
 * 0~59为E; 
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
