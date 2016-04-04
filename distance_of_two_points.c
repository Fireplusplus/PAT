#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
	int x1, y1, x2, y2;
	double rs;
	while (scanf("%d", &x1) != EOF) {
		scanf("%d%d%d", &y1, &x2, &y2);
		rs = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
		printf("%.2f\n", rs);
	}

	return 0;
}