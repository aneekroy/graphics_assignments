#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
//define a structure for a Point
typedef struct{
    int x;
    int y;
}Point;

//initialize graphics window and draw the graph
int initMainGraph(int cw1){
    int cwidth=cw1;
    int i;
    //request autodetection
    int gdriver=DETECT,gmode,errorcode;
    //initialize graphics mode
    initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

    //read result of initialization
    errorcode=graphresult();

    if(errorcode!=grOk){
     //an error occurred
    printf("Graphics error: %s\n",grapherrormsg(errorcode));
    printf("Press any key to halt:");

    getch();
    exit(1);    //return with error code
    }

    //draw axes
    setlinestyle(SOLID_LINE,0,4);
    line(getmaxx()/2,0,getmaxx()/2,getmaxy());
    line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

    //draw graph
    setlinestyle(SOLID_LINE,0,1);
    for(i=getmaxx()/2-1;i>=0;i-=cwidth)
	line(i,0,i,getmaxy());
    for(i=getmaxx()/2+1;i<=getmaxx();i+=cwidth)
	line(i,0,i,getmaxy());

    for(i=getmaxy()/2-1;i>=0;i-=cwidth)
	line(0,i,getmaxx(),i);
    for(i=getmaxy()/2+1;i<=getmaxy();i+=cwidth)
	line(0,i,getmaxx(),i);

    return 0;
}

//returns 1 for arguments >=0 and -1 for <0
int sign(float f){
    if(f>=0)
	return 1;
    else
	return -1;
}

//maps the point and returns the Point structure
Point mapPoint(float x1,float y1,int cwidth){
    int x0=getmaxx()/2, y0=getmaxy()/2;
    Point p;
    p.x=x0+(int)(cwidth*x1);
    p.y=y0-(int)(cwidth*y1);
    return p;
}

//plots the corresponding pixel
void plot(int x,int y, int cwidth){
    Point p=mapPoint(x,y,cwidth);
    setfillstyle(SOLID_FILL,GREEN);
    setcolor(LIGHTGRAY);
    rectangle(p.x,p.y-cwidth,p.x+cwidth,p.y);
    floodfill(p.x+cwidth/2,p.y-cwidth/2,LIGHTGRAY);
    setcolor(WHITE);
}

//draws the original line which was rasterized
void drawLine(float x0,float y0,float x1,float y1,int cwidth){
    Point p0,p1;
    p0=mapPoint(x0,y0,cwidth);
    p1=mapPoint(x1,y1,cwidth);
    setlinestyle(SOLID_LINE,0,3);
    setcolor(RED);
    line(p0.x,p0.y,p1.x,p1.y);
    setlinestyle(SOLID_LINE,0,1);
    setcolor(WHITE);
}


void BresenhamAll(){
    int cw,s1,s2,flag,i=1;
    int x1,y1,x2,y2,dx,dy,x,y,temp,e=0;
    printf("Enter cell width: ");
    scanf("%d",&cw);
     initMainGraph(cw);
    printf("Enter co-ordinates in this order: x1 y1 x2 y2:: ");
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);


    //initialize variables
    x=x1;
    y=y1;
    dx=abs(x2-x1);
    dy=abs(y2-y1);

    s1=sign(x2-x1);
    s2=sign(y2-y1);

    //initialize e to compensate for a nonzero intercept
    e=2*dy-dx;

    //interchange dx and dy, depending on the slope of the line
    if(dy>dx){
	temp=dx;
	dx=dy;
	dy=temp;
	flag=1;
    }
    else
	flag=0;

   // m=fabs(dy/dx);

    //begin main loop
    while(i<=dx){
	plot(x,y,cw);
	delay(1000);
	while(e>=0){
	    if(flag==1)
		x=x+s1;
	    else
		y=y+s2;
	    e=e-2*dx;
	}
	 if(flag==1)
	     y=y+s2;
	 else
	     x=x+s1;
	e=e+2*dy;
	i=i+1;

    }
    drawLine(x1,y1,x2,y2,cw);
}

//Main function to call DDA subroutine
int main(){
   // clrscr();
   BresenhamAll();
    getch();
    closegraph();
    return 0;
}
