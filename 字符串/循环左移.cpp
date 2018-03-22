#include<iostream>
#include<cstring> 
using namespace std;
//我要取于字符串的长度
void leftstring(char *s,int leftn){
	int len,left;
	char *p1,*p2,swap;

	len=strlen(s);
	left=leftn % len;
	//
	p1=s;
	p2=s+left-1;
	while(p1<p2){
		swap=*p1;
		*p1=*p2;
		*p2=swap;
		p1=p1+1;
		p2=p2-1;
	}
	p1=s+left;
	p2=s+len-1;
	while(p1<p2){
		swap=*p1;
		*p1=*p2;
		*p2=swap;
		p1=p1+1;
		p2=p2-1;
	}
	//最后交换整体
	p1=s;
	p2=s+len-1;
	while(p1<p2){
		swap=*p1;
		*p1=*p2;
		*p2=swap;
		p1=p1+1;
		p2=p2-1;
	}
	return;
} 
void swaps(char *p1,char *p2){
	char temp;
	while(p1<p2){
		temp=*p1;
		*p1=*p2;
		*p2=temp;
	}
} 
void leftmove(char *s,int n){
	int len=strlen(s);
	int nl;
	char *p1,*p2;
	nl=n%len;
	p1=s;
	p2=s+nl-1;
	swaps(p1,p2);
	
	p1=s+n;
	p2=s+len-1;
	swaps(p1,p2);
	
	p1=s;
	p2=s+len-1;
	swaps(p1,p2);
}






int main(){
	char s[]="abcdef";
	leftmove(s,2);
	cout<<s<<endl;
	return 0;
}
