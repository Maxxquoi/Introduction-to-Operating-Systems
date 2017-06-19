//
// Created by Maxxquoi on 5/24/17.
//

#include <time.h>
	#include <stdio.h>

	int main(void)
	{
		struct tm str_time;
		time_t time_of_day;

		str_time.tm_year = 2012-1900;
		str_time.tm_mon = 6;
		str_time.tm_mday = 5;
		str_time.tm_hour = 10;
		str_time.tm_min = 3;
		str_time.tm_sec = 5;
		str_time.tm_isdst = 0;

		time_of_day = mktime(&str_time);
		printf(ctime(&time_of_day));

		return 0;
	}
