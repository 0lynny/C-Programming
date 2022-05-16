//HW1_3(4���� 6p) 20191023 �ֿ��� ��ǻ���а� 2�г�
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// ��� Ÿ��
	element data;
	struct ListNode *link;
} ListNode;

// ���� ó�� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	//exit(1);
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode*  insert_next(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	p->link = pre->link;	//(3)	
	pre->link = p;		//(4)	
	return head;		//(5)	
}

ListNode* insert_first(ListNode *head, int value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = head;	// ��� �������� ���� ����	//(3)
	head = p;	// ��� ������ ����		//(4)
	return head;	// ����� ��� ������ ��ȯ
}

ListNode* insert_last(ListNode *head, int value)
{
	ListNode *temp = head;
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = NULL;	
	if(head == NULL)	
		head = p;	
	else{
		while(temp->link != NULL)
			temp =  temp->link;
		temp->link = p;
	}
	return head;
}

// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�. 
ListNode* delete_next(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link;		// (2)
	free(removed);			// (3)
	return head;			// (4)
}

ListNode* delete_first(ListNode *head)
{
	ListNode *removed;
	if (head == NULL) 
		error("������ �׸��� ����");
	removed = head;	// (1)
	head = removed->link;	// (2)
	free(removed);		// (3)
	return head;		// (4)
}

ListNode* delete_last(ListNode *head)
{
	ListNode *temp = head;
	ListNode *prevTemp;
	ListNode *removed;
	if (head == NULL) 
		error("������ �׸��� ����");
	if(head->link == NULL){
		free(head);
		head = NULL;
	}
	else
	{
		while(temp->link != NULL)
		{
			prevTemp = temp;
			temp = temp->link;
		}
		prevTemp->link = NULL;
		free(temp);
	}
	return head;
}

void display(ListNode *head)
{
	ListNode *p;
	printf("< ");
	for (p = head; p != NULL; p = p->link)
		printf("%d ", p->data);
	printf(">\n");
}

ListNode* search(ListNode *head, int x)
{
	ListNode *p;
	p = head;
	while(p != NULL) 
	{
		if(p->data == x)
			return p;
		p = p->link;
	}
	return NULL;
}

ListNode* concat(ListNode *head1, ListNode *head2)
{
	ListNode *p;
	if (head1 == NULL)
		return head2;
	else if(head2 == NULL)
		return head1;
	else{
		p = head1;
		while(p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}

ListNode* reverse(ListNode *head)
{
	ListNode *p, *q, *r;
	p = head;
	q = NULL;
	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}

int is_in_list(ListNode *head, element item)//item �� ����Ʈ�� ������ 1 �� �ƴϸ� 0 �� ��ȯ 
{
	 ListNode *p = head;

	 while( (p != NULL) ){
	 	 if( p->data == item )
			 break;
		  p = p->link;
	 }
	if(p == NULL) 
		return 0;
	else 
		return 1;
}
int get_length(ListNode *head)//�ܼ� ���� ����Ʈ�� �����ϴ� ����� ���� ��ȯ
{
	ListNode *p = head;
    int length = 0;

	if(head == NULL)
		return 0;
	else{
		while(p != NULL){
			length++;
			p = p->link;
		}
	}
	return length;
}
int get_total(ListNode *head)//�ܼ����Ḯ��Ʈ�� ��� ������ ���� ���� ���� ��ȯ
{
	ListNode *p = head;
    int total = 0;

	if(head == NULL)
		return 0;
	else{
		while(p != NULL){
			total += p->data;
			p = p->link;
		}
	}
	return total;
}
element get_entry(ListNode *head, int pos)//pos ��ġ(0 �� ù ��° ���)�� �ִ� ����� data �� ��ȯ
{
	ListNode *p = head;
	int i;
	if(pos >= get_length(head))
	{
		error("��ġ����\n");
	}
	else
	{
		for(i = 0; i < pos; i++)
		{
			p = p->link;
		}
		return p->data;
	}
}

ListNode* insert_pos(ListNode* head, int pos, element value)
{
   ListNode* p = (ListNode*)malloc(sizeof(ListNode));
   ListNode* temp = head;
   int i;

   if(pos < 0)
   {
		printf("����: �ùٸ��� ���� pos��(����)");
		return;
   }
   if (pos == 0)
      return insert_first(head, value);
   else{
		for (i = 0; i < pos - 1; i++)
		{
			temp = temp->link;
		}
		p->data = value; 
		p->link = temp->link;
		temp->link = p;
   }
   return head; 
} 	

ListNode * delete_pos(ListNode *head, int pos)//pos ��ġ�� ��带 ����
{
	ListNode *p = head;	//(1)
	ListNode *removed = p;
	int i; 

	 if(pos < 0)
   {
		printf("����: �ùٸ��� ���� pos��(����)");
		return;
   }
	if(pos == 0)
	{
		return delete_first(head);	
	}
	else
	{
		for(i = 0; i < pos- 1; i++)
		{
			p = p->link;
		}
		removed = p->link;
		p->link = removed->link;		// (2)
		free(removed);	
		return head;
	}
}

ListNode * delete_by_key(ListNode *head, int key)
{
	ListNode *p = head, *prevp = NULL;

   if (head == NULL)
      printf("����Ʈ�� ����ֽ��ϴ�.\n");
   else if (head->data == key)
   {
	  return delete_first(head);
   }
   else {
		while (p != NULL && p->data != key){
			prevp = p;
			p = p->link;
		}
	}

    if (p != NULL) { 
		prevp->link = p->link;
        free(p);
    }
    else
        printf("������ %d�� �����ϰ� ���� �ʽ��ϴ�.\n", key);
	return head;
}

ListNode *add_item(ListNode *phead, int new_item)
{
	ListNode *p;
	
	if(get_total(phead) + new_item > 100)
		printf("�ִ� ����<100kg>�ʰ��� ������ %d�� �߰��� �� ����\n", new_item);
	else
		phead = insert_first(phead, new_item);
	return phead;
} 

char askChoice(void) {
	char choice;
	printf("enter a<dd>, d<elete> or q<uit>: "); 
	scanf("%c", &choice);
	return choice;
}

int main (void)
{
	ListNode *list = NULL;
	int item;
	char choice;

	while ((choice = askChoice()) != 'q') {
		switch (choice) {
			case 'a':
				printf("enter the weight of the item: ");
				scanf("%d", &item);
				list = add_item(list, item);
				display(list);
				break;
			case 'd':
				printf("enter the weight of the item: ");
				scanf("%d", &item);
				list = delete_by_key(list, item);
				display(list);
		}
		fflush(stdin);
	}
} 
