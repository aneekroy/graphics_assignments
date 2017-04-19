/*2nd order difference..*/
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<graphics.h>

/*void draw_grid() {
	int maxx = getmaxx() - lower_limit;
	int maxy = getmaxy() - lower_limit;
	int x_coordinate, y_coordinate;
	bar(lower_limit, lower_limit, maxx, maxy);

	setcolor(BLACK);
	for(x_coordinate = lower_limit; x_coordinate <= maxx; x_coordinate += interval)
		line(x_coordinate, lower_limit, x_coordinate, maxy);

	for(y_coordinate = lower_limit; y_coordinate <= maxy; y_coordinate += interval)
		line(lower_limit, y_coordinate, maxx, y_coordinate);
}*/

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
		//setfillstyle(SOLID_FILL,BLUE);
		bar(i,(maxy/2-size),i+size,maxy/2);
	}
	//draw y-axis..
	for(i=0;i<=maxy+1;i+=size){
		//setfillstyle(SOLID_FILL,BLUE);
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
void BRESENHAM_CIRCLE(int x1,int y1,int R,int size){
			/*2nd order difference..*/
	int x,y,d,dd,dd1;


	x=0;
	y=R;
	d=2*(1-R);
	while(y>0){

		plot(x+x1,y+y1,size);
		plot(y+x1,x+y1,size);
		plot(x+x1,-y+y1,size);
		plot(y+x1,-x+y1,size);
		plot(-x+x1,-y+y1,size);
		plot(-y+x1,-x+y1,size);
		plot(-x+x1,y+y1,size);
		plot(-y+x1,x+y1,size);
		sleep(0.5);
		if(d<0){ 	/*choose E*/
		       dd=2*d+2*y-1;
		       if(dd<=0){
				x=x+1;
				d=d+2*x+1;
		       }
		       else{
				x=x+1;
				y=y-1;
				d=d+2*x-2*y+2;
		       }
		}
		else if(d>0){
			dd1=2*d-2*x-1;
			if(dd1<=0){
				x=x+1;
				y=y-1;
				d=d+2*x-2*y+2;
			}
			else{
				y=y-1;
				d=d-2*y+1;
			}
		}
		else if(d==0){
				x=x+1;
				y=y-1;
				d=d+2*x-2*y+2;
		}
	}
}

int main(){
	int size,maxx,maxy;
	int gd=DETECT,gm;
	int x1,y1,R;
	size=10;
	
	
	printf("Enter centre x1 y1 and radius R: ");
	scanf("%d %d %d",&x1,&y1,&R);
   
        detectgraph(&gd,&gm);
        initgraph(&gd,&gm,NULL);

        maxx=getmaxx();
	maxy=getmaxy();

        grid(maxx,maxy,size);
	plot(x1,y1,size);
	BRESENHAM_CIRCLE(x1,y1,R,size);
	delay(100000);

	getch();
        closegraph();
}
