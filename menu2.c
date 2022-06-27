
void menu2() {

	int opt2;

	printf("\n\n>>> VACCINE STOCK UPDATE <<< \n");
	printf("\n==========================\n");
	printf("= [1] Add Vaccine Stock  =");
	printf("\n==========================\n");
	printf("= [2] Distribute Vaccine =");
	printf("\n==========================\n");
	printf("= [3] Back to Main Menu  =");
	printf("\n==========================\n");
	printf("\n\nYour Option --> ");
	scanf("%d", &opt2);
	while (opt2 > 3 || opt2 < 1) {
		printf("\nWrong Input !!!\n Try Again...\n");
		printf("\nYour Option --> ");
		scanf("%d", &opt2);
	}
	if (opt2 == 1)
		addstock();
	else if (opt2 == 2)
		distock();
	else
		menu1();
	return;
}