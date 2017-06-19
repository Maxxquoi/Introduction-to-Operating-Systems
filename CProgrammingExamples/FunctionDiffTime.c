//
// Created by Maxxquoi on 5/24/17.
//

#include <stdio.h>
	#include <time.h>

	int main(void)
	{
		time_t start,end;
		volatile long unsigned counter;

		start = time(NULL);

		for(counter = 0; counter < 500000000; counter++)
			; /* Do nothing, just loop */

		end = time(NULL);
		printf("The loop used %f seconds.\n", difftime(end, start));
		return 0;
	}