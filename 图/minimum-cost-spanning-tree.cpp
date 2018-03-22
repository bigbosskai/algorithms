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
	cout<<"���붥�����ͱ���: ";
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
	//Ĭ��G.arc[0][0]�ǵ���0de 
	for(i=1; i<G.numvertexes; i++){//���ѭ��֪ʶ�����ظ�8�Σ���ѭ���ڲ���û���õ�i���� 8��֮����ҵ����еı� 
		min=INFINITY;
		j=1;
		while(j<G.numvertexes){
			if(weight[j]!=0 && weight[j]<min){
				min=weight[j];
				k=j;
			}
			j++;
		}
		//�ҵ���0����Ȩֵ��С��j���� j���±�ŵ�k��ȥ����
		weight[k]=0;
		cout<<"( "<<adjvex[k]<<","<<k<<")"<<endl;
		//����Ѿ������k������뵽�����ˣ�Ӧ�ø���
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
		//init һ��ͼ��ʵ�ڲ���д�� 
	}
}



int main(){
	MGraph G;
	createMGraph(G);
	prim(G); 
	return 0;
}
