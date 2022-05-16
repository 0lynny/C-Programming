//HW 4_1 20191023 �ֿ��� ��ǻ���а� 2�г�
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define TRUE 1
#define FALSE 0
#define MAX_TREE_SIZE 20

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;

	TreeNode n1 = {15, NULL, NULL};
	TreeNode n2 = {4, &n1, NULL};
	TreeNode n3 = {16, NULL, NULL};
	TreeNode n4 = {25, NULL, NULL};
	TreeNode n5 = {15, &n3, &n4};
	TreeNode n6 = {15, &n2, &n5};
	TreeNode *root = &n6;

	TreeNode m1 = {15, NULL, NULL};
	TreeNode m2 = {4, &n1, NULL};
	TreeNode m3 = {16, NULL, NULL};
	TreeNode m7 = {28, NULL, NULL}; // �߰�
	TreeNode m4 = {25, NULL, &m7}; // ����
	TreeNode m5 = {15, &m3, &m4};
	TreeNode m6 = {15, &m2, &m5};
	TreeNode *root2 = &m6;

//p281 Quiz 01
int get_nonleaf_count(TreeNode *t) 
{
	if (t == NULL)
      return 0;
   else if (t->left == NULL && t->right == NULL)
      return 0;
   else
      return get_nonleaf_count(t->left) + get_nonleaf_count(t->right) + 1;

}
//p308 #25
int get_oneleaf_count(TreeNode *node) 
{
	if (node == NULL)
      return 0;
   else if (node->left == NULL&& node->right == NULL)
      return 0;
   else if (node->left == NULL&& node->right != NULL)
      return 1 + get_oneleaf_count(node->right);
   else if (node->left != NULL&& node->right == NULL)
      return 1 + get_oneleaf_count(node->left);
   else
      return get_oneleaf_count(node->left) + get_oneleaf_count(node->right);
}
//p308 #26
int get_twoleaf_count(TreeNode *node) 
{
	if (node == NULL)
       return 0;
    else if (node->left == NULL && node->right == NULL)
       return 0;
    else if (node->left == NULL && node->right != NULL)
       return get_twoleaf_count(node->right);
    else if (node->left != NULL && node->right == NULL)
       return get_twoleaf_count(node->left);
	else
		return get_twoleaf_count(node->right) + get_twoleaf_count(node->left) + 1;
}
//p308 #27
int get_max(TreeNode *node) 
{
	/*
	if(node == NULL)
		return INT_MIN;
	else
		return max(max(node->data, get_max(node->left)), get_max(node->right));
	*/
	int max = INT_MIN;
    int left, right, root_data;

   if (node != NULL)
   {
      root_data = node->data;
      left = get_max(node->left);
      right = get_max(node->right);

      if (left > right)
         max = left;
      else
         max = right;

      if (root_data > max)
         max = root_data;
   }
   return max;

}
int get_min(TreeNode *node) 
{
	/*
	if(node == NULL)
		return INT_MAX;
	else
		return min(min(node->data, get_min(node->left)), get_min(node->right));
	*/
	int min = INT_MAX;
    int left, right, root_data;

   if (node != NULL)
   {
      root_data = node->data;
      left = get_min(node->left);
      right = get_min(node->right);

      if (left < right)
         min = left;
      else
         min = right;

      if (root_data < min)
         min = root_data;
   }
   return min;

}
//p308 #30
void node_increase(TreeNode *node) 
{
	if (node == NULL)
		return;
	else
	{
		node->data++;
		node_increase(node->right);
		node_increase(node->left);
	}
}
//p281 Quiz 02
int equal(TreeNode *t1, TreeNode *t2) 
{
	if(t1 == NULL || t2 == NULL)//�Ѵ� ����Ʈ���� ������
        return TRUE;
	else if((t1 == NULL && t2 != NULL) || (t1 != NULL && t2 == NULL))//���ʸ� ����Ʈ���� ������(��, ������ �ٸ���)
		return FALSE;
	else
		if(t1->data != t2->data) 
			return FALSE;
		else
			return equal(t1->left, t2->left) && equal(t1->right, t2->right);
}
TreeNode *copy(TreeNode * t)
{
	TreeNode *clone =  (TreeNode *)malloc(sizeof(TreeNode));
	if(t == NULL) 
	{
        clone = NULL;
	}
	else
	{
		clone->left = copy(t->left);
		clone->right = copy(t->right);
		clone->data = t->data;
	}
	return clone;
}
void preorder(TreeNode *root) // p271 �ڵ� ����
{
	 if (root) {
      printf("%d ", root->data);
      preorder(root->left);
      preorder(root->right);
   }
}
int main(void)
{
	TreeNode *result[MAX_TREE_SIZE];
	TreeNode *clone;
	int i, num;

	printf("��)\n");
	printf("Ʈ�� root �� ��ܸ������ ������ %d.\n", get_nonleaf_count(root));
	printf("Ʈ�� root2 �� ��ܸ������ ������ %d.\n", get_nonleaf_count(root2));

	printf("Ʈ�� root �� �ڽ��� �ϳ��� �ִ� ����� ������ %d.\n", get_oneleaf_count(root));
	printf("Ʈ�� root2 �� �ڽ��� �ϳ��� �ִ� ����� ������ %d.\n", get_oneleaf_count(root2));

	printf("Ʈ�� root �� �ڽ��� ���� �ִ� ����� ������ %d.\n", get_twoleaf_count(root));
	printf("Ʈ�� root2 �� �ڽ��� ���� �ִ� ����� ������ %d.\n", get_twoleaf_count(root2));

	printf("Ʈ�� root ���� ���� ū ���� %d.\n", get_max(root));
	printf("Ʈ�� root2 ���� ���� ū ���� %d.\n", get_max(root2));

	printf("Ʈ�� root ���� ���� ���� ���� %d.\n", get_min(root));
	printf("Ʈ�� root2 ���� ���� ���� ���� %d.\n", get_min(root2));
	/*
	printf("\n ��)\n");
	num = search(root, 15, result);
	for (i = 0; i < num; i++)
	printf("(0x%p, %d), ", result[i], result[i]->data);
	printf("\n");
	*/

	printf("\n��)\n");
	preorder(root);
	node_increase(root);
	printf("\n");
	preorder(root);
	printf("\n");
	printf("%s\n", equal(root, root) ? "����": "�ٸ���");
	printf("%s\n", equal(root2, root2) ? "����": "�ٸ���");
	printf("%s\n", equal(root, root2) ? "����": "�ٸ���");

	printf("\n��)\n");
	clone = copy(root) ;
	preorder(root) ;
	printf("\n");
	preorder(clone) ;
	printf("\n");
} 