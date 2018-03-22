#include<iostream> 
#include<cstring>
using namespace std;
int main(){
	char s[101];
	int i;
	bool flag=true;
	cin>>s;
	int len=strlen(s);
	for(i=1; i<=len; i++){//i就是代表周期 
		if(len%i==0){
			flag=true;
			for(int j=i; j<len; j++){
				if(s[j]!=s[j%i]){
					flag=false;
					break;
				}
			}
		}
		if(flag){
			break;
		}
	}
	cout<<i<<endl;
	return 0;
}
