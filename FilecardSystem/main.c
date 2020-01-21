#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINES 30
#define ELEMENTS 100+1

struct filecard 
{
    int n;
    char name[20+1];
    int age;
};

struct filecard students[ELEMENTS];


/* **** function prototypes **** */
void init_struct (void);
void clearscreen (int);
void print_menu (void);
void press_enter (void);
void add_element (struct filecard * ptr);
void show_list (struct filecard * ptr);
void remove_element (struct filecard * ptr);
void edit_element(struct filecard * ptr);

int main (void) {
    char choice;
    struct person * s_ptr;
    s_ptr = students;

    init_struct();
    clearscreen (LINES);
    print_menu ();

    choice = getchar();
    getchar ();                 /* read CR from keyboard buffer */
    while (choice != '0') {
        switch (choice) {
            case '1': printf ("add element\n");
                add_element(s_ptr);
                break;
            case '2': printf ("show / print elements\n");
                show_list(s_ptr);
                break;
            case '3': printf ("remove element\n");
                remove_element(s_ptr);
                break;
            case '4': printf ("search element\n");
                search_element(s_ptr);
                break;
            case '5': printf ("swap element\n");
                break;
            case '6': printf ("sort elements\n");
                break;
            case '7': printf ("edit an element\n");
                break;
            case '8': printf ("post in social media\n");
                break;
            case '9': printf ("free / clean / drop all elements\n");
                init_struct();
                break;
            case 'S':
            case 's': printf ("save to disk\n");
                break;
            case 'L':
            case 'l': printf ("load from disk\n");
                break;
            default : break;
        } /* end of switch */
        press_enter ();
        clearscreen (LINES);
        print_menu ();
        choice = getchar();
        getchar ();                  /* read CR from keyboard buffer */
    } /* end of while */
    printf ("Thanks for using the modern file-card system.\n");
    return (0);
}

void init_struct (void) {
    int i;
    for (i=0; i<ELEMENTS; i++) strcpy(students[i].name, "NULL"); students[i].age = -1; students[i].n = i;
    students[-1].age = -2;
}

void clearscreen (int lines) {
    int i;
    for (i=0; i<lines; i++) printf ("\n");
}

void print_menu (void) {
    printf (" The modern file-card system\n");
    printf ("-----------------------------\n\n");
    printf ("1. add / insert element\n");
    printf ("2. show / print list\n");
    printf ("3. remove element\n");
    printf ("4. search element in list\n");
    printf ("5. move / swap elements\n");
    printf ("6. sort the list\n");
    printf ("7. edit an element\n");
    printf ("8. post in Social Media\n");
    printf ("9. free / clean / drop all\n");
    printf ("S. save list on disk\n");
    printf ("L. load list from disk\n");
    printf ("0. quit / leave / exit program\n\n");
    printf ("Please make a choice: ");
}

void press_enter (void) {
    char ch=0;
    printf ("\nPlease press ENTER to continue ...\n");
    while (ch!=10) ch=getchar();
}

void add_element (struct filecard * ptr) {

    while (ptr->age > 0 && ptr->age != -2) ptr ++;
    char sname[20+1];
    int age;
    printf("Insert Student name: ");
    fgets(sname, 21, stdin);
    int len;
    len = strlen(sname);
    if( sname[len-1] == '\n' )
        sname[len-1] = 0;
    strcpy(ptr->name, sname);
    printf("Insert Student Age: ");
    scanf("%d", &age);
    if (age < 0) {
        age = 0;
    }
    ptr->age = age;
    printf("Successfully added Filecard!\n");
}

void show_list (struct filecard * ptr) {
    int i;
    for (i=0; i<ELEMENTS-1; i++) {
        if (ptr->age != -1) {
            printf("[%d] Name: %s\tAge: %d\n",i, ptr->name, ptr->age);
        }
        ptr++;
    }
}

void remove_element (struct filecard * ptr) {
    show_list(ptr);
    int n;
    printf("\nEnter number of Card to remove: ");
    scanf("%d", &n);
    getchar();
    while (ptr->n < n) ptr++;
    ptr->age = -1;
    printf("Removed Student [%d]: %s", ptr->n, ptr->name);
}

void search_name (struct filecard * ptr) {
    char name[20+1];
    printf("Name to search for: ");
    fgets(name, 21, stdin);
    int len;
    len = strlen(name);
    if( name[len-1] == '\n' ) name[len-1] = 0;

    int i;
    for (i=0; i<ELEMENTS-1; i++) {
        if (strncmp(ptr->name, name, 4)==0 && ptr->age != -1) {
            printf("[%d] Name: %s\tAge: %d\n",i, ptr->name, ptr->age);
        }
        ptr++;
    }
    
}

void search_age (struct filecard * ptr) {
    int age;
    printf("Age to search for: ");
    scanf("%d", &age);
    getchar();
    int i;
    for (i=0; i<ELEMENTS-1; i++) {
        if (ptr->age==age) {
            printf("[%d] Name: %s\tAge: %d\n",i, ptr->name, ptr->age);
        }
        ptr++;
    }
}

void search_element (struct filecard * ptr) {
    int c;
    printf("Search for [0] Name or [1] age: ");
    scanf("%d", &c);
    getchar();
    switch(c) {
        case 0: search_name(ptr);
            break;
        case 1: search_age(ptr);
            break;
        default:
            break;
    }
}

void edit_element(struct filecard * ptr) {
    show_list(ptr);
    int n;
    printf("\nEnter number of Card to edit: ");
    scanf("%d", &n);
    getchar();
    while (ptr->n < n) ptr++;


    char sname[20+1];
    int age;
    printf("Insert Student name: ");
    fgets(sname, 21, stdin);
    int len;
    len = strlen(sname);
    if( sname[len-1] == '\n' )
        sname[len-1] = 0;
    strcpy(ptr->name, sname);
    printf("Insert Student Age: ");
    scanf("%d", &age);
    if (age < 0) {
        age = 0;
    }
    ptr->age = age;
}