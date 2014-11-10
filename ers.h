#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct _employee {
	int id;
	char name[50];
	char addr[50];
	char phone[15];
	char dept[50];
	float salary;
};

/* We'll give the above struct a "nickname" to make it easier to use. */
typedef struct _employee EMPLOYEE;


/* function prototypes (declarations) */

/* msg.c */
void display_title (void);        // diaplays the title (on every page)
void welcome (void);              // displays the welcome screen (when  the app loads)
void main_menu (void);            // displays the main menu
void error (const char* error_msg);  // displays an error message

/* util.c */
char* getstr (char* string, int size, FILE* file_ptr);    // modification of fgets() - it is used for all input tasks to avoid use of scanf() gets()
int no_of_records (FILE* file, int element_size);         // returns the no of records of given size in a file
char* strcase (char* string, int flag);                   // converts a string into uppercase (flag=1) or lowercase (flag=0)
int emp_cmp (const void *e1, const void *e2);             // compares

/* db.c */
void add_employee (void);
void search_employee (void);
void search_by_id (int id);
void search_by_name (char* name);
void modify_employee (int id);
void delete_employee (int id);
void view_employees (void);
