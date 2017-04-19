#include<stdio.h>
#include<conio.h>
#include<math.h>
#define pi 3.141592654
float sine(float x);
float cosine(float x);
void tangent(float x,float *s,int *f);
void main()
 {
  int m,flag;
  float x,sum;
  clrscr();
  printf("Deg sin(series) sin(library) cos(series) cos(library) tan(series) tan(library) ");
  for(m=0;m<=360;m+=45)
   {
    printf("\n");
    x=(pi*m)/180;
    printf("%d   %.5f     %.5f      %.5f     %.5f      ",m,sine(x),sin(x),cosine(x),cos(x));
    tangent(x,&sum,&flag);
    if(flag==0)
     printf("%.5f     %.5f",sum,tan(x));
    else
     printf("infinite     infinite",tan(x));
   }
  getch();
 }
 float sine(float x)
  {
   int i=1;
   float term,sum;
   term=x;
   sum=x;
   while(i>=1)
    {
     term=-(term*(x*x)/((i+1)*(i+2)));
     if(fabs(term)>0.000001)
      {
       sum=sum+term;
       i=i+2;
      }
     else
      break;
    }
   return(sum);
  }
 float cosine(float x)
  {
   int i=1;
   float term,sum;
   term=1;
   sum=0;
   while(fabs(term)>0.000001)
    {
     sum=sum+term;
     term=-(term*x*x)/(i*(i+1));
     i+=2;
    }
   return(sum);
  }
 void tangent(float x,float *s,int *f)
  {
   float sum,c,si;
   int flag=0;
   c=cosine(x);
   si=sine(x);
   if(fabs(c)>0.000001)
    sum=si/c;
   else
    flag=1;
   *f=flag;
   *s=sum;
  }