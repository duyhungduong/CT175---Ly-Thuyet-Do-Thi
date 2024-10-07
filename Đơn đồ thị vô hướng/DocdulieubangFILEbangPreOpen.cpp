#include <stdio.h>
//#include "BiendienDondothivohuong.cpp"
//#define MAX_Vertices 20; 
typedef struct {
	int A[20][20];
	int n;
}Graph;

//Ham khoi tao do thi Graph 
void init_graph(Graph *G, int n){
	G->n = n;
	int i,j;
	for (i=1; i<=n ; i++){
		for(j=1; j<=n ; j++)
			G->A[i][j] = 0;
	}
}
//Ham them cung vao do thi
void add_edge(Graph *G, int x, int y){
	G->A[x][y]=1;
	G->A[y][x]=1;
}
// Kiem tra phai la lang gieng voi nhau hay ko
int adjacent(Graph G, int x, int y){
	return G.A[x][y] != 0;
}

//Tinh bac cua mot dinh trong do thi G, degree
int degree (Graph G, int x){
	int i, bac = 0 ;
	for (i=1; i<=G.n ; i++){
		if (G.A[i][x]==1) bac++;
	}
	return bac;
}

// Tim lang gieng bang danh sach List
typedef struct {
	int data[20];
	int size;
}List;
void make_null(List *L){
	L->size = 0;
}
void push_back(List *L, int x){
	L->data [L->size] = x;
	L->size ++;
}
int element_at(List L, int  i){
	return L.data[i-1];
}

void timdanhsach(Graph G, int x){
	List L;
	make_null(&L);
	int i ;
	for (i=1; i<=G.n ; i++){
		if (G.A[i][x]==1) {
			push_back(&L, i);
		}
	}
	printf("Lang gieng cua dinh so %d la : [ ", x);
	for (i=1; i<=L.size ; i++)
		printf("%d, ", L.data [i-1]);
	printf("]\n")	;
	
}


int main (){
	Graph G;
	int e,i,j;
	//Doc du lieu tu tap tin
//	FILE* file = fopen ("dothi.txt", "r");
//Cach2
	freopen("dothi.txt" , "r" , stdin);
	int n,m;
	//n: so luong dinh, , m: so luong cung
//	fscanf(file, "%d%d" , &n, &m);
//Cach 2i
	scanf("%d%d" , &n, &m);
	init_graph(&G, n);
	int u,v;
	// Hai bien doc dinh
	// Dien cac cung vao do thi G, dung bien m
	for (e=1 ; e <= m ; e++ )	{
//		fscanf(file,"%d%d", &u , &v);
//Cach 2
		scanf("%d%d", &u , &v);
		add_edge(&G, u,v);
	}
	//Dong file (close file)
	//Cach 2 khong can dong file
//	fclose(file);
	
	for (i=1; i<=G.n ; i++){
		for(j=1; j<=G.n ; j++)
			printf("%d  ", G.A[i][j]);
			printf("\n");
	}
	
	printf("---------\n");
	if (adjacent(G,2,6)) printf("2 va 6 la lang gieng voi nhau\n");
	else printf("Hai so khong phai la lang gieng\n");
	
	if (adjacent(G,3,4)) printf("3 va 4 la lang gieng voi nhau\n");
	else printf("Hai so 3,4 khong phai la lang gieng\n");
	
	printf("---------\n");
	for (i=1; i<=G.n ; i++)
		printf ("Bac cua dinh so %d la degree(%d) : %d \n",i , i, degree(G,i));
	printf("---------\n");
	for (i=1; i<=G.n ; i++){
		timdanhsach(G, i);
	}
	
	return 0;
	 
} 
