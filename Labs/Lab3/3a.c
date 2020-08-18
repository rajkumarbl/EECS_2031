#include <stdio.h>

#define MAX_SIZE 100

void main() 
{
   char my_strg[ MAX_SIZE ];
   int length =0, i,j;
   char c,temp;
   
   printf("Enter a line of Characters>");
   c = getchar();
   while(c!='\n')
   {

     if(length <=MAX_SIZE)
     {
      my_strg[length] = c;
      length++;
     }
     c = getchar(); 
   }
//my_strg[ length ] = '\0';
    i=0; j=length-1;
    while (i < j)
    {
     temp = my_strg[i];
     my_strg[i] = my_strg[j];
     my_strg[j] = temp;
      i++;             // increment i
      j--;          // decrement j
   }
   
   printf( "%s\n", my_strg );  /* output the reversed string */
}
