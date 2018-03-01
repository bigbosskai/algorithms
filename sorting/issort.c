#include <stdio.h>
void issort(int A[], int n){
	//index form 1 to n
	int i, j, key;
	for (i = 2; i <= n; i++){
		//可以表示当前要查的元素
		key = A[i];
		j = i - 1;
		while (j > 0 && key < A[j]){
			A[j + 1] = A[j];
			j = j - 1;
		}
		A[j + 1] = key;
	}
}
void print(int A[], int n){
	int i;
	for (i = 1; i <= n; i++){
		printf("%d ", A[i]);
	}
}
int mainisort()
{
	int A[] = { 0, 6, 2, 8, 4, 3 };
	issort(A, 5);
	print(A, 5);
	system("pause");
}