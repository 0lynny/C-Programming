// HW1_4(��������) 20191023 �ֿ��� ��ǻ���а� 2�г�
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// ��� Ÿ��
	element data;
	struct ListNode *link;
} ListNode;

// ����Ʈ�� �׸� ���
void print_list(ListNode* head) // Ʋ��
{
	ListNode* p;

	if (head == NULL){
		printf("����Ʈ��\n");
		return;
	}
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);
	printf("����Ʈ��\n");
}

ListNode* insert_first(ListNode* head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
	}
	return head;	// ����� ��� �����͸� ��ȯ�Ѵ�. 
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
		head = node;		// (3)
	}
	return head;	// ����� ��� �����͸� ��ȯ�Ѵ�. 
}

ListNode* delete_first(ListNode* head)
{
     ListNode *temp;
     if (head == NULL) {
          printf("����Ʈ�� ��� ������ ����\n");
          return NULL;
     } 

     else if (head == head->link) {  // �� �ϳ��� ��尡 �������� 
          temp = head;
          head = NULL;
          free(temp);
     }
    else {
          temp = head->link;
          head->link = temp->link;
          free(temp);
     }
	return head;
}

ListNode* delete_last(ListNode *head)//����Ʈ�� ������ ��带 ����, ����Ʈ�� ��������� "����Ʈ�� ����־� ������ ����"�� ��� 
{
	 ListNode *temp, *prevtemp;
     if (head == NULL) {
          printf("����Ʈ�� ����־� ������ ����\n");
          return NULL;
     } 

     else if (head == head->link) {  // �� �ϳ��� ��尡 �������� 
          temp = head;
          head = NULL;
          free(temp);
     }
    else {
		temp = head;
		prevtemp = head->link;
		do {
			prevtemp = prevtemp->link;
		}while (prevtemp->link != head);
        prevtemp->link = temp->link;
        free(temp);
		head = prevtemp;
     }
	return head;
}

ListNode* search(ListNode* head, element data)
{
	ListNode *p;

	if(head == NULL)
	{
         return NULL;
	}
	else{
		p = head->link;
		do{
			if(p->data == data)
			{
				printf("[Ž������ : %d]����� ã�� �����Ͱ��� �ֽ��ϴ�!\n", p->data); 
				return p;
			}
			p = p->link;
		}while(p != head->link);
		printf("[Ž������]����� ã�� �����Ͱ��� �����ϴ�!\n"); 
		return;
	}
}

int get_size(ListNode *head)//����Ʈ�� ���̸� ��ȯ
{
	ListNode *p = head;
    int size = 0;

	if(p == NULL)
		return NULL;
	else{
		do{
			size++;
			p = p->link;
		}while(p != head);
	}
	return size;
}   

// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main(void)
{
	ListNode *head = NULL;

	// list = 10->20->30->40
	head = insert_last(head, 20);
	print_list(head);
	printf("����Ʈ�� ������� %d\n\n", get_size(head));

	head = insert_last(head, 30);
	print_list(head);
	printf("����Ʈ�� ������� %d\n\n", get_size(head));

	head = insert_last(head, 40);
	print_list(head);
	printf("����Ʈ�� ������� %d\n\n", get_size(head));

	head = insert_first(head, 10);
	print_list(head);
	printf("����Ʈ�� ������� %d\n\n", get_size(head));

	head = delete_first(head);
	print_list(head);
	printf("����Ʈ�� ������� %d\n\n", get_size(head));
	
	head = delete_last(head);
	print_list(head);
	printf("����Ʈ�� ������� %d\n\n", get_size(head));

	printf("���� ����Ʈ ���´� �Ʒ��� �����ϴ�.\n");
	print_list(head);

	printf("\nŽ���ϰ� ���� �� : 30\n");
	head = search(head, 30);

	printf("\nŽ���ϰ� ���� �� : 10\n");
	head = search(head, 10);

	return 0;
}
