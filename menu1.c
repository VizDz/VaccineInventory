
void menu1() {

	int opt;

	printf("\n");
	printf("\t\t\t\t   ================================\n");
	printf("\t\t\t\t   =   VACCINE INVENTORY SYSTEM   =\n");
	printf("\t\t\t\t   ================================ by:Kevin A [TP058396]");

	displayvac();			//Display the table of all vaccine information.

	printf("\n\t\t\t\t\t >>Available Option<<\n");
	printf("\t\t\t\t ====================================\n");
	printf("\t\t\t\t = [1] Create Vaccine Record        =\n");
	printf("\t\t\t\t ====================================\n");
	printf("\t\t\t\t = [2] Update Vaccine Stock         =\n");
	printf("\t\t\t\t ====================================\n");
	printf("\t\t\t\t = [3] Search & Display Vaccine     =\n");
	printf("\t\t\t\t ====================================\n");
	printf("\t\t\t\t = [4] Produce Vaccine List         =\n");
	printf("\t\t\t\t ====================================\n");
	printf("\t\t\t\t = [5] Delete Vaccine Record        =\n");
	printf("\t\t\t\t ====================================\n");
	printf("\t\t\t\t = [6] Exit the Program :(          =\n");
	printf("\t\t\t\t ====================================\n");
	printf("\n\nYour Option --> ");
	scanf("%d", &opt);
	while (opt > 6 || opt < 1) {
		printf("\nWrong Input !!!\n Try Again...\n");
		printf("\nYour Option --> ");
		scanf("%d", &opt);
	}
	if (opt == 1)
		addvac();			
	else if (opt == 2)
		menu2();			
	else if (opt == 3)
		search();		
	else if (opt == 4)
		displaysort();
	else if (opt == 5)
		delvac();
	else {
		printf("\nThank You for Using the Program :)\n");
		printf("\n>>Exited<<\n");
		exit(0);		//TO EXIT, exit(0) mean Reports the successful termination/completion of the program or when the program gets executed without any error.
	}
	return;
}




		