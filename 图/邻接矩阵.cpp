#include<iostream>
#include<climits>
using namespace std;
typedef char vertextype;
typedef int edgetype;
#define MAXVEX 100
#define INFINITY INT_MAX
//�ڽӾ��� �����ڶ����ٱ�����ĳ���ͼ 
typedef struct{
	vertextype vexs[MAXVEX];
	edgetype arc[MAXVEX][MAXVEX];
	int numvertexes,numedges; 
}MGraph;
//ok 
void createMGraph(MGraph *G){
	int i,j,k,w;
	cout<<"���붥�����ͱ���:"<<endl;
	cin>>G->numvertexes>>G->numedges;
	for(i=0; i< G->numvertexes; i++){
		cin>>G->vexs[i];
	} 
	//init infinity
	for(i=0; i<G->numvertexes; i++){
		for(j=0; j<G->numvertexes; j++){
			G->arc[i][j]=INFINITY;
		}
	}
	
	for(k=0; k<G->numedges; k++){
		cout<<"�����(vi,vj)�ϵ��±�i�����±�j��Ȩ��w:\n"<<endl;
		cin>>i>>j>>w;
		G->arc[i][j]=w;
		G->arc[j][i]=w; 
	}
	return;
}
bool visited[MAXVEX];
void dfs(MGraph G,int i){
	int j;
	visited[i]=true;
	//printf("%c\n", G.vexs[i]);
	cout<<G.vexs[i]<<endl;
	for(j=0; j<G.numvertexes; j++){
		//������һ��
		if(G.arc[i][j]!=INFINITY && !visited[j]){
			dfs(G,j);
		} 
	}
} 
void dfstraverse(MGraph G){
	int i;
	for(i=0; i<G.numvertexes; i++){
		visited[i]=false;
	}
	for(i=0; i<G.numvertexes; i++){
		if(!visited[i]){
			dfs(G,i);
		}
	}	
}
int deque[100];
int base=0;
int top=0;
void bfstraverse2018319215200(MGraph G){
	int i,j;
	base=0;
	top=0;
	//init visited array
	for(i=0; i<G.numvertexes; i++){
		visited[i]=false;
	}
	for(i=0; i<G.numvertexes; i++){
		if(!visited[i]){
			visited[i]=true;
			deque[top++]=i;
			while(base!=top){
				int x=deque[base++]; 
				cout<<G.vexs[x]<<endl;
				for(j=0; j<G.numvertexes; j++){
					if(!visited[j] && G.arc[i][j]!=INFINITY){
						visited[j]=true;
						deque[top++]=j;
					}
				}
			}	
		}
	}
} 
void bfstraverse(MGraph G){
	int i,j;
	for(i=0; i<G.numvertexes; i++){
		visited[i]=false;
	}
	for(i=0; i<G.numvertexes; i++){
		if(!visited[i]){
			visited[i]=true;
			deque[top++]=i;//the first in deque
			while( base!=top ){
				int x=deque[base++];
				cout<<G.vexs[x]<<endl;//����Ԫ�� 
				for(j=0; j<G.numvertexes; j++){
					if(!visited[j] && G.arc[i][j]!=INFINITY){
						visited[j]=true;
						deque[top++]=j;
					}
				}
			} 
		}
	}
	return; 
} 

void dfs2018319214450(MGraph G,int i){
	int j;
	visited[i]=true;
	cout<<G.vexs[i]<<endl;
	for(j=0; j<G.numvertexes; j++){
		if(!visited[j] && G.arc[i][j]!=INFINITY){
			dfs2018319214450(G,j); 
		} 
	}
} 
void dfstraverse2018319214807(MGraph G){
	int i;
	//init visited array
	for(i=0; i<G.numvertexes; i++){
		visited[i]=false;
	}
	for(i=0; i<G.numvertexes; i++){
		if(!visited[i]){
			dfs2018319214450(G,i);
		}
	}
} 
int main(void){
	MGraph G;
	createMGraph(&G);
	dfstraverse(G);//O(n^2) 
	cout<<"bfs----\n";
	bfstraverse(G);
	
	
	cout<<"2018-3-19 21:50:36 dfs\n";
	dfstraverse2018319214807(G); 
	cout<<"2018-3-19 21:56:47 bfs\n";
	bfstraverse2018319215200(G); 
	
	
	cout<<INT_MAX;
	return 0;
}
