/*
Tudor Chiribes
19 Feb 2018
Procedural Programming Assignment
City&Guilds Unit 423
*/

#include <stdio.h>
#include <stdlib.h>

int counter;

char input;

char message[30];

struct item {
	
	char itemName[15];
	double itemPrice;
	char itemManufacturer[15];
	int itemSKU;
};

#define size 10

struct item items[size];

void catalogue();

int showMenu();
int display();
int displayHelp();

int main(){

	printf("Testing counter : %d\n", counter);
    strcpy(message, "Loading application...");
	catalogue();
    printf("Testing input : %c\n", input);
    showMenu();
    printf("...Closing application.");
    return 0;
}

int showMenu(){

	int moreInfo = 0;
	int showHelp = 0;
	
    do {
	
		system("cls");
		printf("%s\n", message);
        printf("*******************************************************************\n");
        printf("*             Welcome to the ArKea Digital Catalogue!             *\n");
        printf("*           Please choose one of the following options:           *\n");
        printf("*   'A' - first;   'S' - previous;    'D' - next;   'F' - last;   *\n");
        printf("*       'M' - more information;   'H' - help;   'X' - exit;       *\n");
        printf("*******************************************************************\n");

		if (showHelp == 0) {
			
			display(moreInfo);
		}
		
		else {
			
			displayHelp();
		}
		
        printf("*******************************************************************\n");
		
        getInput();
		
        switch(input) {
            case 'a':
            case 'A':

            counter = 0;
            strcpy(message, "Showing first item!");
			showHelp = 0;
            break;

            case 's':
            case 'S':

            counter--;
            strcpy(message, "Showing previous item!");
			showHelp = 0;
            break;

            case 'd':
            case 'D':

            counter++;
            strcpy(message, "Showing next item!");
			showHelp = 0;
            break;

            case 'f':
            case 'F':

            counter = size-1;
            strcpy(message, "Showing last item!");
			showHelp = 0;
            break;
			
			case 'm':
			case 'M':

			strcpy(message, "Showing more information!");
			showHelp = 0;
			
			if (moreInfo == 0) {
				
				moreInfo = 1;
			}
			
			else {
				
				moreInfo = 0;
			}
            break;

			case 'h':
			case 'H':
			
			strcpy(message, "Showing Help!");
			
			if (showHelp == 0) {
				
				showHelp = 1;
			}
			
			else {
				
				showHelp = 0;
			}
			break;
			
            case 'x':
            case 'X':

            printf("Thank you, come again!\n");
            break;

            default:

            strcpy(message, "Not a valid option, please try again!");
        }

    } while (input != 'x');

    return 0;
}

int display(int displayMore){

    if (counter < 0 || counter == 9) {

        counter = 9;
        printf("\tDisplaying last item:\n");
    }

    else if (counter > 9 || counter == 0) {

        counter = 0;
        printf("\tDisplaying first item:\n");
    }

    else {

        printf("\tDisplaying item %i of %i:\n", counter+1, size); 
    }
	
	printf("\n\t\tName: %s\n\t\tPrice: $%.2f\n", items[counter].itemName, items[counter].itemPrice);
	
	if (displayMore == 1) {
		
		printf("\n\t\tManufacturer: %s\n\t\tSKU: %i\n", items[counter].itemManufacturer, items[counter].itemSKU);
	}
	
    return 0;
}

int displayHelp() {
	
	printf("\n\t\tHelp Menu\n");
	printf("\n\tType the lowercase or uppercase letter for the desired \n\toption and then press enter.\n");
	printf("\n\tPress M to toggle more information about the item!\n");
	printf("\n\tPress X to close the application.\n\n");
	
	return 0;
}

int getInput() {
	
	int buffer;
	
	scanf(" %c", &input);
	
	while((buffer = getchar()) != '\n') {
		
		printf("Artificial Intelligence is reading your mind!\n");
	}
	
	return 0;
}

void catalogue(){
	
	strcpy(items[0].itemName, "item1");
	items[0].itemPrice = 0.99;
	strcpy(items[0].itemManufacturer, "manufacturer1");
	items[0].itemSKU = 111111;
	
	strcpy(items[1].itemName, "item2");
	items[1].itemPrice = 12.50;
	strcpy(items[1].itemManufacturer, "manufacturer2");
	items[1].itemSKU = 222222;
	
	strcpy(items[2].itemName, "item3");
	items[2].itemPrice = 14.99;
	strcpy(items[2].itemManufacturer, "manufacturer3");
	items[2].itemSKU = 333333;
	
	strcpy(items[3].itemName, "item4");
	items[3].itemPrice = 17.50;
	strcpy(items[3].itemManufacturer, "manufacturer4");
	items[3].itemSKU = 444444;
	
	strcpy(items[4].itemName, "item5");
	items[4].itemPrice = 20.99;
	strcpy(items[4].itemManufacturer, "manufacturer5");
	items[4].itemSKU = 555555;
	
	strcpy(items[5].itemName, "item6");
	items[5].itemPrice = 22.50;
	strcpy(items[5].itemManufacturer, "manufacturer6");
	items[5].itemSKU = 666666;
	
	strcpy(items[6].itemName, "item7");
	items[6].itemPrice = 24.99;
	strcpy(items[6].itemManufacturer, "manufacturer7");
	items[6].itemSKU = 777777;
	
	strcpy(items[7].itemName, "item8");
	items[7].itemPrice = 27.50;
	strcpy(items[7].itemManufacturer, "manufacturer8");
	items[7].itemSKU = 888888;
	
	strcpy(items[8].itemName, "item9");
	items[8].itemPrice = 29.99;
	strcpy(items[8].itemManufacturer, "manufacturer9");
	items[8].itemSKU = 900000;
	
	strcpy(items[9].itemName, "item10");
	items[9].itemPrice = 999.99;
	strcpy(items[9].itemManufacturer, "manufacturer10");
	items[9].itemSKU = 999999;
}