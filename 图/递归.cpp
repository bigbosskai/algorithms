#include<iostream> 
using namespace std;
/************
���ӰƱ��m+n���˵ȴ���m������50Ԫ�ֽ�,n��������100Ԫ�����ҵĿ�Ǯ��������Ŀ
����50Ԫ������һ�� 
*************/

int f(m,n){
	if(n==0){
		return 1;
	}
	if(n>m){
		return 0;
	}
	return f(m-1,n)+f(m,n-1);
}
int main(){
	return 0;
}
