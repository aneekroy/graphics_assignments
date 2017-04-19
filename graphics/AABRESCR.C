#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>

void printGridLine(int x1, int y1, int x2, int y2, int color){
	int i, j;
	if(x1 == x2){
		for(i = y1; i <= y2; i++){
			putpixel(x1, i, color);
		}
	}
	else{
		for(i = x1; i <= x2; i++){
			putpixel(i, y1, color);
		}
	}
}

void makegraph(int X_MAX, int Y_MAX, int width){
	int i;
	for( i = 0; i < X_MAX; i+= width){
		if( i - X_MAX/2 < width && X_MAX/2 - i <  width )
			printGridLine(i, 0, i, Y_MAX, GREEN);
		else
			printGridLine(i, 0, i, Y_MAX, BLUE );	// BLACK
	}
	for( i = 0; i < Y_MAX; i+= width){
		if( i - Y_MAX/2 < width && Y_MAX/2 - i <  width)
			printGridLine(0, i, X_MAX, i, GREEN );
		else
			printGridLine(0, i, X_MAX, i, BLUE );
	}
}

void printMagPixel(int x, int y, int color, int width, int shiftX, int shiftY){
	int i, j;
	x += shiftX;
	y = shiftY-1-y;
	x *= width;
	y *= width;
	for(i = x+1; i < x+width; i++){
		for(j = y+1;j < y+width; j++){
			putpixel(i, j, color);
		}
	}
}

void bresenham_circle(int x_c, int y_c, int radius, int color, int shiftX, int shiftY, int width){
    FILE * fp;
    int x, y;
    int i, delta, d, dPrime;
    fp = fopen("BRES_CIRC.txt", "w");
    x = 0;
    y = radius;
    delta = 2*(1-radius);
    while(y >= 0){
        printMagPixel(x + x_c, y + y_c, color, width, shiftX, shiftY);
        printMagPixel(x + x_c, -y-1 + y_c, color, width, shiftX, shiftY);
        printMagPixel(-x-1 + x_c, y + y_c, color, width, shiftX, shiftY);
        printMagPixel(-x-1 + x_c, -y-1 + y_c, color, width, shiftX, shiftY);
        fprintf(fp, "%d %d\t\t%d %d\t\t%d %d\t\t%d %d\n",x + x_c, y + y_c, x + x_c, -y + y_c, -x + x_c, y + y_c, -x + x_c, -y + y_c);
        if(delta <= 0){
            d = 2*(delta + y) - 1;
            if(d <= 0){
                x += 1;
                delta += 2*x + 1;
            }
            else{
                x += 1;
                y -= 1;
                delta += 2*x - 2*y + 2;
            }
        }
        else{
            dPrime = 2*(delta - x) - 1;
            if(dPrime <= 0){
                x += 1;
                y -= 1;
                delta += 2*x - 2*y + 2;
            }
            else{
                y -= 1;
                delta += 1 - 2*y;
            }
        }
    }
    fclose(fp);
}



int main(void){
    int graph_driver = DETECT, graph_mode;
    int X_MAX, Y_MAX, i, width, shiftX, shiftY;
    int x_c, y_c, radius;
    clrscr();
  	printf("BRESENHAM STRAIGHT LINE RASTERIZATION.\n");
    printf("Enter the co-ordinates of the centre : ");
  	scanf("%d %d", &x_c, &y_c);
  	printf("Enter the radius of the circle : ");
  	scanf("%d", &radius);
    initgraph(&graph_driver, &graph_mode, "C:\\TC\\BGI");
    setbkcolor(WHITE);
    width = 10;
    X_MAX = getmaxx();
  	Y_MAX = getmaxy();
  	X_MAX++;	//640
  	Y_MAX++;	//460
    makegraph(X_MAX, Y_MAX, width);
    shiftX = X_MAX/(2*width);
    shiftY = Y_MAX/(2*width);
    bresenham_circle(x_c, y_c, radius, 5, shiftX, shiftY, width);
    //bresenham_circle(0,0, radius, 8, shiftX, shiftY, width);
    getch();
  	clrscr();
    return 0;
}
