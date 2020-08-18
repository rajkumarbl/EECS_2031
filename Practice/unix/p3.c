#include<stdio.h>
#include<stdlib.h>

typedef struct{
char *text;
int length;
}line;

void inplines(line *l, int *mlen)
{
 int i,len;
 scanf("%d",&len);  l->length =len;
 l->text = (char *) malloc((len+2)*sizeof(char));
 getchar();
 for(i=0;i<len+1;i++) l->text[i] = getchar();
  l->text[len+1] = '\0';
 if((l->length)>*mlen)*mlen=(l->length);
}

void outlines(line *l, int *mlen)
{
 if(l->length== *mlen)printf("%s",l->text);
}

int main()
{
 line *lines;
 int nol,mlength=0,i;
 printf("Enter the number of lines");
 scanf("%d", &nol);
 lines = (line *) malloc (nol*sizeof(line));
 for(i=0;i<nol;i++)inplines(lines+i,&mlength);
 for(i=0;i<nol;i++)outlines(lines+i,&mlength);
}
 
