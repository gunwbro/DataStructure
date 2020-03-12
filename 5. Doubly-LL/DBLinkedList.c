#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));

	plist->head->next = plist->tail;
	plist->head->prev = NULL;

	plist->tail->next = NULL;
	plist->tail->prev = plist->head;

	plist->numOfData = 0;
}

void LInsert(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->tail;
	newNode->prev = plist->tail->prev;
	
	newNode->prev->next = newNode;
	plist->tail->prev = newNode;

	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata)
{
	if (plist->head->next == plist->tail)
		return FALSE;

	plist->cur = plist->head->next;
	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List* plist, Data* pdata)
{
	if (plist->cur->next == plist->tail)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

Data LRemove(List* plist)
{
	Node* delNode = plist->cur;
	Data delData = plist->cur->data;

	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;
	plist->cur = plist->cur->prev;

	free(delNode);
	(plist->numOfData)--;
	return delData;
}

int LCount(List* plist)
{
	return plist->numOfData;
}