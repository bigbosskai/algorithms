#include<iostream> 
using namespace std;
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
void p(char *s,int from,int to){
	if(from==to){
		cout<<s<<endl;
		return;
	}
	for(int i=from; i<=to; i++){
		swap(s[from],s[i]);//让不同的左首字符 
		p(s,from+1,to);
		swap(s[from],s[i]);
	}
}

//解决有重复的全排列 
bool check(char *s,int from,int to){
	bool res=true;
	for(int i=from; i<to; i++){
		if(s[i]==s[to]){
			res=false;
			break;
		}
	}
	return res;
} 
int count=0;
void pup(char *s,int from,int to){
	if(from==to){
		count++;
		cout<<count<<": "<<s<<endl;
	}
	for(int i=from; i<=to; i++){
		//在交换之前要判断from到i-1中的字符是不是有和s[i]相等
		//相等则不能交换 
		if(!check(s,from,i)){//如果不能交换就continue 
			continue;
		}
		swap(s[from],s[i]);
		pup(s,from+1,to);
		swap(s[from],s[i]);
	}
}


//这里考虑最朴素的hash  用hash函数会比较好 
void pupup(char *s,int from,int to){
	if(from==to){
		count++;
		cout<<count<<": "<<s<<endl;
	}
	int mark[256]={0};//这里有个思考为什么mark不能用全局变量 
	for(int j=0; j<256; j++){
		mark[j]=0;
	}
	for(int i=from; i<=to; i++){
		//在交换之前要判断from到i-1中的字符是不是有和s[i]相等
		//相等则不能交换  
		if(mark[s[i]]==1){
			continue;
		}
		mark[s[i]]=1;
		if(!check(s,from,i)){//如果不能交换就continue 
			continue;
		}
		swap(s[from],s[i]);
		pupup(s,from+1,to);
		swap(s[from],s[i]);
	}
}



 
int main(){
	char s1[]="1223";
	pupup(s1,0,3);
	return 0;
}
