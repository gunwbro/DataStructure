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
	BTreeNode* pVRoot = MakeBTreeNode(); // ���� ��Ʈ ���
	BTreeNode* pNode = pVRoot;			 // �θ� ���
	BTreeNode* cNode = *pRoot;			 // ���� ���
	BTreeNode* dNode;					 // ������ ���

	// ��Ʈ ��带 pVRoot�� ����Ű�� ����� ������ �ڽ� ��尡 �ǰ� �Ѵ�.
	ChangeRightSubTree(pVRoot, *pRoot);

	// ���� ����� ��带 Ž��
	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;

		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if (cNode == NULL)		// ���� ����� �������� �ʴ´ٸ�,
		return NULL;

	dNode = cNode;			// ���� ����� dNode�� ����Ű�� �Ѵ�.

	// ù ��° ���: ���� ����� �ܸ� ����� ���
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	// �� ��° ���: ���� ����� �ϳ��� �ڽ� ��带 ���� ���
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode* dcNode; // ���� ����� �ڽ� ��� ����Ŵ

		if (GetLeftSubTree(dNode) != NULL) // ���� ����� ���� �ڽ� ��带 ���� ��
			dcNode = GetLeftSubTree(dNode);
		else // ������ �ڽ� ��带 ���� ��
			dcNode = GetRightSubTree(dNode);

		if (GetLeftSubTree(pNode) == dNode) // ���� ����� ���� ����� ���
			ChangeLeftSubTree(pNode, dcNode); // ���� ����� �θ� ��忡 ���� ����� �ڽ� ��带 ����
		else
			ChangeRightSubTree(pNode, dcNode);
	}

	// �� ��° ���: �� ���� �ڽ� ��带 ��� ���� ���
	else
	{
		BTreeNode* mNode = GetRightSubTree(dNode);
		BTreeNode* mpNode = dNode;	// ��ü ����� �θ� ��� ����Ŵ
		int delData;

		// ���� ����� ��ü ��带 ã�´�.
		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		// ��ü ��忡 ����� ���� ������ ��忡 �����Ѵ�.
		delData = GetData(dNode);	// ���� �� ������ ���
		SetData(dNode, GetData(mNode)); // ����

		// ��ü ����� �θ� ���� �ڽ� ��带 �����Ѵ�.
		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData);	// ��� ������ ����
	}

	// ������ ��尡 ��Ʈ ����� ���
	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot); // ��Ʈ ����� ������ �ݿ�

	free(pVRoot);	// ���� ��Ʈ ����� �Ҹ�
	return dNode;	// ���� ����� ��ȯ
}

void ShowIntData(int data)
{
	printf("%d ", data);
}
void BSTShowAll(BTreeNode* bst)
{
	InorderTraverse(bst, ShowIntData);		// ���� ��ȸ
}