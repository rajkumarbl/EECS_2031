#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void changepos(char *ch1, char *ch2)
{
  char temp;
  temp = *ch1;
  *ch1 = *ch2;
  *ch2 = temp;
}

void changeperm(char *cht, int st, int end)
{
  int i;
  if( st == end)
  printf("%s\t",cht);
  else
  {
    for(i=st;i<=end;i++)
     {
       changepos((cht+st),(cht+i));
       changeperm(cht,st+1,end);
       changepos((cht+st),(cht+i));
     }
  }
}

int main()
{ 
  int len=0,n,i;
  char *strg,c;
  printf("Enter the no of char to be entered: ");
  scanf("%d",&n);
  strg =(char *) malloc((n+1)*sizeof(char));
  printf("Enter the string with only char: ");
  getchar();
  for(i=0;i<n;i++)
  {
   strg[i]=getchar();
  }
 // strg[i]='\0';
  printf("The permutations of the string are:\n");
  changeperm(strg,0,n-1);
  printf("\n\n");
}

