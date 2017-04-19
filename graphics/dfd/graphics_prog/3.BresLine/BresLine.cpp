/*** Program to Draw a Line using Bresenham's Algorithm ***/
#include <stdio.h>
#include <dos.h>
#include <graphics.h>

void cartesian()        ///drawing x and y axes
{
    setcolor(BLACK);
for(int i=getmaxx()/2;i<=getmaxx()/2+3;i++)
    line(i,0,i,getmaxy());
for(int i=getmaxy()/2;i<=getmaxy()/2+3;i++)
    line(0,i,getmaxx(),i);

}

void makegrid()  ///making grid
{int i,j;
    for(i=0;i<getmaxy();i+=5)
        line(0,i,getmaxx(),i);
        for(j=0;j<getmaxx();j+=5)
        line(j,0,j,getmaxy());

}

void putp(int x,int y)
{y=getmaxy()/2-y;
x=x+getmaxx()/2;
    for(int i=x ;i <x+5 ;i++)
for( int j=y; j>y-5 ;j--)
putpixel(i,j,BLACK);
}

void lineBres(int x1, int y1, int x2, int y2);
int main()
{
int x1, y1, x2, y2;
int gd = DETECT, gm;
printf("Enter starting coordinates of line: ");
scanf("%d %d", &x1, &y1);
printf("Enter ending coordinates of line: ");
scanf("%d %d", &x2, &y2);
initgraph(&gd, &gm, "");
makegrid();
cartesian();
lineBres(x1, y1, x2, y2);
return 0;}

void lineBres(int x1, int y1, int xn, int yn)
{int i,j;


    int dx = xn - x1, dy = yn - y1;
int di = 2 * dy - dx;
int ds = 2 * dy, dt = 2 * (dy - dx);

putp(x1,y1);
while (x1 < xn)
{
x1++;
if (di < 0)     ///choosing east point
di = di + ds;
else
{
y1++;           ///choosing north-east point
di = di + dt;
}
putp(x1,y1);
}
getch();
}
