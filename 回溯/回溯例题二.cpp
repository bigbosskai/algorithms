#include<iostream>
/*******************************************
方框中可以填1-9 
 □              □                 □
-----    +      -----       =      -----  
 □□            □□               □□
********************************************/
using namespace std;
void get_answer(int a[]){
	//1--9
	cout<<a[1]<<"\t"<<a[4]<<"\t"<<a[7]<<endl;
	cout<<"----"<<" +  "<<"----"<<" =  "<<"----"<<endl;
	cout<<a[2]<<a[3]<<"\t"<<a[5]<<a[6]<<"\t"<<a[8]<<a[9]<<endl;
}
int main2018315151707(){
	int a[10]={0};
	int g;
	int i=1;
	a[i]=1;
	int s=0;
	while(1){
		g=1;
		for(int k=i-1; k>=1; k--){
			if(a[k]==a[i])
				g=0;
				break;
		}
		if(i==9 && g && a[1]<a[4]){
			int m1=a[2]*10+a[3];
			int m2=a[5]*10+a[6];
			int m3=a[8]*10+a[9];
			if((a[1]*m2*m3+a[4]*m1*m3)==a[7]*m1*m2){
				//get_answer(a);
				s++;	
			}
		}
		if(i<9 && g){
			i++;
			a[i]=1;
			continue;
		}
		while(a[i]==9 && i>1){
			i--;
		}
		if(a[i]==9 && i==1){
			break;
		}
		else{
			a[i]=a[i]+1;
		}	
	}
	cout<<s;
} 



int main01(){
	int a[10]={0};
	int g;
	int i=1;
	a[i]=1;
	int s=0;
	while(1){
		g=1;
		for(int k=i-1; k>=1; k--){
			if(a[k]==a[i])
				g=0;
				break;
		}
		if(i==9 && g && a[1]<a[4]){
			int m1=a[2]*10+a[3];
			int m2=a[5]*10+a[6];
			int m3=a[8]*10+a[9];
			if((a[1]*m2*m3+a[4]*m1*m3)==a[7]*m1*m2){
				//get_answer(a);
				s++;
			}
		}
		if(i<9 && g==1){
			i++;
			a[i]=1;
			continue;
		}
		while(a[i]==9 && i>1){
			i--;
		}
		if(a[i]==9 && i==1){
			break;
		}
		else{
			a[i]=a[i]+1;
		}	
	}
	cout<<s;
}
