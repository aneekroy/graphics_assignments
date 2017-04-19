#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

int max_x = 640,max_y = 480,d_x,d_y,c_x,c_y;

void setup(){

	int gd = DETECT,gm;
	initgraph(&gd,&gm,"C:\\Turboc3\\bgi");
	d_x=10;										// distance between two Horizontal grid lines
	d_y=10;										// distance between two vertical grid lines
	c_x = max_x/(2*d_x);						// X-co-ordinate of origin
	c_y = max_y/(2*d_y);						// Y-co-ordinate of origin
	setcolor(BLUE);
}
void draw_grid(){
	int i,j;
	for(i=d_x;i<max_x;i+=d_x)
		line(i,0,i,max_y);						// Drawing vertical grid lines
	for(i=d_y;i<max_y;i+=d_y)
		line(0,i,max_x,i);						// Drawing horizontal grid lines
	setcolor(WHITE);
	line(c_x*d_x,0,c_x*d_x,max_y);				// X-axis
	line(0,c_y*d_y,max_x,c_y*d_y);				// Y-axis
}


void fill(int x,int y){
	x = x + c_x ;								// x position in screen
	y = c_y - y ;								// y position in screen
	setfillstyle(SOLID_FILL, WHITE);
	bar(x*d_x+1,(y-1)*d_y+1,(x+1)*d_x-1,y*d_y-1);	// fill the grid
}

int sgn(int x){
	return (x>0) - (x<0);
}

void bresenham_generalised(int x1,int y1,int x2,int y2){

	int dy = abs(y2 - y1);
	int dx = abs(x2 - x1);
	int temp ;
	int s1 = sgn (x2 - x1);
	int s2 = sgn (y2 - y1);
	int interchange;
	int x,y,e;
	int i;

	if (dy > dx){
		temp = dy;
		dy = dx;
		dx = temp;
		interchange = 1;

	}
	else {
		interchange = 0;
	}

	e = 2*dy - dx;

	x = x1;
	y = y1;

	for (i =1;i<=dx;i++){
		fill(x,y);
		while (e>0){
			e-=2*dx;
			if (interchange == 1)
				x = x+s1;

			else
				y = y+s2;
		}

		e+=2*dy;

		if (interchange == 1)
			y = y +s2;
		else
			x = x +s1;

	}

}

main(){
	int x1,y1,x2,y2;
	int num;
	setup();
	draw_grid();
	printf("Enter starting point : ");
	scanf("%d %d",&x1,&y1);
	printf("\nEnter ending point : ");
	scanf("%d %d",&x2,&y2);
	bresenham_generalised(x1,y1,x2,y2);
	getch();
	closegraph();
	return 0;
}