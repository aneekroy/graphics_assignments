#include<stdio.h>
#include<math.h>
#include<time.h>
int fact(int n)
{
    int i,f=1;
    for(i=1;i<=n;i++)
	    {
        f=f*i;
    }
    return(f);
}
int main()
{
    time_t start1,start2,end1,end2;
    int x,n,i,sn=-1;
    double sum=0.0,sum1=0.0,t,t1,inter,sum2=0.0,time1,time2;
    printf("\nEnter the value of x for which the series value is to be calculated: ");
    scanf("%d",&x);
    printf("\nEnter the limit up to which the series sum is to be calculated: ");
    scanf("%d",&n);
    sum+=1.0;
	    start1= time(NULL);
    for(i=1;i<=n;i++)
    {
        t=pow(x,i)/fact(i);
        sum+=t;
    }
    end1=time(NULL);
    time1=difftime(start1,end1);
    printf("\nThe value of the series is: %f",sum);
    start2=time(NULL);
    for(i=1;i<=n;i++)
    {
       inter=pow(x,i)/i;
       sn*=-1;
       t1=inter*sn;
	          sum2=sum2+t1;
    }
    end2=time(NULL);
    time2=difftime(start2,end2);
     printf("\nThe value of the series is: %f",sum2);
     if(time1>time2)
     {
         printf("\n exponential series converges first.");
     }
     else
     {
          printf("\n logarithmic series converges first.");
     }
    return 0;
}

