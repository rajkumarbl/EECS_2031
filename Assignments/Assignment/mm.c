/***********************************
* EECS 2031 - Assignment 2
* Filename  : mm.c
* Author    : Balakrishnan Lakshmi, Rajkumar
* Email     : kumarraj@my.yorku.ca
* Login ID  : kumarraj
*Student Id : 213141197
************************************/


#include <stdio.h>
#include <stdlib.h>


/***************** DO NOT USE ARRAY INDEXING *****************/
/************** USE ONLY POINTERS IN THIS FILE ***************/

/* You may define additional functions and local variables. */


/*
   Save the three command-line arguments into nr1, nc1 and nc2.
 */

void get_args( char **argv, int *nr1, int *nc1, int *nc2 )
{

   /*************** ADD YOUR CODE HERE ***************/
   int i, j;
   int a = 0;
   for (i=1; i<4; i++)
   {
     a = 0;

     for(j=0; *(*(argv+i)+j) != '\0'; j++)
     {
        a = a * 10 + *(*(argv+i)+j) - '0';
     }
    if(i==1) {*nr1 = a;}
    else if(i==2) {*nc1 = a;}
    else if(i==3) {*nc2 = a;}
   }
}




/*
   Initialize a 2-dimensional array.
   Element (i, j) is assigned value i+j.
 */

void initMatrix ( int **a, int nrows, int ncols )
{

   int i,j;
   for (i = 0; i <= nrows-1; i++)
   {
     for (j = 0; j<= ncols-1; j++)
     {
       *(*(a+i)+j) = i + j;
     }
   }
}


/*
   Multiply arrays a and b.
   Array a has nr1 rows and nc1 columns.
   Array b has nc1 rows and nc2 columns.
   Allocate an array c having nr1 rows and nc2 columns.
   Compute a x b and store the result in array c.
   Return array c.
   If an error occurs (e.g., insufficient memory), return NULL pointer.
 */


int **matrix_mult( int **a, int **b, int nr1, int nc1, int nc2 )
{

   /*************** ADD YOUR CODE HERE ***************/

  int **c,i,j,k;

   /* Allocate an array of pointers, each pointing to a row. */
   c = ( int** ) malloc( nr1 * sizeof( int* ) );
   if ( c == NULL ) {
        printf( "Insufficient memory!\n" );
        exit ( 1 );
   }

   /* Allocate each row. */
   for(i = 0; i < nr1; i++)
   {
        *(c+i) = ( int* ) malloc( nc1 * sizeof( int ) );
        if ( *(c+i)  == NULL ) {
           printf( "Insufficient memory!\n" );
           exit ( 1 );
        }
        031A asg2
         for(j=0; j<nc2; j++)
          {
            for (k=0; k<nc1; k++)
             {
               *(*(c+i)+j) += (*(*(a+i)+k)) * (*(*(b+k)+j));
             }
          }
   }

   return(c);   /* replace this line with your code */
}



/************************* END OF FILE *************************/
