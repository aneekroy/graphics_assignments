#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<time.h>

#define MAX(a, b) ((a)>(b) ? (a) : (b))
#define LMAX(a, b, c) ((a)>(b) ? ((a)>(c) ? (a) : (c)) : ((b)>(c) ? (b) : (c)))
#define LMIN(a, b, c) ((a)<(b) ? ((a)<(c) ? (a) : (c)) : ((b)<(c) ? (b) : (c)))
#define ABS(a) ((a)>=0 ? (a) : (-(a)))
#define COMPLEMENT(x) ((x)==0 ? 1 : 0)
#define MAXST 1024

int isLocalMin(int x, int a, int b, int c){
 if(x==a){
  return(x<b && x<c);
 }
 else if(x==b){
  return(x<a && x<c);
 }
 else if(x==c){
  return(x<a && x<c);
 }
 return 0;
} 

int isLocalMax(int x, int a, int b, int c){
 if(x==a){
  return(x>b && x>c);
 }
 else if(x==b){
  return(x>a && x>c);
 }
 else if(x==c){
  return(x>a && x>c);
 }
 return 0;
} 

//gridsize=no. of cells per row/column
//cellsize=width of a cell in pixels
void grid(int gridsize, int cellsize){
 int i;

 for(i=0;i<=gridsize;++i){
  if(i==gridsize/2){
   setlinestyle(CENTER_LINE,0,3);
   line(0,i*cellsize,gridsize*cellsize,i*cellsize);
   line(i*cellsize,0,i*cellsize,gridsize*cellsize);
   setlinestyle(SOLID_LINE,0,1);
  }
  line(0,i*cellsize,gridsize*cellsize,i*cellsize);
  line(i*cellsize,0,i*cellsize,gridsize*cellsize);
 }

}

void drawLine(float x1, float y1, float x2, float y2, int gridsize, int cellsize){
 //setcolor(YELLOW);
 setlinestyle(SOLID_LINE,0,3);
 line((gridsize/2+x1)*cellsize,(gridsize/2-y1)*cellsize,(gridsize/2+x2)*cellsize,(gridsize/2-y2)*cellsize);
 setlinestyle(SOLID_LINE,0,1);
 //setcolor(WHITE);
}

int sign(int x){
 if(x>0)
  return 1;
 else if(x<0)
  return -1;
 else return 0;
}


void setpixel(int x, int y, int gridsize, int cellsize){
 int x1, y1;
 setfillstyle(SOLID_FILL, BLUE);
 x1=(int)((gridsize/2+x+.5)*cellsize);
 y1=(int)((gridsize/2-y-.5)*cellsize);
 floodfill(x1,y1,WHITE);
}

void setpolypixel(int x, int y, int gridsize, int cellsize){
 int x1, y1;
 x1=(int)((gridsize/2+x+.5)*cellsize);
 y1=(int)((gridsize/2-y-.5)*cellsize);
 setfillstyle(SOLID_FILL, RED);
 floodfill(x1,y1,WHITE);
}

void resetpixel(int x, int y, int gridsize, int cellsize){
 int x1, y1;
 x1=(int)((gridsize/2+x+.5)*cellsize);
 y1=(int)((gridsize/2-y-.5)*cellsize);
 setfillstyle(SOLID_FILL, BLACK);
 floodfill(x1,y1,WHITE);
}

void complementpixel(int x, int y, int gridsize, int cellsize){
 int x1, y1;
 x1=(int)((gridsize/2+x+.5)*cellsize);
 y1=(int)((gridsize/2-y-.5)*cellsize);
 if(getpixel(x1,y1)==BLACK){
  setfillstyle(SOLID_FILL, RED);
  floodfill(x1,y1,WHITE);
 }
 else{
  setfillstyle(SOLID_FILL, BLACK);
  floodfill(x1,y1,WHITE);
 }
}

void intbres(int x1, int y1, int x2, int y2, int gridsize, int cellsize){
 int i,j;
 int x,y,deltax,deltay,s1,s2,inter,temp,e;

 x=x1;
 y=y1;
 deltax=ABS(x2-x1);
 deltay=ABS(y2-y1);
 s1=sign(x2-x1);
 s2=sign(y2-y1);

 if(deltax==0){
  for(i=1;i<=deltay;++i){
   setpixel(x,y,gridsize,cellsize);
   y+=s2;
  }
  return;
 }

 if(deltay==0){
  for(i=1;i<=deltax;++i){
   setpixel(x,y,gridsize,cellsize);
   x+=s1;
  }
  return;
 }

 if(deltax==deltay){
  for(i=1;i<=deltax;++i){
   setpixel(x,y,gridsize,cellsize);
   x+=s1;
   y+=s2;
  }
  return;
 }


 if(deltay>deltax){
  temp=deltay;
  deltay=deltax;
  deltax=temp;
  inter=1;
 }
 else{
  inter=0;
 }

 e=2*deltay-deltax;

 for(i=1;i<=deltax;i++){
  setpixel(x,y,gridsize,cellsize);
  while(e>0){
   if(inter==1){
    x+=s1;
   }
   else{
    y+=s2;
   }
   e=e-2*deltax;
  }

  if(inter==1){
   y+=s2;
  }
  else{
   x+=s1;
  }
  e=e+2*deltay;
 }

}

