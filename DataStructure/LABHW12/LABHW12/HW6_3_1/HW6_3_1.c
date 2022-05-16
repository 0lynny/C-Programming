//HW6_3_1 20191023 최영린 컴퓨터학과 2학년
#include <stdio.h>
#include "minheap.h"
#include "unionfind.h"

#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType {
   int n;               // 정점의 개수
   int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// 그래프 초기화 
void graph_init(GraphType *g)
{
     // 구현
   int r, c;
   g->n = 0;
   for (r = 0; r < MAX_VERTICES; r++)
      for (c = 0; c < MAX_VERTICES; c++)
         g->adj_mat[r][c] = INF;
}

/*  */
void read_graph(GraphType *g, char *filename)
{
     // 구현
   int n, u, v, c;
   FILE *fp = fopen(filename, "r");
   if (fp == NULL) {
      printf("file %s open error!\n", filename);
      return;
   }
   fscanf(fp, "%d \n", &n);
   g->n = n;
   while (!feof(fp)) {
      fscanf(fp, "%d %d %d\n", &u, &v, &c);
      g->adj_mat[u][v] = c;
      g->adj_mat[u][v] = c;
   }
   fclose(fp);
}

/*  */
void write_graph(GraphType *g, char *filename)
{
     // 구현
   int i, j;
   FILE *fp;
   if (filename == NULL)
      fp = stdout;
   else
   {
      fp = fopen(filename, "w");
      if (fp == NULL)
      {
         printf("file %s open error!\n", filename);
         return;
      }
   }
   fprintf(fp, "%d\n", g->n);
   for (i = 0; i < g->n; i++)
      for (j = i; j < g->n; j++)
         if (g->adj_mat[i][j] != INF)
            fprintf(fp, "%d %d %d\n", i, j, g->adj_mat[i][j]);
   printf("\n");
   if (filename != NULL)
      fclose(fp);
}

// 인접 행렬이나 인접 리스트에서 간선들을 읽어서 최소 히프에 삽입 
// 현재는 예제 그래프의 간선들을 삽입한다.
void insert_all_edges(HeapType *h, GraphType *g)
{
     // 구현
   int i, j;
   element e;
   for (i = 0; i < g->n; i++)
      for (j = i; j < g->n; j++)
         if (g->adj_mat[i][j] != INF)
         {
            e.key = g->adj_mat[i][j];
            e.u = i;
            e.v = j;
            insert_min_heap(h, e);
         }
}

// kruskal의 최소 비용 신장 트리 프로그램
void kruskal(GraphType *g, GraphType *t)
{
     // 구현
   int edge_accepted = 0;
   HeapType h;
   int uset, vset;
   element e;
   int n = g->n;

   init(&h);
   insert_all_edges(&h, g);
   set_init(n);
   printf("선택된 간선<순서대로>\n");
   while (edge_accepted < (n - 1))
   {
      e = delete_min_heap(&h);
      uset = set_find(e.u);
      vset = set_find(e.v);

      if (uset != vset) 
      {
         printf("(%d, %d) %d\n", e.u, e.v, e.key);
         edge_accepted++;
         set_union(uset, vset);
         t->adj_mat[e.u][e.v] = e.key;
         t->adj_mat[e.v][e.u] = e.key;
      }
   }
}

int main(void)
{
   GraphType g, t;      // 입력 그래프, 결과 트리
   
   graph_init(&g);
   //read_graph(&g, "input1.txt");
   read_graph(&g, "input.txt");

   graph_init(&t);
   t.n = g.n;
   
   kruskal(&g, &t);
   
   printf("\n파일로 출력:\n");
   write_graph(&t, "output.txt");   
   write_graph(&t, NULL);   // to stdout
}