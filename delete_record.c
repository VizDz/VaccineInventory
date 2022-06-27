#include "main.h"

void delvac() {

	FILE* fv;
	vaccine vac, vac1[200];

	int cnt1 = 1, i = 0, j;
	char codename[10];

	printf("\n***REMOVE VACCINE RECORD***\n");
	while (cnt1 == 1) {
		fseek(stdin, 0, SEEK_END);
		printf("\nEnter Vaccine Code  : ");
		fgets(vac.vcode, 10, stdin);
		vac.vcode[strcspn(vac.vcode, "\n")] = 0;  //To remove newline (\n). Also can an use ==> vac.vcode[strlen(vac.vcode) - 1] = 0;
		strcpy(codename, vac.vcode);
		cnt1 = codechecker2(codename);
	}

	fv = fopen("vaccine.txt", "r");
	if (fv == NULL) {
		printf("\nFILE NOT FOUND\n\n");
		return;
	}

	while (!feof(fv)) {		
		fscanf(fv, "%[^,],%[^,],%[^,],%f,%f,%lf\n", vac.vcode, vac.vname, vac.vprod, &vac.vdosage, &vac.vpopul, &vac.vquantity);
		if (strcmp(codename, vac.vcode) != 0) {
			strcpy(vac1[i].vcode, vac.vcode);
			strcpy(vac1[i].vname, vac.vname);
			strcpy(vac1[i].vprod, vac.vprod);
			vac1[i].vdosage = vac.vdosage;
			vac1[i].vpopul = vac.vpopul;
			vac1[i].vquantity = vac.vquantity;
			i++;
		}
	}
	fclose(fv);

	fv = fopen("vaccine.txt", "w");
	for (j = 0; j < i; j++) {
		fprintf(fv, "%s,%s,%s,%.2f,%.2f,%.2f\n", vac1[j].vcode, vac1[j].vname, vac1[j].vprod, vac1[j].vdosage, vac1[j].vpopul, vac1[j].vquantity);
	}
	fclose(fv);

	printf("\n>>>SUCCESS REMOVE THE RECORD :)<<<\n");
	return;
}