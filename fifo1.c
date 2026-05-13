#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_FILE "MYFIFO"

int main(void)
{
    FILE *fp;
    char readbuf[80];

    /* Create the FIFO if it does not exist */
    umask(0);
    mkfifo(FIFO_FILE, 0666);

    while(1)
    {
        fp = fopen(FIFO_FILE, "r");
        if(fp == NULL)
        {
            perror("fopen");
            exit(1);
        }

        fgets(readbuf, sizeof(readbuf), fp);
        printf("Received string: %s\n", readbuf);

        fclose(fp);
    }

    return 0;
}
