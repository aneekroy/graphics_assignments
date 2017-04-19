#include "header.h"
#define top 8
#define bottom 4
#define right 2
#define left 1

int cellWidth;
float xMin, xMax, yMin, yMax,x1,y1,x2,y2;

int endCode(float x, float y, float xMin, float xMax, float yMin, float yMax)
{
	int code=0;
	if(y>yMax)
		code=code|top;
	else if(y<yMin)
		code=code|bottom;
	if(x>xMax)
		code=code|right;
	else if(x<xMin)
		code=code|left;
	return code;
}

void DDA(float x1,float y1, float x2, float y2)
{
    int i;
    float dx,dy,x,y,length;
    if(fabs(x2-x1)>=fabs(y2-y1))
		length=fabs(x2-x1);
    else
		length=fabs(y2-y1);
    dx=(x2-x1)/length;
    dy=(y2-y1)/length;
    x=x1+sign(x2-x1)*0.5;
    y=y1+sign(y2-y1)*0.5;
    i=1;
    while(i<=length){
	plot(floor(x),floor(y),cellWidth);
	x=x+dx;
	y=y+dy;
	i=i+1;
    }
    drawLine(x1,y1,x2,y2,cellWidth);
}
void SC()
{
	int done=0, ecode1,ecode2;
	float x,y;
	int ecodeOut;
	float slope;
	ecode1=endCode(x1,y1,xMin,xMax,yMin,yMax);
	ecode2=endCode(x2,y2,xMin,xMax,yMin,yMax);
	slope=1.0f*(y2-y1)/(x2-x1);
	do
	{
		printf("%f %f\n", x1,y1);
		if(ecode1==0 && ecode2==0) // totally visible
		{
			DDA(x1,y1,x2,y2);
			done=1;
			break;
		}
		else if(ecode1&ecode2) // trivially invisible
		{
			done=1;
			break;
		}
		else // partially visible
		{
			if(ecode1)
				ecodeOut=ecode1;
			else
				ecodeOut=ecode2;
		}
		if(ecodeOut&top) // split line at top edge
		{
			x=x1+1.0*(yMax-y1)/slope;
			y=yMax;
		}
		else if(ecodeOut&bottom) // split line at bottom edge
		{
			x=x1+1.0*(yMin-y1)/slope;
			y=yMin;
		}
		else if(ecodeOut&right) // split line at right edge
		{
			y=y1+1.0*(xMax-x1)*slope;
			x=xMax;
		}
		else // split line at left edge
		{
			y=y1+1.0*(xMin-x1)*slope;
			x=xMin;
		}
		if(ecodeOut==ecode1)
		{
			x1=x;
			y1=y;
			ecode1=endCode(x1,y1,xMin,xMax,yMin,yMax);
		}
		else
		{
			x2=x;
			y2=y;
			ecode2=endCode(x2,y2,xMin,xMax,yMin,yMax);
		}
		
	} while(done==0);
}	
	
int main()
{	
    //pt points[500]; 
	int n, i;
	printf("Enter cell width : ");
    scanf("%d",&cellWidth);	
	printf("Enter end-pts of line segment (x1,y1,x2,y2) :");
	scanf("%f %f %f %f",&x1,&y1, &x2, &y2);
	printf("Enter the left and right window boundaries :");
	scanf("%f %f",&xMin, &xMax);
	printf("Enter the bottom and top window boundaries :");
	scanf("%f %f",&yMin, &yMax);
	initMainGraph(cellWidth); // initializing graphics
	//drawLine(x1,y1,x2,y2,cellWidth);
	drawLine(xMin,yMin,xMax,yMin,cellWidth);
	drawLine(xMin,yMin,xMin,yMax,cellWidth);
	drawLine(xMax,yMax,xMin,yMax,cellWidth);
	drawLine(xMax,yMax,xMax,yMin,cellWidth);
	SC();
	getch();
	closegraph();
return(0);
}
