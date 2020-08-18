#include <stdio.h>

#define MAX_SIZE 100

void main() 
{
   char my_strg[ MAX_SIZE ];
   int length =0, i,j,repeat=0;
   char c;
   
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
my_strg[length]= '\0';

  for(i=0;i<length-1;i++)
  {
    j=i+1;//for(j=i-1;((my_strg[j]!=' ')&&(j>=0));j--)
    {
      if((my_strg[i]==my_strg[j]) && (my_strg[i]!=' ' && my_strg[j]!=' '))
       repeat=1;
    }
  }
 if(repeat==0)
  {
    my_strg[length]= my_strg[length-1];
    length++;
    my_strg[length]= '\0';
    printf( "%s\t", my_strg );  /* output the reversed string */
    printf( "%d\n", length-1 );  
  }
else
{  
   
   printf( "%d\n", 0 ); 
} 
}
