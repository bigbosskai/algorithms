#include<iostream>
using namespace std;
typedef char vertextype;
typedef int edgetype;
#define MAXVEX 100
//����߱�ڵ�
typedef struct edgenode{
	int adjvex;//
	edgetype weight;
	struct edgenode *next; 
}EdgeNode;
typedef struct vertexnode{
	vertextype data;//data��
	EdgeNode * firstedge; 
}vertexNode,AdjList[MAXVEX]; 

typedef struct{
	AdjList adjList;
	int numvertexes,numedges;
}GraphAdjList;


//����ͼ  �ڽӱ� 
void createALGraph(GraphAdjList *G){
	int i,j,k;
	edgetype w;
	EdgeNode *e;//�߱�ڵ���Ҫmalloc
	cout<<"���붥�����ͱ���:"<<endl;
	cin>>G->numvertexes>>G->numedges;
	//���붥����
	for(i=0; i<G->numvertexes; i++){
		cin>>G->adjList[i].data;
		G->adjList[i].firstedge=NULL;
	} 
	for(k=0; k<G->numedges; k++){
		cout<<"�����(vi,vj)�ϵ��±�i�����±�j��Ȩ��w:\n"<<endl;
		cin>>i>>j>> w;
		
		e=new EdgeNode;
		e->adjvex=j;
		e->weight=w;
		e->next=G->adjList[i].firstedge;
		G->adjList[i].firstedge=e;//ͷ�巨
		
		e=new EdgeNode;
		e->adjvex=i;
		e->weight=w;
		e->next=G->adjList[j].firstedge;
		G->adjList[j].firstedge=e; 
		
	}
}
//����ͼ ���ڽӱ�
void createALGraphAgainst(GraphAdjList *G){
	int i,j,k;
	edgetype w;
	EdgeNode *e;//�߱�ڵ���Ҫmalloc
	cout<<"���붥�����ͱ���:"<<endl;
	cin>>G->numvertexes>>G->numedges;
	for(i=0; i<G->numvertexes; i++){
		cin>>G->adjList[i].data;
		G->adjList[i].firstedge=NULL;
	} 
	for(k=0; k<G->numedges; k++){
		cout<<"�����(vi,vj)�ϵ��±�i�����±�j��Ȩ��w:\n"<<endl;
		cin>>i>>j>> w;
		e=new EdgeNode;
		e->adjvex=i;
		e->weight=w;
		e->next=G->adjList[j].firstedge;
		G->adjList[j].firstedge=e; 
	}
} 
bool visited[MAXVEX];
void dfs(GraphAdjList G,int i){
	int j;
	EdgeNode *p;
	visited[i]=true;
	cout<<G.adjList[i].data<<endl;
	p=G.adjList[i].firstedge;
	while(p){
		if(!visited[p->adjvex]){
			dfs(G,p->adjvex);
		}
		
		p=p->next;
	}
} 

void dfstraverse(GraphAdjList G){
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

void dfs2018319215942(GraphAdjList G,int i){
	int j;
	EdgeNode *p;
	visited[i]=true;
	//����
	cout<<G.adjList[i].data<<endl; 
	p=G.adjList[i].firstedge;
	while(p){
		if(!visited[p->adjvex]){
			dfs2018319215942(G,p->adjvex);
		}
		p=p->next;	
	}
} 
void dfstraverse2018319220258(GraphAdjList G){
	int i;
	for(i=0; i<G.numvertexes; i++){
		visited[i]=false;
	} 
	for(i=0; i<G.numvertexes; i++){
		if(!visited[i]){
			dfs2018319215942(G,i);
		}
	}
}


int queue[100];
int top=0;
int base=0;

void bfstraverse2018319220537(GraphAdjList G){
	int i,j;
	EdgeNode *p;
	top=0;
	base=0;
	//init visited array
	for(i=0; i<G.numvertexes; i++){
		visited[i]=false;
	}
	for(i=0; i<G.numvertexes; i++){
		if(!visited[i]){
			visited[i]=true;
			queue[top++]=i;
			while(base!=top){
				int x=queue[base++];
				cout<<G.adjList[x].data<<endl;
				p=G.adjList[x].firstedge;
				while(p){
					if(!visited[p->adjvex])	{
						visited[p->adjvex]=true;
						queue[top++]=p->adjvex;
					}
					p=p->next;
				}
			}
		}
	}
} 


void bfstraverse(GraphAdjList G){
	int i,j;
	for(i=0;i<G.numvertexes; i++){
		visited[i]=false;
	}
	for(i=0;i<G.numvertexes; i++){
		if(!visited[i]){
			visited[i]=true;
			queue[top++]=i;
			while(top!=base){
				int x=queue[base++];
				cout<<G.adjList[x].data<<endl;//��������� 
				EdgeNode *p=G.adjList[x].firstedge;
				while(p){
					if(!visited[p->adjvex]){
						visited[p->adjvex]=true;
						queue[top++]=p->adjvex;
					}	
					p=p->next;
				}
			}
			
			
		}
	}
} 
int main(){
	GraphAdjList G;
	createALGraph(&G);
	dfstraverse(G);//O(n+e) 
	cout<<"bfs-----\n";
	bfstraverse(G); 
	
	
	cout<<"2018-3-19 22:04:19 dfs\n";
	dfstraverse2018319220258(G); 
	
	cout<<"2018-3-19 22:10:48 bfs\n";
	bfstraverse2018319220537(G) ;
	return 0;
}
