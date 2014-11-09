#include "ers.h"

/* This function is a modified version of fgets()
 * It is required because scanf() and gets() don't work together well!
 * Plus, the fgets() has a slight problem
 */
char * getstr(char* string, int size, FILE* file_ptr)
{
	int len;

	fgets(string, size, file_ptr);
	len = strlen(string);

	/* after typing the text, we hit [Enter] key to submit the text.
	 * but fgets() takes that [Enter] character (which is '\n') as a part of the input.
	 * So when we print the string, a new line is automatically printed at the end.
	 * To solve this problem, we create a new function that converts that last '\n' into '0\
	 */

	if (len>0 && string[len-1]=='\n')
		string[len-1] = '\0';

	return string;
}

/* This function returns the no of records of size 'element_size' in a file */
int no_of_records(FILE* file, int element_size) {
	rewind(file); /* goes to the beginning of the file */
	int count = 0;
	char c; /* a place to hold every byte of file through the loop */
	while (!feof(file)) {            /* until we reach the end of file */
		fread(&c, 1, 1, file);        /* read a single byte             */
		count++;                      /* add the counter by 1           */
	}

	/* now we know the size of the file in bytes.
	 * Divide that by the size of single element, and we get the "number" of elements.
	 * In this project, the element is an employee struct
	 */

	rewind(file); /* go back to the beginning of file */
	return count/element_size; /* return number of elements */
}


/* A function to convert whole string into uppercase or lowercase */
char* strcase(char* string, int flag) {
	/* if flag=1, into uppercase
	 * if flag=0, into lowercase
	 */

	int len = strlen(string);

	char newstring[100];

	int i;
	for (i=0; i<=len; i++) { /* copy all the character of string to newstring */
		if (flag)      /* if flag=1, then convert all characters into uppercase and copy */
			newstring[i] = toupper(string[i]);
		else           /* if flag=0, then convert all characters into lowercase and copy */
			newstring[i] = tolower(string[i]);
	}

	return newstring;
}


/* a function to compare two employees (to be used with qsort() function) */
int emp_cmp (const void *e1, const void *e2)
{
	if (((EMPLOYEE*)e1)->id < ((EMPLOYEE*)e2)->id) return -1;
	else if (((EMPLOYEE*)e1)->id == ((EMPLOYEE*)e2)->id) return 0;
	else return 1;
}