void delay(long t){
 time_t time1, time2;
 time1=clock();
 time2=time1;
 while((long)time2<(long)time1+t){
  time2=clock();
 }
}

/*void redraw(){
 float x1=-10,y1=-20,x2=10,y2=-20,x3=10,y3=0,x4=5,y4=-5,x5=-10,y5=10;
 int gridsize=50, cellsize=10;
 drawLine(x1,y1,x2,y2,gridsize,cellsize);
 drawLine(x2,y2,x3,y3,gridsize,cellsize);
 drawLine(x3,y3,x4,y4,gridsize,cellsize);
 drawLine(x4,y4,x5,y5,gridsize,cellsize);
 drawLine(x5,y5,x1,y1,gridsize,cellsize);
}*/

void edgefill(int x1, int y1, int x2, int y2, int gridsize, int cellsize){
 int x,y,cmaxx,maxy,cminx,miny;
 if(y1>y2){
  cmaxx=x1;
  maxy=y1;
  cminx=x2;
  miny=y2;
 }
 else{
  cmaxx=x2;
  maxy=y2;
  cminx=x1;
  miny=y1;
 }
 for(y=maxy-1;y>=miny;--y){
  x=cmaxx+(float)(y-maxy)*(cminx-cmaxx)/(miny-maxy);
  for(;x<gridsize/2;++x){
    complementpixel(x,y,gridsize,cellsize);
   }
 }
 //redraw();
}

void drawFence(float x1, float y1, float x2, float y2, int gridsize, int cellsize){
 setlinestyle(SOLID_LINE,0,3);
 line((gridsize/2+x1)*cellsize,(gridsize/2-y1)*cellsize,(gridsize/2+x2)*cellsize,(gridsize/2-y2)*cellsize);
 setlinestyle(SOLID_LINE,0,1);
}

void fencefill(int x1, int y1, int x2, int y2, int xfence, int gridsize, int cellsize){
 int x,y,cmaxx,maxy,cminx,miny;
 if(y1>y2){
  cmaxx=x1;
  maxy=y1;
  cminx=x2;
  miny=y2;
 }
 else{
  cmaxx=x2;
  maxy=y2;
  cminx=x1;
  miny=y1;
 }
 if(maxy==miny)
  return;
 for(y=maxy-1;y>=miny;--y){
  x=cmaxx+(float)(y-maxy)*(cminx-cmaxx)/(miny-maxy);
  if(x<xfence){
   for(;x<xfence;++x){
    complementpixel(x,y,gridsize,cellsize);
   }
  }
  else{
   for(--x;x>=xfence;--x){
    complementpixel(x,y,gridsize,cellsize);
   }
  }
 }
 //redraw();
 //drawFence(5,-5,5,-20,gridsize,cellsize);
}

void edgeflag(float maxy, float miny, int gridsize, int cellsize){
 int x,y,x1,y1;
 int inside;
 for(y=maxy-1;y>=miny;--y){
  inside=0;
  for(x=-gridsize/2;x<gridsize/2;++x){
   x1=(int)((gridsize/2+x+.5)*cellsize);
   y1=(int)((gridsize/2-y-.5)*cellsize);
   if(getpixel(x1,y1)==BLUE){
    inside=COMPLEMENT(inside);
   }
   if(inside==1){
    setpolypixel(x,y,gridsize,cellsize);
   }
   else{
    resetpixel(x,y,gridsize,cellsize);
   }
  }
  delay(5);
 }
}

int isBoundaryPixel(int x, int y, int gridsize, int cellsize){
 int x1, y1;
 x1=(int)((gridsize/2+x+.5)*cellsize);
 y1=(int)((gridsize/2-y-.5)*cellsize);
 if(getpixel(x1,y1)==BLUE || getpixel(x1,y1)==WHITE){
  return 1;
 }
 else
  return 0;
}

int isFilledPixel(int x, int y, int gridsize, int cellsize){
 int x1, y1;
 x1=(int)((gridsize/2+x+.5)*cellsize);
 y1=(int)((gridsize/2-y-.5)*cellsize);
 if(getpixel(x1,y1)==RED){
  return 1;
 }
 else
  return 0;
}

