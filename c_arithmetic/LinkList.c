#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int key;
	struct node *pNext;
}Node,*pNode;
pNode CreatList();
void TraverseList(pNode pHead);
int main(void)
{
	pNode pHead = (pNode)malloc(sizeof(Node));
	pHead = CreatList();
	TraverseList(pHead);
	return 0;

}





pNode CreatList()
{
	int i, len, value;
	pNode  pHead= (pNode)malloc(sizeof(Node));
	pNode pTail = pHead;
	pTail->pNext = NULL;
	printf("请输入节点数： ");
	scanf_s("%d", &len);
	for (i = 0; i < len; i++)
	{
		printf("输入第%d个节点: ", i + 1);
		scanf_s("%d", &value);
		pNode pNew = (pNode)malloc(sizeof(Node));
		pNew->key = value;
		pNew->pNext = NULL;
		pTail->pNext = pNew;
		pTail = pNew;
		
	}
	return pHead;

}

void TraverseList(pNode pHead)
{
	pNode p;
	p = pHead->pNext;
	while (p != NULL)
	{
		printf("%d  ", p->key);
		p = p->pNext;
	}

}