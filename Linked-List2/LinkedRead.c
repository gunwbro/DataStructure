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
//	Node* head = NULL;    // NULL ������ �ʱ�ȭ
//	Node* tail = NULL;
//	Node* cur = NULL;
//
//	Node* newNode = NULL;
//	int readData;
//
//	head = (Node*)malloc(sizeof(Node));
//	tail = head;
//	/**** �����͸� �Է� �޴� ���� ****/
//	while (1)
//	{
//		printf("�ڿ��� �Է�: ");
//		scanf("%d", &readData);
//		if (readData < 1)
//			break;
//
//		/*** ����� �߰����� ***/
//		newNode = (Node*)malloc(sizeof(Node));
//		newNode->data = readData;
//		newNode->next = NULL;
//
//		tail->next = newNode;
//		tail = newNode;
//	}
//	printf("\n");
//
//	/**** �Է� ���� �������� ��°��� ****/
//	printf("�Է� ���� �������� ��ü���! \n");
//	if (head->next == NULL)
//	{
//		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
//	}
//	else
//	{
//		cur = head->next;
//
//		while (cur != NULL)    // �� ��° ������ ������ ���
//		{
//			printf("%d  ", cur->data);
//			cur = cur->next;
//		}
//	}
//	printf("\n\n");
//
//	/**** �޸��� �������� ****/
//	if (head->next == NULL)
//	{
//		return 0;    // ������ ��尡 �������� �ʴ´�.
//	}
//	else
//	{
//		Node* delNode = head->next;
//		Node* delNextNode = delNode->next;
//
//		while (delNode != NULL)
//		{
//			printf("%d��(��) �����մϴ�. \n", delNode->data);
//			free(delNode);
//			delNode = delNextNode;
//			delNextNode = delNextNode->next;
//		}
//	}
//
//	return 0;
//}