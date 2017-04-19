#include<stdio.h>
#include<conio.h>
float uCr(float u,int r);
void table(int n);
float m[10][10];
void main()
{
int n,i,j;
float s=0.0,u,x,h;
clrscr();
printf("\nHow many points:");
scanf("%d",&n);
table(n);
printf("\nEnter the value of X where Y is to be found:");
scanf("%f",&x);
h=m[1][0]-m[0][0];
u=(x-m[0][0])/h;
s=m[0][1];
for(i=1;i<n;i++)
s=s+uCr(u,i)*m[0][i+1];
printf("\nThe value of f(%f) is %f",x,s);
getch();
}
void table(int n)
{
int i,j;
printf("\nEnter the values of X:");
for(i=0;i<n;i++)
scanf("%f",&m[i][0]);
printf("\nEnter the values of Y:");
for(i=0;i<n;i++)
scanf("%f",&m[i][1]);
j=1;
while(j<n)
{
for(i=0;i<n;i++)
m[i][j+1]=m[i+1][j]-m[i][j];
j++;
}
for(i=0;i<n;i++)
{
for(j=0;j<=n-i;j++)
printf("%f\t",m[i][j]);
printf("\n");
}
}
float uCr(float u,int r)
{
if(r==0)
return 1.0;
else if(r==1)
return (u);
else
return uCr(u,r-1)*(u-r+1)/r;
}
/*----------------------------OUTPUT------------------------------------------
CASE 1:


How many points:4                                                               
                                                                                
Enter the values of X:1                                                         
3                                                                               
5
7

Enter the values of Y:14.5
16.3
17.5
18.0
1.000000        14.500000       1.799999        -0.599998       -0.100002

3.000000        16.299999       1.200001        -0.700001
5.000000        17.500000       0.500000
7.000000        18.000000

Enter the value of X where Y is to be found:2.5

The value of f(2.500000) is 15.902343

CASE 2:


How many points:3                                                               
                                                                                
Enter the values of X:2.7                                                       
2.8                                                                             
2.9                                                                             
                                                                                
Enter the values of Y:0.37                                                      
0.35                                                                            
0.34                                                                            
2.700000        0.370000        -0.020000       0.010000                        
2.800000        0.350000        -0.010000                                       
2.900000        0.340000                                                        
                                                                                
Enter the value of X where Y is to be found:2.78

The value of f(2.780000) is 0.353200
*/