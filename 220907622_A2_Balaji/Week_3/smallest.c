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
	for(int* ptr = &arr[0]; ptr <= &arr[n-1]; ptr++){
		scanf("%d", ptr);
	}

	int smallest = arr[0];
	for(int* ptr = &arr[0]; ptr <= &arr[n-1]; ptr++){
		if (*ptr < smallest){
			smallest = *ptr;
		}
	}

	printf("Smallest Number in the array is: %d\n", smallest);
	return 0;
}