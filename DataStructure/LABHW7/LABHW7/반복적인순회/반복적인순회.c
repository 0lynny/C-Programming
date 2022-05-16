//반복적인 순회 20191023 최영린 컴퓨터학과 2학년
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
   int data;
   struct TreeNode *left, *right;
} TreeNode;

typedef struct TreeNode* element;
typedef struct StackNode {
   element item;
   struct StackNode *link;
} StackNode;

typedef struct {
   StackNode *top;
} LinkedStackType;

void init(LinkedStackType *s)
{
   s->top = NULL;
}
// 공백 상태 검출 함수
int is_empty(LinkedStackType *s)
{
   return (s->top == NULL);
}
// 포화 상태 검출 함수
int is_full(LinkedStackType *s)
{
   return 0;
}

void push(LinkedStackType *s, element item)
{
   StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
   temp->item = item;
   temp->link = s->top;
   s->top = temp;
}
element pop(LinkedStackType *s)
{
   if (is_empty(s)) {
      fprintf(stderr, "스택이 비어있음\n");
      //exit(1);
   }
   else {
      StackNode* temp = s->top;
	  element item = temp->item;
	  s->top = s->top->link;
	  free(temp);
	  return item;
   }
}
element peek(LinkedStackType *s)
{
   if (is_empty(s)) {
      fprintf(stderr, "스택이 비어있음\n");
      exit(1);
   }
   else {
	   return s->top->item;
   }
}

void inorder_iter(TreeNode *root)
{
   LinkedStackType s;
   init(&s);
   while (1) 
   {
      for (; root; root = root->left)
         push(&s, root);
      if(is_empty(&s))
         break;
      else
         root = pop(&s);
	  printf("[%d] ", root->data);
      root = root->right;
   }
}
//     15 
//  4    20
// 1  16    25

int main(void)
{
   TreeNode n1 = { 1, NULL, NULL };
   TreeNode n2 = { 4, &n1, NULL };
   TreeNode n3 = { 16, NULL, NULL };
   TreeNode n4 = { 25, NULL, NULL };
   TreeNode n5 = { 20, &n3, &n4 };
   TreeNode n6 = { 15, &n2, &n5 };
   TreeNode *root = &n6;

   printf("중위 순회=");
   inorder_iter(root);
   printf("\n");
   return 0;
}