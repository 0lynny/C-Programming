//1주차_순환연습2 20191023 최영린 컴퓨터학과 2학년
#include <stdio.h>
void print_fact_exp(int n) 
{
	
	if (n > 1){
		printf("%d *  ", n);
		print_fact_exp(n - 1); 
	}
	else
		printf("1");
}
int main(void)
{
	int n;
	printf("Enter a number:"); 
	scanf("%d", &n);

	printf("%d! = ", n); 
	print_fact_exp(n); 
	printf("\n");
}