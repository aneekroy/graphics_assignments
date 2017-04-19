#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>

int main()
{
	int gdriver = DETECT, gmode;
	int i, j, x1, x2, y1, y2, dx, dy, step;
	float x, y, xincr, yincr;

	initgraph(&gdriver, &gmode, "C:\TC\BGI");

	//to print the horizental lines
	x2 = getmaxx();
	x1 = 0; y = 5;
	dx = x2 - x1;
	xincr = 1;

	for(y=5; y<getmaxy(); y = y + 5)
	{   x = x1;

		for(j=0; i<dx; j++)
		{
			putpixel((int)x, y, WHITE);
			x = x + xincr;
		}
	}

	// to print the vertical lines
	y2 = getmaxy();
	y1 = 0;
	dy = y2 - y1;
	yincr = 1;

	for(x=5; x<getmaxx(); x = x+5)
	{
		y = y1;

		for(j=0; j<dy; j++)
		{
			putpixel(x, (int)y, WHITE);
			y += yincr;
		}
	}

	//to print the line desired
	x1 = 0, y1 = 0;
	x2 = getmaxx(), y2 = getmaxy();

	dx = x2 - x1;
	dy = y2 - y1;

	step = dx > dy ? dx : dy;

	xincr = (dx * 1) / step;
	yincr = (dy * 1) / step;

	x = x1;
	y = y1;
	putpixel((int)x, (int)y, WHITE);

	for(i=1; i<=step; i++)
	{
		x = x + xincr;
		y = y + yincr;

		putpixel((int)x, (int)y, WHITE);
		delay(50);
	}

	return 0;
}