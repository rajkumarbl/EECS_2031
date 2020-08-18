/*****************************************
* EECS2031 - Lab 1                       *
* Filename:  lab1a.c                     *
* Author: Balakrishnan Lakshmi, Rajkumar *
* Email:kumarraj@my.yorku.ca             *
* Login ID:kumarraj                      *
*****************************************/

#include <stdio.h>

main() {
	float inch, cm;
	
	printf( "Enter the measurement in inches > " );
	scanf( "%f", &inch );
	while( inch != 0 ) {
		cm = inch * 2.54;
		printf( "%.2f cm\n", cm );
		printf( "Enter the measurement in inches > " );
		scanf( "%f", &inch );
	} 
}
