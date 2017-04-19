#include<stdio.h>
#include<conio.h>
void main()
{
float i,j,x[10],y[10],n,p1,p2,S=0.0,l[10],x0;
clrscr();
printf("\nenter the no of points");
scanf("%f",&n);
for(i=0;i<n;i++)
{
printf("\nenter the values of x");
 scanf("%f",&x[i]);
printf("\nentr the values of y");
 scanf("%f",&y[i]);
 }
 printf("\nenter the target value of x");
 scanf("%f",&x0);
 j=0;
 while(j<n)
 {
 p1=1.0; p2=1.0;
 for(i=0;i<n;i++)
 if(i==j) continue;
 else
 {
 p1=p1*(x0-x[i]);
 p2=p2*(x[j]-x[i]);
 }
 l[j]=p1/p2;
 j++;
 }
 for(i=0;i<n;i++)
 S=S+l[i]*y[i];
 printf("S=%f",S);
 getch();
 }
 /*-------------------------output-------------------------------
enter the no of points5                                                         
                                                                                
enter the values of x5.0                                                        
                                                                                
entr the values of y0.28366                                                     
                                                                                
enter the values of x5.1                                                        
                                                                                
entr the values of y0.37798

enter the values of x5.3

entr the values of y0.55437

enter the values of x5.5

entr the values of y0.70867

enter the values of x5.6

entr the values of y0.77557

enter the target value of x5.4
S=0.634687   */

























