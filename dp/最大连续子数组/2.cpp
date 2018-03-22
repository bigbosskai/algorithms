#include<iostream>
using namespace std;
//这里的low和high是没有机会相等的 
int find_max_crossing_subarray(int a[],int low,int mid,int high){
	int max_left=a[mid];
	int max_right=a[mid+1];
	int sum=0;
	for(int i=mid; i>=low; i--){
		sum=sum+a[i];
		if(sum>max_left){
			max_left=sum;
		}
	}
	sum=0;
	for(int j=mid+1; j<=high; j++){
		sum=sum+a[j];
		if(sum>max_right){
			max_right=sum;
		}
	}
	return max_left+max_right;
}

int find_maxmum_subarray(int a[],int low,int high){
	if(low==high){
		return a[low];
	}
	else{
		int mid=(low+high)/2;
		int m1=find_maxmum_subarray(a,low,mid);
		int m2=find_maxmum_subarray(a,mid+1,high);
		int m3=find_max_crossing_subarray(a,low,mid,high);
		if(m1>=m2 && m1>=m3){
			return m1;
		}
		else if(m2>=m1 && m2>=m3){
			return m2;
		}else{
			return m3;
		}
	}
}

int main(){
	int A[]={0,13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	cout<<sizeof(A)/sizeof(A[0])<<endl;
	cout<<find_maxmum_subarray(A,1,16);
	return 0;
}
