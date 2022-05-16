//HW1_5(이중연결) 20191023 최영린 컴퓨터학과 2학년
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {	// 이중연결 노드 타입
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

// 이중 연결 리스트를 초기화
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

// 이중 연결 리스트의 노드를 출력
void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}
// 새로운 데이터를 노드 before의 오른쪽에 삽입한다.
void dinsert(DListNode *before, element data)
{
	DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
	newnode->data = data;

	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}
// 노드 removed를 삭제한다.
void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) return;

	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

void print_reverse_dlist(DListNode *head)
{
	DListNode* p;
	for (p = head->llink; p != head; p = p->llink)
	{
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}

DListNode *search(DListNode *head, element data)
{
	DListNode *p;
	for (p = head->rlink; p != head; p = p->rlink) 
	{
		if(p->data == data)
		{
			printf("[탐색성공 : %d]당신이 찾는 데이터값이 있습니다!\n", p->data); 
			return p;
		}
	}
	printf("[탐색실패]당신이 찾는 데이터값이 없습니다!\n"); 
	return;
}

// 이중 연결 리스트 테스트 프로그램
int main(void)
{
	DListNode* head = (DListNode *)malloc(sizeof(DListNode));
	DListNode *temp;
	init(head);
	printf("추가 단계\n");
	
	// 처음에 삽입
	dinsert(head, 10);
	print_dlist(head);
	dinsert(head, 20);
	print_dlist(head);
	dinsert(head, 30);
	print_dlist(head);
	
	// 뒤에 삽입하려면?
	dinsert(head->llink, 99);
	print_dlist(head);

	printf("\n역순 단계\n");
	print_reverse_dlist(head);
	
	printf("\n삭제 단계");
	printf("\n현재 리스트는 아래와 같습니다.\n");
	print_dlist(head);

	printf("앞에 것을 삭제\n");
	ddelete(head, head->rlink);
	print_dlist(head);
	
	printf("뒤에 것을 삭제\n");
	ddelete(head, head->llink);
	print_dlist(head);

	printf("\n탐색 단계");
	printf("\n현재 리스트는 아래와 같습니다.\n");
	print_dlist(head);
	
	printf("\n탐색하고 싶은 값 : 30\n");
	temp = search(head, 30);
	
	printf("\n탐색하고 싶은 값 : 10\n");
	temp = search(head, 10);
	
	free(head);
	return 0;
}