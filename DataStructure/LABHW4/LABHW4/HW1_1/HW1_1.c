//HW1_1 20191023 최영린 컴퓨터학과 2학년
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 5

typedef int element;
typedef struct{
	element array[MAX_LIST_SIZE];
	int size;
}ArrayListType;

// 리스트 초기화 함수
void init(ArrayListType *L)
{
	L->size = 0;
}

// 리스트가 비어 있으면 1을 반환
// 그렇지 않으면 0을 반환
int is_empty(ArrayListType *L)
{
	return L->size == 0;
}

// 리스트가 가득 차 있으면 1을 반환
// 그렇지 많으면 1을 반환
int is_full(ArrayListType *L)
{
	return L->size == MAX_LIST_SIZE;
}
element get_entry(ArrayListType *L, int pos)
{
	if (pos < 0 || pos >= L->size)
		printf("위치 오류");
	return L->array[pos];
}

// 리스트 출력
void print_list(ArrayListType *L)
{
	int i;
	if(L->size == 0)
		printf("리스트끝");
	for (i = 0; i < L->size; i++)
	{
		printf("%d->", L->array[i]);
		if(i == L->size-1)
			printf("리스트끝");

	}
	printf("\n");
}

void insert_last(ArrayListType *L, element item)
{
	if( L->size >= MAX_LIST_SIZE ) {
		printf("리스트 오버플로우");
	}
	L->array[L->size++] = item;
}

void insert(ArrayListType *L, int pos, element item)
{
	int i;
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (i = (L->size - 1); i >= pos; i--)
			L->array[i + 1] = L->array[i];
		L->array[pos] = item;
		L->size++;
	}
}

element delete(ArrayListType *L, int pos)
{
	element item;
	int i;

	if (pos < 0 || pos >= L->size)
		printf("위치 오류");
	item = L->array[pos];
	for (i = pos; i < (L->size - 1); i++)
		L->array[i] = L->array[i + 1];
	L->size--;
	return item;
}

void clear(ArrayListType *L)//리스트를 비운다.
{
	init(L);
}

void insert_first(ArrayListType *L, element item)//item을 리스트의 첫번째 항목에 추가한다.
{
	int i;
	if( L->size >= MAX_LIST_SIZE ) 
		printf("리스트 오버플로우\n");
	else
	{
		for(i = L->size - 1; i >= 0; i--)
		{
			L->array[i + 1] = L->array[i];
		}
		L->array[0] = item;
		L->size++;
	}
	
}

int get_length(ArrayListType *L)//리스트의 항목수를 반환한다.
{
	return L->size;
}

void replace(ArrayListType *L, int pos, element item)
{
	L->array[pos] = item;
}

int is_in_list(ArrayListType *L, element item)
{
	int i;
	for(i = 0; i < L->size; i++)
	{
		if(L->array[i] == item)
			return 1;
	}
	return 0;
}

void delete_by_key(ArrayListType *L, element key)
{
	int i;
	for(i = 0; i < L->size; i++)
	{
		if(L->array[i] == key)
		{
			delete(L, i);
			return;
		}
	}
	printf("삭제하려는 key값 %d은 리스트에 없습니다.\n", key);
}

int main(void)
{
	ArrayListType list1;

	init(&list1);
	insert(&list1, 0, 20);
	insert(&list1, 0, 10);
	print_list(&list1);
	clear(&list1);
	print_list(&list1);

	insert_last(&list1, 90);
	print_list(&list1);
	
	insert(&list1, 0, 30);
	insert(&list1, 0, 20);
	insert(&list1, 0, 10);
	print_list(&list1);

	delete(&list1, 2);
	print_list(&list1);

	printf("\n-이 이후는 HW1_1에서 추가한 함수들 테스트-\n");
	insert_first(&list1, 9);
	print_list(&list1);
	insert_last(&list1, 99);
	print_list(&list1);

	insert_first(&list1, 1);
	print_list(&list1);

	printf("길이는 %d\n", get_length(&list1));
	printf("3번째 데이터는 %d\n", get_entry(&list1, 2));

	replace(&list1, 3, 40);
	print_list(&list1);
	printf("20은 리스트에 %s\n", is_in_list(&list1, 20) ? "있습니다" : "없습니다");
	printf("22는 리스트에 %s\n", is_in_list(&list1, 22) ? "있습니다" : "없습니다");

	delete_by_key(&list1, 20);
	print_list(&list1);
	delete_by_key(&list1, 22);
	print_list(&list1);

}