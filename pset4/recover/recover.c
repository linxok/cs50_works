#include <stdio.h>
#include <stdlib.h>
//#include <cs50.h>

int main (int argc, char* argv[])
{
   if (argc != 2)
   {
       fprintf(stderr, "Usage: ./recover image\n");
       return 1;
   }

    FILE *inPtr = fopen(argv[1], "r");

    if (inPtr == NULL)
    {
        fprintf(stderr, "File can be not opened.\n");
        return 1;
    }


    unsigned char data[512];
    FILE *outPtr = NULL;
    char filename[8] = "000.jpg";
    int jpgcount = 0;


    while (fread(&data, sizeof(data), 1, inPtr))
    {


        if ( ((data[0] == 0xff) &&
             (data[1] == 0xd8) &&
             (data[2] == 0xff)) &&
             ((data[3] == 0xe0) || (data[3] == 0xe1)))
        {

            if (!outPtr)
            {
                outPtr = fopen(filename, "w");
                jpgcount++;
            } else
                    {
                    sprintf(filename, "%03i.jpg", jpgcount++);
                    outPtr = fopen(filename, "w");
                    }
        }

        if (outPtr)
        {
            fwrite(&data, sizeof(data), 1, outPtr);

        }


    }

    fclose(inPtr);
    fclose(outPtr);

}
