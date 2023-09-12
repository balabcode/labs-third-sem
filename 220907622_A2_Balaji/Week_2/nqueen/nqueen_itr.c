#include <stdio.h>

int place(int n, int placed, int row_pos[], int col_pos[], int r, int c){
	n--;
	row_pos[placed] = r;
	col_pos[placed] = c;
}
int nqueen(int n, int rows, int cols){
	int row_pos[n],col_pos[n];
	for (int r = 0; r < rows; r++){
		for(int c = 0; c < cols; c++){
			place(n,r,row_pos,col_pos,r,c);
		}
	}
}
