#include<stdio.h>
#include<conio.h>
#include<math.h>
#define F(x) (x*x*x)-(2*x)-5
#define e 0.00001
void main()
{
int i=0;
float x0,x1,x2,fx0,fx1,fx2;
clrscr();
printf("Enter the initial guess values: ");
scanf("%f%f",&x0,&x1);
printf("i\tx0\tx1\tx2\tf(x0) \t f(x1) \t  f(x2)");
printf("\n");
fx0=F(x0);
fx1=F(x1);
if((fx0*fx1)<0)
{
while(fabs(x1-x0)>=e)
{
fx0=F(x0);
fx1=F(x1);
x2=(x0+x1)/2;
fx2=F(x2);
i++;
printf("%d %f %f %f %f %f %f\n",i,x0,x1,x2,fx0,fx1,fx2);
if((fx0*fx2)<0)
x1=x2;
else
x0=x2;
}
printf("\nThe final root is %f",x2);
printf("\nThe function value is %f",fx2);
printf("\nThe iteration number is %d",i);
}
else
printf("\nDoes not converge any root");
getch();
}
