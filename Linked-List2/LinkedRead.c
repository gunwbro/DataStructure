//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct _node
//{
//	int data;
//	struct _node* next;
//} Node;
//
//int main(void)
//{
//	Node* head = NULL;    // NULL 포인터 초기화
//	Node* tail = NULL;
//	Node* cur = NULL;
//
//	Node* newNode = NULL;
//	int readData;
//
//	head = (Node*)malloc(sizeof(Node));
//	tail = head;
//	/**** 데이터를 입력 받는 과정 ****/
//	while (1)
//	{
//		printf("자연수 입력: ");
//		scanf("%d", &readData);
//		if (readData < 1)
//			break;
//
//		/*** 노드의 추가과정 ***/
//		newNode = (Node*)malloc(sizeof(Node));
//		newNode->data = readData;
//		newNode->next = NULL;
//
//		tail->next = newNode;
//		tail = newNode;
//	}
//	printf("\n");
//
//	/**** 입력 받은 데이터의 출력과정 ****/
//	printf("입력 받은 데이터의 전체출력! \n");
//	if (head->next == NULL)
//	{
//		printf("저장된 자연수가 존재하지 않습니다. \n");
//	}
//	else
//	{
//		cur = head->next;
//
//		while (cur != NULL)    // 두 번째 이후의 데이터 출력
//		{
//			printf("%d  ", cur->data);
//			cur = cur->next;
//		}
//	}
//	printf("\n\n");
//
//	/**** 메모리의 해제과정 ****/
//	if (head->next == NULL)
//	{
//		return 0;    // 해제할 노드가 존재하지 않는다.
//	}
//	else
//	{
//		Node* delNode = head->next;
//		Node* delNextNode = delNode->next;
//
//		while (delNode != NULL)
//		{
//			printf("%d을(를) 삭제합니다. \n", delNode->data);
//			free(delNode);
//			delNode = delNextNode;
//			delNextNode = delNextNode->next;
//		}
//	}
//
//	return 0;
//}