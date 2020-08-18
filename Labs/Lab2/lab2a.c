#include<stdio.h>
void main()
{ 
  int digits = 0, sum = 0;
  char c;

 c = getchar();
 while(c != '\n')
 {
  if(c >='0' && c<='9')
  {
  digits++;
  sum += c - '0';
 }
 c = getchar();
 }
 printf ("Digits:%d\tSum:%d\n",digits,sum);
}
