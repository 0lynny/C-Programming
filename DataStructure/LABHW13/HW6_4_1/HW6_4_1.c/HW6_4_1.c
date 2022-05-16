#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000 /* 무한대 (연결이 없는 경우) */

typedef struct GraphType {
   int n;               // 정점의 개수
   int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES];/* 시작정점으로부터의 최단경로 거리 */
int found[MAX_VERTICES]; /* 방문한 정점 표시 */
int previous[MAX_VERTICES];

// 그래프 초기화 
void graph_init(GraphType *g)
{
     // 구현
   int r, c;
   g->n = 0;
   for (r = 0; r < MAX_VERTICES; r++)
      for (c = 0; c < MAX_VERTICES; c++)
         g->weight[r][c] = INF;
}

/*  */
void read_graph(GraphType *g, char *filename)
{
     // 구현
   int n, u, v, c;
   FILE *fp = fopen(filename, "r");
   if (fp == NULL) {
      fprintf(stderr, "파일 %s을 열 수 없음!\n", filename);
      return;
   }
   fscanf(fp, "%d \n", &n);
   g->n = n;
   while (!feof(fp)) {
      fscanf(fp, "%d %d %d\n", &u, &v, &c);
      g->weight[u][v] = c;
     g->weight[v][u] = c;
   }
   fclose(fp);
}
int choose(int distance[], int n, int found[])
{
   int i, min, minpos;
    min = INT_MAX;
    minpos = -1;

    for(i = 0;i < n;i++)
       if(distance[i] < min && ! found[i] ){
            min = distance[i];
            minpos=i;
       }
    return minpos;
}

void print_allVertex(int start, int u)
{
	if(u == start)
	{
		printf("%d", start);
	}
	else
	{
		print_allVertex(start, previous[u]);
		printf(" -> %d", u);
	}

}

void shortest_path(GraphType *g, int start)
{
   int i, j, u, w, temp;
   for (i = 0; i < g->n; i++)
   {
      distance[i] = g->weight[start][i];
      found[i] = FALSE;
      previous[i] = start;
   }
   found[start] = TRUE;
   distance[start] = 0;
   previous[start] = -1;
   for (i = 0; i < g->n-1; i++)
   {
      u = choose(distance, g->n, found);  
      found[u] = TRUE;  
      for (w = 0; w < g->n; w++)
         if (!found[w])
            if (distance[u] + g->weight[u][w] < distance[w])
            {
               distance[w] = distance[u] + g->weight[u][w];
			   previous[w] = u;
            }
   print_allVertex(start, u);
   printf(" <%d>\n", distance[u]);
   }

}
int main(void)
{
   GraphType g;         
   graph_init(&g);
   read_graph(&g, "input.txt");

   shortest_path(&g, 3);
}