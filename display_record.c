#include "main.h"

void displayvac()
{

	FILE* fv;
	vaccine vac;
	int i = 0;
	fv = fopen("vaccine.txt", "r");
	if (fv == NULL) {
		printf("\nFile Not Found");
		return;
	}

	printf("\n\n\n\t\t\t\t     ***** VACCINE INVENTORY *****\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	printf("| NO | NAME OF VACCINE | VACCINE CODE | PRODUCING COUNTRY | DOSAGE REQUIRED | POPULATION COVERED (%%) |    QUANTITY   |\n");
	printf("----------------------------------------------------------------------------------------------------------------------\n");
	while (!feof(fv)) {
		i = i + 1;
		fscanf(fv, "%[^,],%[^,],%[^,],%f,%f,%lf\n", vac.vcode, vac.vname, vac.vprod, &vac.vdosage, &vac.vpopul, &vac.vquantity); 

		printf("  %d      %-15s     %-15s   %-18s %-18.1f  %-15.1f   %.0f",i, vac.vname, vac.vcode, vac.vprod, vac.vdosage, vac.vpopul, vac.vquantity);
		printf("\n----------------------------------------------------------------------------------------------------------------------\n");
	}			
	fclose(fv);
	return;
}
