#include<stdio.h>
#include<malloc.h>
#include<limits.h>
#define max(a,b) ((a)>(b)?(a):(b))
//n is the length of rod
int cut_rod(int p[],int n){//runtime: O(2^n) 
	if(n==0){
		return 0;
	}
	int q=INT_MIN;
	int i;
	for(i=1; i<=n; i++){
		q=max(q,p[i]+cut_rod(p,n-i));
	} 
	return q;
}
//the better one
//top-down with memoization
int mem[100];
int cut_rod2(int p[],int n){
	if(mem[n]>=0){
		return mem[n];
	}
	if(n==0){
		return 0;
	}
	int q=INT_MIN;
	int i;
	for(i=1; i<=n; i++){
		q=max(q,p[i]+cut_rod2(p,n-i));
	}
	mem[n]=q;
	return q;
}
//the best one
//bottom_up

int BOTTOM_UP_CUT_ROD(int p[],int n){
	int *r=malloc(sizeof(int)*(n+1));
	r[0]=0;
	int j,i;
	for(j=1; j<=n; j++){
		int q=INT_MIN;
		for(i=1; i<=j; i++){
			q=max(q,p[i]+r[j-i]);
		}
		r[j]=q;
	}
	int ret=r[n];
	printf("r array: ");
	for(i=0;i<=n; i++){
		printf("%d ",r[i]); 
	}
	printf("\n");
	free(r);
	return r[n];
} 

//extended
int EXTENDED_BOTTOM_UP_CUT_ROD(int p[],int n){
	int *r=malloc(sizeof(int)*(1+n));
	int *s=malloc(sizeof(int)*(1+n));
	int i,j,reval;
	s[0]=0;
	r[0]=0;
	for(j=1; j<=n; j++){
		int q=INT_MIN;
		for(i=1; i<=j; i++){
			if( (p[i]+r[j-i])>q){
				q=p[i]+r[j-i];
				s[j]=i;
			}
		}
		r[j]=q;
	}
	printf("\nr array: ");
	for(i=0;i<=n;i++){
		printf("%d ",r[i]);
	}
	printf("\ncut rod scheme: ");
	reval=r[n];
	while(n>0){
		printf("%d ",s[n]);
		n=n-s[n];
	}
	printf("\n");  
	free(r);
	free(s);
	return reval;
}





int main(){
	int p[]={0,1,5,8,9,10,17,17,20,24,30};
	int i;
	for(i=0; i<100; i++){
		mem[i]=INT_MIN;
	}
	printf("%d",cut_rod2(p,5));
	printf("\n%d",BOTTOM_UP_CUT_ROD(p,5));
	printf("\n%d",EXTENDED_BOTTOM_UP_CUT_ROD(p,5));
	return 0; 
} 
