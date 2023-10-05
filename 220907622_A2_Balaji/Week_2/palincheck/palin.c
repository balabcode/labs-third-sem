#include <stdio.h>
#include <string.h>

int palincheck(char str[], int ri, int li){
	if (li > ri)
		return 1;
	else if (str[ri] != str[li])
		return 0;
	else{
		palincheck(str,ri-1,li+1);
	}
}

int main(){
	printf("Enter string: ");
	char str[100];
	fgets(str,100,stdin);
	if(palincheck(str,strlen(str)-2,0) == 1){
		printf("Palindrome\n");
	}
	else{
		printf("Not a palindrome\n");
	}
	return 0;
}