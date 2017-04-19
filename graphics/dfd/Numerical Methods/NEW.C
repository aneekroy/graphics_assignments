#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) x*x*x-2*x-5
#define fd(x) 3*x*x-2
void main()
{
  float x0,x1,f0,fd0,e;
  clrscr();
  printf("\t\t\t Newton Raphson Method");
  printf("\nEnter the initial value\n");
  scanf("%f",&x0);
  printf("\nf(x0)\t\tfd(x0)\t\tx1\t\tError");
  begin:
  f0=f(x0);
  fd0=fd(x0);
  x1=x0-(f0/fd0);
  e=fabs((x1-x0)/x1);
  if(e<0.0001)
	{printf("\nRoot is =%5f",x1);
	}
  else
	{printf("\n%2f\t\t%3f\t\t%3f\t\t%4f",f(x0),fd(x0),x1,e);
	  x0=x1;
	  goto begin;
	}
	getch();
}