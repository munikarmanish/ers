#include "ers.h"

int main (void) 
{   
	system("clear");
	display_title();
	welcome();

	printf("\nPress [Enter] key to enter the program.\n");
	getchar();

	main_menu();

	return 0;
}
