#include<iostream> 
#include<cstring>
using namespace std;
int bf(const char *s,const char *p){
	int i=0,j=0;
	int slen=strlen(s);
	int plen=strlen(p);
	while((i<slen) && (j<plen)){
		if((s[i+j])==p[j]){
			j++;
		}
		else{
			i++;
			j=0;
		}
	}
	if(j>=plen){
		return i;
	}
	return -1;
}
//数组下表从0开始 
int next[9];
void getnext(const char *p,int next[]){
	int len=strlen(p);
	next[0]=-1;
	int k=-1;
	int j=0;
	while(j<len-1){
		if(k==-1||p[j]==p[k]){
			++k;
			++j;
			next[j]=k;
		}
		else{
			k=next[k];
		}
	}	
}
void get_nextval(const char *p,int next[]){
	int k=-1;
	int plen=strlen(p);
	next[0]=-1;
	int j=0;
	while(j<plen-1){
		if(k==-1 || p[j]==p[k]){
			++k;
			++j;
			if(p[k]!=p[j]){
				next[j]=k;
			}
			else{
				next[j]=next[k];
			}
		}
		else{
			k=next[k];
		}
	}
}
int kmp(const char *s,const char *p){
	int j=-1,i=0;
	int slen=strlen(s);
	int plen=strlen(p);
	get_nextval(p,next);
	while(i<slen && j<plen){
		if(j==-1 || s[i]==p[j]){
			++i;
			++j;
		}
		else{
			j=next[j];
		}
	}
	if( j>=plen){
		return i-plen;
	}
	return -1;
} 


int main(){

	const char *s="abaabcaba";
	const char *p="baab";
	cout<<kmp(s,p)<<endl;
	return 0;
}
