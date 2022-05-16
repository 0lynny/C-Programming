//Review2_2 20191023 �ֿ��� ��ǻ���а� 2�г�
#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode{
	int number;
	struct ListNode *link;
}ListNode;

//�ݺ��� �̿��Ͽ� ��帮��Ʈ�� ���
void displayList1(ListNode *head)
{
	ListNode *temp = head;

	if(temp == NULL)
		printf("Empty list\n");
	else
	{
		while(temp != NULL)
		{
			printf("%d->", temp->number);
			temp = temp->link;
		}
	}
}

//��ȯ�� �̿��Ͽ� ��帮��Ʈ�� ���
void displayList2(ListNode *head)
{
	ListNode *temp = head;

	if(temp == NULL)
		printf("Empty list\n");
	else
	{
		if(temp != NULL)
		{
			printf("%d->", temp->number);
			displayList2(temp->link);
		}
	}
}

int main(void)
{
	ListNode *head, *newNode, *temp;

	//1)
	newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->number = 10;
	newNode->link = NULL;
	head = newNode;

	//2)
	newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->number = 20;
	newNode->link = NULL;
	head->link = newNode;

	//3)
	newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->number = 30;
	newNode->link = NULL;
	head->link->link = newNode;

	//4)
	newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->number = 44;
	newNode->link = NULL;
	temp = head;
	//head->link->link->link = newNode;
	while(temp->link != NULL)
		temp = temp->link;
	temp->link = newNode;

	//5)
	newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->number = 1;
	newNode->link = NULL;
	newNode->link = head;
	head = newNode;

	displayList1(head);
	printf("\n");
	displayList2(head);
	printf("\n");
}

