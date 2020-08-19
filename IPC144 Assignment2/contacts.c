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

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contacts.h"
#include "contactHelpers.h"
#include <string.h>



// +---------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2   |
// |        function definitions below...              |
// |                                                   |
// | *** See hint regarding the getNumbers function    |
// +---------------------------------------------------+

// getName:
void getName(struct Name* name) {
	int value;
	printf("Please enter the contact's first name: ");
	scanf("%31[^\n]s", name->firstName);
	clearKeyboard();


	printf("Do you want to enter a middle initial(s)? (y or n): ");
	value = yes();

	if (value == 1) {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]s ", name->middleInitial);
		clearKeyboard();

	}else if (value == 0){
	strcpy(name->middleInitial,"");
	}

	printf("Please enter the contact's last name: ");
	scanf("%36[^\n]s", name->lastName);
	clearKeyboard();


}



// getAddress:
void getAddress(struct Address* address) {
	char prompt;
	printf("Please enter the contact's street number: ");
	(address->streetNumber) = getInt();



	while ((address->streetNumber) < 0) {
		printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
		scanf("%d", &address->streetNumber);
		clearKeyboard();
	}


	printf("Please enter the contact's street name: ");
	scanf("%41[^\n]s", address->street);
	clearKeyboard();

	printf("Do you want to enter an apartment number? (y or n): ");
	prompt = yes();

	if (prompt == 1) {
		printf("Please enter the contact's apartment number: ");
		(address->apartmentNumber) = getInt();
	}


		while ((address->apartmentNumber) < 0) {
			printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
			scanf("%d", &address->apartmentNumber);
			clearKeyboard();
		}



	printf("Please enter the contact's postal code: ");
	scanf("%7[^\n]s", address->postalCode);
	clearKeyboard();



	printf("Please enter the contact's city: ");
	scanf("%40[^\n]s", address->city);
	clearKeyboard();
}




// getNumbers:
// HINT:  Update this function to use the new helper
//        function "getTenDigitPhone" where applicable
void getNumbers(struct Numbers* numbers) {
	int input;
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);
	clearKeyboard();
	printf("Do you want to enter a home phone number? (y or n): ");
	input = yes();
	if(input == 1){
            printf("Please enter the contact's home phone number: ");
	getTenDigitPhone(numbers->home);

	}else{
	    strcpy(numbers->home,"\0");
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	input = yes();
	if(input ==1) {
            printf("Please enter the contact's business phone number: ");

        getTenDigitPhone(numbers->business);
        clearKeyboard();

	}
	else{
        strcpy(numbers->business,"\0");

	}
}


// getContact
void getContact(struct Contact* contact) {
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);

}
