#include "main.h"

int codechecker1(char codename[]) { //For create record function

	FILE* fv;
	vaccine vac;

	int cnt1 = 1;

	fv = fopen("vaccine.txt", "r");

	if (fv == NULL) {
		printf("\nFILE NOT FOUND\n\n");
		return;
	}
	while (!feof(fv)) {
		fscanf(fv, "%[^,],%[^,],%[^,],%f,%f,%lf\n", vac.vcode, vac.vname, vac.vprod, &vac.vdosage, &vac.vpopul, &vac.vquantity);

		if (strcmp(codename, vac.vcode) == 0) {
			printf("\nCode Exist :(\nTry Again !!!\n");
			cnt1 = 0;
			fclose(fv);
			return cnt1;
		}
	}

	if (cnt1 == 1) {
		fclose(fv);
		return cnt1;
	}
	fclose(fv);
}

int codechecker2(char codename[]) {		//For update quantity functions, search function, and delete function

	FILE* fv;
	vaccine vac;

	int cnt1 = 1;

	fv = fopen("vaccine.txt", "r");

	if (fv == NULL) {
		printf("\nFILE NOT FOUND\n\n");
		return;
	}
	while (!feof(fv)) {
		fscanf(fv, "%[^,],%[^,],%[^,],%f,%f,%lf\n", vac.vcode, vac.vname, vac.vprod, &vac.vdosage, &vac.vpopul, &vac.vquantity);

		if (strcmp(codename, vac.vcode) == 0) {
			printf("\nVaccine Found :)\n");
			cnt1 = 0;
			fclose(fv);
			return cnt1;
		}
	}
	if (cnt1 == 1) {
		fclose(fv);
		printf("\nVaccine not Exist :(\nTry Again !!!\n");
		return cnt1;
	}
	fclose(fv);
}


