//1주차_순환 Review1_1_2 20191023 최영린 컴퓨터학과 2학년
#include<stdio.h>
#include<string.h>
//방법 1)
/*
void reverse_string(char *str, int s, int e)
{
	int i;
	char temp;

	for(i = 0; i < e / 2; i++)
	{
		temp = str[e - i];
		str[e - i] = str[i];
		str[i] = temp;
	}
	
}*/

//방법 2
void reverse_string(char *str, int s, int e)
{
	char temp;

	while(s < e)
	{
		temp = str[e];
		str[e] = str[s];
		str[s] = temp;
		s++;
		e--;
	}
}
int main()
{
	char str[100];

	printf("Enter any string: ");
	scanf("%s", str);

	reverse_string(str, 0, strlen(str) - 1);
	printf("\nReversed String is:  %s\n", str);
	return 0;
}