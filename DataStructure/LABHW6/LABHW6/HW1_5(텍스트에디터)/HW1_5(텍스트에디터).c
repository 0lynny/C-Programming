//HW1_5(텍스트에디터) 20191023 최영린 컴퓨터학과 2학년
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

// 나머지 함수들 정의를 그대로 여기에
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
	p->link = head;	// 헤드 포인터의 값을 복사	//(3)
	head = p;	// 헤드 포인터 변경		//(4)
	return head;	// 변경된 헤드 포인터 반환
}

ListNode* delete_first(ListNode *head)
{
	ListNode *removed;
	if (head == NULL) 
		error("삭제할 항목이 없음");
	removed = head;	// (1)
	head = removed->link;	// (2)
	free(removed);		// (3)
	return head;		// (4)
}

int get_length(ListNode *head)//단순 연결 리스트에 존재하는 노드의 수를 반환
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

element get_entry(ListNode *head, int pos)//pos 위치(0 이 첫 번째 노드)에 있는 노드의 data 를 반환
{
	ListNode *p = head;
	int i;
	if(pos >= get_length(head))
	{
		error("위치오류\n");
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
		printf("오류: 올바르지 않은 pos값");
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

ListNode * delete_pos(ListNode *head, int pos)//pos 위치의 노드를 삭제
{
	ListNode *p = head;	//(1)
	ListNode *removed = p;
	int i; 

	 if(pos < 0)
   {
		printf("오류: 올바르지 않은 pos값");
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
void display_te(ListNode *head) // text editor 를 위해 변경 // 2)
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
	printf("a: 텍스트 끝에 라인 추가\n"); 
	printf("i: 라인 번호로 라인 추가\n"); 
	printf("d: 라인 번호로 라인 삭제\n"); 
	printf("v: 라인 번호로 해당 라인 출력\n"); 
	printf("p: 전체 텍스트 출력\n"); 
	printf("q: 끝\n");
	printf("메뉴 선택:"); 
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
				printf("텍스트 끝에 삽입할 라인: ");
				fflush(stdin);
				fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);
				newElement.line[strlen(newElement.line) - 1] = '\0'; 
				printf("----------text edited----------\n");
				list = insert_last(list, newElement);
				display_te(list);
				break;
			case 'i':
				printf("삽입할 라인 번호: ");
				scanf("%d", &lineNb);
				printf("삽입할 라인: ");
				fflush(stdin);
				fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);
				newElement.line[strlen(newElement.line) - 1] = '\0'; 
				printf("----------text edited----------\n");
				list = insert_pos(list, lineNb - 1, newElement);
				display_te(list);
				break;
			case 'd':
				printf("삭제할 라인 번호: ");
				scanf("%d", &lineNb);
				printf("----------text edited----------\n");
				list = delete_pos(list, lineNb - 1);
				display_te(list);
				break;
			case 'v':
				printf("출력할 라인 번호: ");
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