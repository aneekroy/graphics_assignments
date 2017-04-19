/*generating random points in plane */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
struct two_d{ int x;int y;};
int main(void) {
	int n,i; time_t t;
	struct two_d *a;struct two_d max,min;clrscr();
	printf("Enter the number of points : ");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	srand(time(&t)); printf("RANDOM POINTS IN PLANE ARE :- \n");
	for(i=0;i<n;i++) {
		a[i].x=rand()%100;
		a[i].y=rand()%100;printf("	(%d,%d)\n",a[i].x,a[i].y);
	}
	max=a[0];
	min=a[0];
	for(i=1;i<n;i++) {
		if(a[i].x >= max.x) {
			if(a[i].x == max.x)
				if(a[i].y >= max.y)
				max=a[i];  max=a[i];
		}
		if(a[i].x <= min.x) {
			if(a[i].x == min.x)
				if(a[i].y <= min.y)
				min=a[i]; min=a[i];
		}
	}
	printf("The extreme right point is (%d,%d)\n",max.x,max.y);
	printf("The extreme left point is (%d,%d)\n",min.x,min.y);
	getch();
	return 0;
}