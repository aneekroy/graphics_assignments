//# include <iostream>
//#include <bits/stdc++.h>
# include "stdio.h"
# include <graphics.h>
//# include    <conio.h>
# include     <math.h>


class LineCoordinates
   {
      public:
     float x_1;
     float y_1;
     float x_2;
     float y_2;

     LineCoordinates(const float x1,const float y1,
                         const float x2,const float y2)
        {
       x_1=x1;
       y_1=y1;
       x_2=x2;
       y_2=y2;
        }
   };

/*************************************************************************///-------------------------  WindowCoordinates  -------------------------///*************************************************************************/
class WindowCoordinates
   {
      public:
     float x_min;
     float y_min;
     float x_max;
     float y_max;

     WindowCoordinates(const  float x1,const  float y1,
                         const  float x2,const  float y2)
        {
       x_min=x1;
       y_min=y1;
       x_max=x2;
       y_max=y2;
        }
   };


void show_screen( );

const int clip_line(const  WindowCoordinates,LineCoordinates&);
const int check_line(const float,const float,float&,float&);

void Rectangle(const  int,const int,const int,const int);
void Line(const  int,const  int,const int,const int);


int main( )
   {
      int driver=VGA;
      int mode=VGAHI;

      initgraph(&driver,&mode,"..\\Bgi");

      show_screen( );

      WindowCoordinates WC(180,140,470,340);

      setcolor(15);
    Rectangle(WC.x_min,WC.y_min,WC.x_max,WC.y_max);

      LineCoordinates LC_1(150,160,120,320);
      LineCoordinates LC_2(250,150,200,200);
      LineCoordinates LC_3(160,200,490,260);
      LineCoordinates LC_4(300,300,400,380);
      LineCoordinates LC_5(550,300,450,400);
      LineCoordinates LC_6(440,110,400,370);

      setcolor(7);
    Line(LC_1.x_1,LC_1.y_1,LC_1.x_2,LC_1.y_2);
    Line(LC_2.x_1,LC_2.y_1,LC_2.x_2,LC_2.y_2);
    Line(LC_3.x_1,LC_3.y_1,LC_3.x_2,LC_3.y_2);
    Line(LC_4.x_1,LC_4.y_1,LC_4.x_2,LC_4.y_2);
    Line(LC_5.x_1,LC_5.y_1,LC_5.x_2,LC_5.y_2);
    Line(LC_6.x_1,LC_6.y_1,LC_6.x_2,LC_6.y_2);

      char Key=NULL;

      do
     {
        Key=getch( );
     }
      while(Key!='C' && Key!='c');

      settextstyle(0,0,1);
    setcolor(0);
      outtextxy(163,450,"  Press 'C' to see the Clipped Lines.  ");

   setcolor(15);
      outtextxy(163,450,"------                          -------");

    setcolor(12);
      outtextxy(213,450,"  Press any Key to exit.  ");

      setcolor(10);

      if(clip_line(WC,LC_1))
     Line(LC_1.x_1,LC_1.y_1,LC_1.x_2,LC_1.y_2);

      if(clip_line(WC,LC_2))
     Line(LC_2.x_1,LC_2.y_1,LC_2.x_2,LC_2.y_2);

      if(clip_line(WC,LC_3))
     Line(LC_3.x_1,LC_3.y_1,LC_3.x_2,LC_3.y_2);

      if(clip_line(WC,LC_4))
     Line(LC_4.x_1,LC_4.y_1,LC_4.x_2,LC_4.y_2);

      if(clip_line(WC,LC_5))
     Line(LC_5.x_1,LC_5.y_1,LC_5.x_2,LC_5.y_2);

      if(clip_line(WC,LC_6))
     Line(LC_6.x_1,LC_6.y_1,LC_6.x_2,LC_6.y_2);

      getch( );
      return 0;
   }

