//HW2_2_2 20191023 �ֿ��� ��ǻ���а� 2�г�
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX_STRING 100

typedef struct {
	int num;
	char numString[MAX_STRING];
} element;

typedef struct StackNode {
	element data;
	struct StackNode *link;
} StackNode;

typedef struct {
	StackNode *top;
} LinkedStackType;
// �ʱ�ȭ �Լ�
void init(LinkedStackType *s)
{
	s->top = NULL;
}
// ���� ���� ���� �Լ�
int is_empty(LinkedStackType *s)
{
	return (s->top == NULL);
}
// ��ȭ ���� ���� �Լ�
int is_full(LinkedStackType *s)
{
	return 0;
}
// ���� �Լ�
void push(LinkedStackType *s, element item)
{
	StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}
void stack_print(LinkedStackType *s)
{
	StackNode *p;
	element e;
	if(is_empty(s))
		printf("<empty>\n");
	for (p = s->top; p != NULL; p = p->link)
	{
		printf("[%d, %s]", p->data.num, p->data.numString);
		if(p == s->top)
			printf("<- top");
		printf("\n");
	}	
	printf("--\n");
}
// ���� �Լ�
element pop(LinkedStackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
		//exit(1);
	}
	else {
		StackNode *temp = s->top;
		element data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}
// ��ũ �Լ�
element peek(LinkedStackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
		//exit(1);
	}
	else {
		return s->top->data;
	}
}
// �� �Լ�
int main(void)
{
	LinkedStackType s;
	element e;

	init(&s);
	stack_print(&s);

	e.num = 10;
	strcpy(e.numString, "ten"); 
	push(&s, e);
	stack_print(&s);

	e.num = 20;
	strcpy(e.numString, "twenty"); 
	push(&s, e);
	stack_print(&s);
	
	e.num = 30;
	strcpy(e.numString, "thirty"); 
	push(&s, e);
	stack_print(&s);
	
	e.num = 40;
	strcpy(e.numString, "forty"); 
	push(&s, e);
	stack_print(&s);

	pop(&s);
	stack_print(&s);
	
	e.num = 50;
	strcpy(e.numString, "fifty"); 
	push(&s, e);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);

	pop(&s);
	stack_print(&s);
}
