#include <stdio.h>

#define max 100 // sos cung toi da

typedef int Element;

typedef struct {
	Element data[max];
	int size;
}List;

// cau truc cua do thi G
typedef struct{
	int n; // so dinh vaf so cung cua do thi
	 List adj[max];
}Graph;


void make_null(List *L){
	L->size = 0;
}

void push(List *L, Element x){
	L->data[L->size] = x;
	L->size++;
}

Element element_at(List * L, int x){
	return L->data[x-1];
}

int countList(List *L){
	return L->size;
}
// ham khoi tao do thi
void init_Graph(Graph *G, int n){
	G->n = n; // gan so dinh cho do thi
	int u;
	for(u = 1; u <= n; u++)
	make_null(&G->adj[u]);
}

// ham them cung cho do thi
void add_Edge(Graph *G, int x, int y){
	push(&G->adj[x],y);
		push(&G->adj[y],x);
}

int adjacent(Graph *pG, int u, int v) {
	int j;
	for (j = 1; j <= pG->adj[u].size; j++)
		if (element_at(&pG->adj[u], j) == v)
			return 1; //v n?m trong dánh sách adj[u]
	return 0;//v không có trong danh sách adj[u]
}

void neighbours(Graph *G, int u){
	int v;
	for(v = 1; v<= G->n; v++)
		if(adjacent(G,u,v) != 0)
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
	
		for(i = 1; i <= G.n; i++){
		printf("Neighbours cua %d la: ", i);
		neighbours(&G, i);
		printf("\n");
	}
	return 0;
	
	
}
