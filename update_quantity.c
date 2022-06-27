#include "main.h"

void addstock() {

	FILE* fv;
	vaccine vac, vac1[200];

	char codename[10];
	int cnt1 = 1, i = 0, j;
	double vacadd;

	printf("\n***ADD VACCINE STOCK***\n");

	while (cnt1 == 1) {
		fseek(stdin, 0, SEEK_END);
		printf("\nEnter Vaccine Code : ");
		fgets(vac.vcode, 10, stdin);
		vac.vcode[strcspn(vac.vcode, "\n")] = 0;
		strcpy(codename, vac.vcode);
		cnt1 = codechecker2(codename);			//Send the code to check the code availability 
	}

	fv = fopen("vaccine.txt", "r");

	if (fv == NULL) {
		printf("\nFILE NOT FOUND\n\n");
		return;
	}

	printf("\nEnter Vaccine Quantity : ");
	scanf("%lf", &vacadd);
	while (vacadd <= 0 ) {
		printf("\nThe Quantity Cannot 0 or Minus !!!\nEnter Vaccine Quantity : ");
		scanf("%lf", &vacadd);
	}

	while (!feof(fv)) {
		fscanf(fv, "%[^,],%[^,],%[^,],%f,%f,%lf\n", vac.vcode, vac.vname, vac.vprod, &vac.vdosage, &vac.vpopul, &vac.vquantity);
		if (strcmp(codename, vac.vcode) == 0) {
			vac1[i].vquantity = vacadd + vac.vquantity;
			strcpy(vac1[i].vcode, vac.vcode);
			strcpy(vac1[i].vname, vac.vname);
			strcpy(vac1[i].vprod, vac.vprod);
			vac1[i].vdosage = vac.vdosage;
			vac1[i].vpopul = vac.vpopul;
		}

		else {
			strcpy(vac1[i].vcode, vac.vcode);
			strcpy(vac1[i].vname, vac.vname);
			strcpy(vac1[i].vprod, vac.vprod);
			vac1[i].vdosage = vac.vdosage;
			vac1[i].vpopul = vac.vpopul;
			vac1[i].vquantity = vac.vquantity;
		}
		i++;
	}
	fclose(fv);

	fv = fopen("vaccine.txt", "w");
	for (j = 0; j < i; j++) {
		fprintf(fv, "%s,%s,%s,%.2f,%.2f,%.2f\n", vac1[j].vcode, vac1[j].vname, vac1[j].vprod, vac1[j].vdosage, vac1[j].vpopul, vac1[j].vquantity);
	}
	fclose(fv);
	printf("\n>>>SUCCESS UPDATE THE STOCK :)<<<\n");
	return;
}

void distock() {

	FILE* fv, * fd;
	vaccine vac, vac1[200];

	int cnt1 = 1, i = 0, j;
	char codename[10];

	printf("\n***DISTRIBUTE VACCINE***\n");

	while (cnt1 == 1) {
		fseek(stdin, 0, SEEK_END);
		printf("\nEnter Vaccine Code : ");
		fgets(vac.vcode, 10, stdin);
		vac.vcode[strcspn(vac.vcode, "\n")] = 0;  //TO REMOVE \n. Can use ==> vac.vcode[strlen(vac.vcode) - 1] = 0;
		strcpy(codename, vac.vcode);
		cnt1 = codechecker2(codename);			  //Send the code to check the code availability 
	}

	fv = fopen("vaccine.txt", "r");
	

	if (fv == NULL) {
		printf("\nFILE NOT FOUND\n\n");
		return;
	}

	printf("\nEnter Hospital\t\t: ");
	fgets(vac.hospital, 50, stdin);
	vac.hospital[strcspn(vac.hospital, "\n")] = 0;

	printf("Enter Date (dd/mm/yy)\t: ");
	fgets(vac.dated, 50, stdin);
	vac.dated[strcspn(vac.dated, "\n")] = 0;

	fd = fopen("dist.txt", "a");

	while (!feof(fv)) {
		fscanf(fv, "%[^,],%[^,],%[^,],%f,%f,%lf\n", vac.vcode, vac.vname, vac.vprod, &vac.vdosage, &vac.vpopul, &vac.vquantity);

		if (strcmp(codename, vac.vcode) == 0) {
			printf("\nEnter Distribute Quantity : ");
			scanf("%lf", &vac.numd);
			while (vac.numd > vac.vquantity || vac.numd <= 0) {
				printf("\nThe Number Exceed Vaccine Initial Quantity !!!\nEnter Distribute Quantity : ");
				scanf("%lf", &vac.numd);
			}
			vac1[i].vquantity = vac.vquantity - vac.numd;
			strcpy(vac1[i].vcode, vac.vcode);
			strcpy(vac1[i].vname, vac.vname);
			strcpy(vac1[i].vprod, vac.vprod);
			vac1[i].vdosage = vac.vdosage;
			vac1[i].vpopul = vac.vpopul;

			fprintf(fd, "%s,%s,%s,%s,%.2f\n", vac.vcode, vac.vname, vac.hospital, vac.dated, vac.numd);	//SAVE THE DATA TO dist.txt
		}

		else {
			strcpy(vac1[i].vcode, vac.vcode);
			strcpy(vac1[i].vname, vac.vname);
			strcpy(vac1[i].vprod, vac.vprod);
			vac1[i].vdosage = vac.vdosage;
			vac1[i].vpopul = vac.vpopul;
			vac1[i].vquantity = vac.vquantity;
		}
		i++;
	}

	fclose(fd);
	fclose(fv);

	fv = fopen("vaccine.txt", "w");
	for (j = 0; j < i; j++) {
		fprintf(fv, "%s,%s,%s,%.2f,%.2f,%.2f\n", vac1[j].vcode, vac1[j].vname, vac1[j].vprod, vac1[j].vdosage, vac1[j].vpopul, vac1[j].vquantity);
	}
	fclose(fv);

	printf("\n>>>SUCCESS DISTRIBUTE THE VACCINE :)<<<\n");
	return;
}



