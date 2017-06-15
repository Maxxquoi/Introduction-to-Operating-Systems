//
// Created by Maxxquoi on 5/24/17.
//

#include <stdio.h>
#include <time.h>

#define PST (-8)
#define CET (1)

	int main ()
       {
                time_t raw_time;
                struct tm *ptr_ts;

                time ( &raw_time );
                ptr_ts = gmtime ( &raw_time );

                printf ("Time Los Angeles: %2d:%02d\n",
                     ptr_ts->tm_hour+PST, ptr_ts->tm_min);
                printf ("Time Amsterdam: %2d:%02d\n",
                     ptr_ts->tm_hour+CET, ptr_ts->tm_min);
		return 0;
         }
