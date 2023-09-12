#include <stdio.h>

int triplets(int a[], int n){
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			for(int k = j+1; k< n; k++){
				if (a[i] + a[j] + a[k] == 0){
					printf("%d, %d, %d\n",a[i], a[j], a[k]);
				}
			}
		}
	}
}

int main(){
	int a[] = {0,-1,2,-3,1};
	triplets(a, 5);
	return 0;
}