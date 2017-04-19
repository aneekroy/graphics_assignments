/*addition,subtraction,multiplication and transpose of two matrices */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main ()
{
int a[50][50],b[50][50],c[50][50],d[50][50],e[50][50],f[50][50],g[50][50];
int i,j,k,n,ch;
printf("enter the value of n \n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
		{
		printf("enter the array value\n");
		scanf("%d",&a[i][j]);
		}
		printf("\n");
	}
	printf("output of the 1st matrix\n");
	for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
			{
			printf("%d\t",a[i][j]);
			}
			printf("\n");
		}

	for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
			{
			printf("enter the array value\n");
			scanf("%d",&b[i][j]);
			}
		printf("\n");
		}
	printf("output of the 2nd matrix\n");
		for(i=0;i<n;i++)
		{
		 for(j=0;j<n;j++)
			{
			printf("%d\t",b[i][j]);
			}
			printf("\n");
		}
		while(1)
		{
		printf("enter 1 for addition of two matrices\n");
		printf("enter 2 for substraction of two matrices\n");
		printf("enter 3 for multiplication of two matrices\n");
		printf("enter 4 for transpose of 1st matrix\n");
		printf("enter 5 for transpose of 2nd matrix\n");
		printf("enter 6 for exit\n");
		printf("enter your choise\n");
		scanf("%d",&ch);
		switch(ch)
		{
	     case 1:

	      for(i=0;i<n;i++)
	      {
	      for(j=0;j<n;j++)
		{
		c[i][j]=a[i][j]+b[i][j];
		}
	      }
	      printf("addition of two matrices is:\n");
	      for(i=0;i<n;i++)
		{
		 for(j=0;j<n;j++)
			{
			printf("%d\t",c[i][j]);
			}
			printf("\n");
		}
		break;
		case 2:
		for(i=0;i<n;i++)
	      {
	      for(j=0;j<n;j++)
		{
		d[i][j]=a[i][j]-b[i][j];
		}
	      }
		        printf("substraction of two matrices is:\n");
	      for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
			{
			printf("%d\t",d[i][j]);
			}
			printf("\n");
		}
		break;
		case 3:
		for(i=0;i<n;i++)
			{
			for(j=0;j<n;j++)
				{
				 e[i][j]=0;
				for(k=0;k<n;k++)
				e[i][j]=(a[i][k]*b[k][j])+e[i][j];
				}
			}
			printf("multiplication of two matrices is\n");
			for(i=0;i<n;i++)
				{
				for(j=0;j<n;j++)
					{
					printf("%d\t",e[i][j]);
					}
					printf("\n");
				}
				   break;
		   case 4:
		     for(i=0;i<n;i++)
			{
			for(j=0;j<n;j++)
				{
				f[i][j]=a[j][i];
				}
			}
			printf("transpose of the 1st matrix is\n");
			for(i=0;i<n;i++)
				{
				for(j=0;j<n;j++)
					{
					printf("%d\t",f[i][j]);
					}
					printf("\n");
				}
				break;
				case 5:
				for(i=0;i<n;i++)
			{
			for(j=0;j<n;j++)
				{
				g[i][j]=b[j][i];
				}
			}
			printf("transpose of the 2nd matrix is\n");
			for(i=0;i<n;i++)
				{
				 for(j=0;j<n;j++)
					{
					printf("%d\t",g[i][j]);
					}
					printf("\n");
				}
				break;

				   case 6: exit(0);
				   default: break;
				   }
		}
		getch();
		return 0;
}

