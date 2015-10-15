#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int key;
	struct node *pNext;
}Node, *pNode;

pNode CreatList();
void TraverseList(pNode pHead);
int  FindKthToTail(pNode pHead, unsigned int k);
int main(void)
{
	pNode pHead = (pNode)malloc(sizeof(Node));
	pHead = CreatList();
	printf("%d", FindKthToTail(pHead,3));
	/*TraverseList(pHead);*/
	return 0;
}
pNode CreatList()
{
	int len, val, i;
	printf("请输入节点个数： ");
	scanf_s("%d", &len);
	pNode pHead = (pNode)malloc(sizeof(Node));
	pNode pTail = pHead;
	pTail->pNext = NULL;
	for (i = 1; i <= len; i++)
	{
		printf("请输入第%d个节点： ", i);
		scanf_s("%d", &val);
		pNode pNew = (pNode)malloc(sizeof(Node));
		pNew->key = val;
		pTail->pNext = pNew;
		pTail = pNew;
	}
	return pHead;


}

void TraverseList(pNode pHead)
{
	pNode p = pHead->pNext;
	while (p != NULL)
	{
		printf("%d  ", p->key);
		p = p->pNext;
	}
}

int FindKthToTail(pNode pHead, unsigned int k)
{
	pNode pAhead = pHead;
	pNode pBehind = NULL;
	for (unsigned int i = 0; i < k - 1; i++)
	{
		pAhead = pAhead->pNext;
	}
	pBehind = pHead;

	while (pAhead->pNext != NULL)
	{
		pAhead = pAhead->pNext;
		pBehind = pBehind->pNext;
	}
	return pBehind->key;
}