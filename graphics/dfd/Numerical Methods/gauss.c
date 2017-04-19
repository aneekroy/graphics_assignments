#include<stdio.h>

void main()
{
    int i,j,k,n;
    float a[20][20],c,x[10],sum=0.0;
    printf("Enter the order of the matrix: ");
    scanf("%d",&n);
    printf("Enter the augmented matrix row wise: ");
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
        {
            printf("A[%d][%d] = ",i+1,j+1);
            scanf("%f",&a[i][j]);
        }
    }
    for(j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
        {
            if(i>j)
            {
                c=a[i][j]/a[j][j];
                for(k=0;k<=n;k++)
                    a[i][k]=a[i][k]-c*a[j][k];
            }
        }
    }
    x[n-1]=a[n-1][n]/a[n-1][n-1];
    for(i=n-2;i>=0;i--)
    {
        sum=0;
        for(j=i+1;j<n;j++)
            sum=sum+a[i][j]*x[j];
        x[i]=(a[i][n]-sum)/a[i][i];
    }
    printf("The solution is: \n");
    for(i=0;i<n;i++)
        printf("\nx%d = %f\t",i,x[i]);
}
