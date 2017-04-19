#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>

void grid();
int adjust_x(int k);
int adjust_y(int k);
int sign(int x,int y);
void plot(int x,int y,int c);
void poly(int x1,int y1,int x2,int y2,int c);
void push(int a,int b);
int pop_x();
int pop_y();
int pop_y();
int check(int x1,int y1);

int i,j,k = 0;
int max_x = 500;
int max_y = 500;
int side = 10;

int p[100];
int q[100];
int mat[100][100];


int main()
{

    //initwindow(max_x,max_y,"Scanseed Fill");
    int gdriver=DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
    grid();

    int x1[10],x2[10],y1[10],y2[10],n,a,b,x,y,l,savex,savey,xleft,xright,pflag,xenter;

    printf("enter number of sides:");

    scanf("%d",&n);

    printf("%d",n);



    for(l = 0; l<n; l++)
    {

        printf("enter x1 for side %d:",l+1);

        scanf("%d",&x1[l]);

        printf("enter y1 for side %d:",l+1);

        scanf("%d",&y1[l]);

        printf("enter x2 for side %d:",l+1);

        scanf("%d",&x2[l]);

        printf("enter y2 for side %d:",l+1);

        scanf("%d",&y2[l]);

        poly(x1[l],y1[l],x2[l],y2[l],3);

    }



    system("pause");

    printf("enter initial seed:");

    scanf("%d  %d",&a,&b);

    push(a,b);



    while(k!=0)
    {

        x = pop_x();

        y = pop_y();

        k = k-1;
        delay(500);
        plot(x,y,6);

        savex = x;

        x = x+1;



        while(check(x,y)!=1)
        {
            delay(500);
            plot(x,y,6);

            x = x + 1;

        }



        xright = x - 1;

        x = savex;

        x = x-1;

        while(check(x,y)!=1)
        {
            delay(500);
            plot(x,y,6);

            x = x-1;

        }

        xleft = x+1;

        x = savex;

        x = xleft;

        savey = y;

        y = y+1;



        while(x<=xright)
        {

            pflag = 0;

            while(check(x,y)!=1 && x<xright)
            {

                if (pflag==0)

                    pflag = 1;

                x = x+1;

            }



            if (pflag==1)
            {

                if(x == xright && check(x,y)!=1)

                    push(x,y);

                else

                    push(x-1,y);

                pflag = 0;

            }

            xenter = x;

            while(check(x,y)==1 && x<xright)
            {

                x = x+1;

            }

            if(x==xenter)

                x = x+1;

        }



        x = xleft;

        y = savey;

        y = y-1;



        while(x<=xright)
        {

            pflag = 0;

            while(check(x,y)!=1 && x<xright)
            {

                if (pflag==0)

                    pflag = 1;

                x = x+1;

            }



            if (pflag==1)
            {

                if(x == xright && check(x,y)!=1)

                    push(x,y);

                else

                    push(x-1,y);

                pflag = 0;

            }

            xenter = x;

            while(check(x,y)==1 && x<xright)
            {

                x = x+1;

            }



            if(x==xenter)

                x = x+1;

        }





    }

    system("pause");
    return 0;

}


void grid()
{
    i = 0;
    j = 0;

    while(i<max_x)
    {

        j = 0;
        while(j<max_y)
        {

            putpixel(i,j,2);
            j = j + side;
        }

        i = i+1;
    }


    i = 0;
    j = 0;


    while(j<max_y)
    {

        i = 0;
        while(i<max_x)
        {

            putpixel(i,j,2);
            i = i+ side;
        }
        j = j+1;
    }


    i = max_x/2;
    j = 0;


    while(j<max_y)
    {

        putpixel(i,j,5);
        j++;

    }


    j = max_y/2;
    i = 0;


    while(i<max_x)
    {
        putpixel(i,j,5);
        i++;
    }
}

int adjust_x(int k)
{
    k = k*side + max_x/2;
    return(k);
}


int adjust_y(int k)
{
    k = max_y/2 - k*side;
    return(k);
}


int sign(int x,int y)
{
    if(x>y)
        return(1);
    else
        return(-1);
}


void plot(int x,int y,int c)
{
    mat[x][y] = 1;
    x = adjust_x(x);
    y = adjust_y(y);

    for(i = 0; i<10; i++)
    {
        for(j = 0; j>-10; j--)
        {
            putpixel(x+i,y+j,c);
        }
    }
}


void poly(int x1,int y1,int x2,int y2,int c)
{
    int del_x,del_y,sx,sy,temp,inter=0,e;
    del_x = fabs(x2-x1);
    del_y = fabs(y2-y1);
    sx = sign(x2,x1);
    sy = sign(y2,y1);

    if(del_y>del_x)
    {
        temp = del_x;
        del_x = del_y;
        del_y = temp;
        inter = 1;
    }

    e = 2*del_y-del_x;
    printf("%d",e);

    if(x1!=x2)
    {
        while(x1!=x2+sx)
        {
            plot(x1,y1,c);
            while(e>0)
            {
                if (inter == 1)
                    x1 = x1+sx;
                else
                    y1 = y1+sy;
                e = e - 2*del_x;

            }

            if(inter == 1)

                y1 = y1+sy;

            else

                x1 = x1+sx;

            e = e+2*del_y;

        }

    }





    else
    {

        while(y1!=y2)
        {

            plot(x1,y1,c);

            y1 = y1+sy;

        }



        plot(x1,y1,c);

    }

}





void push(int a,int b)
{

    p[k] = a;

    q[k] = b;

    k = k+1;

}





int pop_x()
{

    return(p[k-1]);

}





int pop_y()
{

    return(q[k-1]);

}





int check(int x1,int y1)
{

    if(mat[x1][y1]==1)

        return(1);

    else

        return(0);

}
