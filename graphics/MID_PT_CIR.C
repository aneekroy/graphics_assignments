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
	//setfillstyle(SOLID_FILL,RED);
	bar(x,y-size,x+size,y);

}
	/*Mid-Point Cicle Drawing Algorithm to rasterize a circle with
	centre(x1,y1)and radius R.*/
void MIDPOINT_CIRCLE(int x1,int y1,int R,int size){
	int x,y,h;
	x=0;
	y=R;
	h=1-R;
	plot(x+x1,y+y1,size);
	plot(y+x1,x+y1,size);
	plot(x+x1,-y+y1,size);
	plot(y+x1,-x+y1,size);
	plot(-x+x1,-y+y1,size);
	plot(-y+x1,-x+y1,size);
	plot(-x+x1,y+y1,size);
	plot(-y+x1,x+y1,size);
	sleep(1);
	while(y>x){
		if(h<0) 	/*choose E*/
		       h=h+2*x+3;
		else{           /*choose SE*/
		       y=y-1;
		       h=h+2*(x-y)+5;
		}
		x=x+1;
		plot(x+x1,y+y1,size);
		plot(y+x1,x+y1,size);
		plot(x+x1,-y+y1,size);
		plot(y+x1,-x+y1,size);
		plot(-x+x1,-y+y1,size);
		plot(-y+x1,-x+y1,size);
		plot(-x+x1,y+y1,size);
		plot(-y+x1,x+y1,size);
		sleep(1);
	}
}
int main(){
	int size,maxx,maxy;
	int gd=DETECT,gm;
	int x1,y1,R;
	size=5;
	
	
	printf("Enter the centre x1 y1 and the radius R: ");
	scanf("%d %d %d",&x1,&y1,&R);

        initgraph(&gd,&gm,NULL);

        maxx=getmaxx();
	maxy=getmaxy();
	grid(maxx,maxy,size);
	plot(x1,y1,size);
	MIDPOINT_CIRCLE(x1,y1,R,size);

       //	closegraph();
	getch();
        closegraph();
}
