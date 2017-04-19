#include "header.h"
#define swap(a,b)           {a^=b; b^=a; a^=b;}

int cellWidth;

typedef struct ll
{
    int x1,y1,x2,y2;
    int bucketFlag;
}LINE;
typedef struct nd{
    double x,dx;
    int dy;
    struct nd *next;
} NODE;

NODE **buckets;
LINE *lines;

NODE *newNode(double x,double dx,int dy){
    NODE *n = (NODE *)malloc(sizeof(NODE));
    n->x = x;
    n->dx = dx;
    n->dy = dy;
    n->next = NULL;
    return n;
}

/*a function to take the input of all the lines that are to be displayed*/
void input_lines(int *num_lines){
    int n,i;
	printf("Enter the number of lines to display : ");
    scanf("%d",&n);
    *num_lines = n;
    lines = (LINE *)malloc(n * sizeof(LINE));
    

    for(i=0;i<n;i++)
	{
       printf("For line number %d\n",(i+1));
       printf("Enter coordinates (x1,y1,x2,y2) : ");
       scanf("%d %d %d %d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2);
       lines[i].bucketFlag = 0;
    }

   
}

/*a function to initialise a list of empty buckets corresponding to each scan line*/
void init_buckets(){
	int i;
    buckets = (NODE **)malloc(48 * sizeof(NODE *));
    for(i=0;i<48;i++)
		buckets[i] = NULL;
}

/*a function to insert a node to the front of a linked list*/
void insert_front(NODE *target,NODE **head){
   target->next = *head;
   *head = target;
}

/*a function to send in the higher and the lower point of a line*/
void find_higher(LINE line, int *xh, int *yh, int *xl, int *yl)
{
    
	*yh = line.y1;
	*xh = line.x1;
	*yl = line.y2;
	*xl = line.x2;
    if(line.y1 <= line.y2)
	{
		swap(*yl,*yh);
		swap(*xl,*xh);
	}
}

/*a function to fill the buckets corresponding to each scan line*/
void fill_buckets(NODE **buckets, LINE *lines, int num_lines){

    int i;
	int xh,yh,xl,yl,dy;
	int bucket_id;
	double x,dx,dy2;
	NODE *target;

    for(i=0;i<num_lines;i++)
    {
      if(!(lines[i].bucketFlag))
      {
	   if(lines[i].y1 == lines[i].y2)
	   {
	       int j;
	       for(j=lines[i].x1;j<=lines[i].x2;j++)
	       {
				plot(j, lines[i].y1,cellWidth);
				//sleep(1);
	       }
	   }

	   
	   find_higher(lines[i],&xh,&yh,&xl,&yl);
	   bucket_id = 24 - yh;

	   x = xh;
	   dy = yh - yl + 1;
	   dy2 = dy;
	   dx = (xl - xh)/ dy2;
	   target = newNode(x,dx,dy);
	   insert_front(target,&(buckets[bucket_id]));
	   lines[i].bucketFlag = 1;
      }
    }

}

void scanConversion(NODE **buckets)
{
     NODE *ael = NULL;
	 NODE *cur, *cur_bucket;

     int i;

     for(i=0;i<48;i++)
     {
	 cur_bucket = buckets[i];
	 /*Update the AEL with all the buckets of the current scan line*/
	 while(cur_bucket)
	 {
	     NODE *t = newNode(cur_bucket->x,cur_bucket->dx,cur_bucket->dy);
	     insert_front(t,&ael);
	     cur_bucket = cur_bucket->next;
	 }

	 cur = ael;
	 while(cur)
	 {
	     if(cur->dy < 0)
	     {
		cur = cur->next;
		continue;
	     }
	     plot(cur->x,(24-i),cellWidth);
		 //sleep(1);
	     cur->dy--;
	     cur->x = cur->x + cur->dx;
	     cur = cur->next;
	 }
     }
}

int main(void)
{
    int n_lines,i;
 
	printf("Enter cell width : ");
	scanf("%d", &cellWidth);
	input_lines(&n_lines);
    init_buckets();

    initMainGraph(cellWidth); // initializing graphics
    
	fill_buckets(buckets,lines,n_lines);
    scanConversion(buckets);

    getch();
    closegraph();
    return 0;
}
