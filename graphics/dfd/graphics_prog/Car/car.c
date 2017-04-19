#include<graphics.h>
#include<stdio.h>
int main()
{
int i, j = 0, gd = DETECT, gm;

initgraph(&gd,&gm,NULL);
setcolor(WHITE);
getch();

for( i = 0 ; i <= 420 ; i = i + 10)
{
rectangle(50+i,275,150+i,400);///car engine and body
rectangle(150+i,350,200+i,400);
circle(75+i,410,10);///car wheels
circle(175+i,410,10);
sleep(1);
if( i == 420 )
break;


cleardevice();
}

getch();
closegraph();
return 0;
}

