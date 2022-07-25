#include <string.h>
#include <time.h>
#include "segmentsK.h"

int main()
{
    time_t rawtime;
    struct tm *info;
    char buffer[9], cache[9];

    while (1)
    {
        time(&rawtime);
        info = localtime(&rawtime);
        strftime(buffer, 9, "%H:%M:%S", info);
        if (buffer[7] != cache[7])
        {
            printS((((int)buffer[0] - 48) * 10) + ((int)buffer[1] - 48),
                   (((int)buffer[3] - 48) * 10) + ((int)buffer[4] - 48),
                   (((int)buffer[6] - 48) * 10) + ((int)buffer[7] - 48));
            strcpy(cache, buffer);
        }
    }

    return (0);
}