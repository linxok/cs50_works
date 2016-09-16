#include <stdio.h>
#include <cs50.h>

int main(void)
{
    
    int height = 0;
    do 
    {
    printf("height: ");
    height = GetInt();
    } while (height <0 || height >=24);   //until it enters a positive number
   
    for (int i = 0; i<height; i++)            // how to print line
    {
        for (int b = height-i-1; b>0; b--)      // how to print " "
        printf(" ");
        printf("#");
        for (int c = height; c>height-i; c--) // how to print "#"
        printf("#");
        printf("#\n");                        // finish line

    }
   
}