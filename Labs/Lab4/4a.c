#include <stdio.h>

#define MAX_SIZE 500

void myStrInput ( char *s );
int myStrCmp( char *s1, char *s2 );

void main() 
{
   char strg1[ MAX_SIZE ], strg2[ MAX_SIZE ];

   /* Input strings strg1 and strg2. */
   /* Assume that the length of each input string is less than 100 characters. */

   myStrInput( strg1 );
   myStrInput( strg2 );
   printf( "%d\n", myStrCmp( strg1, strg2 ));
}


/************* DO NOT MODIFY ANYTHING ABOVE THIS LINE, *************/
/************* EXCEPT THE HEADER CONTAINING YOUR INFO **************/


/* Function myStrInput
   Input: an array of char pointed to by pointer s.
   Output: the same array that stores the user's input string.
   Note: The length of each input string is less than the array size. 
   So no error checking for the string length is required. 
   Do not modify the function definition.
 */

void myStrInput ( char *s )
{

   char c;
   c=getchar();
   while(c!='\n')
    {
       *s=c;
       s++;
       c=getchar();
    }
    *s='\0';
}



/* Function myStrCmp
   Input: two strings pointed to by pointers s1 and s2.
   Output: returns the first position (array index) where the two strings differ. 
   Special cases:
   1. Two strings are equal: returns -1.
   2. One string is a substring of the other (e.g., "CSE2031" and "CSE2031E3.0"):
	returns the length of the shorter string.
   Do not modify the function definition.
 */

int myStrCmp( char *s1, char *s2 )
{

  int pos = 0, diff = -1;
   while( *(s1+pos) != '\0' && *(s2+pos) !='\0' ){
      if( *(s1+pos) != *(s2+pos) && diff == -1 )
         diff = pos;
      pos++;
   }
   if( *(s1+pos) != *(s2+pos) && diff == -1 )
      diff = pos;
   
   return diff;

}
