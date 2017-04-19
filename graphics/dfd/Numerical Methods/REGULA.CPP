#include<stdio.h>
#include<conio.h>
#include<math.h>
#define F(x) (x)*(x)*(x)-2*(x)-5
#define e 0.001
void main()
{
int i;
float x0,x1,x2,fx0,fx1,fx2;
clrscr();
printf("Enter the initial guess values: ");
scanf("%f%f",&x0,&x1);
fx0=F(x0);
fx1=F(x1);
if((fx0*fx1)<0)
{
while(fabs(x1-x0)>=e)
{
x2=x0-(fx0*(x1-x0))/(fx1-fx0);
fx2=F(x2);
if((fx0*fx2)<0)
x1=x2;
else
x0=x2;
}
printf("\nThe root is %f",x2);
printf("\nThe function value is %f",fx2);
}
else
{
printf("\ndoes not converge any root");
}
getch();
}