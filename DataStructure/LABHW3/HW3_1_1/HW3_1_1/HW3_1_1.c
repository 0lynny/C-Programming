//HW3_1_1 20191023 �ֿ��� ��ǻ���а� 2�г�
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#define MAX_QUEUE_SIZE 3
#define MAX_STRING_SIZE 100

typedef struct{
	char name[MAX_STRING_SIZE];
}element;

typedef struct {
   element queue[MAX_QUEUE_SIZE];
   int  front, rear;
} QueueType;

// �ʱ�ȭ �Լ�
void init(QueueType* q)
{
   q->front = q->rear = 0;
}
// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
   return (q->front == q->rear);
}
// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
   return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// ���� �Լ�
void enqueue(QueueType* q, element item)
{
   if (is_full(q)) {
      //fprintf(stderr, "���� ����ڰ� �����ϴ�. ������ȸ�� �̿�.\n");
      return;
   }
   else{
      q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	  strcpy(q->queue[q->rear].name, item.name);
   }
}
// ���� �Լ�
element dequeue(QueueType* q)
{
   if (is_empty(q)) {
      fprintf(stderr, "ť�� ��������Դϴ�.\n");
      exit(1);
   }
   q->front = (q->front + 1) % MAX_QUEUE_SIZE;
   return q->queue[q->front];
}

element peek(QueueType* q) {
   if (is_empty(q))
      printf("ť�� �����Դϴ�.\n");
   return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];

}
int  get_count(QueueType* q) 
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

int main(void)
{
   QueueType manQ, womanQ;
   element newPerson;

   char answer, gender;
   init(&manQ);
   init(&womanQ);

   printf("���� �ּ� ���α׷��Դϴ�.\n");
   do
   {
      fflush(stdin);
      printf("i<nsert, ���Է�>, c<heck, ����� üũ>, q<uit>: ");
      scanf("%c", &answer);

      if (answer == 'q')
      {
         break;
      }

      if (answer == 'i')
      {
         printf("�̸��� �Է�: ");
         scanf("%s", newPerson.name);
         fflush(stdin);
         printf("������ �Է�(m or f): ");
         scanf(" %c", &gender);

         if (gender == 'm')
         {
            if(!is_full(&manQ))
            {
               enqueue(&manQ, newPerson);
               if (is_empty(&womanQ))
               {
                  printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�. \n");
               }
               else
               {
                  printf("Ŀ���� ź���߽��ϴ�!%s�� %s\n", dequeue(&womanQ).name, dequeue(&manQ).name);
               }
            }
            else
               printf("���� ����ڰ� �����ϴ�. ����ڰ� ��á���� ������ �̿�..\n");
         }
         else if (gender == 'f')
         {
            if(!is_full(&womanQ))
            {
               enqueue(&womanQ, newPerson);
               if (is_empty(&manQ))
               {
                  printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�. \n");
               }
               else
               {
                  printf("Ŀ���� ź���߽��ϴ�!%s�� %s\n", dequeue(&womanQ).name, dequeue(&manQ).name);
               }
            }
            else
               printf("���� ����ڰ� �����ϴ�. ����ڰ� ��á���� ������ �̿�..\n");
         }
         else;

      }
      else if (answer == 'c')
      {
         printf("��������� %d��: ", get_count(&manQ));
         print_queue(&manQ);
         printf("��������� %d��: ", get_count(&womanQ));
         print_queue(&womanQ);
      }
      else;
   } while (answer != 'q');

}