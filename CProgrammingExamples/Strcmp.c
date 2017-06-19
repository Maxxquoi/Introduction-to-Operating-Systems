//
// Created by Maxxquoi on 5/24/17.
//

/* strcmp.c */

   #include <stdio.h>
   #include <string.h>

   #define ANSWER "blue"

   int main()
   {
     char t[100];
     puts( "What is the secret color?" );
     gets( t );
     while ( strcmp( t, ANSWER ) != 0 )
     {
       puts( "Wrong, try again." );
       gets( t );
     }
     puts( "Right!" );
   }
