/*** Program to Draw a Line using Mid Point Algorithm ***/
#include <stdio.h>
#include <dos.h>
#include <graphics.h>

void cartesian()   ///drawing x and y axes
{
    setcolor(BLACK);
for(int i=getmaxx()/2;i<=getmaxx()/2+3;i++)
    line(i,0,i,getmaxy());
for(int i=getmaxy()/2;i<=getmaxy()/2+3;i++)
    line(0,i,getmaxx(),i);

}
void lineMid(int x1, int y1, int x2, int y2);
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
int x1, y1, x2, y2;
int gd = DETECT, gm;
printf("Enter starting coordinates of line: ");
scanf("%d %d", &x1, &y1);
printf("Enter ending coordinates of line: ");
scanf("%d %d", &x2, &y2);
initgraph(&gd, &gm, "");
makegrid();
cartesian();
lineMid(x1, y1, x2, y2);
getch();
return 0;}

void lineMid(int x1, int y1, int x2, int y2){
 int dy = y2-y1;
 int dx = x2-x1;
 int p=dy-dx/2;
 int y=y1;
 for (int x=x1; x <=x2; x++) {
   putp(x, y);
   if(p > 0) {
    y++;
   p+=dy-dx;        ///choosing north-east point(x+1,y+1)
   }
   else         ///choosing east point(x+1,y)
   p+=dy;
 }
 getch();

}

