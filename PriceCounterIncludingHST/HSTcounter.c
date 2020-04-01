#include <stdio.h>

int main()
{
float num_itm=0;
float itm_price=0;
float purch_price;
float hst=0;
float total_price=0;
float tender=0;
int loonies=0;
int cents=0;
float change=0;

printf("Enter the number of items:");
scanf("%f",&num_itm);

while(num_itm<1){
printf("Wrong number , please re-enter\n");
scanf("%f",&num_itm);
}
printf("Enter the item price:");
scanf("%f",&itm_price);

purch_price = num_itm * itm_price;
printf("Purchase price:%.2f\n", purch_price);

hst = purch_price * 0.13;
printf("HST %.2f\n", hst);

total_price = purch_price + hst;
printf("Total price %.2f\n\n", total_price);

printf("Cash tender:",tender );
scanf("%f",&tender);
printf("Cash tendered\t%.2f\n", tender);

change = tender - total_price;
loonies = change;
printf("Change loonies %d\n", loonies);

change = change * 100;
cents = change;
cents = cents&100;
printf("Change cents %d\n", cents);

return 0;
}



