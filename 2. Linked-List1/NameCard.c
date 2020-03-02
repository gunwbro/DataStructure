#define _CRT_SECURE_NO_WARNINGS
#include "NameCard.h"
#include <stdio.h>
#include <string.h>

NameCard* MakeNameCard(char* name, char* phone)
{
	NameCard* nCard = (NameCard*)malloc(sizeof(NameCard));
	strcpy(nCard->name, name);
	strcpy(nCard->phone, phone);

	return nCard;
}

void ShowNameCardInfo(NameCard* pcard)
{
	printf("name : %s\n", pcard->name);
	printf("phone : %s\n", pcard->phone);
}

int NameCompare(NameCard* pcard, char* name)
{
	return strcmp(pcard->name, name);
}

void changePhoneNum(NameCard* pcard, char* phone)
{
	strcpy(pcard->phone, phone);
}