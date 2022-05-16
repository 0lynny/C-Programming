//1주차_순환 Review1_1_0 20191023 최영린 컴퓨터학과 2학년
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

