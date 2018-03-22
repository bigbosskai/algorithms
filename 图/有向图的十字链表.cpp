#include<iostream>
using namespace std;
typedef char vertextype;
typedef int edgetype;
#define MAXVEX 100
//定义边表节点
typedef struct edgenode{
	int headvex;
	int tailvex; 
	struct edgenode *headlink;
	struct edgenode *taillink; 
}EdgeNode;
typedef struct vertexnode{
	vertextype data;//data域
	EdgeNode * firstout;
	EdgeNode * firstin; 
}vertexNode,AdjList[MAXVEX]; 

typedef struct{
	AdjList adjList;
	int numvertexes,numedges;
}DGraphAdjList;
void createDGraphAdjList(DGraphAdjList *G){
	int i,j,k;
	EdgeNode *e;//边表节点需要malloc
	cout<<"输入顶点数和边数:"<<endl;
	cin>>G->numvertexes>>G->numedges;
	//读入顶点数
	for(i=0; i<G->numvertexes; i++){
		cin>>G->adjList[i].data;
		G->adjList[i].firstin=G->adjList[i].firstout=NULL;
	} 
	for(k=0; k<G->numedges; k++){
		cout<<"输入边(vi,vj)上的下标i，和下标j"<<endl;
		cin>>i>>j;
		
		e=new EdgeNode;
		e->headvex=j;
		e->headlink=G->adjList[i].firstout;
		G->adjList[i].firstout=e;
		
		e->tailvex=i;
		e->taillink=G->adjList[j].firstin;
		G->adjList[j].firstin=e;
	}
}
int main(){
	DGraphAdjList G;
	createDGraphAdjList(&G);
	
	return 0;
}
