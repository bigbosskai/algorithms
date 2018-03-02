#include<iostream>
#include<cmath>
using namespace std;

void q(int *sum,int low,int high){
    if(low>=high){
        return;
    }
    int first=low;
    int last=high;
    int key=sum[first];
    while(first<last){
        while(first<last && sum[last]>=key){
            last--;
        }
        sum[first]=sum[last];
        while(first<last && sum[first]<=key){
            first++;
        }
        sum[last]=sum[first];
    }
    sum[first]=key;
    q(sum,low,first-1);
    q(sum,first+1,high);
}
void qsort(int *sum,int n){
    q(sum,0,n-1);
    return;
}
int sim_zero(int *a,int n){
    int *sum=new int[n];
    sum[0]=a[0];
    for(int i=1; i<n; i++){
        sum[i]=sum[i-1]+a[i];
    }
    qsort(sum,n);
    int min1=sum[1]-sum[0];
    int min2=abs(sum[0])<abs(sum[1])?sum[0]:sum[1];
    for(int i=2; i<n; i++){
        int s=sum[i]-sum[i-1];
        if(min1>abs(s)){
            min1=s;
        }
        if(abs(min2)>abs(sum[i])){
            min2=sum[i];
        }
    }
    return abs(min1)<abs(min2)?min1:min2;
}


int main(){
    int a[]={1,-2,3,10,-4,7,2,-5};
    cout<<sim_zero(a,sizeof(a)/sizeof(a[0]))<<endl;
    cout<<"helloworld"<<endl;
    return 0;
}