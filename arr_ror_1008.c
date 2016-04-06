#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	n = 0, m = 0, i = 0, j = 0;
	int arr[100] = {0};
	int tmp = 0;


	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (i = 0; i < m; i++) {
		tmp = arr[n - 1];
		for (j = 0; j < n - 1; j++)
			arr[n - 1 - j] = arr[n - 2 - j];
		arr[0] = tmp;
	}
	for (i = 0; i < n; i++) {
		printf("%d", arr[i]);
		if (i != n - 1)
			printf(" ");	
	}
		
	system("pause");
	return 0;
}
