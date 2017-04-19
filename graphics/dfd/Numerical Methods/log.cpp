
#include<stdio.h>
#include<math.h>
main()
{
float x,y,sum1=0.0,term1=0.0,term2=1.0,sum2=1.0;
int i=0,j;
printf("Enter the value of x: ");
scanf("%f",&x);
y=1+x;
do
{
sum1=sum1+term1;
i++;
term1=pow(x,i)*pow(-1,i+1)/i;
} while(fabs(term1)>0.000001); 
printf("\nValue of ln %0.2f= %f",y,sum1);
for(j=1;;j=j+1)
{
term2=term2*sum1/j;
if(fabs(term2)<0.000001)
break;
sum2=sum2+term2;
}
printf("\nValue of e^ln(%0.2f)=e^%f= %f",y,sum1,sum2);
if(fabs(y-sum2)<0.0001)
printf("\nRounding of the result, the value of the series is verified.");
}
