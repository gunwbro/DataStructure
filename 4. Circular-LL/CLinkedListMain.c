#include <stdio.h>
#include "CLinkedList.h"

void SearchEmp(char* name, int num, List* list)
{
	Employee* emp = (Employee*)malloc(sizeof(Employee));
	if (LFirst(list, &emp))
	{
		if (strcmp(emp->name, name) == 0)
		{
			for (int i = 0; i < num; i++)
			{
				LNext(list, &emp);
			}
			printf("---%s ���� %d �� �� ������---\n", name, num);
			printf("�̸� : %s , ��� : %s \n", emp->name, emp->number);
			return;
		}
		while (LNext(list, &emp))
		{
			if (strcmp(emp->name, name) == 0)
			{
				for (int i = 0; i < num; i++)
				{
					LNext(list, &emp);
				}
				printf("---%s ���� %d �� �� ������---\n", name, num);
				printf("�̸� : %s , ��� : %s \n", emp->name, emp->number);
				return;
			}
			if (list->cur == list->tail)
			{
				printf("���� ����");
				return;
			}
		}
	}
	else
	{
		printf("���� ����");
		return;
	}
}

int main(void)
{
	List list;
	Employee* nEmp;
	ListInit(&list);

	nEmp = MakeEmployee("5105", "���ǿ�");
	LInsert(&list, nEmp);
	nEmp = MakeEmployee("4239", "�����");
	LInsert(&list, nEmp);
	nEmp = MakeEmployee("5115", "������");
	LInsert(&list, nEmp);
	nEmp = MakeEmployee("5145", "������");
	LInsert(&list, nEmp);

	SearchEmp("���ſ�", 7, &list);

	return 0;
}