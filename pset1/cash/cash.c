#include <cs50.h>
#include <stdio.h>


int main(void){
    float userchange;
    do{
        userchange = get_float("Change owed: ");
    } while(userchange < 0);

    userchange = userchange * 100;

    int coincount = 0;

    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    int countCoinFit (int amount){
        printf('%i', amount);
        // while(newamount >= coin){
        //     count = newamount % coin;
        //     newamount = newamount - (coin*count);
        // }
    }

    countCoinFit(quarter);


}