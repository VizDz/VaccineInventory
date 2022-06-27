#include "main.h"

void search() {

	FILE* fv;
	vaccine vac;

	char codename[10];
	int cnt1 = 1, i = 0;

	printf("\n***SEARCH VACCINE***\n");

	while (cnt1 == 1) {
		fseek(stdin, 0, SEEK_END);				
		printf("\nEnter Vaccine Code\t\t: ");
		fgets(vac.vcode, 10, stdin);
		vac.vcode[strcspn(vac.vcode, "\n")] = 0;
		strcpy(codename, vac.vcode);
		cnt1 = codechecker2(codename);		//Send the code to check the code availability 
	}

	fv = fopen("vaccine.txt", "r");
	if (fv == NULL) {
		printf("\nFILE NOT FOUND\n\n");
		return;
	}

	while (!feof(fv)) {
		fscanf(fv, "%[^,],%[^,],%[^,],%f,%f,%lf\n", vac.vcode, vac.vname, vac.vprod, &vac.vdosage, &vac.vpopul, &vac.vquantity);
		if (strcmp(codename, vac.vcode) == 0) {
			printf("\n-------------------------------------");
			printf("\nVaccine Code\t\t: %s", vac.vcode);
			printf("\n-------------------------------------");
			printf("\nVaccine Name\t\t: %s", vac.vname);
			printf("\n-------------------------------------");
			printf("\nProducing Country\t: %s", vac.vprod);
			printf("\n-------------------------------------");
			printf("\nDosage Required\t\t: %.1f", vac.vdosage);
			printf("\n-------------------------------------");
			printf("\nPopulation Covered\t: %.1f %%", vac.vpopul);
			printf("\n-------------------------------------");
			printf("\nVaccine Quantity\t: %.0f", vac.vquantity);
			printf("\n-------------------------------------\n");
		}
	}
	fclose(fv);
	return;
}