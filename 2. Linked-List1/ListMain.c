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

	/*** 3개의 데이터 저장 ***/
	nCard = MakeNameCard("조건우", "01099605105");
	LInsert(&list, nCard);

	nCard = MakeNameCard("장소희", "01040674239");
	LInsert(&list, nCard);

	nCard = MakeNameCard("찌겅쓰", "01020190531");
	LInsert(&list, nCard);

	/*** 저장된 데이터의 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));

	// 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 출력 //
	


	printf("검색하실 인물의 이름을 입력하세요 : ");
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

	printf("전화번호 정보를 변경하실 인물의 이름을 입력하세요 : ");
	scanf("%s", cmName);
	printf("변경하실 번호를 입력하세요 : ");
	scanf("%s", pNum);
	
	if (LFirst(&list, &nCard))
	{
		if (NameCompare(nCard, cmName) == 0)
		{
			changePhoneNum(nCard, pNum);
			printf("변경 완료!\n");
		}
		while (LNext(&list, &nCard))
		{
			if (NameCompare(nCard, cmName) == 0)
			{
				changePhoneNum(nCard, pNum);
				printf("변경 완료!\n");
			}
		}
	}

	printf("정보를 삭제하실 인물의 이름을 입력하세요 : ");
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
	/*** 삭제 후 남은 데이터 전체 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &nCard))
	{
		ShowNameCardInfo(nCard);

		while (LNext(&list, &nCard))
			ShowNameCardInfo(nCard);
	}
	printf("\n");

	return 0;
}