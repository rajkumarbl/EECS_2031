/***********************************
* EECS2031   - Assignment 1
* Filename   : poly.c 
* Author     : Balakrishnan Lakshmi, Rajkumar
* Email      : kumarraj@my.yorku.ca
* Login ID   : kumarraj
* STUDENT ID : 213141197
************************************/

#include "poly.h"

void init_polynom( int coeff[ ], int exp[ ] )
{
   
   int i;
   for(i=0;i<ASIZE;i++)
   { 
     coeff[i]=0;exp[i]=0;
   }
}  


void get_polynom( int coeff[ ], int exp[ ] )
{
   int inputsz,i,index=0;
   scanf("%d", &inputsz);
   for(i=0;i<(2*inputsz);i++)
   { 
     if((i%2)==0)
      {
        scanf("%d", &coeff[index]);
	continue;
      }
     scanf("%d", &exp[index]);
     index++;
   }
}


void polynom_to_string( int coeff[ ], int exp[ ], char s[ ] )
{

   int i,count=0;

   for(i=0;i<ASIZE;i++)
   { 
     //if coeff is zero exit the loop using break statement and add zero to the string
     if(coeff[0]== 0)
     {
       s[count]='0';count++;break;
     }
     else if(coeff[i]!= 0)
     {
       int coeffecient1 = coeff[i];
       int coeffecient2 = coeff[i];
       int temp = -1;
       //counting the zero for coeff
       while((coeffecient2%10)==0)
       {
         coeffecient2 = coeffecient1%10;
         coeffecient1/=coeffecient1;temp++;
       }
       coeffecient1 = coeff[i];
       if (coeff[i] < 0)
       {
        s[count++] = '-';coeffecient1 = coeff[i] * -1;
       }
       else if (coeff[i] > 0 && count > 0)
       {s[count++] = '+';}

      int x=0,y=0,z=0;
      if(coeffecient1>1)
      {
        if(coeffecient1>=1)
        {
         while(coeffecient1>=1)
         {
          x= coeffecient1%10;
          coeffecient1/=10;
          y=(y*10)+x;
         }
        coeffecient1=y;x=0;
        //converting integer part
        while(coeffecient1>=1)
         {
          x= coeffecient1%10;
          coeffecient1/=10;
          s[count]= x+'0';count++;
         }
        while(z<temp){s[count]='0';count++;z++;}
      }}
        int exponent1 = exp[i];
        if(exp[i]==0 && coeff[i]==1){s[count] = coeff[i] + '0';count++;}
        if(exp[i]==0 && coeff[i]==-1){s[count] = 1 + '0';count++;}
        if(exp[i]!=0){s[count] ='x';count++;
        if(exp[i]!=1 && exp[i]!=-1){s[count] ='^';count++;}
        if(exp[i]<0){s[count] ='-';count++;exponent1 = exp[i] * -1;}
        
        int x=0,y=0,z=-1,temp=exp[i];
        while((temp%10) == 0)
        {
         temp = exponent1%10;
         exponent1/=10;
         z++;
        }
        exponent1 = exp[i];
       if (exponent1 > 1)
       {
        while(exponent1 >= 1)
        {
         x = exponent1 % 10;
         exponent1/=10;
         y = (y*10) + x;
        }
        exponent1 = y;x=0;
         while(exponent1 >= 1)
        {
         x = exponent1 % 10;
         exponent1/=10;
         s[count] = x + '0';
         count++;
        }
        int t=0;
        while(t<z)
        {
         s[count] = '0';
         t++;count++;
        }
      }
    }
  }
}
 s[count] = '\0';
}  

void eval_polynom( int coeff[ ], int exp[ ], double x, double *result )
{
    int index=0,i=5,sum=0,j;
    double value=1;
    while(i)
    {
      if(coeff[index]==0)break;
      if(exp[index]==0)
      {
       sum+=coeff[index];index++;
       continue;
      } 
      for(j=1;j<exp[index];j++){value=value*x;}
      sum+=(double)(coeff[index] * value);
      index++;
    }
   *result=sum;
}  


void add_polynom( int co1[ ], int ex1[ ], int co2[ ], int ex2[ ] )
{
         int coeffecient[ASIZE], exponant[ASIZE];
         int index;
         int position1 = 0;
         int position2 = 0;
       
         for (index= 0; index<ASIZE; index++){
              if (ex1[position1] == ex2[position2]){
                coeffecient[index] = co1[position1] + co2[position2];
               exponant[index] = ex1[position1];
                position1++; position2++;}
              else if (ex1[position1] > ex2[position2]){
               coeffecient[index] = co1[position1];
                exponant[index] = ex1[position1++];}
              else if (ex1[position1] < ex2[position2]){
                coeffecient[index] = co2[position2];
                exponant[index] = ex2[position2++];}} 
       
            int position3;
            for (position3 = 0; position3<ASIZE; position3++){
                co1[position3] = coeffecient[position3];
                ex1[position3] = exponant[position3];}

} 

/************************** END OF FILE ***************************/





