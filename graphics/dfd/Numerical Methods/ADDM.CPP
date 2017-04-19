#include<stdio.h>
#include<conio.h>
void main()
	{
	int m,n,a[10][10],b[10][10],c[10][10],d[10][10],i,j,p,q;
	clrscr();
	printf("enter the order of the first matrix:");
	scanf("%d%d",&m,&n);
	printf("enter the first matrix:");
	for(i=0;i<m;i++)
	{
	for(j=0;j<n;j++)
	{
	scanf("%d",&a[i][j]);
	}
	}
	printf("enter the order of the second matrix:");
	scanf("%d%d",&p,&q);
	printf("enter the second matrix");
	for(i=0;i<p;i++)
	{
	for(j=0;j<q;j++)
	{
	scanf("%d",&b[i][j]);
	}
	}
	if(m==p&&n==q)
	{
	for(i=0;i<m;i++)
	{
	for(j=0;j<n;j++)
	{
	c[i][j]=a[i][j]+b[i][j];
	}
	}
	printf("the addition of two matrices is \n");
	for(i=0;i<m;i++)
	{
	for(j=0;j<n;j++)
	{
	printf("%d",c[i][j]);
	}
	printf("\n");
	}
	for(i=0;i<m;i++)
	{
	for(j=0;j<n;j++)
	{
	d[i][j]=a[i][j]-b[i][j];
	}
	}
	printf("the substraction is:");
	for(i=0;i<m;i++)
	{
	for(j=0;j<n;j++)
	{
	printf("%d",d[i][j]);
	}
	printf("\n");
	}
	}
	getch();
	}
