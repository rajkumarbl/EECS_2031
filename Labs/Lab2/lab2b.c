#include<stdio.h>
#define max_Size 100

void main()
{
  int count=0,max,min,num[max_Size],n;
  scanf("%d", &n);
  num[count++] = n;
  min =n; max=n;
  while( n !=0 && count<max_Size)
   {
    scanf("%d", &n);
    num[count++] = n;
    if(max<n)
    max=n;
    if(min>n)
    min=n;
    }
  printf("%d\t%d\n",max,min);
}

   
  
