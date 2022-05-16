// HW1_4(원형연결) 20191023 최영린 컴퓨터학과 2학년
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode *link;
} ListNode;

// 리스트의 항목 출력
void print_list(ListNode* head) // 틀림
{
	ListNode* p;

	if (head == NULL){
		printf("리스트끝\n");
		return;
	}
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);
	printf("리스트끝\n");
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
	return head;	// 변경된 헤드 포인터를 반환한다. 
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
	return head;	// 변경된 헤드 포인터를 반환한다. 
}

ListNode* delete_first(ListNode* head)
{
     ListNode *temp;
     if (head == NULL) {
          printf("리스트가 비어 삭제를 못함\n");
          return NULL;
     } 

     else if (head == head->link) {  // 즉 하나의 노드가 남았을때 
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

ListNode* delete_last(ListNode *head)//리스트의 마지막 노드를 삭제, 리스트가 비어있으면 "리스트가 비어있어 삭제를 못함"을 출력 
{
	 ListNode *temp, *prevtemp;
     if (head == NULL) {
          printf("리스트가 비어있어 삭제를 못함\n");
          return NULL;
     } 

     else if (head == head->link) {  // 즉 하나의 노드가 남았을때 
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
				printf("[탐색성공 : %d]당신이 찾는 데이터값이 있습니다!\n", p->data); 
				return p;
			}
			p = p->link;
		}while(p != head->link);
		printf("[탐색실패]당신이 찾는 데이터값이 없습니다!\n"); 
		return;
	}
}

int get_size(ListNode *head)//리스트의 길이를 반환
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

// 원형 연결 리스트 테스트 프로그램
int main(void)
{
	ListNode *head = NULL;

	// list = 10->20->30->40
	head = insert_last(head, 20);
	print_list(head);
	printf("리스트의 사이즈는 %d\n\n", get_size(head));

	head = insert_last(head, 30);
	print_list(head);
	printf("리스트의 사이즈는 %d\n\n", get_size(head));

	head = insert_last(head, 40);
	print_list(head);
	printf("리스트의 사이즈는 %d\n\n", get_size(head));

	head = insert_first(head, 10);
	print_list(head);
	printf("리스트의 사이즈는 %d\n\n", get_size(head));

	head = delete_first(head);
	print_list(head);
	printf("리스트의 사이즈는 %d\n\n", get_size(head));
	
	head = delete_last(head);
	print_list(head);
	printf("리스트의 사이즈는 %d\n\n", get_size(head));

	printf("현재 리스트 상태는 아래와 같습니다.\n");
	print_list(head);

	printf("\n탐색하고 싶은 값 : 30\n");
	head = search(head, 30);

	printf("\n탐색하고 싶은 값 : 10\n");
	head = search(head, 10);

	return 0;
}
