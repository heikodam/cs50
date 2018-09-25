#include <cs50.h>
#include <stdio.h>


int main(void){
    float userchange;
    do{
        userchange = get_float("Change owed: ");
    } while(userchange < 0);

    userchange = userchange * 100;
    int newuserchange = (int) userchange;

    int coincount = 0;

    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    int rest = 0;
    if(newuserchange >= quarter){
        rest = newuserchange%quarter;
        coincount += (newuserchange - rest)/quarter;
        newuserchange = newuserchange - (((newuserchange - rest)/quarter)*quarter);
    }
    if(newuserchange >= dime){
        rest = newuserchange%dime;
        coincount += (newuserchange - rest)/dime;
        newuserchange = newuserchange - (((newuserchange - rest)/dime)*dime);
    }
    if(newuserchange >= nickel){
        rest = newuserchange%nickel;
        coincount += (newuserchange - rest)/nickel;
        newuserchange = newuserchange - (((newuserchange - rest)/nickel)*nickel);
    }
    if(newuserchange >= penny){
        rest = newuserchange%penny;
        coincount += (newuserchange - rest)/penny;
        newuserchange = newuserchange - (((newuserchange - rest)/penny)*penny);
    }

    printf("%i\n", coincount);

    // int countCoinFit (int amount){
    //     printf('%i', amount);
    //     // while(newamount >= coin){
    //     //     count = newamount % coin;
    //     //     newamount = newamount - (coin*count);
    //     // }
    // }

    // countCoinFit(quarter);


}