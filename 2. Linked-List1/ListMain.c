#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"
#include "NameCard.h"

int main(void)
{
	List list;
	NameCard* nCard;
	char cmName[10];
	char pNum[15];
	ListInit(&list);

	/*** 3���� ������ ���� ***/
	nCard = MakeNameCard("���ǿ�", "01099605105");
	LInsert(&list, nCard);

	nCard = MakeNameCard("�����", "01040674239");
	LInsert(&list, nCard);

	nCard = MakeNameCard("��Ͼ�", "01020190531");
	LInsert(&list, nCard);

	/*** ����� �������� ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));

	// Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ������ ��� //
	


	printf("�˻��Ͻ� �ι��� �̸��� �Է��ϼ��� : ");
	scanf("%s", cmName);

	if (LFirst(&list, &nCard))
	{
		if (NameCompare(nCard, cmName) == 0)
			ShowNameCardInfo(nCard);

		while (LNext(&list, &nCard))
		{
			if (NameCompare(nCard, cmName) == 0)
				ShowNameCardInfo(nCard);
		}
	}

	printf("��ȭ��ȣ ������ �����Ͻ� �ι��� �̸��� �Է��ϼ��� : ");
	scanf("%s", cmName);
	printf("�����Ͻ� ��ȣ�� �Է��ϼ��� : ");
	scanf("%s", pNum);
	
	if (LFirst(&list, &nCard))
	{
		if (NameCompare(nCard, cmName) == 0)
		{
			changePhoneNum(nCard, pNum);
			printf("���� �Ϸ�!\n");
		}
		while (LNext(&list, &nCard))
		{
			if (NameCompare(nCard, cmName) == 0)
			{
				changePhoneNum(nCard, pNum);
				printf("���� �Ϸ�!\n");
			}
		}
	}

	printf("������ �����Ͻ� �ι��� �̸��� �Է��ϼ��� : ");
	scanf("%s", cmName);

	if (LFirst(&list, &nCard))
	{
		if (NameCompare(nCard, cmName) == 0)
		{
			nCard = LRemove(&list);
			free(nCard);
		}

		while (LNext(&list, &nCard))
		{
			if (NameCompare(nCard, cmName) == 0)
			{
				nCard = LRemove(&list);
				free(nCard);
			}
		}
	}
	/*** ���� �� ���� ������ ��ü ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));

	if (LFirst(&list, &nCard))
	{
		ShowNameCardInfo(nCard);

		while (LNext(&list, &nCard))
			ShowNameCardInfo(nCard);
	}
	printf("\n");

	return 0;
}