#include "main.h"			//THE MAIN MENU WHICH IS CONSIST OF ALL AVAILABLE OPTION
#include "menu1.h"			//THE MAIN MENU WHICH IS CONSIST OF ALL AVAILABLE OPTION
#include "menu2.h"			//MENU TO CHOOSE THE USER WANT TO ADD VACCINE STOCK OR DISTRIBUTE THE VACCINE
#include "display_record.h"	//TO DISPLAY THE VACCINE LIST AND THE CURRENT QUANTITY
#include "create_record.h"	//TO ADD VACCINE RECORD AND SAVE IT TO vaccine.txt
#include "code_checker.h"	//TO CHECK THE VACCINE CODE EXIST OR NOT
#include "update_quantity.h"//TO UPDATE THE CURRENT QUANTITY (ADD NEW AMOUNT OR DISTRIBUTE)
#include "search.h"			//TO SEARCH AVAILABLE VACCINE RECORD AND DISPLAY THE VACCINE INFORMATION
#include "display_sort.h"	//TO DISPLAY THE TOTAL OF EACH DISTRIBUTED VACCINE IN DESCENDING ORDER
#include "delete_record.h"	//TO DELETE VACCINE RECORD


int main() {
	
	char opt1[10] = "Y";
	
	while ((strcmp(opt1, "Y") == 0) || (strcmp(opt1, "y") == 0)) { //strcmp = string compare, to compare the value of char based on ASCII
		system("cls");			//To clearscreen. Can comment that system("cls") if won't clear the screen
		menu1();				//menu1 function which consist of all available options.
		fseek(stdin, 0, SEEK_END);	// To avoid buffer, use this before getting input by using fgets | SEEK_END : It denotes end of the file.
		printf("\nYou want to Continue ? (Y/N)\n");
		fgets(opt1, 10, stdin);
		opt1[strcspn(opt1, "\n")] = 0;	//remove newline inside the variable.

		while ((strcmp(opt1, "Y") != 0) && (strcmp(opt1, "y") != 0)  && (strcmp(opt1, "N") != 0) && (strcmp(opt1, "n") != 0)) {
			fseek(stdin, 0, SEEK_END);
			printf("\nWrong Input !!!\nYou want to Continue ? (Y/N)\n");
			fgets(opt1, 10, stdin);
			opt1[strcspn(opt1, "\n")] = 0; //remove newline that automatically assigned to value if using fgets
		}								// calculates the length of the number of characters before the 1st occurrence of character present in both the string.
	}									

	if ((strcmp(opt1, "N") == 0) || (strcmp(opt1, "n") == 0)) {		
		remove("tempo.txt");		//remove the temporary just in case it not deleted in display_sort part
		printf("\nThank You for Using the Program :)\n");
		printf("\n>>Exited<<\n");

	}
	return 0;

}