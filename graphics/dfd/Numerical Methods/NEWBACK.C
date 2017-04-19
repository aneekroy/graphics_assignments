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
u=(x-m[n-1][0])/h;
s=m[n-1][1];
for(i=1;i<n;i++)
s=s+uCr(u+i-1,i)*m[n-i-1][i+1];
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
/*-------------------------------OUTPUT---------------------------------------

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

Enter the value of X where Y is to be found:5.7

The value of f(5.700000) is 17.902256

CASE 2:

How many points:5

Enter the values of X:0.22
0.24
0.26
0.28
0.30

Enter the values of Y:1.6698
1.6804
1.6912
1.7024
1.7139
0.220000        1.669800        0.010600        0.000200        0.000200
-0.000300
0.240000        1.680400        0.010800        0.000400        -0.000100

0.260000        1.691200        0.011200        0.000300
0.280000        1.702400        0.011500
0.300000        1.713900

Enter the value of X where Y is to be found:0.29

The value of f(0.290000) is 1.719649

CASE 3:


How many points:4                                                               
                                                                                
Enter the values of X:20                                                        
24                                                                              
28                                                                              
32                                                                              
                                                                                
Enter the values of Y:0.01427                                                   
0.01581                                                                         
0.01772                                                                         
0.01996                                                                         
20.000000       0.014270        0.001540        0.000370        -0.000040       
                                                                                
24.000000       0.015810        0.001910        0.000330                        
28.000000       0.017720        0.002240
32.000000       0.019960

Enter the value of X where Y is to be found:30

The value of f(30.000000) is 0.021191

CASE 4:

How many points:4                                                               
                                                                                
Enter the values of X:1                                                         
3                                                                               
5                                                                               
7                                                                               
                                                                                
Enter the values of Y:3                                                         
5                                                                               
8                                                                               
12                                                                              
1.000000        3.000000        2.000000        1.000000        0.000000        
                                                                                
3.000000        5.000000        3.000000        1.000000
5.000000        8.000000        4.000000
7.000000        12.000000

Enter the value of X where Y is to be found:8

The value of f(8.000000) is 9.875000
*/