#include<iostream>
using namespace std;
int count=0;
void hanoi(int n,char x,char y,char z)
{
	if(n==1)
	{
		cout<<"第"<<count++<<"步："<<"第"<<n<<"块从"<<x<<"移动到"<<z<<endl; 
	}
	else
	{
		hanoi(n-1,x,z,y);
		cout<<"第"<<count++<<"步："<<"第"<<n<<"块从"<<x<<"移动到"<<z<<endl;
		hanoi(n-1,y,x,z); 
	}
}


int main()
{
	hanoi(3,'A','B','C');
	return 0;
}
