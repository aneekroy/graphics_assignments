#include<graphics.h>
#include<conio.h>
#include<stdio.h>

void cartesian()    ///drawing x and y axes
{
    setcolor(BLACK);
for(int i=getmaxx()/2;i<=getmaxx()/2+3;i++)
    line(i,0,i,getmaxy());
for(int i=getmaxy()/2;i<=getmaxy()/2+3;i++)
    line(0,i,getmaxx(),i);

}
void putp(int x,int y)
{y=getmaxy()/2-y;
x=x+getmaxx()/2;
    for(int i=x ;i <x+5 ;i++)
for( int j=y; j>y-5 ;j--)
putpixel(i,j,BLACK);

}
void makegrid() ///making grid
{int i,j;
    for(i=0;i<getmaxy();i+=5)
        line(0,i,getmaxx(),i);
        for(j=0;j<getmaxx();j+=5)
        line(j,0,j,getmaxy());

}
int main()
{
int gd=DETECT,gm;
int i,r,x,y,xc,yc;
float d;
printf("Enter Radius\n");
scanf("%d",&r);
printf("Enter Center of circle\n");

scanf("%d",&xc);
scanf("%d",&yc);
initgraph(&gd,&gm,"");
makegrid();
cartesian();
putp(xc,yc);
d=1.25-r;
x=0;
y=r;
do
{
if(d<0)
{

x=x+1; ///choosing next  horizontal point
d=d+2*x+1;
}
else
{

x=x+1;
y=y-1;///choosing next diagonal point
d=d+2*x-2*y+10;
}
 putp(xc+x,yc+y);///8 points plotted due to symmetry
putp(xc-y,yc-x);
putp(xc+y,yc-x);
putp(xc-y,yc+x);
putp(xc+y,yc+x);
putp(xc-x,yc-y);
putp(xc+x,yc-y);
putp(xc-x,yc+y);
}
while(x<y);

getch();
return 0;}
