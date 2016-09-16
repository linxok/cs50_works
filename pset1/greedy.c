#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float cash = 0.01;
    int coin25 =0;
    int coin10 =0;
    int coin5 =0;
    int coin1 =0;
    printf("O hai! ");
    do 
    {
    printf("How much change is owed?\n");
    cash = GetFloat();     // scanf ("%f", &cash);
    } while (cash <=0); 
    cash = round(cash*100);
    
    if (cash >= 25)
    {
        coin25 = cash/25;
        cash = cash - (coin25*25);
    }
    if (cash >= 10)
    {
        coin10 = cash/10;
        cash = cash - (coin10*10);
    }
    if (cash >= 5)
    {
        coin5 = cash/5;
        cash = cash - (coin10*5);
    }
    if (cash >= 1)
    {
        coin1 = cash/1;
        //cash = cash - (coin1*1);
    }
    
    /*
    printf("coin 25: %i\n", coin25);
    printf("coin 10: %i\n", coin10);
    printf("coin  5: %i\n", coin5);
    printf("coin  1: %i\n", coin1);
    */
    printf("%i\n", coin25+coin10+coin5+coin1);
    return 0;
}