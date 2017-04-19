#include<stdio.h>
#include<conio.h>
#include<math.h>
#define Eabs 0.001
//#define f(x) (x)*(x)*(x)+3*(x)-5
//#define f(x) (x)*(x)*(x)-2*(x)-5
//#define g(x) 3*(x)*(x)-2
//#define f(x) (x)*(x)-3*(x)+2
//#define g(x) 2*(x)-3
//#define f(x) (x)*(x)-5*(x)+4
//#define g(x) 2*(x)-5
#define f(x) (x)*tan(x)-1.28
#define g(x) tan(x)+(x)*(1/(cos(x)*cos(x)))
void bisection(float a,float b,float *x,float *y);
void regula(float a,float b,float *x,float *y);
void newton(float a,float *x,float *y);
int main()
 {
  float a,b,x,y,u,v,p,q;
  clrscr();
  printf("enter the value for 'a' and 'b' such that f(a)*f(b)<0 and the real root exits\n");
  scanf("%f%f",&a,&b);
  bisection(a,b,&x,&y);
  printf("\nthe approximation real root of the given equation by bisection method is %f \nand the value at that point is %f\n",x,y);
  newton(a,&u,&v);
  printf("\nthe approximation real root of the given equation by newton raphson method is %f \nand the value at that point is %f\n",u,v);
  regula(a,b,&p,&q);
  printf("\nthe approximation real root of the given equation by regula falsi method is %f \nand the value at that point is %f\n",p,q);
  getch();
  return(0);
 }
 void bisection(float a,float b,float *x,float *y)
  {
   float u;
   while(1)
    {
     u=(a+b)/2;
     if(fabs(f(u))<=Eabs)
      {
       *x=u;
       *y=f(u);
       break;
      }
     else
      {
       if((f(a)<0 && f(u)<0) || (f(a)>0 && f(u)>0))
	a=u;
       else
	b=u;
      }
    }
  }
 void regula(float a,float b,float *x,float *y)
  {
   float u1,c,d,e;
    c=f(a);
    d=f(b);
    u1=a+((fabs(c)*(b-a))/(fabs(d)+fabs(c)));
    e=f(u1);
     while(fabs(e)>Eabs)
      {
       if((c*e)<0)
	b=u1;
       else
	a=u1;
       c=f(a);
       d=f(b);
       u1=a+((fabs(c)*(b-a))/(fabs(d)+fabs(c)));
       e=f(u1);
      }
    *x=u1;
    *y=f(u1);
  }
  void newton(float a,float *x,float *y)
   {
    float b,c;
    b=f(a);
    while(fabs(b)>Eabs)
     {
      b=f(a);
      c=g(a);
      if(c<0 || c>0)
	a=a-(b/c);
      else
       break;
     }
     *x=a;
     *y=f(a);
   }
