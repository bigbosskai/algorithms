#include<iostream>
using namespace std;
int find_min(int *a,int n){
    int low=0;
    int high=n-1;
    int mid;
    while(low<high){
        mid=(low+high)/2;
        if(a[mid]<a[high]){
            high=mid;
        }
        else if(a[mid]>a[high]){
            low=mid+1;
        }
    }
    return a[low];
}

int main(){
    int a[]={4,5,6,7,0,1,2};
    cout<<find_min(a,7)<<endl;
    cout<<"helloworld"<<endl;
    return 0;
}
