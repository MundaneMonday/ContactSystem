//==============================================
// Name:           Andrew Qin
// Student Number: 132244195
// Email:          aqin1@myseneca.ca
// Section:        NPP
// Date:
//==============================================
// Assignment:     2
// Milestone:      3
//==============================================

#define _CRT_SECURE_NO_WARNINGS
//define MAX CONTACTS for sizing content array(5):
#define MAXCONTACTS 5


#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:

#include <string.h>
#include <ctype.h>
// Include your contactHelpers header file on the next line:

#include "contactHelpers.h"
//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition
void clearKeyboard(void)
{
	while (getchar() != '\n');

}

// pause: Empty function definition goes here:
void pause(void) {
	printf("(Press Enter to Continue)");
	clearKeyboard();

}


// getInt: Empty function definition goes here:

int getInt(void) {
	int integer;
	char newLine = 'x';


	while (newLine != '\n') {
		scanf("%d%c", &integer, &newLine);
		if (newLine != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");

		}
	}

	return integer;
}

// getIntInRange: Empty function definition goes here:

int getIntInRange(int min, int max) {
	int value;

	value = getInt();
	while (value > max || value < min) {
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		scanf("%d", &value);
		clearKeyboard();

	}

	return value;
}

// yes: Empty function definition goes here:

int yes(void) {
	char newLine = 't';
	char response = 't';
	int value;

	while (newLine != '\n') {
		scanf("%c%c", &response, &newLine);

		if (newLine != '\n') {
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
		else if (response == 'y' || response == 'Y') {
			value = 1;
		}
		else if (response == 'n' || response == 'N') {
			value = 0;
		}
		else {
			newLine = 't';
		}

	}


	return value;

}

// menu: Empty function definition goes here:

int menu(void) {
	int option;
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");

	option = getIntInRange(0, 6);
printf("\n");
	return option;


}

// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void)
{
    struct Contact contact [MAXCONTACTS] = { { { "Rick", {'\0'}, "Grimes" },
                   { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
                   { "4161112222", "4162223333", "4163334444" } },
                 {
                    { "Maggie", "R.", "Greene" },
                    { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
                    { "9051112222", "9052223333", "9053334444" } },
{
{ "Morgan", "A.", "Jones" },
{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" }, { "7051112222", "7052223333", "7053334444" } },
                 {
                    { "Sasha", {'\0'}, "Williams" },
                    { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
                    { "9052223333", "9052223333", "9054445555" } },
};

	int option;
	int exit = 0;

	do {
		option = menu();
		switch (option) {
		case 1:
			displayContacts(contact,MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");

			break;
		case 2:
			addContact(contact,MAXCONTACTS);
			break;

		case 3:
			updateContact(contact,MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;
		case 4:
			deleteContact(contact,MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;

		case 5:
			searchContacts(contact,MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");

			break;

		case 6:
			sortContacts(contact,MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;

		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			exit = yes();
			printf("\n");
			break;
		default:
			break;

		}

	} while (exit == 0);


	if (exit == 1) {
		printf("Contact Management System: terminated\n");
	}




}



// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
    int needInput = 1;
    int i=0;

    while (needInput == 1) {
        scanf("%10s", phoneNum);


        // (String Length Function: validate entry of 10 characters)
for(i=0;i<strlen(phoneNum);i++){
         if (!isdigit(phoneNum[i]) || strlen(phoneNum) != 10)
            {
                needInput = 1;
                clearKeyboard();

            }
            else{
                needInput = 0;
            }

if(needInput == 1){
       printf("Enter a 10-digit phone number: ");
 scanf("%10s", phoneNum);
}
}
}
}
// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    int i;
    for(i=0;i<size;i++){
        if(strcmp(contacts[i].numbers.cell,cellNum) == 0){
                return i;
        }

    }
    return -1;
}
// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void) {
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");

}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count) {
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n",count);

}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact) {

 if(strlen((*contact).name.middleInitial)==0){
    printf(" %s %s\n",(*contact).name.firstName,(*contact).name.lastName);
 }else{
     printf(" %s %s %s\n",(*contact).name.firstName,(*contact).name.middleInitial,(*contact).name.lastName);

 }

printf("    C: %-10s   H: %-10s   B: %-10s\n",(*contact).numbers.cell,(*contact).numbers.home,(*contact).numbers.business);

printf("       %d %s, ",(*contact).address.streetNumber,(*contact).address.street);

if((*contact).address.apartmentNumber>0){
printf("Apt# %d, ",(*contact).address.apartmentNumber);}

printf("%s, %s\n",(*contact).address.city,(*contact).address.postalCode);

}
// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size) {

int i=0;
int j=0;
displayContactHeader();
for(i=0;i<size;i++){
    if(strlen(contacts[i].numbers.cell)!=0)
{
    displayContact(&(contacts[i]));
    j++;
}

}
displayContactFooter(j);
}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size) {
int i;
char cellNum[11];
printf("Enter the cell number for the contact: ");
getTenDigitPhone(cellNum);
i=findContactIndex(contacts,size,cellNum);
clearKeyboard();
if(i == -1){
printf("*** Contact NOT FOUND ***\n");

}else{
printf("\n");
   displayContact(&contacts[i]);
}
}


// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size) {
int i=0,index;
index = -1;
for(i=0;i<size;i++){
if(strlen(contacts[i].numbers.cell) == 0) //interating the contact array and finding the first cell phone number with zero string length
{
    index = i;
    break;
}
}
if(index > -1 ){
getContact(&contacts[i]);
printf("--- New contact added! ---\n\n");
pause();
printf("\n");

}
else{

printf("*** ERROR: The contact list is full! ***\n");
printf("\n");
pause();
printf("\n");
}
}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size) {
char cellNum[11];
int index;
int prompt;
printf("Enter the cell number for the contact: ");
getTenDigitPhone(cellNum);
index = findContactIndex(contacts,size,cellNum);
clearKeyboard();
if(index == -1){
    printf("*** Contact NOT FOUND ***\n");
}
else{
        printf("\nContact found:\n");

displayContact(&(contacts[index]));
printf("\n");

printf("Do you want to update the name? (y or n): ");
prompt = yes();
if (prompt == 1){
    getName(&contacts[index].name);
}

printf("Do you want to update the address? (y or n): ");
prompt = yes();
if (prompt == 1){
    getAddress(&contacts[index].address);
}

printf("Do you want to update the numbers? (y or n): ");
prompt = yes();
if (prompt == 1){
    getNumbers(&contacts[index].numbers);
}
printf("--- Contact Updated! ---\n");

}

}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size) {
char cellNum[11];
int index;
int prompt;
printf("Enter the cell number for the contact: ");
getTenDigitPhone(cellNum);
index = findContactIndex(contacts,size,cellNum);
if(index == -1){
    printf("*** Contact NOT FOUND ***\n");
}else{
    printf("\nContact found:\n");
displayContact(&contacts[index]);
clearKeyboard();
printf("\n");
printf("CONFIRM: Delete this contact? (y or n): ");
prompt = yes();
if(prompt == 1){
    strcpy((contacts[index].numbers.cell),"\0");
    strcpy((contacts[index].numbers.business),"\0");
    strcpy((contacts[index].numbers.home), "\0");
    printf("--- Contact deleted! ---\n");
}


}
}

// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size) {
printf("<<< Feature to sort is unavailable >>>\n");
}
