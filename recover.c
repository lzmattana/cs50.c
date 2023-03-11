#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;
    BYTE buffer[512];
    int bytes_read, count = 0;
    char filename[8];
    FILE *img = NULL;
    // open memory card.
    FILE *f = fopen(argv[1], "r");
    // repeat until end of the card

    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }
    if (f == NULL)
    {
        printf("./recover card.raw");
    }

    while (1)
    {
        // read 512 bytes into a buffer
        bytes_read = fread(buffer, sizeof(BYTE), 512, f);
        // if start of new jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            // if first jpeg
            if (count == 0)
            {
                // create a file and write
                sprintf(filename, "%03i.jpg", count);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), bytes_read, img);
                count++;
            }
            // else
            // close the file and open new file to write to
            else
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", count);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), bytes_read, img);
                count++;
            }
        }
        // else
        // if already found jpeg
        // keep writing to it, can ocour multiple times
        else if (count != 0)
        {
            fwrite(buffer, sizeof(BYTE), bytes_read, img);
            if (bytes_read == 0)
            {
                fclose(img);
                fclose(f);
                return 0;
            }
        }
    }
    fclose(img);
    fclose(f);
}