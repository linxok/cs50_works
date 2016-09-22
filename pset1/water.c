#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int minutes = 0;
    do 
    {
    printf("minutes: ");
    minutes = GetInt();
    } while (minutes <=0);
        printf("bottles: %i\n", minutes*192/16);

    return 0;
}
