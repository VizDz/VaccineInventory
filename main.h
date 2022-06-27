#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct vaccine
{
	char vcode[10];		//Vaccine Code
	char vname[50];		//Vaccine Name
	char vprod[50];		//Country that produce the Vaccine
	float vdosage;		//Vaccine Dosage Required
	float vpopul;		//Population Covered
	double vquantity;		//Remaining Vaccine Quantity

	char hospital[50];	//Hospital Name
	char dated[50];		//Date of Distribution
	double numd;		//Distribute Quantity
	double tnumd;		//Total Number of Distributed Vaccine

}vaccine;

