#include<stdio.h>
#include<string.h>
void stringChange(char *s, char ch, char newCh)
{
	int i;
	for(i = 0; s[i] != '\0'; i++)
		if(s[i] == ch)
			s[i] = newCh;
}
int main(void)
{
 char name [20];
 //printf("Enter a name: ");
 scanf("%s", name);
 stringChange(name, 'e', 'x');
 printf("%s\n", name);
}