#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *arr; int n;
	printf("Enter Number of Elements: \n");
	scanf("%d", &n);
	arr = (int*)calloc(n,sizeof(int));
	if (arr == NULL){
		printf("Memory not allocated. \n");
		exit(0);
	}

	printf("Enter Elements: ");
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}

	for(int i = 0; i < n/2; i++){
		arr[i] = (arr[n-i-1] + arr[i]) - (arr[n-i-1] = arr[i]);
	}

	printf("After Reversing: ");
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
}