//1����_��ȯ Review1_1_2 20191023 �ֿ��� ��ǻ���а� 2�г�
#include<stdio.h>
#include<string.h>
//��� 1)
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

//��� 2
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