#include <stdio.h>
#include <cs50.h>
#include <string.h>

   char GetCapLetter (char charUp)
   {
        if (charUp > 96 && charUp < 123)
        charUp = charUp - 32;
        return charUp;
   }
    
    

int main(void)
{
    string strIn = GetString();
   
    int lenght = strlen(strIn);
    char charOut[lenght/2];
    int k = 0;           // переменная для счетчика массива символов
    
    if (strIn[0]!=' ')   //  the first letter is always Capcha
    {
        charOut[0]= GetCapLetter(strIn[0]);
        k = k +1;
    }
    
    for (int i =0; i<lenght-1; i++)
    {
        if (strIn[i]==' ' && strIn[i+1] != ' ')
        {
            charOut[k] = GetCapLetter(strIn[i+1]);
            k++;
            
        }
    }
    
    for (int i=0; i<k; i++)
        printf("%c", charOut[i]);
    printf("\n");
    return 0;
}