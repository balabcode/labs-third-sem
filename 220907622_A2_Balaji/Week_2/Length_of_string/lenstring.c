#include <stdio.h>

void copystring(char str[], char cpystr[], int i){
	//base case
	if (str[i] == '\0'){
		return;
	}
	else{
		cpystr[i] = str[i];
		copystring(str,cpystr,i+1);
	}
}

int main(){
	char str[100];
	printf("Enter a string: ");
	fgets(str,100,stdin);
	char cpystr[100];
	copystring(str,cpystr,0);
	printf("String is: %s\n", cpystr);
	return 0;
}