#include <stdio.h>
#define SIZE 100

int main(){

int array[SIZE];
int i=0;
long long barcode[SIZE]={0};
int quantity[SIZE]={0};
float price[SIZE]={0};
float value[SIZE]={0};
float total=0;
int count = 0;

printf("Grocery Store Inventory\n");
printf("=======================\n");

for(i=0;i<SIZE;i++){
printf("Barcode:");
scanf("%lld",&barcode[i]);

if(barcode[i]==0){
i=SIZE;
printf("\nThank you");
}else{

printf("Price:");
scanf("%f",&price[i]);

printf("Quantity:");
scanf("%d",&quantity[i]);

count++;
}
value[i]=price[i]*quantity[i];
total=value[0]+value[1]+value[2];

}

printf("\n\tGoods in Stock\t");
printf("\n\t==============\t");
printf("\nBarcode\tPrice\tQuantity\tValue\n");
printf("===============================\n");

for(i=0;i<count;i++){
printf("%lld\t%.2f\t%d\t%.2f\n",barcode[i],price[i],quantity[i],value[i]);
}

printf("\n==============================\n");
printf("Total value good in stock\t%.2f\n",total);

return 0;
}
