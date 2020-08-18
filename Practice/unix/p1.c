#include <stdio.h>

#define MAX_SIZE 100

void main() 
{
   int my_strg[ MAX_SIZE ],n;
   int length =0,i,count=0;
   float sum=0;
   
   printf("Enter a line of numbers:");
   scanf("%d",&n);
   my_strg[length++] = n;if(n>0)
      {sum+=n;count++;}
   while(n!= 0)
   {
     if(length <=MAX_SIZE)
     {
      scanf("%d",&n);
      my_strg[length++] = n;
     }
      if(n>0)
      {sum+=n;count++;}
 printf( "%6.2f\n", sum ); 
   }
   sum=sum/count;
   
   printf( "%6.2f\n", sum );  
}
