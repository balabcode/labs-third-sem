#include <stdio.h>
#include <stdlib.h>

int multiply(int row1, int col1, int** m1, int row2, int col2, int** m2){
	if(col1 != row2){
		printf("Not multiplicable\n");
		exit(0);
	}
//	int result[row1][col2];
	int** result = (int **) calloc(row1, sizeof(int*));
	for(int i = 0; i < row1; ++i){
		result[i] = (int *) calloc(col2, sizeof(int));
	}
	for (int r = 0; r < row1; r++){
		for (int c = 0; c < col2; c++){
			// result[r][c]= 0;
			*(*(result+r)+c) = 0;
			for(int k = 0; k < row2; k++){
				// result[r][c] += m1[r][k]*m2[k][c];
				*(*(result+r)+c) += *(*(m1+r)+k) * *(*(m2+k)+c);
			}
		}
	}
	printf("Result: \n");
	for (int r = 0; r < row1; r++){
		for (int c = 0; c < col2; c++){
			printf("%d\t",*(*(result+r)+c));
		}
		printf("\n");
	}
	return 0;
}
int main(){
	int row1, col1;
	printf("Enter number of rows,cols: ");
	scanf("%d,%d", &row1,&col1);
	// int m1[row1][col1];
	int** m1 = (int **) calloc(row1, sizeof(int*));
	for(int i = 0; i < row1; ++i){
		m1[i] = (int *) calloc(col1, sizeof(int));
	}
	printf("Enter elements: ");
	for(int r = 0; r < row1; r++){
		for(int c = 0; c<col1; c++){
			scanf("%d",&m1[r][c]);
		}
	}
	int row2, col2;
	printf("Enter number of rows,cols: ");
	scanf("%d,%d", &row2,&col2);
	// int m2[row2][col2];
	int **m2 = (int **) calloc(row2, sizeof(int*));
	for(int i = 0; i < row2; ++i){
		m2[i] = (int *) calloc(col2, sizeof(int));
	}
	printf("Enter elements: ");
	for(int r = 0; r < row2; r++){
		for(int c = 0; c<col2; c++){
			scanf("%d",&m2[r][c]);
		}
	}

	multiply(row1,col1,m1,row2,col2,m2);
	return 0;
}