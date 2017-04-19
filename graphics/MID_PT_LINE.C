#include<stdio.h>
#include<math.h>
#include<time.h>
#include<graphics.h>

void grid(int maxx,int maxy,int size){
		      /* function to draw grid
				and axes..*/
	int i,j;
	
	for(i=0;i<=maxx;i+=size){
		line(i,0,i,maxy);
	}
	for(i=0;i<=maxy;i+=size)
		line(0,i,maxx,i);

	//draw x-axis..
	for(i=0;i<=maxx;i+=size){
		
		bar(i,(maxy/2-size),i+size,maxy/2);
	}
	//draw y-axis..
	for(i=0;i<=maxy+1;i+=size){
		
		bar((maxx/2),i-size,maxx/2+size,i);
	}


}
void plot(int x1,int y1,int size){
		/* function to plot the points
			at the given coordinates..*/
	int x0=getmaxx()/2 , y0=getmaxy()/2;
	int x=x0+(int)(size*x1);
	int y=y0-(int)(size*y1);
	
	bar(x,y-size,x+size,y);

}

void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
	/*Generalized Midpoint Algorithm for rasterizing a line with
	endpoints(x1,y1)and(x2,y2). The points maybe in any quadrant.
	Both the points are not co-incident.*/
void MIDPOINT_LINE(int x1,int y1,int x2,int y2,int size){
	int dx,dy,d,incry,incrE,incrNE,slopegt1=0;
	int x22,y22;
	x22=x2;
	y22=y2;
	plot(x1,y1,size);
	dx=abs(x1-x2);
	dy=abs(y1-y2);
	if(dy>dx)    //if slope is greater than 1, then swap points
	{            //(x1,y1) with (x2,y2).
		swap(&x1,&y1);
		swap(&x2,&y2);
		swap(&dx,&dy);
		slopegt1=1;
	}
	if(x1>x2)       //since we are rasterizing a line from x1 to x2
	{               //so we are swapping x1 with x2 if x2 is smaller.
		swap(&x1,&x2);
		swap(&y1,&y2);
	       //	plot(x1,y1,size);
	}
	if(y1>y2)      //check if y1>y2 for incrementing or decrementing
		incry=-1;    //the y value.
	else
		incry=1;
	  /* initialize variables*/
	d=2*dy-dx;
	incrE=2*dy;
	incrNE=2*(dy-dx);
	/*Main Loop*/
	while(x1<x2)
	{
		if(d<=0)
			d+=incrE;
		else
		{
			d+=incrNE;
			y1+=incry;
		}
		x1++;

		if(slopegt1)
			plot(y1,x1,size);
		else
			plot(x1,y1,size);
	}
	plot(x22,y22,size);
}

int main(){
	int size,maxx,maxy;
	int gd=DETECT,gm;
	int x1,y1,x2,y2;
	size=10;
	
	printf("Enter starting points: ");
	scanf("%d %d",&x1,&y1);
        printf("Enter ending points :");
	scanf("%d %d",&x2,&y2);

        initgraph(&gd,&gm,NULL);
	
	maxx=getmaxx();
	maxy=getmaxy();
	grid(maxx,maxy,size);

	if(x1==x2 && y1==y2) 
		plot(x1,y1,size);

	else
	MIDPOINT_LINE(x1,y1,x2,y2,size);

	getch();
	closegraph();
	//getch();
}
