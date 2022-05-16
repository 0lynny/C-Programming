//HW1_2 20191023 �ֿ��� ��ǻ���а� 2�г�
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

void print_list(ListNode *head)
{
	ListNode *p;
	for (p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("����Ʈ ��\n");
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
ListNode * delete_by_key(ListNode *head, int key)
{
	ListNode *p = head, *prevp = NULL;

   if (head == NULL)
      printf("����Ʈ�� ����ֽ��ϴ�.\n");
   else if (head->data == key) { 
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
        printf("%d�� ����Ʈ�� ����\n", key);
	return head;
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

// �׽�Ʈ ���α׷�
int main(void)
{
	ListNode *list1 = NULL, *list2 = NULL, *list3;
	
	//list1 = 30->20->10->�� �����. �̶� 10, 20, 30�� ������ ��带 �����Ѵ�.
	list1 = insert_first(list1, 10);
	list1 = insert_first(list1, 20);
	list1 = insert_first(list1, 30);
	// list1�� ���
	printf("list1 = ");
	print_list(list1);

	//list1�� �� �� ��带 �����ϰ� list1�� ����Ѵ�.
	list1 = delete_first(list1);
	// list1�� ���
	printf("list1 = ");
	print_list(list1);

	//list2 = 11->22->33->44->�� �����. �̶�, 11,22,33,44�� ������ ��带 �����Ѵ�.
	list2 = insert_last(list2, 11);
	list2 = insert_last(list2, 22);
	list2 = insert_last(list2, 33);
	list2 = insert_last(list2, 44);
	//list2�� ���
	printf("list2 = ");
	print_list(list2);

	//list2�� ���� �� �� ��带 �����Ѵ�. ��,  list2 = 11->22->33->
	list2 = delete_last(list2);
	//list2�� ���
	printf("list2 = ");
	print_list(list2);

	//list2�� �������� �ٲ� ����Ʈ�� list3�� ����Ű�� �Ѵ�. list3 = 33->22->11->�� �����.
	list3 = reverse(list2);
	//list3�� ����Ѵ�.
	printf("list3 = ");
	print_list(list3);

	// list1 = 20->30->33->22->11->�� �����. ��, list1�� list3�� ���ļ� list1�� ����Ű�� �Ѵ�.
	list1 = concat(list1, list3);
	//list1�� ����Ѵ�.
	printf("list1 = ");
	print_list(list1);

	//(A) ����: ���⼭���ʹ� list1�� ����Ͽ� �Լ����� �׽�Ʈ���� 
	printf("<list1>\n");
	printf("14�� list1�� %s\n", is_in_list(list1, 14)? "�ֽ��ϴ�" : "�����ϴ�");//��
	printf("20�� list1�� %s\n", is_in_list(list1, 20)? "�ֽ��ϴ�" : "�����ϴ�"); //��
	printf("11�� list1�� %s\n", is_in_list(list1, 11)? "�ֽ��ϴ�" : "�����ϴ�"); //��

	printf("\n");
	printf("list1�� ���̴� %d\n", get_length(list1));

	printf("\n");
	printf("list1�� ��� ������ ���� %d\n", get_total(list1));

	printf("\n");
	printf("list1�� 1��° ����� ���� %d�Դϴ�. \n", get_entry(list1, 0));
	printf("list1�� 2��° ����� ���� %d�Դϴ�. \n", get_entry(list1, 1));
	printf("list1�� 4��° ����� ���� %d�Դϴ�. \n", get_entry(list1, 3));

	printf("\nlist1�� ���� ����\nlist1 = ");
	print_list(list1);

	printf("\nlist1���� ����� ���� 11�� ��带 �����Ѵ�.\n");
	list1 = delete_by_key(list1, 11);
	printf("list1 = ");
	print_list(list1);
	printf("\nlist1���� ����� ���� 20�� ��带 �����Ѵ�.\n");
	list1 = delete_by_key(list1, 20);
	printf("list1 = ");
	print_list(list1);

	printf("\nlist1���� pos=0�� ��ġ�� 20�� ���� �����Ѵ�.\n");
	list1 = insert_pos(list1, 0, 20);
	printf("list1 = ");
	print_list(list1);
	printf("\nlist1���� pos=2�� ��ġ�� 11�� ���� �����Ѵ�.\n");
	list1 = insert_pos(list1, 2, 11);
	printf("list1 = ");
	print_list(list1);

	printf("\nlist1���� pos=0�� ��ġ�� ��带 �����Ѵ�.\n");
	list1 = delete_pos(list1, 0);
	printf("list1 = ");
	print_list(list1);
	printf("\nlist1���� pos=1�� ��ġ�� ��带 �����Ѵ�.\n");
	list1 = delete_pos(list1, 1);
	printf("list1 = ");
	print_list(list1);
	
}
