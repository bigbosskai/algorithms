#include<iostream>
using namespace std;
int count=0;
void hanoi(int n,char x,char y,char z)
{
	if(n==1)
	{
		cout<<"��"<<count++<<"����"<<"��"<<n<<"���"<<x<<"�ƶ���"<<z<<endl; 
	}
	else
	{
		hanoi(n-1,x,z,y);
		cout<<"��"<<count++<<"����"<<"��"<<n<<"���"<<x<<"�ƶ���"<<z<<endl;
		hanoi(n-1,y,x,z); 
	}
}


int main()
{
	hanoi(3,'A','B','C');
	return 0;
}
