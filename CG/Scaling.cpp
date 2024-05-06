#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int main()
{
	initwindow(700, 500, "Scaling on Line");
	
	float x0,x1,x2,x3,y0,y1,y2,y3,sx,sy;
	printf("Enter the coordinate of starting point: ");
	scanf("%f%f",&x0,&y0);
	printf("Enter the coordinates of ending point: ");
	scanf("%f%f",&x1,&y1);
	printf("Enter scaling factors (sx,sy): ");
	scanf("%f%f", &sx,&sy);
	setcolor(RED);

    outtextxy(x2+2, y2+2, (char*)"ORIGINAL LINE");
	line((int)x0,(int)y0,(int)x1,(int)y1);
	x2 = x0*sx;
	y2 = y0*sy;
	x3 = x1*sx;
	y3 = y1*sy;
	setcolor(BLUE);

    outtextxy(x2+5, y2-20, (char*)"LINE AFTER SCALING");
	line((int)x2,(int)y2,(int)x3,(int)y3);
    getch();
    return 0;
}