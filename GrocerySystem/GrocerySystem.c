#include <stdio.h>

void welcome(void);
void clrKyb(void);
void pause(void);
int getInt(void);
int yes(void);  // ms2
int getIntLimited(int lowerLimit, int upperLimit);
void GrocInvSys(void);  // ms2
int menu(void);  // ms2
void prnTitle(void);
void prnFooter(double gTotal);
double getDbl(void);
double getDblLimited(double lowerLimit, double upperLimit);


int main(void) {
	GrocInvSys();
	return 0;
}

void welcome(void) {
	printf("---=== Grocery Inventory System ===---\n\n");
}

int yes()
{
	char ch = 'x';                                                                                                                          //a character or char value is in single quotes
	int RET = 0;
	printf("Exit the program? (Y)es/(N)o : ");
	scanf(" %c", &ch);
	while (ch != 'y' && ch != 'Y' && ch != 'N' && ch != 'n')                                        //using != with || doesn't work.
	{
		clrKyb();
		printf("Only (Y)es or (N)o are acceptable: ");
		scanf(" %c", &ch);
																	//put space in front of format string to skip leading whitespace characters. this means the space after "acceptable: " gives an error out of the gate
	}
	if (ch == 'Y' || ch == 'y')
	{
		RET = 1;
	}

	if (ch == 'n' || ch == 'N')
	{
		RET = 0;
		GrocInvSys();
	}
	return RET;
}

int menu()
{
	int value = 0;

	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf("> ");
	scanf("%d", &value);
	while (value < 0 || value > 7)
	{
		printf("Invalid value, 0 < value < 7: ");                                                               //using scan is one way to prevent loops
		scanf("%d", &value);
	}
	return value;
}

void GrocInvSys(void)
{
	int value = 0, done = 0;

	while (!done)                                                                                                   //while 1, loop. so always true until specific command to exit()
	{
																			//but if it is 0, it breaks loop and shows title again, then re - enters loop
		value = menu();
		switch (value)
		{

		case 1:
			printf("List Items!\n");
			pause();
			clrKyb();
			break;
		case 2:
			printf("Search Items!\n");
			pause();
			clrKyb();
			break;
		case 3:
			printf("Checkout Item!\n");
			pause();
			clrKyb();
			break;
		case 4:
			printf("Stock Item!\n");
			pause();
			clrKyb();
			break;
		case 5:
			printf("Add/Update Item!\n");
			pause();
			clrKyb();
			break;
		case 6:
			printf("Delete Item!\n");
			pause();
			clrKyb();
			break;
		case 7:
			printf("Search by name!\n");
			pause();
			clrKyb();
			break;
		case 0:
			done = yes();
		}

	}
}

void clrKyb(void) {
	char input;                                                                                                                                             //needs to be only char since it looks for character value and not a number
	do {
		scanf("%c", &input);
	} while (input != '\n');
}

void pause(void) {
	printf("Press <ENTER> to continue...");
	clrKyb();
}

int getInt(void) {
	char NL = 'x';                                                                                                                                                          //NL is x because that is one char whereas a number would be int
	int value;
	while (NL != '\n') {                                                                            //scan value to store it for later, scan for \n to prevent spaces after value
		scanf("%d%c", &value, &NL);                                                             //loop is broken if not \n so it is routed to another loop to keep loop going until \n
		if (NL != '\n') {
			clrKyb();
			printf("Invalid integer, please try again: ");
		}
	} return value;

}

int getIntLimited(int lowerLimit, int upperLimit) {
	int value = 0;
	while (value < lowerLimit || value > upperLimit) {
		value = getInt();                                                                                                       //without value = getint() it would be infinite loop. to get value, value goes back up to getInt to scan and even print invalid integer if needed
		if (value < lowerLimit || value > upperLimit)                                   //if is here so it won't print invalid then end after a valid number. so only if number is still invalid, print the message
			printf("Invalid value, 10 < value < 20: ");

	}
	return value;
}

void prnTitle(void) {
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}

void prnFooter(double gTotal) {
	printf("--------------------------------------------------------+----------------\n");
	if (gTotal > 0)
		printf("                                           Grand Total: |%12.2lf\n", gTotal);
}

double getDbl(void) {
	char NL = 'x';
	double value;
	while (NL != '\n') {
		scanf("%lf%c", &value, &NL);
		if (NL != '\n') {
			clrKyb();
			printf("Invalid number, please try again: ");
		}
	} return value;
}

double getDblLimited(double lowerLimit, double upperLimit) {
	double value = 0;
	while (value < lowerLimit || value > upperLimit) {
		value = getDbl();
		if (value < lowerLimit || value > upperLimit)
			printf("Invalid value, 10.000000< value < 20.000000: ");
	} return value;
}

/*
---=== Grocery Inventory System ===---

1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 8
Invalid value, 0 < value < 7: 1
List Items!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 2
Search Items!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 3
Checkout Item!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 4
Stock Item!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 5
Add/Update Item!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 6
Delete Item!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 7
Search by name!
Press <ENTER> to continue...
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 0
Exit the program? (Y)es/(N)o : x
Only (Y)es or (N)o are acceptable: n
1- List all items
2- Search by SKU
3- Checkout an item
4- Stock an item
5- Add new item or update item
6- delete item
7- Search by name
0- Exit program
> 0
Exit the program? (Y)es/(N)o : y
*/
