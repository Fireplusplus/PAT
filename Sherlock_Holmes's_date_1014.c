#define _CRT_SECURE_NO_WARNINGS
/* 
 * 大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 
 * 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。
 * 大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，
 * 因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，
 * 代表星期四；第2对相同的字符是'E'，那是第5个英文字母，
 * 代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；
 * 后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。
 * 现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。
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
	//MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，
	//FRI表示星期五，SAT表示星期六，SUN表示星期日
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