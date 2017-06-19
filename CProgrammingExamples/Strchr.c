//
// Created by Maxxquoi on 5/24/17.
//

/* strchr.c */

   #include <stdio.h>

   #include <string.h>

   int main()
   {
     char *t = "MEAS:VOLT:DC?";
     char *p;
     p = t;
     puts( p );
     while(( p = strchr( p, ':' )) != NULL )
     {
       puts( ++p );
     }
   }
