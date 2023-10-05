// #include <stdio.h>
// typedef struct{
// 	int day;
// 	int* month;
// 	int year;
// }dob;

// typedef struct{
// 	int reg_no;
// 	char* name;
// 	scanf("%d",&stud.stu.reg_no);
// 	char address[150];
// }stu_info;

// typedef struct{
// 	char* collegeName;
// 	scanf("%d/%d/%d",&stud.db.day,&month,&stud.db.year);
// 	char universityName[150];
// }college;

// typedef struct{
// 	dob *db;
// 	stu_info stu;
// 	college col;
// }student;

// void main(){
// 	student* stud;
// 	int month;
// 	char name[150], collegeName[150];
// 	printf("Enter DD/MM/YYYY for student: ");	
// 	fgets(stud.col.universityName,150,stdin);
// 	stud.db.month = &month;
// 	printf("Enter Name of Student: \n");
// 	fgets(name,150,stdin);
// 	stud.stu.name = name;
// 	printf("Enter Reg. No. of Student: ");	
// 	printf("Enter Address of Student: ");
// 	fgets(stud.stu.address,150,stdin);
// 	printf("Enter College Name: ");
// 	fgets(collegeName,150,stdin);
// 	stud.col.collegeName = collegeName;
// 	printf("Enter University Name: ");
	

// 	//display
// 	printf("DOB: %d/%d/%d",stud.db.day,*stud.db.month,stud.db.year);
// }

#include<stdio.h>
#include<stdlib.h>


typedef struct{
    int day;
    int *month;
    int year;
}DOB;

typedef struct{
    int regNum;
    char *name;
    char address[10000];

}STU_INFO;


typedef struct{
    char *colName;
    char univName[1000];

}COLLEGE;

typedef struct{
    DOB *dob;
    STU_INFO stud;
    COLLEGE col;


}STUDENT;

void *read(STUDENT *stu){
    printf("Enter Student Information");
    printf("\nEnter registration number: ");
    scanf("%d", &(stu->stud.regNum));
    getchar();
    printf("Enter name of student: ");
    fgets(stu->stud.name,1000,stdin);
    printf("Enter address: ");
    fgets(stu->stud.address, 10000, stdin);
    printf("Enter dob (DD MM YYYY): ");
    scanf("%d %d %d", &stu->dob->day, stu->dob->month, &stu->dob->year);
    getchar();
    printf("Enter University Name: ");
    fgets(stu->col.univName, 1000, stdin);
    printf("Enter college name: ");
    fgets(stu->col.colName, 1000, stdin);

}

int main(){
    STUDENT *stu = (STUDENT*)malloc(sizeof(STUDENT));
    stu->dob = (DOB*)malloc(sizeof(DOB));
    stu->dob->month = (int*)malloc(sizeof(int));
    stu->stud.name = (char*)calloc(1000,sizeof(char));
    stu->col.colName = (char*)calloc(1000,sizeof(char));
    read(stu);

    printf("\n\nStudent Name: %s", stu->stud.name);
    printf("Registration Number: %d", stu->stud.regNum);
    printf("\nDate of Birth: %d/%d/%d", stu->dob->day, *(stu->dob->month), stu->dob->year);
    printf("\nUniversity: %s", stu->col.univName);
    printf("College Name: %s", stu->col.colName);
    printf("Student Address: %s", stu->stud.address);
}