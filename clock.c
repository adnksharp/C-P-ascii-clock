#include "Segments.h"
#include <time.h>
#include <string.h>
#include <unistd.h>
//#include <Windows.h>

int main (int argc, char *argv[])
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	char hour[3][2] = {{tm.tm_hour/10 + '0', tm.tm_hour%10 + '0'},
			{tm.tm_min/10 + '0', tm.tm_min%10 + '0'},
			{tm.tm_sec/10 + '0', tm.tm_sec%10 + '0'}};
	print(hour[0]);
	while (1)
	{
		t = time(NULL);
		tm = *localtime(&t);
		hour[0][0] = tm.tm_hour/10 + '0';
		hour[0][1] = tm.tm_hour%10 + '0';
		hour[1][0] = tm.tm_min/10 + '0';
		hour[1][1] = tm.tm_min%10 + '0';
		hour[2][0] = tm.tm_sec/10 + '0';
		hour[2][1] = tm.tm_sec%10 + '0';
		print(hour[0]);
		sleep(1);
	}
	return 0;
}
