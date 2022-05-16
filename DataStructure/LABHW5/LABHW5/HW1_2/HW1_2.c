//HW1_2 20191023 최영린 컴퓨터학과 2학년
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode *link;
} ListNode;

// 오류 처리 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	//exit(1);
}

// 노드 pre 뒤에 새로운 노드 삽입
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
	p->link = head;	// 헤드 포인터의 값을 복사	//(3)
	head = p;	// 헤드 포인터 변경		//(4)
	return head;	// 변경된 헤드 포인터 반환
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

// pre가 가리키는 노드의 다음 노드를 삭제한다. 
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
		error("삭제할 항목이 없음");
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
		error("삭제할 항목이 없음");
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
	printf("리스트 끝\n");
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

int is_in_list(ListNode *head, element item)//item 이 리스트에 있으면 1 을 아니면 0 을 반환 
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
int get_total(ListNode *head)//단순연결리스트의 모든 데이터 값을 더한 합을 반환
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
ListNode * delete_by_key(ListNode *head, int key)
{
	ListNode *p = head, *prevp = NULL;

   if (head == NULL)
      printf("리스트는 비어있습니다.\n");
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
        printf("%d은 리스트에 없음\n", key);
	return head;
}

ListNode* insert_pos(ListNode* head, int pos, element value)
{
   ListNode* p = (ListNode*)malloc(sizeof(ListNode));
   ListNode* temp = head;
   int i;

   if(pos < 0)
   {
		printf("오류: 올바르지 않은 pos값(음수)");
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
		printf("오류: 올바르지 않은 pos값(음수)");
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

// 테스트 프로그램
int main(void)
{
	ListNode *list1 = NULL, *list2 = NULL, *list3;
	
	//list1 = 30->20->10->를 만든다. 이때 10, 20, 30의 순으로 노드를 삽입한다.
	list1 = insert_first(list1, 10);
	list1 = insert_first(list1, 20);
	list1 = insert_first(list1, 30);
	// list1을 출력
	printf("list1 = ");
	print_list(list1);

	//list1을 맨 앞 노드를 삭제하고 list1을 출력한다.
	list1 = delete_first(list1);
	// list1을 출력
	printf("list1 = ");
	print_list(list1);

	//list2 = 11->22->33->44->를 만든다. 이때, 11,22,33,44의 순으로 노드를 삽입한다.
	list2 = insert_last(list2, 11);
	list2 = insert_last(list2, 22);
	list2 = insert_last(list2, 33);
	list2 = insert_last(list2, 44);
	//list2를 출력
	printf("list2 = ");
	print_list(list2);

	//list2의 값이 맨 뒤 노드를 삭제한다. 즉,  list2 = 11->22->33->
	list2 = delete_last(list2);
	//list2를 출력
	printf("list2 = ");
	print_list(list2);

	//list2를 역순으로 바꾼 리스트를 list3가 가리키게 한다. list3 = 33->22->11->를 만든다.
	list3 = reverse(list2);
	//list3를 출력한다.
	printf("list3 = ");
	print_list(list3);

	// list1 = 20->30->33->22->11->를 만든다. 즉, list1과 list3를 합쳐서 list1이 가리키게 한다.
	list1 = concat(list1, list3);
	//list1을 출력한다.
	printf("list1 = ");
	print_list(list1);

	//(A) 주의: 여기서부터는 list1만 사용하여 함수들을 테스트하자 
	printf("<list1>\n");
	printf("14는 list1에 %s\n", is_in_list(list1, 14)? "있습니다" : "없습니다");//없
	printf("20는 list1에 %s\n", is_in_list(list1, 20)? "있습니다" : "없습니다"); //있
	printf("11는 list1에 %s\n", is_in_list(list1, 11)? "있습니다" : "없습니다"); //있

	printf("\n");
	printf("list1의 길이는 %d\n", get_length(list1));

	printf("\n");
	printf("list1의 모든 노드들의 합은 %d\n", get_total(list1));

	printf("\n");
	printf("list1의 1번째 노드의 값은 %d입니다. \n", get_entry(list1, 0));
	printf("list1의 2번째 노드의 값은 %d입니다. \n", get_entry(list1, 1));
	printf("list1의 4번째 노드의 값은 %d입니다. \n", get_entry(list1, 3));

	printf("\nlist1의 현재 상태\nlist1 = ");
	print_list(list1);

	printf("\nlist1에서 노드의 값이 11인 노드를 삭제한다.\n");
	list1 = delete_by_key(list1, 11);
	printf("list1 = ");
	print_list(list1);
	printf("\nlist1에서 노드의 값이 20인 노드를 삭제한다.\n");
	list1 = delete_by_key(list1, 20);
	printf("list1 = ");
	print_list(list1);

	printf("\nlist1에서 pos=0의 위치에 20인 값을 삽입한다.\n");
	list1 = insert_pos(list1, 0, 20);
	printf("list1 = ");
	print_list(list1);
	printf("\nlist1에서 pos=2의 위치에 11인 값을 삽입한다.\n");
	list1 = insert_pos(list1, 2, 11);
	printf("list1 = ");
	print_list(list1);

	printf("\nlist1에서 pos=0의 위치의 노드를 삭제한다.\n");
	list1 = delete_pos(list1, 0);
	printf("list1 = ");
	print_list(list1);
	printf("\nlist1에서 pos=1의 위치의 노드를 삭제한다.\n");
	list1 = delete_pos(list1, 1);
	printf("list1 = ");
	print_list(list1);
	
}
