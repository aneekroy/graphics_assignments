#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
double e(double x)
{

    double c=2,s=1,t=x,error=pow(10,-6);
    printf("%f\n",x);
    printf(" %f %f \n",t,fabs(t));
    while(fabs(t)>error)
	     {
	s=s+t;
	t=t*(x/c++);
     }
  return s;
}

double f(double x)
{
  double t;
  t=exp(2*x);
  return (t-(x*x)+1);
}
void bisection(double a,double b)
{
  double error=pow(10,-4),c=0,cprev,FA,FB,FC;
   if(f(a)*f(b)>0)
    {
       printf("Root not lie between  given points");
       
    }

  else 
    {
       do 
	{
	  cprev=c;
	  c=(a+b)/2;
	  FC=f(c);
	    FA=f(a);
	    FB=f(b);
	 printf("a=%f b=%f prev=%f  c=%f  fc=%f  fa=%f  fb=%f  \n",a,b,cprev,c,FC,FA,FB);
	    if(FC==0)
	      {
		 printf("The root is %f",c);
		 exit(0);
	      }
	    else 
	      {
		  if(FC<0)
		   {
		         if(FA<0)
		       a=c;
		     else 
		       b=c;
		   }
		  else 
		   {
		     if(FA>0)
		      a=c;
		     else 
		      b=c;
		   }
	      }
	 }while(fabs(c-cprev)>error);
	       printf("\n\nThe root %f",c);
    }
}
void find_range(double x,double y,double *a,double *b)
{
  while(x<y)
  {
    printf("%f    %f",f(x),f(y));
     if((f(x)*f(y))>0)
      {
      x+=.5;
      y-=.5;
     }
     else 
	       {
	printf("\nRoot lie in %f and %f\n",x,y);
	*a=x;
	*b=y;
	break;
      }
  }
 printf("     %f    %f",a,b);
}
int main()
{
  double i=0;
  double a,b,x,y,c;
    printf("Enter the two initial point A and B-->");
  scanf("%lf%lf",&x,&y);
  printf("\n%lf %lf",x,y);
  if(x<y)
    find_range(x,y,&a,&b);
  else if(x>y)
   {
      c=x;
      x=y;
      y=c;
       find_range(x,y,&a,&b);
   }
    bisection(a,b);
	     printf("%lf \n",exp(2*(-1.3125)));


  getch();
  return 0;
}		

