//Review2_2 20191023 최영린 컴퓨터학과 2학년
#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode{
	int number;
	struct ListNode *link;
}ListNode;

//반복을 이용하여 노드리스트를 출력
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

//순환을 이용하여 노드리스트를 출력
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

