//HW4_3_0 20191023 �ֿ��� ��ǻ���а� 2�г�
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define TRUE 1
#define FALSE 0
#define MAX_STRING 100
typedef struct {
	int id;
	char name[MAX_STRING];
	char tel[MAX_STRING];
	char dept[MAX_STRING];
}element;

typedef struct TreeNode{
	element data;
	struct TreeNode *left, *right;
}TreeNode;

TreeNode* new_node(element item)
{
	TreeNode* temp = (TreeNode *)malloc(sizeof(TreeNode));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(TreeNode * root) 
{
	if (root) {
		inorder(root->left);// ���ʼ���Ʈ�� ��ȸ
		printf("----------------------------------------------\n");
		printf("�й�: %d\n�̸�: %s\n��ȭ��ȣ: %s\n�а�: %s\n", 
			root->data.id,root->data.name, root->data.tel, root->data.dept);  // ��� �湮
		inorder(root->right);// �����ʼ���Ʈ�� ��ȸ
	}
}

TreeNode * search(TreeNode * node, element key)
{
	if (node == NULL) return NULL;
	if (key.id == node->data.id) return node;
	else if (key.id < node->data.id)
		return search(node->left, key);
	else
		return search(node->right, key);
}

TreeNode * insert_node(TreeNode * root, element key)
{
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�. 
	if (root == NULL) return new_node(key);

	// �׷��� ������ ��ȯ������ Ʈ���� ��������. 
	if (key.id < root->data.id)
		root->left = insert_node(root->left, key);
	else if (key.id > root->data.id)
		root->right = insert_node(root->right, key);

	// ����� ��Ʈ �����͸� ��ȯ�Ѵ�. 
	return root;
}

TreeNode * min_value_node(TreeNode * node)
{
	TreeNode * current = node;

	// �� ���� �ܸ� ��带 ã���� ������
	while (current->left != NULL)
		current = current->left;

	return current;
}
 
TreeNode * delete_node(TreeNode * root, element key)
{
	TreeNode * temp;
	if (root == NULL) return root;

	// ���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ����
	if (key.id < root->data.id)
		root->left = delete_node(root->left, key);
	// ���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ����
	else if (key.id > root->data.id)
		root->right = delete_node(root->right, key);
	// Ű�� ��Ʈ�� ������ �� ��带 �����ϸ� ��
	else {
		// ù ��°�� �� ��° ���
		if (root->left == NULL) {
			temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			temp = root->left;
			free(root);
			return temp;
		}
		// �� ��° ���
		temp = min_value_node(root->right);

		// �߿� ��ȸ�� �İ� ��带 �����Ѵ�. 
		root->data = temp->data;
		// �߿� ��ȸ�� �İ� ��带 �����Ѵ�. 
		root->right = delete_node(root->right, temp->data);
	}
	return root;
}

int get_node_count(TreeNode *node)
{
	int count = 0;
	if(node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	return count;
}

void print_searchRslt(TreeNode * root, element key) 
{
	if(key.id == root->data.id)
	{
		printf("----------------------------------------------\n");
		printf("�й�: %d\n�̸�: %s\n��ȭ��ȣ: %s\n�а�: %s\n", 
			root->data.id,root->data.name, root->data.tel, root->data.dept);  // ��� �湮
	}
	else
		printf("id�� %d�� �л��� �����ϴ�.\n", key.id);

}

int main(void)
{
	TreeNode * root = NULL;
	TreeNode * tmp = NULL;
	element data;
	char choice;

	do{
		fflush(stdin);
		printf("Enter i<nsert>, d<elete>, s<earch>, p<rint>, c<ount>, q<uit>: ");
		scanf("%c", &choice);
		switch(choice)
		{
		case 'i':
			printf("�й� �Է�: ");
			scanf("%d", &data.id);
			printf("�̸� �Է�: ");
			scanf("%s", data.name);
			printf("��ȭ��ȣ �Է�: ");
			scanf("%s", data.tel);
			printf("�а� �Է�: ");
			scanf("%s", data.dept);
			root = insert_node(root, data);
			break;
		case 'd':
			printf("������ �й� �Է�: ");
			scanf("%d", &data.id);
			root = delete_node(root, data);
			break;
		case 's':
			printf("Ž���� �й� �Է�: ");
			scanf("%d", &data.id);
			print_searchRslt(root, data);
			break;
		case 'p':
			printf("�л� ���� �й� �� ���\n");
			inorder(root);
			printf("\n");
			break;
		case 'c':
			printf("���� ����� �л��� �� ���� %d\n", get_node_count(root));
			break;
		case 'q':
			break;
		}
	}
	while(choice != 'q');
}
