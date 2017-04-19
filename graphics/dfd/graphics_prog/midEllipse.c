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

int MidEllipse()
{

    int midx,midy,xrad,yrad,w;
    int xrad2,yrad2,xrad22,yrad22;
    int x,y,dp,dpx,dpy;

    printf("\n Enter cell width: ");
    scanf("%d", &w);
    initMainGraph(w);
    printf("\n Enter x Radius: ");
    scanf("%d", &xrad);
    printf("\n Enter y Radius: ");
    scanf("%d", &yrad);
    printf("\n Enter Center(x,y): ");
    scanf("%d %d", &midx,&midy);


    xrad2=xrad*xrad;
    yrad2=yrad*yrad;

    xrad22=2*xrad2;
    yrad22=2*yrad2;

    x=dpx=0;
    y=yrad;
    dpy= yrad22*y;

    plot(midx+x,midy+y,w);
    plot(midx-x,midy+y,w);
    plot(midx+x,midy-y,w);
    plot(midx-x,midy-y,w);

    dp=(int)(0.5+yrad2-(xrad2*yrad)+(0.25*xrad2));

    while(dpx<dpy)
    {
        x++;
        dpx=dpx+yrad22;
        if(dp<0)
        {
            dp=dp+yrad2+dpx;
        }
        else
        {
            y--;
            dpy=dpy-xrad22;
            dp=dp+yrad2+dpx-dpy;
        }
        /* plotting points in y-axis (top- bottom)*/
    plot(midx+x,midy+y,w);
    plot(midx-x,midy+y,w);
    plot(midx+x,midy-y,w);
    plot(midx-x,midy-y,w);
    delay(500);
    }
    delay(1000);

    dp=(int)(0.5+yrad2*(x+0.5)+xrad2*(y-1)*(y-1)-xrad2*yrad2);
    while(y>0)
    {
        y--;
        dpy=dpy-xrad22;
        if(dp>0)
        {

            dp=dp+xrad2-dpy;
        }
        else
        {
         x++;
        dpx=dpx+yrad22;
        dp=dp+xrad2-dpy+dpx;
        }
        //plotting points at x-axis (left-right)
    plot(midx+x,midy+y,w);
    plot(midx-x,midy+y,w);
    plot(midx+x,midy-y,w);
    plot(midx-x,midy-y,w);
    delay(500);
}
return 0;

}
int main(){

  MidEllipse();
    getch();
    closegraph();
    return 0;
}
