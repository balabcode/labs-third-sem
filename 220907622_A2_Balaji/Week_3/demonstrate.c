#include <stdio.h>

void swap(int *a, int *b){
	*b = (*a + *b) - (*a = *b);
}

int *smallest(int *a, int *b){
	if (*a < *b){
		return a;
	}
	else{
		return b;
	}
}

int center(int a[][10], int i, int j){
	//to print the center element:
	printf("%d\n", (*(*a + (i+1)/2) + (j+1)/2));
}

int main(){
	printf("Enter 2 numbers: ");
	int a,b;
	scanf("%d", &a);
	scanf("%d", &b);
	int *p = smallest(&a,&b);
	printf("Smallest of the two: %d", *p);
	swap(&a,&b);
	printf("After Swap: a = %d, b = %d",a,b);

	int row,col;
	printf("Enter number of rows,cols: ");
	scanf("%d,%d", &row,&col);
	int ar[row][col];
	printf("Enter elements: ");
	for(int r = 0; r < row; r++){
		for(int c = 0; c<col; c++){
			scanf("%d",&ar[r][c]);
		}
	}
	center(ar,row,col);


}