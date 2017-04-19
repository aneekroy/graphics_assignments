# include<stdio.h>
# include<conio.h>
# include<graphics.h>
void cartesian()        ///drawing x and y axes

{
    setcolor(BLACK);
for(int i=getmaxx()/2;i<=getmaxx()/2+3;i++)
    line(i,0,i,getmaxy());
for(int i=getmaxy()/2;i<=getmaxy()/2+3;i++)
    line(0,i,getmaxx(),i);

}
void putp(int x,int y)
{y=getmaxy()/2-y;
x=x+getmaxx()/2;
    for(int i=x ;i <x+5 ;i++)
for( int j=y; j>y-5 ;j--)
putpixel(i,j,BLACK);
}
void makegrid()     ///making grid
{int i,j;
    for(i=0;i<getmaxy();i+=5)
        line(0,i,getmaxx(),i);
        for(j=0;j<getmaxx();j+=5)
        line(j,0,j,getmaxy());

}

int main()
{
            int gd=DETECT,gm,xc,yc,r,x,y,Pk;
            printf("Enter the value of Xc\t");
            scanf("%d",&xc);
            printf("Enter the value of yc\t");
            scanf("%d",&yc);
            printf("Enter the Radius of circle\t");
            scanf("%d",&r);
            initgraph(&gd,&gm,"");
            makegrid();
           cartesian();
           putp(xc,yc);
            x=0;
            y=r;
            putp(xc+x,yc-y);
            Pk=2*(1-r);int d,d1;
while(y>0)            {
                        if (Pk<0)
                        {
                                    d=2*Pk+2*y-1;
                                    if(d<=0)
                                        x++,Pk+=2*x+1;  ///choosing  next horizontal point
                                    else{
                                        x++,y--,Pk+=2*x-2*y+2;      ///choosing  next diagonal point
                                    }
                                    }
                                    else if (Pk>0)
                                    {
                                        d1=2*Pk-2*x-1;
                                    if(d1<=0)
                                        x++,y--,Pk+=2*x-2*y+2; ///choosing next diagonal point
                                    else{
                                        y--,Pk+=-2*y+1;         ///choosing  next vertical point
                                    }
                                    }
                                    else
x++,y--,Pk+=2*x-2*y+2;  ///choosing  next diagonal point


                        putp(xc+x,yc-y);///8 points plotted due to symmetry
                        putp(xc-x,yc-y);
                        putp(xc+x,yc+y);
                        putp(xc-x,yc+y);
                        putp(xc+y,yc-x);
                        putp(xc-y,yc-x);
                        putp(xc+y,yc+x);
                        putp(xc-y,yc+x);

                     }


            getch();

return 0;}
