#include <stdio.h>

int hanoi(int disk, char source, char dest, char spare){
	static int count = 0;
	if (disk == 0)
		return count;
	else{
		hanoi(disk-1,source,spare,dest);
		count++;
		hanoi(disk-1,spare,dest,source);
	}
}

int main(){
	printf("Enter number of steps: ");
	int n;
	scanf("%d", &n);
	printf("Steps: %d\n",hanoi(n,'a','b','c'));
	return 0;
}