//1����_��ȯ Review1_1_1 20191023 �ֿ��� ��ǻ���а� 2�г�
#include<stdio.h>
#include<string.h>
void reverse_string(char *str, int s, int e)
{
	char temp;
	if(s >= e)
		return;
	else
	{
		temp = str[e];
		str[e] = str[s];
		str[s] = temp;
		reverse_string(str, s + 1, e - 1);
	}

}
int main()
{
	char str[100];

	printf("Enter any string: ");
	scanf("%s", str);

	reverse_string(str, 0, strlen(str) - 1);
	printf("Reversed String is:  %s\n", str);
	return 0;
}