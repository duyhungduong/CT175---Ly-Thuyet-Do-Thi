#include <stdio.h>

#define max 100 // sos cung toi da

// cau truc cua do thi G
typedef struct{
	int n,m; // so dinh vaf so cung cua do thi
	int A[max][max];
}Graph;

// ham khoi tao do thi
void init_Graph(Graph *G, int n){
	G->n = n; // gan so dinh cho do thi
	G->m = 0; // gan so cung cua do thi = 0
	int u,v;
	for(u = 1; u <= n; u++)
	for(v = 1; v<= n; v++)
	G->A[u][v] = 0;
}

// ham them cung cho do thi
void add_Edge(Graph *G, int x, int y){
	G->A[x][y] = 1;
	G->A[y][x] = 1;
	G->m++;
}

// kiem tra dinh ke
int adjacent(Graph *G, int x, int y){
	return G->A[x][y] > 0;
}

// xac dinh bac cua mot dinh
int degree(Graph *G, int x){
	int e, deg = 0;
	for(e = 1; e<=G->n;e++){ // duyet tung cung 
		deg += G->A[x][e];
	}
	return deg + G->A[x][x];
}

void neighbours(Graph *G, int u){
	int v;
	for(v = 1; v<= G->n; v++)
		if(G->A[u][v] != 0)
		printf("%d ", v);
		printf("\n");
}
int main(){
	
	Graph G;
	int x,y,e;
//	FILE *f = fopen("dothi.txt", "r");
//	fscanf(f, "%d%d", &x, &y);
//	init_Graph(&G, x);
//	int u, v;
//	for(e = 1; e<= y; e++){
//		fscanf(f, "%d%d", &u,&v);
//		add_Edge(&G, u, v);
//	}
	int u, v;
	freopen("dothi1.txt", "r", stdin);
	scanf("%d%d", &x,&y);
	init_Graph(&G, x);
	for(e = 1; e<=y; e++)
	{
		scanf("%d%d", &u, &v);
		add_Edge(&G, u,v);
	}
//	init_Graph(&G, 4);
//	add_Edge(&G, 1,2);
//	add_Edge(&G, 2,3);
//	add_Edge(&G, 3,4);
//	add_Edge(&G, 4,1);
//	add_Edge(&G, 2,4);
	int i,j;
	for(i = 1; i <= G.n; i++)
	printf("Degree(%d): %d\n", i, degree(&G, i));
	printf("-------------------------------\n");
	int a;
	for(a = 1; a <= G.n; a++)
	for(j = 1; j <=G.n; j++){
		if(adjacent(&G, a, j) == 1){
				printf("%d ke %d\n", a, j);
		}
		else {
		printf("%d khong ke %d\n", a, j);
		}
	}
	
	printf("-------------------------\n");
	for(i = 1; i <= G.n; i++){
		printf("Neighbours cua %d la: ", i);
		neighbours(&G, i);
		printf("\n");
	}
	return 0;
	
	
}
