#include<iostream>
using namespace std;
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
void select_sort(int A[],int n)
{
	for(int i=0; i<=n-2; i++)
	{
		int j=i;
		for(int k=i+1; k<=n-1; k++)
		{
			if(A[j]>A[k]){
				j=k;
			}
		}
		if(j!=i){
			swap(A[j],A[i]);	
		}
	}
}

int main()
{
	int a[4]={2,3,6,1};
	select_sort(a,4);
	for(int i=0; i<4; i++){
		cout<<a[i]<<endl;
	}
	return 0;
}
