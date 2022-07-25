#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

void printS(int H, int M, int S)
{
    struct winsize w;
    int Date[2][3] = {{H - ((H / 10) * 10), M - ((M / 10) * 10), S - ((S / 10) * 10)}, {H / 10, M / 10, S / 10}};
    char aclock[20][5];

    for (int j = 0; j < 5; j++)
        for (int i = 0; i < 20; i++)
            aclock[i][j] = '.';

    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 20; i++)
        {
            if (i == 1 || i == 4 || i == 8 || i == 11 || i == 15 || i == 18)
            {
                if (j == 1 || j == 3)
                    aclock[i][j] = ' ';
            }
            else if (i == 6 || i == 13)
            {
                if (j == 0 || j == 2 || j == 4)
                    aclock[i][j] = ' ';
            }
        }
    }

    for (int c = 0; c < 20; c += 7)
    {
        int j = c / 7;
        for (int i = 0; i < 2; i++)
        {
            if (Date[1 - i][j] != 1)
                aclock[c + (i * 3)][0] = '#';
            if (Date[1 - i][j] != 1 && Date[1 - i][j] != 2 && Date[1 - i][j] != 3 && Date[1 - i][j] != 7)
                aclock[c + (i * 3)][1] = '#';
            if (Date[1 - i][j] != 1 && Date[1 - i][j] != 7)
                aclock[c + (i * 3)][2] = '#';
            if (Date[1 - i][j] == 0 || Date[1 - i][j] == 2 || Date[1 - i][j] == 6 || Date[1 - i][j] == 8)
                aclock[c + (i * 3)][3] = '#';
            if (Date[1 - i][j] != 1 && Date[1 - i][j] != 4 && Date[1 - i][j] != 7 && Date[1 - i][j] != 9)
                aclock[c + (i * 3)][4] = '#';
            if (Date[1 - i][j] != 1 && Date[1 - i][j] != 4)
                aclock[c + 1 + (i * 3)][0] = '#';
            if (Date[1 - i][j] != 0 && Date[1 - i][j] != 1 && Date[1 - i][j] != 7)
                aclock[c + 1 + (i * 3)][2] = '#';
            if (Date[1 - i][j] != 1 && Date[1 - i][j] != 4 && Date[1 - i][j] != 7 && Date[1 - i][j] != 9)
                aclock[c + 1 + (i * 3)][4] = '#';
            aclock[c + 2 + (i * 3)][0] = '#';
            if (Date[1 - i][j] != 5 && Date[1 - i][j] != 6)
                aclock[c + 2 + (i * 3)][1] = '#';
            aclock[c + 2 + (i * 3)][2] = '#';
            if (Date[1 - i][j] != 2)
                aclock[c + 2 + (i * 3)][3] = '#';
            aclock[c + 2 + (i * 3)][4] = '#';
        }
    }

    printf("\033[H\033[J");
    for (int j = 0; j < 5; j++)
    {
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        printf("\033[%d;%dH", ((w.ws_row / 2) - (1 - j)), ((w.ws_col / 2) - 29));
        for (int i = 0; i < 20; i++)
        {
            if (aclock[i][j] == '#')
            {
                if (i == 1 || i == 4 || i == 8 || i == 11 || i == 15 || i == 18)
                    printf("#%c#", aclock[i][j]);
                else if (i == 2 || i == 5 || i == 9 || i == 12 || i == 16 || i == 19)
                    printf("#%c ", aclock[i][j]);
                else
                    printf(" %c#", aclock[i][j]);
            }
            else
                printf(" %c ", aclock[i][j]);
        }
        printf("\n");
    }
}