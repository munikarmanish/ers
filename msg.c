/* This file contains the functions which displays static texts on the string */

#include "ers.h"

void display_title (void)
{
	printf("================================================================\n");
	printf("Pulchowk Engineering Campus \n");
	printf("Lalitpur, Nepal \n");
	printf("\n");
	printf("EMPLOYEE RECORD SYSTEM\n");
	printf("================================================================\n\n");
}

void welcome (void)
{
	printf("\n");
	printf("WELCOME TO THE EMPLOYEE RECORD SYSTEM \n");
	printf("\n");
	printf("Developed by: \n");
	printf("   Manish Munikar (munikarmanish@gmail.com)\n");
	printf("\n");
}

void main_menu (void) {
	char temp[100];
	int id, choice;

	system("clear");
	display_title();

	printf("%s", 
			"\n"
			"MAIN MENU \n"
			"----------------------------- \n"
			"   1.  View all employees \n"
			"   2.  Add employee \n"
			"   3.  Search employee \n"
			"   4.  Modify employee \n"
			"   5.  Delete employee \n"
			"   6.  Exit \n"
			"\n"
			"Enter your choice: ");

	/* In this project, I've used an universal method of getting input
	 * This is because scanf() and gets() don't work together well (they cause problems for each other)
	 * so the universal method of getting input contains following steps
	 *
	 *  STEP 1: Capture everything the user types in a string (large enough) using fgets()
	 *  STEP 2: Convert that string into any desired data type
	 *
	 * In this project, temp[100] works as the large variable to store everything user types.
	 * Then, we can use
	 *       strtol() function to convert it into integer
	 *       strtof() function to convert it into float
	 */
	getstr(temp, 100, stdin); /* getstr is modification of fgets(). it is defined in util.c file */
	choice = strtol(temp, NULL, 10);
	printf("\n");

	switch (choice) {
		case 1: view_employees(); break;
		case 2: add_employee(); break;
		case 3: search_employee(); break;
		case 4: 
				  printf("Enter ID to modify: "); 
				  id = strtol(getstr(temp, 100, stdin), NULL, 10); /* read all text and convert into integer in single step */
				  modify_employee(id); 
				  break;
		case 5: 
				  printf("Enter ID to delete: "); 
				  id = strtol(getstr(temp, 100, stdin), NULL, 10);
				  delete_employee(id);
				  break;
		case 6: exit(0); break;
		default:  main_menu();
	}
}

void error(const char* error_msg) {
	system("clear");
	display_title();

	printf("ERROR: %s \n", error_msg);
	printf("\n");
	printf("Press [Enter] to goto Main Menu\n");
	getchar();
	main_menu();
}
