#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 0, i = 0, max = 0, min = 0;
	char name[10][11] = { 0 }, no[10][11] = { 0 };
	int grade[10] = { 0 };

	scanf("%d", &n);
	for (i = 0; i < n; i++) {

		scanf("%s", name[i]);
		scanf("%s", no[i]);
		scanf("%d", &grade[i]);
	}

	for (i = 1; i < n; i++) {
		if (grade[max] < grade[i])
			max = i;
		if (grade[min] > grade[i])
			min = i;
	}
	printf("%s %s\n", name[max], no[max]);
	printf("%s %s\n", name[min], no[min]);

	system("pause");
	return 0;
}