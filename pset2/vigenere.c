#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


char caesar (char c, int k);

int main (int argc, string argv[])
{
    if (argc !=2)
    {
        printf ("error\n");
        return 1;
    }
    string text_key = argv[1];
    int text_key_lenght = strlen(text_key);
    
    for (int i = 0; i < text_key_lenght; i++)
    {
        if ( !isalpha(argv[1][i]))
        {
        printf ("error\n");
        return 1;
        }
    }
    printf ("plaintext:  ");
    string text_user = GetString();
    int text_user_lenght = strlen(text_user);
    int text_key_index =0;
    int int_text_key[text_key_lenght];
    
    for (int i =0; i < text_key_lenght; i++)   
    {
        int_text_key[i] = toupper(text_key[i]) - 'A' ; // making digital key where a = 0
    }
    
    for (int i=0; i < text_user_lenght; i++)
    {
        if (isalpha(text_user[i]))
        {
            text_user[i] = caesar(text_user[i],int_text_key[(text_key_index)%text_key_lenght]); 
            text_key_index++;
        }
    }

    printf("ciphertext: %s\n", text_user);

    return 0;
}

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