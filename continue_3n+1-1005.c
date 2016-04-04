/* 
 * 当我们验证卡拉兹猜想(3n+1)的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。
 * 例如对n=3进行验证的时候，我们需要计算3、5、8、4、2、1，则当我们对n=5、8、4、2进行验证的时候，
 * 就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这4个数已经在验证3的时候遇到过了，
 * 我们称5、8、4、2是被3“覆盖”的数。我们称一个数列中的某个数n为“关键数”，如果n不能被数列中的其他数字所覆盖。
 * 现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。
 * 你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。
 * 你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。
 * 输入格式：每个测试输入包含1个测试用例，第1行给出一个正整数K(<100)，第2行给出K个互不相同的待验证的正整数n(1<n<=100)的值，数字间用空格隔开。
 * 输出格式：每个测试用例的输出占一行，按从大到小的顺序输出关键数字。
 * 数字间用1个空格隔开，但一行中最后一个数字后没有空格。
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int arr[10][20] = {0};
int i_arr = 0;
int rs[10] = { 0 };
int i_rs = 0;

void record(int data, int i)
{
	int count = 0;
	for (i_arr = 0; data != 1; i_arr++) {
		if (data % 2 == 0) 
			data /= 2;
		else
			data = (3 * data + 1) / 2;
		count++;
		arr[i][i_arr+1] = data;	//将覆盖的数存到对应行的位置
	}
	arr[i][0] = count;		//记录该数覆盖值的个数
}

void judge(int n, int number)	//判断number是否被覆盖
{
	int i = 0, j= 0;
	for (i = 0; i < n; i++) {
		for (j = 1; (i != j) && (j < arr[i][0]); j++) {
			if (number == arr[i][j])
				return;
		}
	}
	rs[i_rs] = number;
	i_rs++;
}
void sort()
{
	int i = 0, j = 0;
	int tmp;
	for (i = 1; i < i_rs; i++) {
		for (j = 1; j < i_rs; j++) {
			if (rs[j - 1] < rs[j]) {
				tmp = rs[j - 1];
				rs[j - 1] = rs[j];
				rs[j] = tmp;
			}
		}
	}
}
int main(void)
{
	int n = 0, i = 0;
	int data[10] = { 0 };

	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++) {
			scanf("%d", &data[i]);
			record(data[i], i);
		}
		for (i = 0; i < n; i++) {
			judge(n, data[i]);
		}
		sort();
		for (i = 0; i < i_rs; i++) {
			printf("%d", rs[i]);
			if (i != i_rs - 1)
				printf("\n");
		}

		//重新初始化
		i_arr = 0;
		i_rs = 0;
	}
	
	system("pause");
	return 0;
}