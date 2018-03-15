#include<iostream> 
#include<cmath>
using namespace std;
int main(){
	int i=1;
	int a[5];
	a[i]=1;
	int g;
	int s=0;
	while(1){
		g=1;
		for(int k=i-1; k>=1; k--){
			if(a[i]==a[k] || abs(a[i]-a[k])==i-k)
			{
				g=0;
				break;
			} 
		}
		if(g==1&& i==4){
			//cout<<"Ò»¸ö½â"<<endl; 
			for(int j=1; j<=4; j++){
				cout<<a[j]<<" ";
			}
			cout<<endl;
			s++;
		}
		if(g==1&& i<4){
			i++;
			a[i]=1;
			continue;
		}
		while(a[i]==4&& i>1)
			i--;
		if(a[i]==4 && i==1){
			break;
		}
		else{
			a[i]=a[1]+1;
		}
	}
	cout<<s<<endl;
	return 0;
}
