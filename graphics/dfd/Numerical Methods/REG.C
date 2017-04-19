#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x)
{
return (3*x)-cos(x)-1;
}
void main()
{
int i;
float a,b,x;
clrscr();
for(i=3;i<=4;i++)
{
if(f(i)*f(i+1)<0.0)
a=i;b=i+1;
break;
}
printf("\nInitial interval:(%f %f)",a,b);
x=a-(b-a)/(f(b)-f(a))*f(a);
do{
if(f(a)>0.0)
{
if(f(x)<0.0)
b=x;
else
a=x;
}
else
{
if(f(x)<0.0)
a=x;
else
b=x;
}
x=a-(b-a)/(f(b)-f(a))*f(a);
}
while(fabs(f(x))>0.000001);
printf("\nRoot is %f;",x);
getch();
}
/*---------------------------OUTPUT-------------------------------------------

CASE 1:
x^3-9x+1=0
Initial interval:(0.000000 1.000000)
Root is 0.111264;

CASE 2:
x^3+2x-2=0
Initial interval:(0.000000 1.000000)
Root is 0.770917;

CASE 3:
2x-log10(x)-7=0
Initial interval:(3.000000 4.000000)
Root is 3.789278;
*/