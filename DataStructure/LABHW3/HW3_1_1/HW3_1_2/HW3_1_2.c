//HW3_1_1 20191023 최영린 컴퓨터학과 2학년
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

// 초기화 함수
void init(QueueType* q)
{
   q->front = q->rear = 0;
}
// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
   return (q->front == q->rear);
}
// 포화 상태 검출 함수
int is_full(QueueType* q)
{
   return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// 삽입 함수
void enqueue(QueueType* q, element item)
{
   if (is_full(q)) {
      //fprintf(stderr, "아직 대상자가 없습니다. 다음기회를 이용.\n");
      return;
   }
   else{
      q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	  strcpy(q->queue[q->rear].name, item.name);
   }
}
// 삭제 함수
element dequeue(QueueType* q)
{
   if (is_empty(q)) {
      fprintf(stderr, "큐가 공백상태입니다.\n");
      exit(1);
   }
   q->front = (q->front + 1) % MAX_QUEUE_SIZE;
   return q->queue[q->front];
}

element peek(QueueType* q) {
   if (is_empty(q))
      printf("큐가 공백입니다.\n");
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

   printf("미팅 주선 프로그램입니다.\n");
   do
   {
      fflush(stdin);
      printf("i<nsert, 고객입력>, c<heck, 대기자 체크>, q<uit>: ");
      scanf("%c", &answer);

      if (answer == 'q')
      {
         break;
      }

      if (answer == 'i')
      {
         printf("이름을 입력: ");
         scanf("%s", newPerson.name);
         fflush(stdin);
         printf("성별을 입력(m or f): ");
         scanf(" %c", &gender);

         if (gender == 'm')
         {
            if(!is_full(&manQ))
            {
               enqueue(&manQ, newPerson);
               if (is_empty(&womanQ))
               {
                  printf("아직 대상자가 없습니다. 기다려주십시오. \n");
               }
               else
               {
                  printf("커플이 탄생했습니다!%s과 %s\n", dequeue(&womanQ).name, dequeue(&manQ).name);
               }
            }
            else
               printf("아직 대상자가 없습니다. 대기자가 꽉찼으니 다음을 이용..\n");
         }
         else if (gender == 'f')
         {
            if(!is_full(&womanQ))
            {
               enqueue(&womanQ, newPerson);
               if (is_empty(&manQ))
               {
                  printf("아직 대상자가 없습니다. 기다려주십시오. \n");
               }
               else
               {
                  printf("커플이 탄생했습니다!%s과 %s\n", dequeue(&womanQ).name, dequeue(&manQ).name);
               }
            }
            else
               printf("아직 대상자가 없습니다. 대기자가 꽉찼으니 다음을 이용..\n");
         }
         else;

      }
      else if (answer == 'c')
      {
         printf("남성대기자 %d명: ", get_count(&manQ));
         print_queue(&manQ);
         printf("여성대기자 %d명: ", get_count(&womanQ));
         print_queue(&womanQ);
      }
      else;
   } while (answer != 'q');

}