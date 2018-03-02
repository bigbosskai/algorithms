#include<iostream>
#include<cstring>

#define MAX(a,b)  (((a) > (b)) ? (a) : (b))
using namespace std;

/*

1th:

int LCS(const char *s1,const char *s2){
    int slen1=strlen(s1);
    int slen2=strlen(s2);
    int *index = new int[ MAX(slen1,slen2) ];
    int d=0;
    //malloc 2-d array
    int **A=new int * [slen1+1];
    for(int i=0;i<slen1+1; i++){
        A[i]=new int[slen2+1];
        A[i][0]=0;
    }
    for(int j=0; j<slen2+1; j++){
        A[0][j]=0;
    }
    for(int m=1; m<slen1+1; m++){
        for(int n=1; n<slen2+1; n++){
            if(s1[m-1]==s2[n-1]){
                A[m][n]=A[m-1][n-1]+1;
            }
            else{
                A[m][n]=MAX( A[m-1][n],A[m][n-1]);
            }
        }
    }
    return A[slen1][slen2];
}
*/
//2th
void show(int i,int j,const char *s1,int **B){
    if(i==0||j==0){
        return;
    }
    if(B[i][j]==1){
        show(i-1,j-1,s1,B);
        cout<<s1[i-1]<<" ";
    }
    else if(B[i][j]==2){
        show(i-1,j,s1,B);
    }
    else{
        show(i,j-1,s1,B);
    }
}
void showB(int m,int n,int **B){
    for(int i=0; i<m;i++){
       for(int j=0; j<n;j++){
           cout<<B[i][j]<<" ";
       } 
       cout<<endl;
    }
    cout<<endl;
}
int LCS(const char *s1,const char *s2){
    int slen1=strlen(s1);
    int slen2=strlen(s2);
    int *index = new int[ MAX(slen1,slen2) ];
    int d=0;
    //malloc 2-d array
    int **A=new int * [slen1+1];
    int **B=new int * [slen1+1];
    for(int i=0;i<slen1+1; i++){
        A[i]=new int[slen2+1];
        B[i]=new int[slen2+1];
        A[i][0]=0;
    }
    for(int j=0; j<slen2+1; j++){
        A[0][j]=0;
    }
    for(int m=1; m<slen1+1; m++){
        for(int n=1; n<slen2+1; n++){
            if(s1[m-1]==s2[n-1]){
                A[m][n]=A[m-1][n-1]+1;
                B[m][n]=1;
            }
            else if(A[m-1][n]>=A[m][n-1]){
                A[m][n]=A[m-1][n];
                B[m][n]=2;
            }
            else{
                A[m][n]=A[m][n-1];
                B[m][n]=3;
            }
        }
    }
    showB(slen1+1,slen2+1,B);
    show(slen1,slen2,s1,B);
    return A[slen1][slen2];
}
int main(){

    const char *s1="ABCBDAB";
    const char *s2="BDCABA";
    cout<<LCS(s1,s2)<<endl;
    cout<<"helloworld"<<endl;
    return 0;
}