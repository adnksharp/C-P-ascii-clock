#include <stdio.h>
#include <string.h>

char zero[] = "#######  ", five[] = "##   ", one[] = "##  ", six[] = "#######  ", four[] = "##   ", two[] = "##  ", three[] = "#######  ",
	nzero[] = ".  .  .  ", nfive[] = ".    ", none[] = " .  ", nsix[] = ".  .  .  ", nfour[] = ".    ", ntwo[] = " .  ", nthree[] = ".  .  .  ",
	szero[] = "## . ##  ", zone[] = ".  . ##  ";

char *ON[7] = { zero, one, two, three, four, five, six },
	 *OFF[7] = { nzero, none, ntwo, nthree, nfour, nfive, nsix };

void print (char *str)
{
	int ForPrint [7][6];
	int i, j;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 6; j++)
		{
			char c = str[j];
			if ((i == 0) && (c != '1') && (c != '4'))
				ForPrint[i][j] = 1;
			else if ((i == 0) && (c == '4'))
				ForPrint[i][j] = 2;
			else if ((i == 0) && (c == '1'))
				ForPrint[i][j] = 3;
			else if ((i == 1) && (c != '5') && (c != '6'))
				ForPrint[i][j] = 1;
			else if ((i == 2) && (c != '2'))
				ForPrint[i][j] = 1;
			else if ((i == 3) && (c != '1') && (c != '4') && (c != '7') && (c != '9'))
				ForPrint[i][j] = 1;
			else if ((i == 3) && (c == '1' || c == '4' || c == '7' || c == '9'))
				ForPrint[i][j] = 3;
			else if ((i == 4) && (c == '0' || c == '2' || c == '6' || c == '8'))
				ForPrint[i][j] = 1;
			else if ((i == 5) && (c != '1') && (c != '2') && (c != '3') && (c != '7'))
				ForPrint[i][j] = 1;
			else if ((i == 6) && (c != '0') && (c != '1'))
				ForPrint[i][j] = 1;
			else if ((i == 6) && (c == '0'))
				ForPrint[i][j] = 2;
			else if ((i == 6) && (c == '1'))
				ForPrint[i][j] = 3;
			else
				ForPrint[i][j] = 0;
		}
	}
	printf("\033[H\033[J");
	for (int i = 0; i < 6; i++)
	{
		if (ForPrint[0][i] == 2)
			printf("%s", szero);
		else if (ForPrint[0][i] == 3)
			printf("%s", zone);
		else
			printf("%s", ForPrint[0][i] ? ON[0] : OFF[0]);
		if ((i + 1) % 2 == 0 && i != 5)
			printf("   ");
	}
	printf("\n");
	for (int i = 0; i < 6; i++)
	{
		printf("%s%s", ForPrint[5][i] ? ON[5] : OFF[5], ForPrint[1][i] ? ON[1] : OFF[1]);
		if ((i + 1) % 2 == 0 && i != 5)
			printf(".  ");
	}
	printf("\n");
	for (int i = 0; i < 6; i++)
	{
		if (ForPrint[6][i] == 2)
			printf("%s", szero);
		else if (ForPrint[6][i] == 3)
			printf("%s", zone);
		else
			printf("%s", ForPrint[6][i] ? ON[6] : OFF[6]);
		if ((i + 1) % 2 == 0 && i != 5)
			printf("   ");
	}
	printf("\n");
	for (int i = 0; i < 6; i++)
	{
		printf("%s%s", ForPrint[4][i] ? ON[4] : OFF[4], ForPrint[2][i] ? ON[2] : OFF[2]);
		if ((i + 1) % 2 == 0 && i != 5)
			printf(".  ");
	}
	printf("\n");
	for (int i = 0; i < 6; i++)
	{
		if (ForPrint[3][i] == 3)
			printf("%s", zone);
		else
			printf("%s", ForPrint[3][i] ? ON[3] : OFF[3]);
		if ((i + 1) % 2 == 0 && i != 5)
			printf("   ");
	}
	printf("\n");
}
