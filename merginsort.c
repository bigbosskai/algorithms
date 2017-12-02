#include <stdio.h>
#include <malloc.h>
#include <memory.h>
void print1(int A[], int n){
	int i;
	for (i = 1; i <= n; i++){
		printf("%d ", A[i]);
	}
}
void topdownmerge(int B[], int ibegin, int imiddle, int iend){
	//ibegin to imiddle
	//imiddle+1 iend
	int i, j, k, caindex;
	int *ca = (int*)malloc(sizeof(int)*(iend - ibegin + 1));
	caindex = 0;
	i = ibegin; j = imiddle + 1;
	for (k = ibegin; k <= iend; k++){
		if (i <= imiddle && (j > iend || B[i] <= B[j])){
			ca[caindex++] = B[i];
			i = i + 1;
		}
		else{
			ca[caindex++] = B[j];
			j = j + 1;
		}
	}
	memcpy(&B[ibegin], ca, sizeof(int)*(iend - ibegin + 1));
	free(ca);
}
void topdownsplitmerge(int B[], int begin, int end){
	if (end - begin < 1){
		return;
	}
	int mid = (begin + end) / 2;//begin=1 & end=2
	topdownsplitmerge(B, begin, mid);//begin=1 & mid=1进入的
	topdownsplitmerge(B, mid + 1, end);//mid+1=2 & end=2进入的
	topdownmerge(B, begin, mid, end);//importance step
}
void topdownmergesort(int A[], int B[], int n){
	memcpy(B, A, sizeof(int)*(n + 1));//A copy to B
	topdownsplitmerge(B, 1, n);
}

void main()
{
	int A[] = { 0, 1, 2, 6, 5, 11, 8, 22, 100 ,-3};
	int B[10];
	topdownmergesort(A, B, 9);
	print1(B, 9);
	getchar();
}