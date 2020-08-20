#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphKruskal.h"
#include "ArrayBaseStack.h"
#include "DLinkedList.h"

int WhoIsPrecede(int data1, int data2);
int PQWeightComp(Edge d1, Edge d2);
void RemoveEdge(ALGraph* pg, int fromV, int toV); // ������ �Ҹ�
void RemoveWayEdge(ALGraph* pg, int fromV, int toV);	// ���� ������ ���� �Ҹ�
void RecoverEdge(ALGraph* pg, int fromV, int toV, int weight);
// ���ڷ� ���޵� �� ������ ����Ǿ� �ִٸ� TRUE, �׷��� �ʴٸ� FALSE ��ȯ
int IsConnVertex(ALGraph* pg, int v1, int v2);

// �׷����� �ʱ�ȭ
void GraphInit(ALGraph* pg, int nv)
{
	int i;

	pg->adjList = (List*)malloc(sizeof(List) * nv);
	pg->numV = nv;
	pg->numE = 0;	// �ʱ��� ���� ���� 0��
	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);

	for (i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}

	// �켱���� ť�� �ʱ�ȭ
	PQueueInit(&(pg->pqueue), PQWeightComp);
}

// �׷��� ���ҽ��� ����
void GraphDestroy(ALGraph* pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList);

	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}

// ������ �߰�
void AddEdge(ALGraph* pg, int fromV, int toV, int weight)
{
	Edge edge = { fromV, toV, weight }; // ������ ����ġ ������ ����
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;

	// ������ ����ġ ������ �켱���� ť�� ����
	PEnqueue(&(pg->pqueue), edge);
}

// ������ ���� ���
void ShowGraphEdgeInfo(ALGraph* pg)
{
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++)
	{
		printf("%c�� ����� ����: ", i + 65);

		if (LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 65);

			while (LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

int WhoIsPrecede(int data1, int data2)
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}

int PQWeightComp(Edge d1, Edge d2)
{
	return d1.weight - d2.weight;
}

int VisitVertex(ALGraph* pg, int visitV)
{
	if (pg->visitInfo[visitV] == 0)
	{
		pg->visitInfo[visitV] = 1;
		//printf("%c ", visitV + 65);
		return TRUE;
	}
	return FALSE;
}

void DFShowGraphVertex(ALGraph* pg, int startV)
{
	Stack stack;
	int visitV = startV;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE)
		{
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if (VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE)
		{
			if (SIsEmpty(&stack) == TRUE)
				break;
			else
				visitV = SPop(&stack);
		}
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void ShowGraphEdgeWeightInfo(ALGraph* pg)
{
	PQueue copyPQ = pg->pqueue;
	Edge edge;

	while (!PQIsEmpty(&copyPQ))
	{
		edge = PDequeue(&copyPQ);
		printf("(%c-%c), w:%d \n", edge.v1 + 65, edge.v2 + 65, edge.weight);
	}
}

void ConKruskalMST(ALGraph* pg)	// ũ�罺Į �˰��� ��� MST�� ����
{
	Edge recvEdge[20];	// ������ ������ ���� ����
	Edge edge;
	int eidx = 0;
	int i;

	// MST�� ������ ������ �Ʒ��� while���� �ݺ�
	while (pg->numE + 1 > pg->numV)	// MST ������ �� + 1 == ������ ��
	{
		edge = PDequeue(&(pg->pqueue));
		RemoveEdge(pg, edge.v1, edge.v2);

		if (!IsConnVertex(pg, edge.v1, edge.v2))
		{
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);
			recvEdge[eidx++] = edge;
		}
	}

	// �켱���� ť���� ������ ������ ������ ȸ��
	for (i = 0; i < eidx; i++)
		PEnqueue(&(pg->pqueue), recvEdge[i]);
}

void RemoveEdge(ALGraph* pg, int fromV, int toV)	// ������ �Ҹ�
{
	RemoveWayEdge(pg, fromV, toV);
	RemoveWayEdge(pg, toV, fromV);
	(pg->numE)--;
}

void RemoveWayEdge(ALGraph* pg, int fromV, int toV)		// ���� ������ ���� �Ҹ�
{
	int edge;

	if (LFirst(&(pg->adjList[fromV]), &edge))
	{
		if (edge == toV) {
			LRemove(&(pg->adjList[fromV]));
			return;
		}

		while (LNext(&(pg->adjList[fromV]), &edge))
		{
			if (edge == toV) {
				LRemove(&(pg->adjList[fromV]));
				return;
			}
		}
	}
}

void RecoverEdge(ALGraph* pg, int fromV, int toV, int weight)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	(pg->numE)++;
}

int IsConnVertex(ALGraph* pg, int v1, int v2)
{
	Stack stack;
	int visitV = v1;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		int visitFlag = FALSE;

		// ������ ���ƴٴϴ� ���߿� ��ǥ�� ã�´ٸ� TRUE �� ��ȯ�Ѵ�.
		if (nextV == v2) {
			// �Լ��� ��ȯ�ϱ� ���� �ʱ�ȭ�� �����Ѵ�.
			memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
			return TRUE;
		}

		if (VisitVertex(pg, nextV) == TRUE)
		{
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				// ������ ���ƴٴϴ� ���߿� ��ǥ�� ã�´ٸ� TRUE�� ��ȯ�Ѵ�.
				if (nextV == v2) {
					// �Լ��� ��ȯ�ϱ� ���� �ʱ�ȭ�� �����Ѵ�.
					memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
					return TRUE;	// ��ǥ�� ã������ TRUE�� ��ȯ!
				}
				
				if (VisitVertex(pg, nextV) == TRUE) {
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE)
		{
			if (SIsEmpty(&stack) == TRUE)
				break;
			else
				visitV = SPop(&stack);
		}
	}
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	return FALSE;	// ������� �Դٴ� ���� ��ǥ�� ã�� ���ߴٴ� ��!
}