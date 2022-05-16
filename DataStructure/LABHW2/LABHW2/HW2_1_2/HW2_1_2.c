//HW2_1_2 20191023 최영린 컴퓨터학과 2학년
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STACK_SIZE 3
#define MAX_STRING_SIZE 100
typedef int element;
typedef struct{
	element data[MAX_STACK_SIZE];
	char stackName[MAX_STRING_SIZE][MAX_STRING_SIZE];
	int top;
}StackType;

void init(StackType *s)
{
	s->top = -1;
}
int is_empty(StackType *s)
{
	return (s->top == -1);
}

int is_full(StackType *s)
{
	return (s->top == MAX_STACK_SIZE - 1);
}

void push(StackType *s, element item)
{
	if(is_full(s))
	{
		fprintf(stderr, "스택포화에러\n");
		return;
	}
	else
	{
		s->data[++(s->top)] = item;
	}
}

element pop(StackType *s)
{
	if(is_empty(s))
	{
		fprintf(stderr, "스택공백에러\n");
		exit(1);
	}
	else
	{
		return s->data[s->top--];
	}
}

element peek(StackType *s)
{
	if(is_empty(s))
	{
		fprintf(stderr, "스택공백에러\n");
		exit(1);
	}
	else
		return s->data[s->top];
}

void stack_print(StackType *s)
{
	int i;
	if(is_empty(s))
		printf("<empty>\n");
	else{
		for(i = s->top; i >= 0; i--)
		{
			printf("[%d, %s]", s->data[i], s->stackName[i]);
			if(i == s->top)
				printf(" <- top");
			printf("\n");
		}
	}
	printf("--\n");
}

int main(void)
{
	StackType s;

	init(&s);
	stack_print(&s);
	push(&s, 10);
	strcpy(s.stackName[0], "ten");
	stack_print(&s);
	push(&s, 20);
	strcpy(s.stackName[1], "twenty");
	stack_print(&s);
	push(&s, 30);
	strcpy(s.stackName[2], "thirty");
	stack_print(&s);
	push(&s, 40);
	strcpy(s.stackName[3], "forty");
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	push(&s, 50);
	strcpy(s.stackName[2], "fifty");
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
}