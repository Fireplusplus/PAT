#define _CRT_SECURE_NO_WARNINGS
/* 
 * ����̽����Ħ˹�ӵ�һ����ֵ�������������Լ��ɣ� 
 * 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm����
 * ����̽�ܿ�������ˣ���������ֵ�����ʵ���Ͼ���Լ���ʱ�䡰������ 14:04����
 * ��Ϊǰ�����ַ����е�1����ͬ�Ĵ�дӢ����ĸ����Сд�����֣��ǵ�4����ĸ'D'��
 * ���������ģ���2����ͬ���ַ���'E'�����ǵ�5��Ӣ����ĸ��
 * ����һ����ĵ�14����ͷ������һ���0�㵽23��������0��9���Լ���д��ĸA��N��ʾ����
 * �������ַ�����1����ͬ��Ӣ����ĸ's'�����ڵ�4��λ�ã���0��ʼ�������ϣ������4���ӡ�
 * �ָ��������ַ��������������Ħ˹����õ�Լ���ʱ�䡣
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char arr1[60] = { 0 }, arr2[60] = { 0 }, arr3[60] = { 0 }, arr4[60] = { 0 };

void decode(char *weekday, int *hour, int *minute, int len_1, int len_2, int len_3, int len_4)
{
	int i = 0, j = 0, count = 0;
	int min = 0;

	for (i = 0; i < len_1; i++) {
		if ((arr1[i] >= 'A') && (arr1[i] <= 'Z')) {
			for (j = 0; j < len_2; j++) {
				if (arr1[i] == arr2[j]) {
					weekday[count++] = arr2[j];
					break;
				}	
			}
		}
	}
	min = len_3 > len_4 ? len_4 : len_3;
	for (i = 0; i < min; i++) {
		if ((arr3[i] == arr4[i]) && (arr3[i] >= 'a') && (arr3[i] <= 'z'))
			break;
	}
	minute[1] = i % 10;
	i /= 10;
	minute[0] = i;

	if (weekday[1] >= 'A' && weekday[1] <= 'N')
		weekday[1] -= 55;
	hour[1] = weekday[1] % 10;
	weekday[1] /= 10;
	hour[0] = weekday[1];
	//MON��ʾ����һ��TUE��ʾ���ڶ���WED��ʾ��������THU��ʾ�����ģ�
	//FRI��ʾ�����壬SAT��ʾ��������SUN��ʾ������
	switch (weekday[0]) {
	case 'A':
		strcpy(weekday, "MON");
		break;
	case 'B':
		strcpy(weekday, "TUE");
		break;
	case 'C':
		strcpy(weekday, "WED");
		break;
	case 'D':
		strcpy(weekday, "THU");
		break;
	case 'E':
		strcpy(weekday, "FRI");
		break;
	case 'F':
		strcpy(weekday, "SAT");
		break;
	case 'G':
		strcpy(weekday, "SUN");
		break;
	default:
		break;
	}
}

int main()
{
	char weekday[4] = {0};
	int hour[2] = { 0 }, minute[2] = { 0 };
	int len_1, len_2, len_3, len_4;
	scanf("%s%s%s%s", arr1, arr2, arr3, arr4);
	/*scanf("%s", arr2);
	scanf("%s", arr3);
	scanf("%s", arr4);*/
	len_1 = strlen(arr1);
	len_2 = strlen(arr2);
	len_3 = strlen(arr3);
	len_4 = strlen(arr4);
	decode(weekday, hour, minute, len_1, len_2, len_3, len_4);

	printf("%s %d%d:%d%d", weekday, hour[0], hour[1], minute[0], minute[1]);

	system("pause");
	return 0;
}