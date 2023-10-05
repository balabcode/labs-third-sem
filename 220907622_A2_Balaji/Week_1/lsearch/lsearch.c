#include <stdio.h>

int Lsearch(int a[], int n, int target){
	for (int i = 0; i < n; i++){
		if (a[i] == target){
			return i+1;
		}
	}
	return -1;
}
int main(){
	int a[] = {1,23,6,7,78,342,69};
	printf("%d\n", Lsearch(a,7,78));
}