typedef struct {
 int x;
 int y;
}pixel;

typedef struct {
 pixel data[MAXST];
 int top;
}stack_t;

typedef stack_t* stack;

stack s_create(){
 stack s;
 if((s=(stack)malloc(sizeof(stack_t)))==NULL){
  exit(0);
 }
 s->top=-1;
 return s;
}

int s_full(stack s){
 return (s->top==MAXST-1);
}

int s_empty(stack s){
 return (s->top==-1);
}

void push(stack s, pixel p){
 if(!s_full(s))
  s->data[++s->top]=p;
}

pixel pop(stack s){
 if(s_empty(s))
  exit(0);
 return (s->data[s->top--]);
}

void seedfill(int x, int y, int gridsize, int cellsize){
 pixel p, q, seed;
 stack s=s_create();
 seed.x=x;
 seed.y=y;
 push(s, seed);
 while(!s_empty(s)){
  p=pop(s);
  setpolypixel(p.x,p.y,gridsize,cellsize);
  delay(1);
  if(!isBoundaryPixel(p.x+1,p.y,gridsize,cellsize) && !isFilledPixel(p.x+1,p.y,gridsize,cellsize)){
   q.x=p.x+1;
   q.y=p.y;
   push(s, q);
  }
  if(!isBoundaryPixel(p.x-1,p.y,gridsize,cellsize) && !isFilledPixel(p.x-1,p.y,gridsize,cellsize)){
   q.x=p.x-1;
   q.y=p.y;
   push(s, q);
  }
  if(!isBoundaryPixel(p.x,p.y+1,gridsize,cellsize) && !isFilledPixel(p.x,p.y+1,gridsize,cellsize)){
   q.x=p.x;
   q.y=p.y+1;
   push(s, q);
  }
  if(!isBoundaryPixel(p.x,p.y-1,gridsize,cellsize) && !isFilledPixel(p.x,p.y-1,gridsize,cellsize)){
   q.x=p.x;
   q.y=p.y-1;
   push(s, q);
  }
 }
}

void scanlineseedfill(int seedx, int seedy, int gridsize, int cellsize){
 int x,y,savex,xleft,xright,pflag,xenter;
 pixel p,seed;
 stack s;
 seed.x=seedx;
 seed.y=seedy;
 s=s_create();
 push(s,seed);
 while(!s_empty(s)){
  seed=pop(s);
  x=seed.x;
  y=seed.y;
  setpolypixel(x,y,gridsize,cellsize);
  savex=x;
  x++;
  while(!isBoundaryPixel(x,y,gridsize,cellsize)){
   setpolypixel(x,y,gridsize,cellsize);
   delay(1);
   x++;
  }
  xright=x-1;
  x=savex;
  x--;
  while(!isBoundaryPixel(x,y,gridsize,cellsize)){
   setpolypixel(x,y,gridsize,cellsize);
   delay(1);
   x--;
  }
  xleft=x+1;

  x=xleft;
  y++;
  while(x<=xright){
   pflag=0;
   while(!isBoundaryPixel(x,y,gridsize,cellsize) && !isFilledPixel(x,y,gridsize,cellsize)&&x<xright){
    if(pflag==0)
     pflag=1;
    x++;
   }
   if(pflag==1){
    if(x==xright && !isBoundaryPixel(x,y,gridsize,cellsize) && !isFilledPixel(x,y,gridsize,cellsize)){
     p.x=x;
     p.y=y;
     push(s,p);
    }
    else{
     p.x=x-1;
     p.y=y;
     push(s,p);
    }
    pflag=0;
   }
   xenter=x;
   while((isBoundaryPixel(x,y,gridsize,cellsize) || isFilledPixel(x,y,gridsize,cellsize)) && x<xright)
    x++;


   if(x==xenter)
    x++;
  }

  x=xleft;
  y-=2;

  while(x<=xright){
   pflag=0;
   while(!isBoundaryPixel(x,y,gridsize,cellsize) && !isFilledPixel(x,y,gridsize,cellsize)&&x<xright){
    if(pflag==0)
     pflag=1;
    x++;
   }
   if(pflag==1){
    if(x==xright && !isBoundaryPixel(x,y,gridsize,cellsize) && !isFilledPixel(x,y,gridsize,cellsize)){
     p.x=x;
     p.y=y;
     push(s,p);
    }
    else{
     p.x=x-1;
     p.y=y;
     push(s,p);
    }
    pflag=0;
   }
   xenter=x;
   while((isBoundaryPixel(x,y,gridsize,cellsize) || isFilledPixel(x,y,gridsize,cellsize)) && x<xright)
    x++;

   if(x==xenter)
    x++;
  }
 }
}


