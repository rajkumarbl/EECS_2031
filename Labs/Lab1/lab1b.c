/*****************************************
* EECS2031 - Lab 1                       *
* Filename:  lab1b.c                     *
* Author: Balakrishnan Lakshmi, Rajkumar *
* Email:kumarraj@my.yorku.ca             *
* Login ID:kumarraj                      *
*****************************************/
#include <stdio.h>

main() {
	int blanks = 0;
	char c;
	
	printf( "Enter a line of characters > " );
	c = getchar();
	while( c != '\n' ) {
		if ( c == ' ' )
			blanks++;
		c = getchar();
	} 
	printf( "%d\n", blanks );
}
