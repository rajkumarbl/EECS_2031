#include <stdio.h>

void power_of_ten( int k, double *d )
{
   
   if(k>0)
   {*d=1;
   for(int i=0; i<k;i++)
   {
       *d=*d*10;
   }
   }
   else
   {*d=1;
   for(int i=0; i>k;i--)
   {
       *d=*d/10.00;
   }
   }
}  /* end power_of_ten */

void main()
{
   int k;
   double my_double;
   scanf( "%d", &k );
   power_of_ten(k,&my_double);
   /* Hint: my_double must be passed by reference (i.e., using a pointer). */
   
   /* Do not modify the following line. */
   printf( "%.15lf\n", my_double );
}
