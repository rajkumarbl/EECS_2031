#include <stdio.h>
#include <stdlib.h>


/* Display the integer n on the standard output. */
/* Do not modify this function */

void prtResult( int n )
{
   printf( "%d\n", n );
}


void prtError( char *s )
{
  printf( "%s\n", s );
}


/* Convert string s to an integer and returns the interger to the caller. */

int str2int( char *s )
{
   int i = 0, value = 0;
   while ( s[i] != '\0' ) {
        value = value * 10 + s[i] - '0';
        i++;
}
   return( value );
}


/* Implement the simple calculator in main() */

main(  int argc, char *argv[] )
{
   int result;

   if ( argc != 4 ) {
        prtError( "Usage: calc [operand_1] [operator] [operand_2]\n" );
        exit( 1 );
   }


   /* Checking all arguments
   printf( "%s %s %s %s\n", argv[0], argv[1], argv[2], argv[3] );
   */

   int num1 = str2int( argv[1] );
   int num2 = str2int( argv[3] );


   /* if-then-else can be used instead of "switch" */
   
   switch( argv[2][0] )
   {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case 'x': result = num1 * num2; break;
        case '/': result = num1 / num2; break;
        case '%': result = num1 % num2; break;
        default: {
        	printf( "Operator \'%c\' not supported.\n", argv[2][0] ); //888888888888888888
        	exit( 1 );
        }
   }

   prtResult( result );
}








#include <stdio.h>
#include <stdlib.h>


  /*****  YOU MAY ADD YOUR OWN FUNCTION(S) HERE.  *****/


/* Convert string s to an integer and returns the interger to the caller. */

int str2int( char *s )
{
   int i = 0, value = 0, sign = 1;
   if ( s[i] == '-' )
     sign = -1;
   if ( s[i] == '-' || s[i] == '+' )
     i++;
   while ( s[i] != '\0' ) {
        value = value * 10 + s[i] - '0';
        i++;
   }
   return( sign * value );
}


/* Function main()
   Input: a set of integers as command-line arguments.
   Output: the maximum, minimum and average of the above set displayed on the standard output.
 */

main( int argc, char *argv[] )
{
  int max, min;
  float avg;

  /*****************************************/
  /***** ADD YOUR CODE BELOW THIS LINE *****/

  int i, num;

  if ( argc == 1 ) {
    printf( "Usage: mmavg int1 int2 int3 ...\n" );
    exit( 1);
  }

  avg = max = min = str2int( argv[1] );
  for( i = 2; i < argc; i++ )
  {
    num = str2int( argv[i] );
    if ( num > max )
      max = num;
    if ( num < min )
      min = num;
    avg += num;
  }
  avg /= ( argc - 1 );    //8888888888888888888888888888888

  /***** ADD YOUR CODE ABOVE THIS LINE *****/
  /*****************************************/

  /**** DO NOT ADD OR CHANGE ANYTHING BELOW THIS LINE ****/

  printf( "%d %d %.2f\n", max, min, avg );
}

