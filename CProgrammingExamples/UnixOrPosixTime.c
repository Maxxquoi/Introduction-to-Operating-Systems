//
// Created by Maxxquoi on 5/24/17.
//

#include <stdio.h>
#include <time.h>
int main ()
{
    time_t sec;
    sec = time (NULL);

    printf ("Number of hours since January 1, 1970 is %ld \n", sec/3600);
    return 0;
}
