//HW2_4 20191023 최영린 컴퓨터학과 2학년
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

int palindrome(char str[])
{
	StackType s; // 배열을 사용할 경우, 연결리스트를 사용하면 LinkedStackType s;

	// 필요한 변수들 선언
	int i, rslt = 0;

	// 스택을 초기화하라
	init(&s);

	//str 의 문자들을 스택에 넣는다
	for(i = 0; str[i] != '\0'; i++)
		push(&s, str[i]);

	//스택에서 하나씩 빼면서 str 의 문자들과 차례로 비교
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
		printf("palindrome 입니다.\n");
	else
		printf("palindrome 이 아닙니다.\n");
} 
