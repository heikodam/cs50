#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void){
    long long int cardNumber;
    do{
        cardNumber = get_long_long("Number: ");
    }while(cardNumber < 1000000000000 || cardNumber > 9999999999999999);

    long long int secondDigits = cardNumber;
    int secondDigitsMultipliedSum = 0;
    secondDigits /= 10;

    while(secondDigits)
    {
        int secDigPro = (secondDigits % 10) * 2;
        while(secDigPro){
            secondDigitsMultipliedSum += secDigPro % 10;
            secDigPro /= 10;
        }
        secondDigits /= 100;

    }
    //printf("%i\n", secondDigitsMultipliedSum);


    long long int firstDigits = cardNumber;
    while(firstDigits){
        secondDigitsMultipliedSum += firstDigits % 10;
        firstDigits /= 100;
    }
    //printf("%i\n", secondDigitsMultipliedSum);

    char cardLenS[50];
    snprintf(cardLenS, 50, "%lli", cardNumber);
    int cardLen = strlen(cardLenS);


    if(secondDigitsMultipliedSum % 10 == 0){
       long long int firstNumber = 0;
       if(cardLen % 2 == 0){
        while(cardNumber){
            firstNumber  = cardNumber % 100;
            cardNumber /= 100;
        }

       } else {
           cardNumber /= 10;
           while(cardNumber){
            firstNumber  = cardNumber % 100;
            cardNumber /= 100;

        }
       }


        if(firstNumber == 34 || firstNumber == 37){
            printf("AMEX\n");
        } else if(firstNumber > 50 && firstNumber < 56){
            printf("MasterCard\n");
        } else if(firstNumber / 10 == 4){
            printf("Visa\n");
        } else {
            printf("INVALID\n");
        }


    } else {
        printf("INVALID\n");
    }
}