#include<iostream>
#include<cstring>
using namespace std;
int longest_palindrome(const char *s,int n){
	int i,j,max;
	if(s==NULL || n<1){
		return 0;
	}
	max=0;
	for(i=0; i<n; i++){//i is the middle point of the palindrome
		for(j=0; (i-j>=0)&&(i+j<n); j++){//if the length of the palindrome is odd
			if(s[i-j]!=s[i+j]){
				break;
			}
		}
		if(j*2+1>max){
			max=j*2+1;
		}
		for(j=0; (i-j>=0) && (i+j+1<n); j++)//for the even case
		{
			if(s[i-j]!=s[i+j+1]){
				break;
			}
		}
		if(j*2+2>max){
			max=j*2+2;
		}
		
	}
	return max;
}
int LongestPalindrome(const char *s, int n)
 {
 int i, j, max;
 if (s == 0 || n < 1)
 return 0;
 max = 0;
 for (i = 0; i < n; ++i) { // i is the middle point of the palindrome
 for (j = 0; (i - j >= 0) && (i + j < n); ++j) // if the length of the palindrome is odd
 if (s[i - j] != s[i + j])
 break;
 if (j * 2 + 1 > max)
 max = j * 2 + 1;
 for (j = 0; (i - j >= 0) && (i + j + 1 < n); ++j) // for the even case
 if (s[i - j] != s[i + j + 1])
 break;
 if (j * 2 + 2 > max)
 max = j * 2 + 2;
 }
 return max;
}
int myfunction(const char *s,int n){
	int i,j;
	int max=0;
	for(i=0; i<n; i++)
	{
		for(j=0; (i-j>=0) && (i+j<n); j++)
		{	
			if(s[i-j]!=s[i+j]){
				break;
			}
		}
		if((2*j-1)>max){
			max=2*j-1;
		}
		for(j=0; (i-j>0) &&(i+j+1<n); j++){
			if(s[i-j]!=s[i+j+1]){
				break;
			}
		}
		if(2*j+2>max){
			max=2*j+2;
		}
		
		
	}
	return max;
}
int min(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
void manacher(const char *s,int P[]){
	int len=strlen(s);
	P[0]=1;
	int id=0;
	int mx=1;
	for(int i=1; i<len; i++){
		if(i < mx){//i在mx的左边 
			P[i]=min( mx-i, P[2*id-i] );
		}
		else{
			P[i]=1;
		}
		//以i为中心往外面
		//for(; s[i+P[i]]==s[i-P[i]];P[i]++); 
		//这个难道没有问题吗
		for(; (i+P[i]<len)&&(i-P[i]>=0)&&(s[i-P[i]]==s[i+P[i]]); P[i]++); 
		if(mx<i+P[i]){//更新mx的值和下标id 
			mx=i+P[i];
			id=i;
		}	
	}
}


int main(){
	const char *s="1211212321";
	cout<<longest_palindrome(s,strlen(s));
	cout<<LongestPalindrome(s,strlen(s));
	cout<<myfunction(s,strlen(s));
	
	const char *s2="$#1#2#2#1#2#3#2#1#";//always even
	int P[20];
	manacher(s2,P);
	for(int i=0; i<strlen(s2); i++){
		cout<<P[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
