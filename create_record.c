#include "main.h"

void addvac() {

	FILE* fv;
	vaccine vac;
	int cnt, cnt1, i;
	char codename[10];

	printf("\nEnter Number of Vaccine : ");
	scanf("%d", &cnt);

	for (i = 0; i < cnt; i++) {
		cnt1 = 0;
		while (cnt1 == 0) {
			printf("\nVaccine Number %d", i + 1);
			fseek(stdin, 0, SEEK_END);			// To avoid buffer, use this before getting input by using fgets | SEEK_END : It denotes end of the file.
			printf("\nEnter Vaccine Code\t\t: ");
			fgets(vac.vcode, 10, stdin);			
			vac.vcode[strcspn(vac.vcode, "\n")] = 0; //remove newline that automatically assigned to value if using fgets
			strcpy(codename, vac.vcode);
			cnt1 = codechecker1(codename);   //send the vaccine code to be checked.
			strcpy(vac.vcode, codename);	//Copy because the vac.vcode get the vcode from codechecker1, to prevent wrong inputted data then need to copy.
		}

		printf("Enter Vaccine Name\t\t: ");
		fgets(vac.vname, 50, stdin);
		vac.vname[strcspn(vac.vname, "\n")] = 0;

		printf("Enter Producing Country\t\t: ");
		fgets(vac.vprod, 50, stdin);
		vac.vprod[strcspn(vac.vprod, "\n")] = 0;

		printf("Enter Dosage Required\t\t: ");
		scanf("%f", &vac.vdosage);

		printf("Enter Population Covered (%%)\t: ");
		scanf("%f", &vac.vpopul);

		vac.vquantity = 0;
		while (vac.vquantity < 1000000) {
			printf("\nMinimum Quantity is 1000000 !!!\nEnter Vaccine Quantity(Million)\t: ");
			scanf("%lf", &vac.vquantity);
		}

		fv = fopen("vaccine.txt", "a");
		if (fv == NULL) {
			printf("\nFile Not Found :(");
			return;
		}

		fprintf(fv, "%s,%s,%s,%.2f,%.2f,%.2f\n", vac.vcode, vac.vname, vac.vprod, vac.vdosage, vac.vpopul, vac.vquantity); //Save to vaccine.txt
		printf("\nSaved to File\n");

		fclose(fv);

	}
	return;
}
