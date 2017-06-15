//
// Created by Maxxquoi on 5/24/17.
//

/* strcat.c */

   #include <stdio.h>
   #include <string.h>

   int main()
   {
     char s1[50],
          s2[50];
     strcpy( s1, "Tweedledee " );
     strcpy( s2, "Tweedledum" );
     strcat( s1, s2 );
     puts( s1 );
   }

