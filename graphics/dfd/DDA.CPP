#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>

int sign(int p){
if(p<0){
return -1;
}
else if(p==0){
return 0;
}
else{
return 1;
}
}

int main(void){
int x1, x2, y1, y2;		//taking starting and ending point of the line
printf("Enter x1:");
scanf("%d", &x1);
printf("Enter x2:");
scanf("%d", &x2);
printf("Enter y1:");
scanf("%d", &y1);
printf("Enter y2:");
scanf("%d", &y2);


int xmax = getmaxx();
int ymax = getmaxy();

int i;				//Creating Graph
for(i=0;i<=xmax;i+=10){
line(i,0,i,ymax);
}
for(i=0;i<=ymax;i+=10){
line(0,i,xmax,i);
}

setlinestyle(0,0,2);
line(xmax/2,0,xmax/2,ymax);
line(0,ymax/2,xmax,ymax/2);

int d1 = (x2-x1)*10;		//implementing the algo.
int d2 = (y2-y1)*10;

x1 = xmax/2;
y1 = ymax/2;

//line(x1,y1,x2,y2);

double len = (abs(x2-x1)>abs(y2-y1))?abs(x2-x1):abs(y2-y1);
double dx, dy;
dx = ((x2-x1)/len)*10;
dy = ((y2-y1)/len)*10;

double x = x1+(5*sign(x2-x1));
double y = y1+(5*sign(y2-y1));

for(i=10;i<=len;i+=10){
floodfill(x,y,WHITE);
x = x+dx;
y = y+dy;
}
setcolor(CYAN);		//drawing final line
line(x1,y1,x2,y2);

getch();
closegraph();
return 0;
}




