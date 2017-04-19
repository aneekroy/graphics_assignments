#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x)
{
return pow(x,3)-3*x+1.06;
}
void main()
{
float a,b,m,x;
int i;
clrscr();
for(i=0;;i++)
	if(f(i)*f(i+1)<0.0)
	{
	a=i;
	b=i+1;
	break;
	}
	printf("\nThe initial interval is %f, %f",a,b);
	m=(a+b)/2;
	do
	{
		if(f(a)>0.0)
		{
			if(f(m)<0.0)
				b=m;
			else
				a=m;
		}
		else
		{
			if(f(m)<0.0)
				a=m;
			else
				b=m;
		}
	m=(a+b)/2;
	}
	while(fabs(f(m))>0.0001);
	printf("\nThe root is %f",m);
	getch();
}
/*------------------------OUTPUT----------------------------------------------
CASE 1:
x^3-9x+1=0
The initial interval is 0.000000, 1.000000
The root is 0.111267

CASE 2:
x^3-3x+1.06
The initial interval is 0.000000, 1.000000
The root is 0.370239
*/