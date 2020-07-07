#include <stdio.h>
#include "BinarySearchTree2.h"

void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}
BSTData BSTGetNodeData(BTreeNode* bst)
{
	return GetData(bst);
}
BTreeNode* BSTInsert(BTreeNode** pRoot, BSTData data)
{
	if (*pRoot == NULL)
	{
		*pRoot = MakeBTreeNode();
		SetData(*pRoot, data);
	}
	else if (data < GetData(*pRoot))
	{
		BSTInsert(&((*pRoot)->left), data);
		*pRoot = Rebalance(pRoot);
	}
	else if (data > GetData(*pRoot))
	{
		BSTInsert(&((*pRoot)->right), data);
		*pRoot = Rebalance(pRoot);
	}
	else
	{
		return NULL;
	}
	return *pRoot;
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
	*pRoot = Rebalance(pRoot);
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