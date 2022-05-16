//HW6_3_1 20191023 �ֿ��� ��ǻ���а� 2�г�
#include <stdio.h>
#include "minheap.h"
#include "unionfind.h"

#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType {
   int n;               // ������ ����
   int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// �׷��� �ʱ�ȭ 
void graph_init(GraphType *g)
{
     // ����
   int r, c;
   g->n = 0;
   for (r = 0; r < MAX_VERTICES; r++)
      for (c = 0; c < MAX_VERTICES; c++)
         g->adj_mat[r][c] = INF;
}

/*  */
void read_graph(GraphType *g, char *filename)
{
     // ����
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
     // ����
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

// ���� ����̳� ���� ����Ʈ���� �������� �о �ּ� ������ ���� 
// ����� ���� �׷����� �������� �����Ѵ�.
void insert_all_edges(HeapType *h, GraphType *g)
{
     // ����
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

// kruskal�� �ּ� ��� ���� Ʈ�� ���α׷�
void kruskal(GraphType *g, GraphType *t)
{
     // ����
   int edge_accepted = 0;
   HeapType h;
   int uset, vset;
   element e;
   int n = g->n;

   init(&h);
   insert_all_edges(&h, g);
   set_init(n);
   printf("���õ� ����<�������>\n");
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
   GraphType g, t;      // �Է� �׷���, ��� Ʈ��
   
   graph_init(&g);
   //read_graph(&g, "input1.txt");
   read_graph(&g, "input.txt");

   graph_init(&t);
   t.n = g.n;
   
   kruskal(&g, &t);
   
   printf("\n���Ϸ� ���:\n");
   write_graph(&t, "output.txt");   
   write_graph(&t, NULL);   // to stdout
}