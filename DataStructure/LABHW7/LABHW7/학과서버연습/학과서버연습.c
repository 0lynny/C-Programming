#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode 
{ 
	element data;
	struct ListNode *link;
} ListNode;

 
ListNode* insert_last(ListNode *head, int value)
{

	ListNode *temp = head;
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	
	p->data = value;	
	p->link = NULL;

	if(head == NULL) 
		head = p;
	else {
		while (temp->link != 0) 
			temp = temp->link;

		temp->link = p;
	}
	return head;
}

ListNode* delete_first(ListNode *head) 
{
	ListNode *temp;
     if (head == NULL) {
          printf("no delete\n");
          return NULL;
     } 

     if (head == head->link) {
          temp = head;
		   free(temp);
          head = NULL;
         
     }
    else {
          temp = head->link;
          head->link = temp->link;
          free(temp);
     }
	return head;

}

void print_list(ListNode *head)
{
	ListNode *p;
	for (p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}

int main(void)
{
	ListNode *head = NULL;
	int n;

	scanf("%d", &n);
	while (n != -1) {
		head = insert_last(head, n);
		scanf("%d", &n);
	}
	
	print_list(head); 
	head = delete_first(head);
	print_list(head);
	
	return 0;
}
