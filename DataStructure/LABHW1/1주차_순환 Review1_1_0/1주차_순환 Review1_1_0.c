//1����_��ȯ Review1_1_0 20191023 �ֿ��� ��ǻ���а� 2�г�
#include <stdio.h>
#include <string.h>
void print_reverse(char *str, int end) 
{
	printf("%c", str[end]);
	if(end == 0)
		return;
	else
		print_reverse(str, end - 1);
}
int main(void) 
{
	char str[100];

	printf("Enter any string: ");
	scanf("%s", str);

	printf("Reversed String is: ");
	print_reverse(str, strlen(str) - 1);
	printf("\n");
	return 0;
}

