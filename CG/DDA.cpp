#include<stdio.h>
#include<math.h>
#include<graphics.h>

int main()
{
    float x1, x2, y1, y2, x, y, pk, dx, dy, length, xinc, yinc;

    //int gd = DETECT, gm;
    //initgraph(&gd, &gm, (char*)"");
    initwindow(700, 700, "Digital Differential Algorithm");
    printf("Enter the initial point(x1, y1) and final point(x2, y2) of the line: ");
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    if(dx>=dy)
        length = dx;
    else
        length = dy;

    xinc = dx/length;
    yinc = dy/length;
    x = x1;
    y = y1;
    putpixel(x, y, WHITE);
    delay(100);

    if(dx<=1)
    {
        x = x1 + 0.5 * (-1.0);
    }
    else    
        x = x1 + 0.5;
    if(dy<0)
        y = y1 + 0.5 * (-1);
    else
        y = y1 + 0.5;
    putpixel(x, y, WHITE);
    delay(100);

    while(length > 0)
    {
        x = x + xinc;
        y = y + yinc;
        length--;
        putpixel(x, y, WHITE);
        delay(100);
    }
    return 0;
}