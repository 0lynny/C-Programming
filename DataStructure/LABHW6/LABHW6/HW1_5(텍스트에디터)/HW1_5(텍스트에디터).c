//HW1_5(�ؽ�Ʈ������) 20191023 �ֿ��� ��ǻ���а� 2�г�
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define MAX_CHAR_PER_LINE 100
// 1) 
typedef struct {
	char line[MAX_CHAR_PER_LINE];
} element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
} ListNode; 

// ������ �Լ��� ���Ǹ� �״�� ���⿡
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	//exit(1);
}

ListNode* insert_last(ListNode *head, element value)
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

ListNode* insert_first(ListNode *head, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = head;	// ��� �������� ���� ����	//(3)
	head = p;	// ��� ������ ����		//(4)
	return head;	// ����� ��� ������ ��ȯ
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
		printf("����: �ùٸ��� ���� pos��");
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
		printf("����: �ùٸ��� ���� pos��");
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
void display_te(ListNode *head) // text editor �� ���� ���� // 2)
{
	ListNode *p;
	int lineNb = 0;
	for (p = head; p != NULL; p = p->link)
	{
		printf("(%d) %s\n", ++lineNb, get_entry(head, lineNb - 1).line);
	}
}

char askChoice(void) {
	char choice;
	printf("------------------------------\n"); 
	printf("a: �ؽ�Ʈ ���� ���� �߰�\n"); 
	printf("i: ���� ��ȣ�� ���� �߰�\n"); 
	printf("d: ���� ��ȣ�� ���� ����\n"); 
	printf("v: ���� ��ȣ�� �ش� ���� ���\n"); 
	printf("p: ��ü �ؽ�Ʈ ���\n"); 
	printf("q: ��\n");
	printf("�޴� ����:"); 
	scanf("%c", &choice);
	return choice;
}
int main(void) // 3)
{
	ListNode *list = NULL;
	char choice;
	int lineNb;
	element newElement;;
	while ((choice = askChoice()) != 'q') {
		switch (choice) {
			case 'a':
				printf("�ؽ�Ʈ ���� ������ ����: ");
				fflush(stdin);
				fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);
				newElement.line[strlen(newElement.line) - 1] = '\0'; 
				printf("----------text edited----------\n");
				list = insert_last(list, newElement);
				display_te(list);
				break;
			case 'i':
				printf("������ ���� ��ȣ: ");
				scanf("%d", &lineNb);
				printf("������ ����: ");
				fflush(stdin);
				fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);
				newElement.line[strlen(newElement.line) - 1] = '\0'; 
				printf("----------text edited----------\n");
				list = insert_pos(list, lineNb - 1, newElement);
				display_te(list);
				break;
			case 'd':
				printf("������ ���� ��ȣ: ");
				scanf("%d", &lineNb);
				printf("----------text edited----------\n");
				list = delete_pos(list, lineNb - 1);
				display_te(list);
				break;
			case 'v':
				printf("����� ���� ��ȣ: ");
				scanf("%d", &lineNb);
				printf("(%d) %s\n", lineNb, get_entry(list, lineNb - 1).line);
				break;
			case 'p':
				printf("----------text edited----------\n");
				display_te(list);
		}
	fflush(stdin);
	}
}