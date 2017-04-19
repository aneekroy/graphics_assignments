
#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <math.h>


void putp(int x,int y)
{y=getmaxy()/2-y;
x=x+getmaxx()/2;
	for(int i=x ;i <x+5 ;i++)
for( int j=y; j>y-5 ;j--)
putpixel(i,j,BLACK);

}
void makegrid()  ///making grid
{int i,j;
	for(i=0;i<getmaxy();i+=5)
		line(0,i,getmaxx(),i);
		for(j=0;j<getmaxx();j+=5)
		line(j,0,j,getmaxy());

}

void cartesian()    ///drawing x and y axes
{   int i;
	setcolor(BLACK);
for(i=getmaxx()/2;i<=getmaxx()/2+3;i++)
	line(i,0,i,getmaxy());
for(i=getmaxy()/2;i<=getmaxy()/2+3;i++)
	line(0,i,getmaxx(),i);

}

int main(){

float x,y,dx,dy;
int x1,y1,x2,y2,i,length;
int gdriver = DETECT, gmode;
printf("Enter starting coordinates of line: ");
scanf("%d %d", &x1, &y1);
printf("Enter ending coordinates of line: ");
scanf("%d %d", &x2, &y2);

initgraph(&gdriver,&gmode,"c:\\TC\\BGI");
makegrid();
cartesian();


dx = abs(x2-x1);
dy = abs(y2-y1);

if(dx>=dy) length = dx;
else length = dy;
dx = dx/length;
dy = dy/length;
x=x1;
y=y1;
i=1;

while(i<=length){
putp(x,y);///plotting pixel
x = x + dx;
y = y + dy;
i++;
}
getch();
closegraph();
return 0;
}