int main(){
 float x[20], y[20], xfence, maxy, miny, sumx, sumy, xc, yc;
 int gd=DETECT, gm, gridsize=50, cellsize=10, choice=0, n, i, x1, y1, found;
 
 clrscr();
 printf("Polygon filling routines\n");
 printf("Enter no. of vertices & vertex coordinates: ");
 scanf("%d", &n);
 for(i=0;i<n;++i){
  scanf("%f %f", &x[i], &y[i]);
 }
 x[n]=x[0]; y[n]=y[0];
 initgraph(&gd, &gm, "C:\\TC\\BGI");
 
 while(choice!=6){
  cleardevice();
  grid(50,10);
  for(i=0;i<n;++i){
   drawLine(x[i],y[i],x[i+1],y[i+1],gridsize,cellsize);
  }
  outtextxy(0,0,"Enter 1 for edge-fill, 2 for fence-fill, 3 for edge-flag,");
  outtextxy(0,10,"4 for simple seed-fill, 5 for scan-line seed-fill and 6 to quit");
  scanf("%d",&choice);
  if(choice!=6){
   cleardevice();
   grid(50,10);
   if(choice==1){
    for(i=0;i<n;++i){
     if(y[i+1]!=y[i]){
      edgefill(x[i],y[i],x[i+1],y[i+1],gridsize,cellsize);
      delay(30);
     }
    }
    for(i=0;i<n;++i){
     drawLine(x[i],y[i],x[i+1],y[i+1],gridsize,cellsize);
    }
    delay(50);
   }
   else if(choice==2){
    outtextxy(0,0,"Enter x-coordinate of fence");
    scanf("%d", &xfence);
    drawFence(xfence,-25,xfence,25,gridsize,cellsize);
    for(i=0;i<n;++i){
     fencefill(x[i],y[i],x[i+1],y[i+1],xfence,gridsize,cellsize);
     delay(30);
    }
    for(i=0;i<n;++i){
     drawLine(x[i],y[i],x[i+1],y[i+1],gridsize,cellsize);
    }
    delay(50);
   }
   else if(choice==3){
    maxy=miny=y[0];
    for(i=0;i<n;++i){
     if(maxy<y[i])
      maxy=y[i];
     if(miny>y[i])
      miny=y[i];
    }
    for(y1=maxy-1;y1>=miny;y1=y1-1){
     found=0;
     for(i=0;i<n;++i){
      if(y[i+1]!=y[i] && ((y[i]<=y1 && y1<=y[i+1])||(y[i+1]<=y1 && y1<=y[i]))){
       x1=x[i]+((x[i+1]-x[i])/(y[i+1]-y[i]))*(y1-y[i]);
       //if(y1!=LMAX(y[i-1],y[i],y[i+1]) && y1!=LMIN(y[i-1],y[i],y[i+1]))
       if(!isLocalMin(y1, y[i-1],y[i],y[i+1]) && !isLocalMax(y1, y[i-1],y[i],y[i+1]))
        setpixel(x1,y1,gridsize,cellsize);
      }
     }
    }
    delay(50);
    edgeflag(maxy,miny,gridsize,cellsize);
    for(i=0;i<n;++i){
     drawLine(x[i],y[i],x[i+1],y[i+1],gridsize,cellsize);
    }
    delay(50);
   }
   else if(choice==4){
    for(i=0;i<n;++i){
     intbres(x[i],y[i],x[i+1],y[i+1],gridsize,cellsize);
    }
    delay(50);
    sumx=0;
    sumy=0;
    for(i=0;i<n;++i){
     sumx+=x[i];
     sumy+=y[i];
    }
    xc=sumx/n;
    yc=sumy/n;
    seedfill(xc,yc,gridsize,cellsize);
    for(i=0;i<n;++i){
     drawLine(x[i],y[i],x[i+1],y[i+1],gridsize,cellsize);
    }
    delay(50);
   }
   else if(choice==5){
    for(i=0;i<n;++i){
     intbres(x[i],y[i],x[i+1],y[i+1],gridsize,cellsize);
    }
    delay(50);
    for(i=0;i<n;++i){
     sumx+=x[i];
     sumy+=y[i];
    }
    xc=sumx/n;
    yc=sumy/n;
    scanlineseedfill(xc,yc,gridsize,cellsize);
    for(i=0;i<n;++i){
     drawLine(x[i],y[i],x[i+1],y[i+1],gridsize,cellsize);
    }
    delay(50);
   }

  }
  
 }
 
 closegraph();

 return 0;
}
