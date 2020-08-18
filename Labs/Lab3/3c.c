#include <stdio.h>

#define MAX_SIZE 100

main() {

   char my_strg[ MAX_SIZE ];   
   char c;
   int my_int=0,length=0,result=1,count=2,i,j,n=0;

   c = getchar();
   if(c=='-'){n=1;}
   while(c!='\n')
    {
     
      if(c>='0' && c<='9') 
       {
         my_strg[length]= c-'0';
         length++;
       } 
      else if(c>='a' && c<='f') 
       {
	 my_strg[length]= c-'a'+10;
         length++;
       }
      else if(c>='A' && c<='F') 
       {
	 my_strg[length]= c-'A'+10;
         length++; 
       }
       else if(c=='-' && length>=1){count=0;}
       else if(c=='-'){}
       else{count=0;}
     c=getchar();    
    }
length = length -1;
   
   for(i=0;i<=length;i++)
   {   
       for(j=length;j>i;j--)
       {
           result = result * 16;
       }
       my_int = my_int + (my_strg[i]*result);
       result = 1;
   }
if(count == 0) 
  {
      printf( "%s\n","Error: not a hexadecimal number");
  }
  else if(count == 2 && n==1) 
  {
      printf( "%d\n",-my_int);
  }
  else
  {

   printf( "%d\n", my_int );  /* output the decimal integer */
  }
}
