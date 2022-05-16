//HW2_4 20191023 �ֿ��� ��ǻ���а� 2�г�
#include<stdio.h>
#include<stdlib.h>
#define MAX_STRING 100

typedef int element;
typedef struct{
	element data[MAX_STRING];
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
	return (s->top == MAX_STRING - 1);
}

void push(StackType *s, element item)
{
	if(is_full(s))
	{
		fprintf(stderr, "������ȭ����\n");
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
		fprintf(stderr, "���ð��鿡��\n");
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
		fprintf(stderr, "���ð��鿡��\n");
		exit(1);
	}
	else
		return s->data[s->top];
}

int palindrome(char str[])
{
	StackType s; // �迭�� ����� ���, ���Ḯ��Ʈ�� ����ϸ� LinkedStackType s;

	// �ʿ��� ������ ����
	int i, rslt = 0;

	// ������ �ʱ�ȭ�϶�
	init(&s);

	//str �� ���ڵ��� ���ÿ� �ִ´�
	for(i = 0; str[i] != '\0'; i++)
		push(&s, str[i]);

	//���ÿ��� �ϳ��� ���鼭 str �� ���ڵ�� ���ʷ� ��
	for(i = 0; str[i] != '\0'; i++)
	{
		if(str[i] == pop(&s))
			rslt =  1;
		else
		{
			rslt = 0;
			break;
		}
	}

	return rslt;
}

int main(void)
{
	char word[MAX_STRING];

	printf("Enter a word to check palindrome: ");
	scanf("%s", word);
	
	if (palindrome(word))
		printf("palindrome �Դϴ�.\n");
	else
		printf("palindrome �� �ƴմϴ�.\n");
} 
