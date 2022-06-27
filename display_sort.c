#include "main.h"

void getvaccode() {

	FILE* fd, * ftp;
	vaccine vac, vac1[200];

	char line[300];
	char linex[300][300];
	int l, j, k;
	int x = 0, i = 0;

	fd = fopen("dist.txt", "r");
	ftp = fopen("tempo.txt", "w");

	if (fd == NULL) {
		printf("\nFile not Found\nDo the distribution first :/\n");
		fclose(ftp);
		remove("tempo.txt");
		return 0;
	}

	while (fgets(line, 300, fd)) {				//Get the available vaccine code from dist.txt.
		sscanf(line, "%[^,],%[^,],%[^,],%[^,],%lf\n", vac.vcode, vac.vname, vac.hospital, vac.dated, &vac.numd); 

		char* tmp = strtok(line, ",");
		strcpy(vac1[x].vcode, tmp);
		x = x + 1;
	}

	for (i = 0; i < x; i++) {					//Write the code to Temporary file
		fprintf(ftp, "%s\n", vac1[i].vcode);
	}

	fclose(ftp);
	fclose(fd);

	ftp = fopen("tempo.txt", "r");

	if (ftp == NULL) {
		printf("\nTEMP FILE NOT FOUND");
		remove("tempo.txt");
		return;
	}

	l = 0;
	while (fgets(linex[l], 300, ftp))
	{
		linex[i][strlen(linex[l]) - 1] = '\0';			//Store the vaccine code into array
		l++;
	}

	fclose(ftp);

	for (i = 0; i < l; i++) {
		for (j = i + 1; j < l;) {
			if (strcmp(linex[i], linex[j]) == 0) {
				for (k = j + 1; k < l; k++) {
					strcpy(linex[k - 1], linex[k]);				//Remove the duplicate vaccine code
				}
				l--;
			}
			else {
				j++;
			}
		}
	}
	ftp = fopen("tempo.txt", "w");

	for (i = 0; i < l; i++) {				//Save the vaccine code to temporary file after remove the duplicated one.
		fprintf(ftp, "%s", linex[i]);			
	}

	fclose(ftp);
	return;
}

void getotdist() {

	FILE* ftp, * fd;
	vaccine vac, vac1[200], vac2[200];

	int i = 0, j = 0;

	ftp = fopen("tempo.txt", "r");

	if (ftp == NULL) {
		remove("tempo.txt");
		return 0;
	}

	while (!feof(ftp)) {						//While Loop to get the total distribution of each vaccine
		fscanf(ftp, "%s\n", vac2[i].vcode);

		vac1[j].tnumd = 0;
		fd = fopen("dist.txt", "r");

		while (!feof(fd)) {
			fscanf(fd, "%[^,],%[^,],%[^,],%[^,],%lf\n", vac.vcode, vac.vname, vac.hospital, vac.dated, &vac.numd);
			if (strcmp(vac.vcode, vac2[i].vcode) == 0) {
				vac1[j].tnumd = vac1[j].tnumd + vac.numd;
				strcpy(vac1[j].vcode, vac.vcode);
				strcpy(vac1[j].vname, vac.vname);
			}
		}
		j = j + 1;
		i = i + 1;
		fclose(fd);
	}
	fclose(ftp);

	ftp = fopen("tempo.txt", "w");				//Save the data of each total distributed vaccine in temporary file.
	for (j = 0; j < i; j++) {
		fprintf(ftp, "%s,%s,%.2f\n", vac1[j].vcode, vac1[j].vname, vac1[j].tnumd);
	}

	fclose(ftp);

	return;
}

void displaysort() {

	FILE* ftp;
	vaccine vac1[200], temp;

	int size, i = 0, j = 0, swap = 1;
	char* ch;

	getvaccode();

	getotdist();

	ftp = fopen("tempo.txt", "r");
	if (ftp == NULL)
	{
		return;
	}

	while (1)				//Get the size of file (How many line in file).
	{
		fscanf(ftp, "%[^,],%[^,],%lf", vac1[i].vcode, vac1[i].vname, &vac1[i].tnumd);
		ch = fgetc(ftp);
		if (ch == EOF)break;
		i++;
	}
	fclose(ftp);

	size = i;

	for (i = 0; i < size && swap == 1; i++)
	{
		swap = 0;

		for (j = 0; j < size - i - 1; ++j)

			if (vac1[j].tnumd < vac1[j + 1].tnumd)					//Bubble Sort.
			{
				temp = vac1[j];
				vac1[j] = vac1[j + 1];
				vac1[j + 1] = temp;
				swap = 1;
			}
	}

	printf("\n\n\n\t\t\t        ***** DISTRIBUTED VACCINE LIST *****\n");				//Print the sorted record.
	printf("\t\t   ---------------------------------------------------------------\n");
	printf("\t\t   | NO | NAME OF VACCINE | VACCINE CODE | DISTRIBUTED QUANTITY  |\n");
	printf("\t\t   ---------------------------------------------------------------\n");
	for (j = 0; j < size; j++) {
		printf("\t\t     %-5d  %-20s %-15s %.0f\n", j + 1, vac1[j].vname, vac1[j].vcode, vac1[j].tnumd);
		printf("\t\t   ---------------------------------------------------------------\n");
	}

	remove("tempo.txt");	//Remove the temporary file.
	return;
}

