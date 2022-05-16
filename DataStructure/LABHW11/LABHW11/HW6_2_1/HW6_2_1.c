#include <stdio.h>

#define MAX_VERTICES 50

typedef struct GraphType {
     int n;
     int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES] = {0};

// �׷��� �ʱ�ȭ 
void graph_init(GraphType *g)
{
	int r,c;
	g->n=0;
	for(r=0;r<MAX_VERTICES;r++)
		for(c=0;c<MAX_VERTICES;c++)
			g->adj_mat[r][c]=0;
}

//
void read_graph(GraphType *g, char *filename)
{
     // ���� �����ڵ忡��
	int number, u, v;
     FILE *fp;
     fp = fopen(filename, "rt");
	if (fp == NULL) 
	{
		printf("file %s open error!\n", filename);
		return;
	}
    fscanf(fp, "%d", &number);
	while(fscanf(fp, "%d %d", &u, &v) != EOF){
		g->adj_mat[u][v] = 1;
		g->adj_mat[v][u] = 1;
	}

    fclose(fp);
}

// �� �Լ��� ������ ����ϱ����� �ڵ带 �����ϴ� ���� HW6_2_1�� �䱸�̴�
void dfs_mat(GraphType* g, int v)
{
   int w;
   visited[v] = 1;
   for (w = 0; w < g->n; w++) {
      if ((g->adj_mat[v][w] == 1) && (visited[w] == 0)) { // u�� ������ �����̰� u�� ���� �湮���� �ʾ�����
         printf("<%d %d>\n", v, w);
         dfs_mat(g, w);
      }
   }
}
int main(void)
{
     GraphType graph;
     int u, v;

     graph_init(&graph);
     read_graph(&graph, "infile.txt");
     //read_graph(&graph, "infile2.txt");
     
     printf("Enter ����:");
     scanf("%d", &v);
     
     dfs_mat(&graph, v);
}