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


    unsigned char data[512];  // buffer for read write and analize data
    FILE *outPtr = NULL; 
    char filename[8] = "000.jpg"; // string wea cheng file name
    int jpgcount = 0;  // count oupened files
    
    while (fread(&data, sizeof(data), 1, inPtr))
    {
        // signature start JPG file
        if ( ((data[0] == 0xff) &&
              (data[1] == 0xd8) &&
              (data[2] == 0xff)) &&
             ((data[3] == 0xe0) || (data[3] == 0xe1)))
        {
            if (!outPtr)  // output file not opened
                {
                    outPtr = fopen(filename, "w");
                    jpgcount++;
                } else
                    {
                        fclose(outPtr);  // clouse previos output file
                        sprintf(filename, "%03i.jpg", jpgcount++); // cheng string filename and increment count
                        outPtr = fopen(filename, "w"); // open new output file for new name
                    }
        }
        if (outPtr)
            { // write lfnf for oupen output file
                fwrite(&data, sizeof(data), 1, outPtr);
            }
    }

    fclose(inPtr);
    fclose(outPtr);

}
