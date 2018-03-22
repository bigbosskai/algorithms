#include<iostream> 
using namespace std;
/************
买电影票，m+n个人等待，m个手中50元现金,n个手中是100元，求找的开钱的排列数目
两个50元交换算一种 
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
