#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


char caesar (char c, int k)
{
    if (isupper(c))
    {
                c = (c - 'A' + k) % 26;
                c = c + 'A';
     }  else
         {
                c = (c - 'a' + k) % 26;
                c = c + 'a';
         }
return c;
}


int main (int argc, string argv[])
{
    if (argc !=2)
    {
        printf ("Usage: ./caesar k\n");
        return 1;
    }
    int k = atoi(argv[1]);
    if (k <=0)
    {
        printf ("Usage: ./caesar k\n");
        return 1;
    }
    
    printf ("plaintext:  ");
    string strIn = GetString();

    int n=strlen(strIn);
    for (int i=0; i<n; i++)
    {
        if ( (strIn[i]>64 && strIn[i]<91) || (strIn[i]>96 && strIn[i]<123) )
            strIn[i] = caesar(strIn[i],k);
    }

    printf("ciphertext: %s\n", strIn);

    return 0;
}