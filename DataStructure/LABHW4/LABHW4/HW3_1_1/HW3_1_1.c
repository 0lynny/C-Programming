//HW3_1_1(������) 20191023 �ֿ��� ��ǻ���а� 2�г�
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 3 //3���� ����
#define MAX_STRING 100 // �߰�

typedef struct { //����
     char name[MAX_STRING];
} element; 

typedef struct {
	element  queue[MAX_QUEUE_SIZE]; 
	int  front, rear;
} QueueType; 
//
void error(char *message)
{
	fprintf(stderr,"%s\n",message);
	exit(1);
}
// �ʱ�ȭ �Լ�
void init(QueueType *q)
{
	q->front = q->rear = 0;
}
// ���� ���� ���� �Լ�
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}
// ��ȭ ���� ���� �Լ�
int is_full(QueueType *q)
{
	return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}
// ���� �Լ�
void enqueue(QueueType *q, element item)
{ 
  	if( is_full(q) ) 
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}
// ���� �Լ�
element dequeue(QueueType *q) 
{ 
   	if( is_empty(q) )
		error("ť�� ��������Դϴ�");
	q->front = (q->front+1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
} 
// ���� �Լ�
element peek(QueueType *q) 
{ 
   	if( is_empty(q) )
		error("ť�� ��������Դϴ�");
	return q->queue[(q->front+1) % MAX_QUEUE_SIZE];
} 

int get_count(QueueType *q)
{
    int count = q->rear - q->front;
	if( count < 0 ) 
		count += MAX_QUEUE_SIZE;
	return count;
}

void print_queue(QueueType *q)
{
    int i;
   if(!is_empty(q))
   {
      i = q->front;
      do{
         i = (i + 1) % MAX_QUEUE_SIZE;
         printf("%s " , q->queue[i].name);
         if(i == q->rear)
            break;
      }while(i != q->front);
   }
   printf("\n");
}

void try_match(element name, QueueType *partnerQ, QueueType *myQ) //�߰� �κ�: �� ���� �Լ� �̸�??
{
	 if(!is_full(myQ))
     {
		 enqueue(myQ, name);
         if (is_empty(partnerQ))
         {
			printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�. \n");
         }
         else
         {
            printf("Ŀ���� ź���߽��ϴ�!%s�� %s\n", dequeue(myQ).name, dequeue(partnerQ).name);
         }
      }
      else
          printf("���� ����ڰ� �����ϴ�. ����ڰ� ��á���� ������ �̿�..\n");
}

int main(void)
{
     QueueType manQ, womanQ;
     char choice;
     element name[MAX_STRING];
     char gender;

     init(&manQ);
     init(&womanQ);

     printf("���� �ּ� ���α׷��Դϴ�.\n");
     
     printf("i(nsert, ���Է�), c(heck, ����� üũ), q(uit):");
     scanf("%c", &choice);
 
     while (choice != 'q') {
          switch(choice) {
          case 'i':
               printf("�̸��� �Է�:");
               scanf("%s", name);
               fflush(stdin);
               printf("������ �Է�(m or f):");
               scanf("%c", &gender);
               if (gender == 'm') 
                    try_match(*name, &womanQ, &manQ);
               else
                    try_match(*name, &manQ, &womanQ);
               break;
          case 'c':
               printf("���� ����� %d��: ", get_count(&manQ));
               print_queue(&manQ);
               printf("���� ����� %d��: ", get_count(&womanQ));
               print_queue(&womanQ);
          } 
          fflush(stdin);
          printf("i(nsert, ���Է�), c(heck, ����� üũ), q(uit):");
          scanf("%c", &choice);          
     }
}