/*  
 * 现给出一批考生的德才分数，请根据司马光的理论给出录取排名。
 * 输入格式：
 * 输入第1行给出3个正整数，分别为：N（<=105），即考生总数；L（>=60），为录取最低分数线，
 * 即德分和才分均不低于L的考生才有资格被考虑录取；H（<100），
 * 为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；
 * 才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；
 * 德才分均低于H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，
 * 但排在第二类考生之后；其他达到最低线L的考生也按总分排序，但排在第三类考生之后。
 * 随后N行，每行给出一位考生的信息，包括：准考证号、德分、才分，其中准考证号为8位整数，
 * 德才分为区间[0, 100]内的整数。数字间以空格分隔。
 * 输出格式：
 * 输出第1行首先给出达到最低分数线的考生人数M，随后M行，每行按照输入格式输出一位考生的信息，
 * 考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；
 * 若德分也并列，则按准考证号的升序输出。 
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student	//存放学号，德分，才分，成绩等级
{	
	char no[9];		//最低优先级关键字
	int morality;	
	int capability;	//（总分为）次高优先级关键字
	int level;		//最高优先级关键字
}stu, *pstu;
void init_level(pstu stu, int pass, int first)	//初始化level,方便排序
{
	if ((stu->morality >= first) && (stu->capability >= first))
		stu->level = 4;
	else if ((stu->morality >= first) && (stu->capability < first) &&
		(stu->morality >= pass) && (stu->capability >= pass))
		stu->level = 3;
	else if ((stu->morality < first) && (stu->capability < first) &&
		(stu->morality >= stu->capability) && (stu->morality >= pass) && (stu->capability >= pass))
		stu->level = 2;
	else if ((stu->morality >= pass) && (stu->capability >= pass))
		stu->level = 1;
	else
		stu->level = 0;
}

pstu  init(int num, int pass, int first, int *count)
{
	pstu  pret = NULL, ptmp = NULL;

	if (num != 0)
		pret = (pstu)malloc(num * sizeof(stu));
	if (pret == NULL) {
		printf("内存不足！\n");
		return NULL;
	}
	ptmp = pret;
	while (num > 0) {
		scanf("%s", ptmp->no);
		scanf("%d%d", &(ptmp->morality), &(ptmp->capability));
		if ((ptmp->morality >= pass) && (ptmp->capability >= pass))
			++(*count);
		init_level(ptmp, pass, first);
		--num;
		++ptmp;
	}
	return pret;
}

void print(pstu stu_table, int num)
{
	while (num > 0) {
		printf("%s %d %d\n", stu_table->no, stu_table->morality, stu_table->capability);
		--num;
		++stu_table;
	}
}

int compare(pstu stu1, pstu stu2)	//比较大小,stu1>stu2,返回1，否则返回-1
{									//学号唯一，所以不存在相等
	if (stu1->level > stu2->level)
		return -1;
	else if (stu1->level < stu2->level)
		return 1;
	else {
		if ((stu1->morality + stu1->capability) > (stu2->morality + stu2->capability))
			return -1;
		else if ((stu1->morality + stu1->capability) < (stu2->morality + stu2->capability))
			return 1;
		else {
			if (stu1->morality > stu2->morality)
				return -1;
			else if (stu1->morality < stu2->morality)
				return 1;
			else {
				if (stu1->capability > stu2->capability)
					return -1;
				else if (stu1->capability < stu2->capability)
					return 1;
				else {
					if (strcmp(stu1->no, stu2->no))	//学号降序
						return 1;
					else
						return -1;
				}			
			}
		}
	}
}
int main()
{
	int num = 0, pass = 0, first = 0;
	pstu stu_table= NULL;
	int count = 0;

	scanf("%d%d%d", &num, &pass, &first);
	stu_table = init(num, pass, first, &count);
	qsort(stu_table, num, sizeof(stu), compare);
	printf("%d\n", count);
	print(stu_table, count);

	system("pause");
	return 0;
}