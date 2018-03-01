#include <stdio.h>
#include <stdlib.h>
//给定一个数组A[0,...n-1],求A的连续子数组
//使得该子数组的和最大
//1, -2 3 10 -4 7 2 -5
//=> 3 10 -4 7 2
int max_sum_array(int *A, int n){//O(n^3)
    int maxsum = A[0];
    int cursum = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            cursum = 0;
            for(int k=i; k<=j; k++){
                cursum += A[k];
            }
            if(cursum>maxsum){
                maxsum = cursum;
            }
        }
    }
    return maxsum;
}
//D C
int max_sum_array2(int *a ,int from, int to){
        if(from==to){
            return a[to];
        }
        int middle = (from+to)/2;
        int m1=max_sum_array2(a,from,middle);
        int m2=max_sum_array2(a,middle+1,to);
        int i,left=a[middle],now=a[middle];
        for(i=middle-1; i>=from; --i){
            now += a[i];
            if(now>left){
                left = now;
            }
        }
        int right=a[middle+1];
        now=a[middle+1];
        for(i=middle+2; i<=to; i++){
            now+=a[i];
            if(now>right){
                right=now;
            }
        }
        int m3=left+right;
        return (m1>m2?m1:m2)>m3?(m1>m2?m1:m2):m3;
}
int max_sum_array3(int *a, int n){
    int *p =(int *)malloc(sizeof(int)*n);
    int m=0;//注意m的初值为什么是0
    int maxsum = a[0];
    p[0]=a[0];
    for(int i=1; i<n;i++){
        p[i]=p[i-1]+a[i];
    }
    for(int j=0; j<n; j++){
        if(p[j]<m){
            m=p[j];
        }
        if((p[j]-m)>maxsum){
            maxsum=p[j]-m;
        }
    }
    free(p);
    return maxsum;
}
int max(int a,int b){
    return a>b?a:b;
}
int max_sum_array4(int *a,int n){
    int sum=a[0];
    int result=a[0];
    for(int i=1; i<n; i++){
        if(sum>0){
            sum+=a[i];
        }
        else{
            sum=a[i];
        }
        if(sum>result){
            result=sum;
        }
    }
    return result;
}
int main()
{
    int A[] = {1,-2,3,10,-4,7,2,-5};
    printf("%d\n",max_sum_array(A,8));//18
    printf("%d\n",max_sum_array2(A,0,7));
    printf("%d\n",max_sum_array3(A,8));
    printf("%d\n",max_sum_array4(A,8));
    printf("Hello world!\n");
    return 0;
}
