//HW2_2_1 20191023 �ֿ��� ��ǻ���а� 2�г�
#include <stdio.h>
#include <malloc.h>

typedef int element;
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
	if(is_empty(s))
		printf("<empty>\n");
	for (p = s->top; p != NULL; p = p->link)
	{
		printf("%d", p->data);
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
		int data = temp->data;
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

	init(&s);
	stack_print(&s);
	push(&s, 10);
	stack_print(&s);
	push(&s, 20);
	stack_print(&s);
	push(&s, 30);
	stack_print(&s);
	push(&s, 40);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	push(&s, 50);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
}