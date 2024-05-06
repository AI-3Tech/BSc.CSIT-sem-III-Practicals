#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

int main()
{
    float x, y, dy, dx, x1, y1, x2, y2, pk, finalx;
    //int gd = DETECT, gm;
    //initgraph(&gd, &gm,(char*)"");
    initwindow(400, 400, "Bresenham's Algorithm");
    printf("Enter the initial and final points: ");
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    //if(x2>x1)
    //{
        x = x1;
        y = y1;
        finalx = x2;
    //}
    /*else{
        x = x2;
        y = y2;
        finalx = x1;
    }*/

    pk = 2*dy - dx;
    putpixel(x, y, RED);
    delay(100);
    if(x1<x2 && y1<y2)
    {
        while(x < finalx)
        {
            x = x+1;
            if(pk < 0)
            {
                pk = pk + 2*dy;
            }
            else 
            {
                y = y + 1;
                pk = pk + 2*dy - 2*dx;
            }
            putpixel(x, y, WHITE);
            delay(100);
        }
    }
    else if(x1>x2 && y1>y2)
    {
        while(x > finalx)
        {
            x = x-1;
            if(pk < 0)
            {
                pk = pk + 2*dy;
            }
            else 
            {
                y = y - 1;
                pk = pk + 2*dy - 2*dx;
            }
            putpixel(x, y, WHITE);
            delay(100);
        }
    }
    else if(x1>x2 && y1<y2)
    {
        while(x > finalx)
        {
            x = x-1;
            if(pk < 0)
            {
                pk = pk + 2*dy;
            }
            else 
            {
                y = y + 1;
                pk = pk + 2*dy - 2*dx;
            }
            putpixel(x, y, WHITE);
            delay(100);
        }
    }
    else 
    {
        while(x < finalx)
        {
            x = x+1;
            if(pk < 0)
            {
                pk = pk + 2*dy;
            }
            else 
            {
                y = y - 1;
                pk = pk + 2*dy - 2*dx;
            }
            putpixel(x, y, WHITE);
            delay(100);
        }
    }
    getch();
    return 0;
}