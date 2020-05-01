#include <stdio.h>
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}
BSTData BSTGetNodeData(BTreeNode* bst)
{
	return GetData(bst);
}
void BSTInsert(BTreeNode** pRoot, BSTData data)
{
	BTreeNode* pNode = NULL;
	BTreeNode* cNode = *pRoot;
	BTreeNode* nNode = NULL;

	while (cNode != NULL)
	{
		if (data == GetData(cNode))
			return;

		pNode = cNode;

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	nNode = MakeBTreeNode();
	SetData(nNode, data);

	if (pNode != NULL)
	{
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else
		*pRoot = nNode;
}
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
	BTreeNode* cNode = bst;
	BSTData cd;

	while (cNode != NULL)
	{
		cd = GetData(cNode);

		if (target == cd)
			return cNode;
		else if (target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	return NULL;
}

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	BTreeNode* pVRoot = MakeBTreeNode(); // 가상 루트 노드
	BTreeNode* pNode = pVRoot;			 // 부모 노드
	BTreeNode* cNode = *pRoot;			 // 현재 노드
	BTreeNode* dNode;					 // 삭제할 노드

	// 루트 노드를 pVRoot가 가리키는 노드의 오른쪽 자식 노드가 되게 한다.
	ChangeRightSubTree(pVRoot, *pRoot);

	// 삭제 대상인 노드를 탐색
	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;

		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if (cNode == NULL)		// 삭제 대상이 존재하지 않는다면,
		return NULL;

	dNode = cNode;			// 삭제 대상을 dNode가 가리키게 한다.

	// 첫 번째 경우: 삭제 대상이 단말 노드인 경우
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	// 두 번째 경우: 삭제 대상이 하나의 자식 노드를 갖는 경우
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode* dcNode; // 삭제 대상의 자식 노드 가리킴

		if (GetLeftSubTree(dNode) != NULL) // 삭제 대상이 왼쪽 자식 노드를 가질 때
			dcNode = GetLeftSubTree(dNode);
		else // 오른쪽 자식 노드를 가질 때
			dcNode = GetRightSubTree(dNode);

		if (GetLeftSubTree(pNode) == dNode) // 삭제 대상이 왼쪽 노드일 경우
			ChangeLeftSubTree(pNode, dcNode); // 삭제 대상의 부모 노드에 삭제 대상의 자식 노드를 붙임
		else
			ChangeRightSubTree(pNode, dcNode);
	}

	// 세 번째 경우: 두 개의 자식 노드를 모두 갖는 경우
	else
	{
		BTreeNode* mNode = GetRightSubTree(dNode);
		BTreeNode* mpNode = dNode;	// 대체 노드의 부모 노드 가리킴
		int delData;

		// 삭제 대상의 대체 노드를 찾는다.
		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		// 대체 노드에 저장된 값을 삭제할 노드에 대입한다.
		delData = GetData(dNode);	// 대입 전 데이터 백업
		SetData(dNode, GetData(mNode)); // 대입

		// 대체 노드의 부모 노드와 자식 노드를 연결한다.
		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData);	// 백업 데이터 복원
	}

	// 삭제된 노드가 루트 노드인 경우
	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot); // 루트 노드의 변경을 반영

	free(pVRoot);	// 가상 루트 노드의 소멸
	return dNode;	// 삭제 대상의 반환
}

void ShowIntData(int data)
{
	printf("%d ", data);
}
void BSTShowAll(BTreeNode* bst)
{
	InorderTraverse(bst, ShowIntData);		// 중위 순회
}