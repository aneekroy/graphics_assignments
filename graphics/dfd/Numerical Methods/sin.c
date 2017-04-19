#include<stdio.h>
#include<math.h>
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
    int n,x,sn=-1,s=1,i;
    double s1=0.0,s2=0.0,t1,v1,v2,v3,s3;
    printf("\nEnter the value of x for which the value of sin series is to be calculated: ");
    scanf("%d",&x);
    v1=sin(x);
    v2=cos(x);
    v3=tan(x);
    for(i=1;i<=7;i=i+2)
	    {
        sn=sn*(-1);
        t1=pow(x,i)/fact(i);
        s1=s1+(t1*sn);

    }
    s2=s2+1;
    for(i=2;i<=6;i=i+2)
    {
        s=s*-1;
        t1=pow(x,i)/fact(i);
        s2=s2+(t1*s);
    }
    s3=s1/s2;
    printf("\nsin(x)[library]\tsin(x)[function]\tcos(x)[library]\tcos(x)[function]\n");
	    printf("%f\t%f\t%f\t%f",v1,s1,v2,s2);
    printf("\ntan(x)[library]\ttanx(x)[function]");
    printf("\n%f\t%f",v3,s3);
    return 0;


}

