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
			printf("---%s 님의 %d 일 후 당직자---\n", name, num);
			printf("이름 : %s , 사번 : %s \n", emp->name, emp->number);
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
				printf("---%s 님의 %d 일 후 당직자---\n", name, num);
				printf("이름 : %s , 사번 : %s \n", emp->name, emp->number);
				return;
			}
			if (list->cur == list->tail)
			{
				printf("정보 없음");
				return;
			}
		}
	}
	else
	{
		printf("정보 없음");
		return;
	}
}

int main(void)
{
	List list;
	Employee* nEmp;
	ListInit(&list);

	nEmp = MakeEmployee("5105", "조건우");
	LInsert(&list, nEmp);
	nEmp = MakeEmployee("4239", "장소희");
	LInsert(&list, nEmp);
	nEmp = MakeEmployee("5115", "조연우");
	LInsert(&list, nEmp);
	nEmp = MakeEmployee("5145", "조병우");
	LInsert(&list, nEmp);

	SearchEmp("조신우", 7, &list);

	return 0;
}