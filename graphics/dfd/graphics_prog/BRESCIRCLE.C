#include <math.h>
#include <stdio.h>
#include <graphics.h>

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
    initgraph(&gdriver,&gmode,NULL);

    //read result of initialization
    //errorcode=graphresult();

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
    //setfillstyle(SOLID_FILL,CYAN);
    setcolor(LIGHTGRAY);
    rectangle(p.x,p.y-cwidth,p.x+cwidth,p.y);
    floodfill(p.x+cwidth/2,p.y-cwidth/2,LIGHTGRAY);
    setcolor(WHITE);
}

//Bresenham's Circle

int Bresenham_circle()
{	
	    int w,xc,yc,r,x,y,Pk;
	    printf("\nEnter width: ");
	    scanf("%d",&w);
	    printf("Enter the value of Xc : ");
            scanf("%d",&xc);
	    printf("Enter the value of yc : ");
            scanf("%d",&yc);
	    printf("Enter the Radius of circle : ");
            scanf("%d",&r);
            initMainGraph(w);
            x=0;
            y=r;
            plot(xc+x,yc-y,w);
            Pk=3-(2*r);
            for(x=0;x<=y;x++)
            {
                        if (Pk<0)
                        {
                                    y=y;
                                    Pk=(Pk+(4*x)+6);
                        }
                        else
                        {
                                    y=y-1;
                                    Pk=Pk+((4*(x-y)+10));
                        }
                        plot(xc+x,yc-y,w);
                        plot(xc-x,yc-y,w);
                        plot(xc+x,yc+y,w);
                        plot(xc-x,yc+y,w);
                        plot(xc+y,yc-x,w);
                        plot(xc-y,yc-x,w);
                        plot(xc+y,yc+x,w);
			plot(xc-y,yc+x,w);
			delay(1000);

            }
            
	return 0;

}

int main(){

  Bresenham_circle();


    getch();
    closegraph();
    return 0;
}