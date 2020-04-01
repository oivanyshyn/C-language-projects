#include <stdio.h>
#include <string.h>
#define MAX 9

int main(void){
   char userName[MAX];
   char userNameBackup[MAX];
   char userGuess[MAX];
   char password[MAX];
   int lives;
   int i;

   printf("Password Game\n");
   printf("=============\n");

   printf("Enter your name (up to 8 characters): ");
   scanf("%8[^\n]", userName);
   strcpy(userNameBackup, userName);

   for(i = 0; userName[i] != '\0'; i++){
      password[i] = userName[i] - 1;
   }
   printf("Welcome %s\n", userName);

   lives = strlen(userName);



   for(i = 0; i < strlen(userNameBackup); i++){
      printf("Guess the password (up to 8 characters) %s: ", userName);
      scanf("\n%8[^\n]", userGuess);

      if(strcmp(userGuess, password) == 0){
         printf("You got it, %s!!!\n", userNameBackup);
      }else{
         //printf("FALSE: ");
         lives--;
         if(lives == 0){
            printf("You has failed.\n");
         }else{
            printf("FALSE: ");
         }
         userName[lives] = '\0';
      }
   }
   printf("Game over!\n");
}
