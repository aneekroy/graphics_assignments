
#include <conio.h>
#include <math.h>
#include <graphics.h>
#include <time.h>

#define lower_limit 20
#define interval 5

void draw_grid() {
	int maxx = getmaxx() - lower_limit;
	int maxy = getmaxy() - lower_limit;
	int x_coordinate, y_coordinate;
	bar(lower_limit, lower_limit, maxx, maxy);

	setcolor(LIGHTBLUE);
	for(x_coordinate = lower_limit; x_coordinate <= maxx; x_coordinate += interval)
		line(x_coordinate, lower_limit, x_coordinate, maxy);

	for(y_coordinate = lower_limit; y_coordinate <= maxy; y_coordinate += interval)
		line(lower_limit, y_coordinate, maxx, y_coordinate);
}

void draw_axis() {
	int x_axis = getmaxx() / 2;
	int y_axis = getmaxy() / 2;

	int maxx = getmaxx() - lower_limit;
	int maxy = getmaxy() - lower_limit;

	int x_coordinate, y_coordinate;
	setcolor(BLUE);
	for(x_coordinate = x_axis; x_coordinate <= x_axis + 1; x_coordinate ++)
		line(x_coordinate, lower_limit, x_coordinate, maxy);

	for(y_coordinate = y_axis; y_coordinate <= y_axis + 1; y_coordinate ++)
		line(lower_limit, y_coordinate, maxx, y_coordinate);

}

void plot(int x, int y) {
	int x_axis, y_axis;
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	x_axis = getmaxx() / 2;
	y_axis = getmaxy() / 2;
	bar(x_axis + x * interval, y_axis - (y + 1) * interval, x_axis + (x + 1) * interval , y_axis - y * interval);
}

void draw_original_line(int x1, int y1, int x2, int y2) {
	int x_axis, y_axis;
	x_axis = getmaxx() / 2;
	y_axis = getmaxy() / 2;

	setcolor(RED);
	line(x_axis + x1 * interval, y_axis - y1 * interval, x_axis + x2 * interval, y_axis - y2 * interval);
}

int sign(int val) {
	if(val < 0)
		return -1;
	else if (val)
		return 1;
	else
		return 0;
}

int main() {
	int i, x1, x2, y1, y2, interchange, x, y, dx, dy, error, temp, s1, s2;
	int gd = DETECT, gm;

	printf("Starting coordnates : ");
	scanf("%d %d", &x1, &y1);

	printf("Ending coordinates : ");
	scanf("%d %d", &x2, &y2);

	initgraph(&gd, &gm, "C:\\TC\\BGI");

	draw_grid();
	draw_axis();

	x = x1;
	y = y1;
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);

	s1 = sign(x2 - x1);
	s2 = sign(y2 - y1);

	if(dy > dx) {
		temp = dx;
		dx = dy;
		dy = temp;
		interchange = 1;
	}
	else
		interchange = 0;

	error = 2 * dy - dx;

	for(i = 1; i <= dx; ++i) {
		plot(x, y);
		delay(100);
		while(error > 0) {
			if(interchange)
				x += s1;
			else
				y += s2;
			error -= 2 * dx;
		}
		if(interchange)
			y += s2;
		else
			x += s1;
		error += 2 * dy;
	}

	getch();

	closegraph();
	return 0;
}
