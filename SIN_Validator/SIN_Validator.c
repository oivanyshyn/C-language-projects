int main(){

int SIN = 0;
int odd_sum = 0;
int even_sum = 0;
int check_digit = 0;
int total_even = 0;
int total_odd = 0;
int i = 0;
int total = 0;
int temp = 0;
int check_sum = 0;
int match = 0;

printf("SIN (0 to quit):");
scanf("%d",&SIN);

check_digit = SIN%10;
SIN = SIN/10;

if(SIN==0){
printf("Have a nice day!\n");
}
for(i=8;i>0;i--){
if(i%2==0){
temp=SIN%10;

even_sum=temp * 2;
even_sum=even_sum/10+even_sum%10;
total_even += even_sum;

SIN=SIN/10;
}else{
temp = SIN%10;
odd_sum=temp;
total_odd += odd_sum;
SIN=SIN/10;
}
}
total=total_odd + total_even;
check_sum=(total/10+1)*10;
match=check_sum - total;

 
if(match==check_digit){
printf("This is a valid SIN.\n");
}else{
printf("This is not a valid SIN.\n");

}

return 0;
}

