#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

int main()
{
	int gd=DETECT, gm;
	initgraph(&gd, &gm, (char*)"");
	int radius, xc, yc, x, y, theta;
	printf("Enter radius: ");
	scanf("%d",&radius);
	printf("Enter coordinates of center of cicle: ");
	scanf("%d%d",&xc,&yc);
	for(theta=0; theta<360; theta++)
    {
		x=xc+radius*cos(theta*3.14159/180);
		y=yc+radius*sin(theta*3.14159/180);
		putpixel(x,y,WHITE);
		delay(10);
	}
	getch();
	closegraph();
	return 0;
}