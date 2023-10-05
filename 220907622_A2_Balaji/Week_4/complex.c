#include <stdio.h>
typedef struct{
	int real;
	int img;
}Complex;

Complex add(Complex a1, Complex a2){
	Complex res;
	res.real = a1.real + a2.real;
	res.img = a1.img + a2.img;
	return res;
}
Complex subtract(Complex a1, Complex a2){
	Complex res;
	res.real = a1.real - a2.real;
	res.img = a1.img - a2.img;
	return res;
}
Complex multiply(Complex a1, Complex a2){
	Complex res;
	res.real = a1.real*a2.real - a1.img*a2.img;
	res.img = a1.real*a2.img + a1.img*a2.real;
	return res;
}
void prints(Complex res){
	if(res.img < 0)
		printf("%d%di\n",res.real,res.img);
	else
		printf("%d + %di\n",res.real,res.img);
}

void main(){
	Complex a1,a2;
	printf("Enter coeff for a1: ");
	scanf("%d %d",&a1.real, &a1.img);
	printf("Enter coeff for a2: ");
	scanf("%d %d",&a2.real, &a2.img);
	Complex res = add(a1,a2);
	printf("Add: "); prints(res);
	res = subtract(a1,a2);
	printf("Subtract: ");prints(res);
	res = multiply(a1,a2);
	printf("Multiply: "); prints(res);
}