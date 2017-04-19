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
 void pixel(int xc,int yc,int x,int y,int w);
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
    setfillstyle(SOLID_FILL,CYAN);
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

/*MID- POINT CIRCLE*/

int midpoint_circle()
{
    int w,xc,yc,r,P,x,y;
    printf("\nEnter Width");
    scanf("%d",&w);
    initMainGraph(w);
    printf("\nEnter Center  (x,y) ");
    scanf("%d %d",&xc,&yc);
    printf("Enter radius");
    scanf("%d" ,&r);

    x=0;
    y=r;
    P=1-r;
    pixel (xc,yc,x,y,w);
    while(x<y)
    {
	if(P<0)
	{

	    x++;
	    P=(P+(2*x)+1);
	}
	else
	{
	    x++;
	    y=y-1;
	    P=P+(2*x)-(2*y)+1;
	}
	pixel(xc,yc,x,y,w);
    }
    return 0;
}
int main(){

  midpoint_circle();


    getch();
    closegraph();
    return 0;
}

void pixel(int xc,int yc,int x,int y,int w)
{
    plot(xc+x,yc+y,w);
    plot(xc+y,yc+x,w);
    plot(xc-y,yc+x,w);
    plot(xc-x,yc+y,w);
    plot(xc-x,yc-y,w);
    plot(xc-y,yc-x,w);
    plot(xc+y,yc-x,w);
    plot(xc+x,yc-y,w);
    delay(1000);
}
