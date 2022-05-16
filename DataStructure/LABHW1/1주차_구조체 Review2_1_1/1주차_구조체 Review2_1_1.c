//1주차_구조체 Review2_1_1 20191023 최영린 컴퓨터학과 2학년
#include <stdio.h>
#include <stdlib.h>
//1) typedef으로 Score를 정의
typedef struct{
	int midterm;
	int final;
}Score;
void printScore(Score * p) 
{
	printf("중간고사 성적은 %d\n", p->midterm);
	printf("학기말고사 성적은 %d\n", p->final);
} 
Score *biggerScore(Score *p1, Score *p2) 
{
	return (p1->midterm + p1->final > p2->midterm + p2->final) ?  p1 : p2;
}  
Score *totalScore(Score *p1, Score *p2) 
{
	Score *total;
	total = (Score *)malloc(sizeof(Score));

	total->midterm = p1->midterm + p2->midterm;
	total->final = p1->final + p2->final;

	return total;

} 
Score *createScore(int m, int f) 
{
	Score *temp;
	temp = (Score *)malloc(sizeof(Score));

	temp->midterm = m;
	temp->final = f;

	return temp;
} 
int main(void) 
{
	Score *p1, *p2, *p3;

	//1) p1, p2를 각각 메모리 할당을 한 후 // 가리키는 변수에 값 대입
	p1 = (Score *)malloc(sizeof(Score));
	p2 = (Score *)malloc(sizeof(Score));

	p1->midterm = 100;
	p1->final = 50;
	p2->midterm = 70;
	p2->final = 70;

	printScore(p1); 
	printScore(p2);

	printf("-----------------------------\n"); 
	printf("둘중 성적이 좋은 점수:\n"); 
	printScore(biggerScore(p1, p2));

	printf("-----------------------------\n"); 
	printf("두 성적의 총 합:\n"); 
	printScore(totalScore(p1, p2));

	printf("-----------------------------\n"); 
	p3 = createScore(100, 100);
	printScore(p3);

	printf("%d", 2 % 12); 
}