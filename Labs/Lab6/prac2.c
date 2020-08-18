/***********************************
* EECS 2031 - Lab 6		   
* Filename: mmavg.c	  	
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
  if(argc == 1)
  { printf("Usage: mmavg int1 int2 int3 ...\n");exit(1);}
  
  int i,z=1; int* arr;max=min=str2int(argv[1]);avg=0;
  arr =  malloc(sizeof(int) * argc);
  for(i=0;i<argc-1;i++)
  { 
    arr[i] = str2int(argv[z]);if(z<argc-1)z++;
    if(arr[i]>max) max= arr[i];
    if(arr[i]<min) min= arr[i];
    avg+=arr[i];
  }
  avg= avg/(argc-1);

  /***** ADD YOUR CODE ABOVE THIS LINE *****/
  /*****************************************/

  /**** DO NOT ADD OR CHANGE ANYTHING BELOW THIS LINE ****/

  printf( "%d %d %.2f\n", max, min, avg );
}

