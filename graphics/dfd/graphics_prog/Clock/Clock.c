//Clock of 4 different time zones.

    #include <graphics.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <math.h>
    #include <string.h>
    #include <time.h>

    #define S_N_L (radius-10)        // Second Needle Length
    #define S_N_C RED                   // Second needle Color
    #define M_N_L (radius-20)           // Minute Needle Length
    #define M_N_C LIGHTRED              // Minute Needle Color
    #define H_N_L (radius-(radius/2))       // Hour Needle Length
    #define H_N_C CYAN                     // Hour Needle Color

    float cx1, cy1, cx2, cy2, cx3, cy3, cx4, cy4;
    float radius = 50;

    void draw_face(float radius, float cx, float cy)
    {

        int theta = 0; // theta is the angle variable.
        float x, y;
        setcolor(WHITE);
        setcolor(WHITE);
        circle(cx, cy, radius+12);   //Border
        circle(cx, cy, 2);           //Center
        int i = 0;
        do{                                                 //5 min interval markings
            x = cx+radius*cos(theta*M_PI/180);
            y = cy+radius*sin(theta*M_PI/180);
            circle(x, y, 2);
            theta+= 30;
            /** Increase i by 1. **/
            i++;

        } while(i!= 12);
    }

    void get_time(int *h, int *m, int *s)                       //Get system time
    {
        time_t rawtime;
        struct tm *t;
        time(&rawtime);
        t = gmtime(&rawtime);
        *h = t->tm_hour;
        *m = t->tm_min;
        *s = t->tm_sec;
    }

    void second_needle(int s, float cx, float cy)
    {                                                   //Draw second needle
        float angle = -90;
        float sx, sy;
        setcolor(0);
        sx = cx+S_N_L*cos((angle+s*6-6)*M_PI/180);
        sy = cy+S_N_L*sin((angle+s*6-6)*M_PI/180);
        line(cx, cy, sx, sy);
        setcolor(S_N_C);
        sx = cx+S_N_L*cos((angle+s*6)*M_PI/180);
        sy = cy+S_N_L*sin((angle+s*6)*M_PI/180);
        line(cx, cy, sx, sy);
    }

    void minute_needle(int m, int s, float cx, float cy)
    {                                                           //Minute needle
        float angle = -90;
        float sx, sy;
        setcolor(0);
        sx = cx+M_N_L*cos((angle+m*6-6)*M_PI/180);
        sy = cy+M_N_L*sin((angle+m*6-6)*M_PI/180);
        line(cx, cy, sx, sy);
        setcolor(M_N_C);
        sx = cx+M_N_L*cos((angle+m*6/*+(s*6/60)*/)*M_PI/180);
        sy = cy+M_N_L*sin((angle+m*6/*+(s*6/60)*/)*M_PI/180);
        line(cx, cy, sx, sy);
    }

    void hour_needle(int h, int m, int s, float cx, float cy)
    {                                                           //Hour needle
        float angle = -90;
        float sx, sy;
        setcolor(0);
        sx = cx+H_N_L*cos((angle+h*30-(m*30/60))*M_PI/180);
        sy = cy+H_N_L*sin((angle+h*30-(m*30/60))*M_PI/180);
        line(cx, cy, sx, sy);
        setcolor(H_N_C);
        sx = cx+H_N_L*cos((angle+h*30+(m*30/60))*M_PI/180);
        sy = cy+H_N_L*sin((angle+h*30+(m*30/60))*M_PI/180);
        line(cx, cy, sx, sy);
    }

 int main(void)
    {
        int gdriver  =  DETECT,  gmode,  errorcode;
        initgraph(&gdriver, &gmode, NULL);
        cx1 = getmaxx()/4.0; // cx1 is center x value.
        cy1 = getmaxy()/4.0; // cy1 is center y value.
        cx2 = (getmaxx()/4.0)*3.0; // cx1 is center x value.
        cy2 = getmaxy()/4.0; // cy1 is center y value.
        cx3 = getmaxx()/4.0; // cx1 is center x value.
        cy3 = (getmaxy()/4.0)*3.0; // cy1 is center y value.
        cx4 = (getmaxx()/4.0)*3.0; // cx1 is center x value.
        cy4 = (getmaxy()/4.0)*3.0; // cy1 is center y value.

        float x, y;
        int hour, minute, second;
        draw_face(radius, cx1, cy1);
        draw_face(radius, cx2, cy2);
        draw_face(radius, cx3, cy3);
        draw_face(radius, cx4, cy4);
        while(!kbhit())
        {
            get_time(&hour, &minute, &second);
            second_needle(second, cx1, cy1);
            minute_needle(minute, second, cx1, cy1);
            hour_needle(hour, minute, second, cx1, cy1);

            second_needle(second, cx2, cy2);
            minute_needle((minute+30)%60, second, cx2, cy2);
            hour_needle((hour+5)%24, minute, second, cx2, cy2);

            second_needle(second, cx3, cy3);
            minute_needle(minute, second, cx3, cy3);
            hour_needle((hour+10)%24, minute, second, cx3, cy3);

            second_needle(second, cx4, cy4);
            minute_needle(minute, second, cx4, cy4);
            hour_needle((hour-5)%24, minute, second, cx4, cy4);
            delay(100);
        }


        getch();
        closegraph();
        return 0;

    }
