/***********************************
* EECS 2031 - Lab 7		   
* Filename: marks.c  	
* Author: Last name, first name	    
* Email: Your preferred email address	 	
* Login ID: Your EECS login ID	
************************************/

#include <stdio.h>
#include <stdlib.h>


  /*****  YOU MAY ADD YOUR OWN FUNCTION(S) HERE.  *****/

void main( int argc, char *argv[] )
{

  if(argc == 1)
  {printf("Usage: marks [input_file] [output_file] \n");exit(1);}
   
  FILE *ip, *op;
  char first[50], last[50];
  int asg1, asg2;
  float avg;

  ip = fopen( argv[1], "r" );
  if( ip == NULL ) {
    printf( "Can't open file %s for reading.\n",  argv[1] );
    exit( 1 );
  }

  op = fopen( argv[2], "w" );
  if( op == NULL ) {
    printf( "Can't open file %s for writing.\n",  argv[2] );
    exit( 1 );
  }

  while ( fscanf( ip, "%s %s %d %d", first, last, &asg1, &asg2 ) != EOF ) 
  {
    avg = ( (float)asg1 + asg2 ) / 2;
    fprintf( op, "%s %s %d %d %.1f\n", first, last, asg1, asg2, avg );
  }

  fclose( ip );
  fclose( op );


}  /* end main */


