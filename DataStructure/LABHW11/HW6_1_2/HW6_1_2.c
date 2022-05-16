//HW6_1_2 20191023 최영린 컴퓨터학과 2학년
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef int element;
typedef struct GraphNode
{  
   int vertex;
   struct GraphNode *link;
} GraphNode;

typedef struct GraphType {
	int n;	// 정점의 개수
	GraphNode *adj_list[MAX_VERTICES];
} GraphType;

// 그래프 초기화 
void graph_init(GraphType *g)
{
	int v;
	g->n=0;
	for(v=0;v<MAX_VERTICES;v++)
		g->adj_list[v]=NULL;
}

// 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.
void insert_edge(GraphType *g, int u, int v)
{
	GraphNode *node, *node1;
	if(u >=g->n || v >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;

	node1 = (GraphNode*)malloc(sizeof(GraphNode));
	node1->vertex = u;
	node1->link = g->adj_list[v];
	g->adj_list[v] = node1;
}

void remove_node(GraphNode **phead, element item) { // 4장 리스트에서 학습한 함수에서 ListNode --> GraphNode로 변경했음
     GraphNode *p, *prevp;
     
     if (*phead == NULL)
          printf("리스트는 비어있습니다.\n");
     else if ((*phead)->vertex == item) {
          p = *phead;
          *phead = (*phead)->link;
          free(p);
     }
     else {
          p = *phead;
          do {
               prevp = p;
               p = p->link;
          }while (p != NULL && p->vertex != item);
          if (p != NULL) {
               prevp->link = p->link;
               free(p);
          }
          else
               printf("%d은 리스트에 없음\n", item);
     }
}
// 간선 삭제 연산, v를 u의 인접 리스트에서 삭제한다.
void delete_edge(GraphType *g, int u, int v)
{
	GraphNode *node, *removed;
	if( u >= g->n || v >= g->n ){
		fprintf(stderr, "그래프: 정점 번호 오류");		
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	removed = (GraphNode*)malloc(sizeof(GraphNode));
     // 코드 삽입
     // (u, v)를 삭제한다. remove_node를 사용

	if(node != NULL){
		if(g->adj_list[u]!=node){
			GraphNode *temp = g->adj_list[u];
			while(temp->link != node)
				temp = temp->link;
			temp->link = node->link;
		}
		else{
			g->adj_list[u] = node->link;
		}
		free(node);
	}


}

void read_graph(GraphType *g, char *filename)
{
    int number, u, v;
	FILE* fp;
	fp = fopen(filename, "rt");
	if (fp == NULL)
	{
		printf("file %s open error!\n", filename);
		return;
	}

	fscanf(fp, "%d\n", &number);
	g->n = number;

	while (fscanf(fp, "%d %d\n", &u, &v) != EOF) {
		insert_edge(g, u, v);
	}
	fclose(fp);
}          


void write_graph(GraphType *g, char *filename)
{
     int u;
     FILE *fp;
     GraphNode *ptr;
     
     if (filename == NULL) fp = stdout;
     else {
          fp = fopen(filename, "w");
	     if (fp == NULL) 
	     {
		     printf("file %s open error!\n", filename);
	          return;
	     }
     }

     // 코드 삽입
	 fprintf(fp, "%d\n", g->n);
	 for(u = 0;u < g->n;u++){
		ptr = g->adj_list[u];
		while(ptr != NULL){
			if(u < ptr->vertex)
				fprintf(fp, "%d %d\n", u, ptr->vertex);
			ptr = ptr->link;
		}
	}
     if (filename != NULL) fclose(fp);
	 printf("\n");
}

int main(void)
{
	GraphType g;
	graph_init(&g);

	read_graph(&g, "input.txt");
	write_graph(&g, NULL);	// to stdout

	insert_edge(&g, 1, 3);
	write_graph(&g, NULL);	// to stdout

	delete_edge(&g, 2, 0);
	write_graph(&g, NULL);	// to stdout

	write_graph(&g, "output.txt");
}
