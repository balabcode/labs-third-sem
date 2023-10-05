#include <stdio.h>

int sparse_check(int row, int col, int a[][col]){
	int count = 0;
	for(int r = 0; r < row; r++){
		for(int c = 0; c<col; c++){
			if(a[r][c] == 0){
				count++;
			}
		}
	}
	if (count > (int)row*col/2)
		printf("sparse\n");
	else
		printf("dense\n");
}
int main(){
	//int a[][3] = {{0,1,0},{0,2,1},{0,0,2}};
	int row, col;
	printf("Enter number of rows,cols: ");
	scanf("%d,%d", &row,&col);
	int a[row][col];
	printf("Enter elements: ");
	for(int r = 0; r < row; r++){
		for(int c = 0; c<col; c++){
			scanf("%d",&a[r][c]);
		}
	}
	sparse_check(row,col,a);
	return 0;
}