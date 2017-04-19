#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void disp();

void cartesian()    ///drawing x and y axes
{
    setcolor(BLACK);
for(int i=getmaxx()/2;i<=getmaxx()/2+3;i++)
    line(i,0,i,getmaxy());
for(int i=getmaxy()/2;i<=getmaxy()/2+3;i++)
    line(0,i,getmaxx(),i);

}
float x,y;
int xc,yc;
void putp(int x,int y)
{y=getmaxy()/2-y;
x=x+getmaxx()/2;
    for(int i=x ;i <x+5 ;i++)
for( int j=y; j>y-5 ;j--)
putpixel(i,j,BLACK);
}
void makegrid()     ///making grid
{int i,j;
    for(i=0;i<getmaxy();i+=5)
        line(0,i,getmaxx(),i);
        for(j=0;j<getmaxx();j+=5)
        line(j,0,j,getmaxy());

}

int main()
{
int gd=DETECT,gm;
int a,b;
float p1,p2;
//clrscr();
printf("Enter center: ");
scanf("%d%d",&xc,&yc);
printf("Enter major and minor axis length: ");
scanf("%d%d",&a,&b);
initgraph(&gd,&gm,"");
makegrid();
cartesian();

x=0;y=b;
disp();
putp(xc,yc);
p1=(b*b)-(a*a*b)+(a*a)/4;
while((2.0*b*b*x)<=(2.0*a*a*y))///region 1 where dy/dx>-1
{
x++;
if(p1<=0)///east point
p1=p1+(2.0*b*b*x)+(b*b);
else
{
y--;        ///south-east point
p1=p1+(2.0*b*b*x)+(b*b)-(2.0*a*a*y);
}
disp();
x=-x;
disp();
x=-x;
}
x=a;
y=0;
disp();
p2=(a*a)+2.0*(b*b*a)+(b*b)/4;
while((2.0*b*b*x)>(2.0*a*a*y))///region 2 where dy/dx<-1
{
y++;
if(p2>0)///south-east point
p2=p2+(a*a)-(2.0*a*a*y);
else
{
x--;///south point
p2=p2+(2.0*b*b*x)-(2.0*a*a*y)+(a*a);
}
disp();
y=-y;
disp();
y=-y;
}
getch();
closegraph();
return 0;}
void disp()
{
putp(xc+x,yc+y);///4 points plotted due to symmetry
putp(xc-x,yc+y);
putp(xc+x,yc-y);
putp(xc+x,yc-y);
}
