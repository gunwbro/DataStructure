#ifndef __AL_GRAPH__
#define __AL_GRAPH__

#include "DLinkedList.h"

// 정점의 이름을 상수화
enum { A, B, C, D, E, F, G, H, I, J };

typedef struct _ual
{
	int numV;
	int numE;
	List* adjList;
} ALGraph;

// 그래프의 초기화
void GraphInit(ALGraph* pg, int nv);

// 그래프의 리소스 해제
void GraphDestroy(ALGraph* pg);

// 간선의 추가
void AddEdge(ALGraph* pg, int fromV, int toV);

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph* pg);

#endif // !__AL_GRAPH__
