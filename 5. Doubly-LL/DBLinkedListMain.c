#include <stdio.h>
#include "DBLinkedList.h"

int main(void)
{
	// ����� ���� ����Ʈ�� ���� �� �ʱ�ȭ ///////
	List list;
	int data;
	ListInit(&list);

	// 8���� ������ ���� ///////
	LInsert(&list, 1); LInsert(&list, 2);
	LInsert(&list, 3); LInsert(&list, 4);
	LInsert(&list, 5); LInsert(&list, 6);
	LInsert(&list, 7); LInsert(&list, 8);

	// ����� �������� ��ȸ ///////
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		// ������ ���� �̵��ϸ� ������ ��ȸ
		while (LNext(&list, &data))
			printf("%d ", data);

		printf("\n\n");
	}

	// 2�� ��� ���� ���� ///////
	if (LFirst(&list, &data))
	{
		if (data % 2 == 0)
			LRemove(&list);
		while (LNext(&list, &data))
		{
			if (data % 2 == 0)
				LRemove(&list);
		}
	}

	// ����� �������� �� ��ȸ ///////
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		// ������ ���� �̵��ϸ� ������ ��ȸ
		while (LNext(&list, &data))
			printf("%d ", data);

		printf("\n\n");
	}

	return 0;
}