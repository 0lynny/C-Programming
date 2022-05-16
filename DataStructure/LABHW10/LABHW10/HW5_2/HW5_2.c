//HW5_2 20191023 �ֿ��� ��ǻ���а� 2�г�
/*
read_heap(HeapType *h, char *filename) - ���Ͽ��� �о max Heap �� �����Ѵ�.
write_heap_array(HeapType *h, char *filename) - max Heap �� ����� ������ �迭�� ǥ�� �״�� ���Ͽ�
����Ѵ�.
write_descending_order(HeapType *h, char *filename) - max Heap �� ����� ������ ������������ ���Ͽ�
����Ѵ�. 
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;


// ���� �Լ�
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}
// �ʱ�ȭ �Լ�
void init(HeapType* h)
{
	h->heap_size = 0;
}
// ���� ����� ������ heap_size�� ���� h�� item�� �����Ѵ�.
// ���� �Լ�
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // ���ο� ��带 ����
}
// ���� �Լ�
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ�� �� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		// �� �ܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void read_heap(HeapType *h, char *filename)
{
   // �ʿ��� ����
   int n;
   element new_;
   FILE *fp = fopen(filename, "r");
   if (fp == NULL) {
      fprintf(stderr, "���� %s�� �� �� ����!\n", filename); return;
   }
   // ����: while (fscanf(fp, "%d\n", &n) != EOF) {...} �� ����Ѵ�.
   while (fscanf(fp, "%d\n", &n) != EOF)
   {
      new_.key = n;
      insert_max_heap(h, new_);
   }
   fclose(fp); 
}

void write_heap_array(HeapType *h, char *filename)
{
   // �ʿ��� ����
   FILE *fp;
   int i;
   if (filename == NULL) fp = stdout;
   else 
      fp = fopen(filename, "w");
   // ����: fprintf(fp, "%d\n", ...)�� ����Ѵ�
   for (i = 1; i <= h->heap_size; i++)
      fprintf(fp, "%d\n", h->heap[i]);
}

int main(void)
{
	HeapType heap;
	element e1 = {20}, e2 = {40};
	init(&heap);
	read_heap(&heap, "input.txt");
	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);
	write_heap_array(&heap, "heapArray.txt");
	//write_descending_order(&heap, "sorted.txt");
}