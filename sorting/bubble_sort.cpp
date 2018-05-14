#include<iostream>
using namespace std;
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
void bubble_sort(int a[],int n)
{
	bool change=true;
	for(int i=n-1; i>=1&&change; i--){
		change=false;
		for(int j=0; j<i; j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
				change=true;
			}
		}
	}
}

int main()
{
	int a[4]={2,4,6,1};
	bubble_sort(a,4);
	for(int i=0; i<4; i++){
		cout<<a[i]<<endl;
	}
} 
