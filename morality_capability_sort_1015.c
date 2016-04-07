/*  
 * �ָ���һ�������ĵ²ŷ����������˾�������۸���¼ȡ������
 * �����ʽ��
 * �����1�и���3�����������ֱ�Ϊ��N��<=105����������������L��>=60����Ϊ¼ȡ��ͷ����ߣ�
 * ���·ֺͲŷ־�������L�Ŀ��������ʸ񱻿���¼ȡ��H��<100����
 * Ϊ����¼ȡ�ߡ����·ֺͲŷ־������ڴ��ߵı�����Ϊ���ŵ�ȫ���������࿼�����²��ִܷӸߵ�������
 * �ŷֲ������·ֵ��ߵ�һ�࿼�����ڡ���ʤ�š���Ҳ���ܷ����򣬵����ڵ�һ�࿼��֮��
 * �²ŷ־�����H�����ǵ·ֲ����ڲŷֵĿ������ڡ��ŵ¼����������С���ʤ�š��ߣ����ܷ�����
 * �����ڵڶ��࿼��֮�������ﵽ�����L�Ŀ���Ҳ���ܷ����򣬵����ڵ����࿼��֮��
 * ���N�У�ÿ�и���һλ��������Ϣ��������׼��֤�š��·֡��ŷ֣�����׼��֤��Ϊ8λ������
 * �²ŷ�Ϊ����[0, 100]�ڵ����������ּ��Կո�ָ���
 * �����ʽ��
 * �����1�����ȸ����ﵽ��ͷ����ߵĿ�������M�����M�У�ÿ�а��������ʽ���һλ��������Ϣ��
 * ������������˵���Ĺ���Ӹߵ������򡣵�ĳ�࿼�����ж����ܷ���ͬʱ������·ֽ������У�
 * ���·�Ҳ���У���׼��֤�ŵ���������� 
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student	//���ѧ�ţ��·֣��ŷ֣��ɼ��ȼ�
{	
	char no[9];		//������ȼ��ؼ���
	int morality;	
	int capability;	//���ܷ�Ϊ���θ����ȼ��ؼ���
	int level;		//������ȼ��ؼ���
}stu, *pstu;
void init_level(pstu stu, int pass, int first)	//��ʼ��level,��������
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
		printf("�ڴ治�㣡\n");
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

int compare(pstu stu1, pstu stu2)	//�Ƚϴ�С,stu1>stu2,����1�����򷵻�-1
{									//ѧ��Ψһ�����Բ��������
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
					if (strcmp(stu1->no, stu2->no))	//ѧ�Ž���
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