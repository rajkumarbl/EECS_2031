/***********************************
* EECS 2031 - Lab 6		   
* Filename: calc.c	  	
* Author: Last name, first name	    
* Email: Your preferred email address	 	
* Login ID: Your EECS login ID	
************************************/


#include <stdio.h>
#include <stdlib.h>


  /*****  YOU MAY ADD YOUR OWN FUNCTION(S) HERE.  *****/

int str2int(char *s)
{
  int value=0,i=0;
  while(s[i]!='\0'){value = value * 10 + s[i] - '0';i++;}
  return value;
}
/* Implement a simple calculator. 
   Input: two operands and one operator as command-line arguments.
   Output: the result displayed on the standard output. 
 */

void main( int argc, char *argv[] )
{
  int result = 0;  /* stores the result of the arithmetic operation */


  /*****************************************/
  /***** ADD YOUR CODE BELOW THIS LINE *****/

  if(argc!=4){ printf("Usage: calc [operand_1] [operator] [operand_2]\n");exit(1);}
  int num1 = str2int(argv[1]);
  int num2 = str2int(argv[3]);
  switch(argv[2][0])
  {
    case '+': result = num1+num2;break;
    case '-': result = num1-num2;break;
    case 'x': result = num1*num2;break;
    case '/': result = num1/num2;break;
    case '%': result = num1%num2;break;  
    default: {
        	printf( "Operator \'%c\' not supported.\n", argv[2][0] ); 
        	exit( 1 );
        }
   }
   

  /***** ADD YOUR CODE ABOVE THIS LINE *****/
  /*****************************************/

  /**** DO NOT ADD OR CHANGE ANYTHING BELOW THIS LINE ****/

  printf( "%d\n", result );
}