/*************************************************************************///---------------------------  clip_line( )  ----------------------------///*************************************************************************/const int clip_line(const  WindowCoordinates wc,LineCoordinates &lc)
   {
      float u_1=0;
      float u_2=1;

      float dx=(lc.x_2-lc.x_1);
      float dy=(lc.y_2-lc.y_1);

      float p1=(-dx);
      float p2=dx;
      float p3=(-dy);
      float p4=dy;

      float q1=(lc.x_1-wc.x_min);
      float q2=(wc.x_max-lc.x_1);
      float q3=(lc.y_1-wc.y_min);
      float q4=(wc.y_max-lc.y_1);

      if(check_line(p1,q1,u_1,u_2) && check_line(p2,q2,u_1,u_2) &&
            check_line(p3,q3,u_1,u_2) && check_line(p4,q4,u_1,u_2))
     {
        if(u_2<1)
       {
          lc.x_2=(lc.x_1+(u_2*dx));
          lc.y_2=(lc.y_1+(u_2*dy));
       }

        if(u_1>0)
       {
          lc.x_1+=(u_1*dx);
          lc.y_1+=(u_1*dy);
       }

        lc.x_1=(int)(lc.x_1+0.5);
        lc.y_1=(int)(lc.y_1+0.5);
        lc.x_2=(int)(lc.x_2+0.5);
        lc.y_2=(int)(lc.y_2+0.5);

        return 1;
     }

      return 0;
   }

/*************************************************************************///------------------------------  check_line( )  ------------------------///*************************************************************************/const int check_line(const float p,const float q,float &u_1,float &u_2)
   {
      int flag=1;

      float r=(q/p);

      if(p<0)
     {
        if(r>u_2)
       flag=0;

        elseif(r>u_1)
       u_1=r;
     }

      elseif(p>0)
     {
        if(r<u_1)
       flag=0;

        elseif(r<u_2)
       u_2=r;
     }

      else
     {
        if(q<0)
       flag=0;
     }

      return flag;
   }

/*************************************************************************///---------------------------  Rectangle( )  ----------------------------///*************************************************************************/void Rectangle(const int x_1,const int y_1,const int x_2,const int y_2)
   {
      Line(x_1,y_1,x_2,y_1);
      Line(x_2,y_1,x_2,y_2);
      Line(x_2,y_2,x_1,y_2);
      Line(x_1,y_2,x_1,y_1);
   }

/*************************************************************************///--------------------------  Line( )  ------------------------///*************************************************************************/void Line(const int x_1,const int y_1,const int x_2,const int y_2)
   {
      int color=getcolor( );

      int x1=x_1;
      int y1=y_1;

      int x2=x_2;
      int y2=y_2;

      if(x_1>x_2)
     {
        x1=x_2;
        y1=y_2;

        x2=x_1;
        y2=y_1;
     }

      int dx=abs(x2-x1);
      int dy=abs(y2-y1);
      int inc_dec=((y2>=y1)?1:-1);

      if(dx>dy)
     {
        int two_dy=(2*dy);
        int two_dy_dx=(2*(dy-dx));
        int p=((2*dy)-dx);

        int x=x1;
        int y=y1;

        putpixel(x,y,color);

        while(x<x2)
       {
          x++;

          if(p<0)
             p+=two_dy;

          else
             {
            y+=inc_dec;
            p+=two_dy_dx;
             }

          putpixel(x,y,color);
       }
     }

      else
     {
        int two_dx=(2*dx);
        int two_dx_dy=(2*(dx-dy));
        int p=((2*dx)-dy);

        int x=x1;
        int y=y1;

        putpixel(x,y,color);

        while(y!=y2)
       {
          y+=inc_dec;

          if(p<0)
             p+=two_dx;

          else
             {
            x++;
            p+=two_dx_dy;
             }

          putpixel(x,y,color);
       }
     }
   }

/*************************************************************************///--------------------------  show_screen( )  ---------------------------///*************************************************************************/void show_screen( )
   {
      setfillstyle(1,1);
    bar(165,26,470,38);

      settextstyle(0,0,1);
    setcolor(15);
      outtextxy(5,5,"******************************************************************************");
      outtextxy(5,17,"*-**************************************************************************-*");
      outtextxy(5,29,"*------------------                                        ------------------*");
      outtextxy(5,41,"*-**************************************************************************-*");
      outtextxy(5,53,"*-**************************************************************************-*");

    setcolor(11);
      outtextxy(174,29,"Liang-Barsky Line Clipping Algorithm");

    setcolor(15);

      for(int count=0;count<=30;count++)
         outtextxy(5,(65+(count*12)),"*-*                                                                        *-*");

      outtextxy(5,438,"*-**************************************************************************-*");
      outtextxy(5,450,"*-------------------                                       ------------------*");
      outtextxy(5,462,"******************************************************************************");

    setcolor(12);
      outtextxy(163,450,"  Press 'C' to see the Clipped Lines.  ");
   }
