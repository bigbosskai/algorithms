#include<iostream> 
#include<climits>
#define INFINITY INT_MAX
#define MAXVEX 100
typedef char vertextype;
typedef int edgetype;
using namespace std;
typedef struct{
	vertextype vexs[MAXVEX];
	edgetype arc[MAXVEX][MAXVEX];
	int numvertexes,numedges; 
}MGraph;

void createMGraph(MGraph &G){
	int i,j,k,w;
	cout<<"输入顶点数和边数: ";
	cin>>G.numvertexes>>G.numedges; 
	for(i=0; i<G.numvertexes; i++){
		cin>>G.vexs[i];
	}
	for(i=0; i<G.numvertexes; i++){
		for(j=0; j<G.numvertexes; j++){
			G.arc[i][j]=INFINITY;
			if(i==j){
				G.arc[i][j]=0;
			}
		}
	}
	for(i=0; i<G.numedges; i++){
		cout<<"<index1,index2>:=";
		cin>>j>>k>>w;
		G.arc[j][k]=w;
		G.arc[k][j]=w; 
	}
}
void prim(MGraph G){
	int j,i,min,k;
	int adjvex[MAXVEX];
	int weight[MAXVEX];	
	for(i=0; i<G.numvertexes; i++){
		adjvex[i]=0;
		weight[i]=G.arc[0][i];
	}
	//默认G.arc[0][0]是等于0de 
	for(i=1; i<G.numvertexes; i++){//这个循环知识控制重复8次，其循环内部并没有用到i变量 8次之后就找到所有的边 
		min=INFINITY;
		j=1;
		while(j<G.numvertexes){
			if(weight[j]!=0 && weight[j]<min){
				min=weight[j];
				k=j;
			}
			j++;
		}
		//找到与0顶点权值最小的j顶点 j的下标放到k中去备份
		weight[k]=0;
		cout<<"( "<<adjvex[k]<<","<<k<<")"<<endl;
		//这个已经把这个k顶点加入到进来了，应该跟新
		for(j=1; j<G.numvertexes; j++){
			if(weight[j]!=0 && G.arc[k][j] <weight[j]){
				weight[j]=G.arc[k][j];
				adjvex[j]=k;
			}
		} 
	}
}
void init(MGraph G){
	int i,j;
	for(i=0; i<G.numvertexes; i++){
		//init 一个图我实在不想写了 
	}
}



int main(){
	MGraph G;
	createMGraph(G);
	prim(G); 
	return 0;
}
