#include <stdio.h>
#include <graphics.h>
#include <conio.h>
int BoundaryFill(int x,int y,int colorfill,int bdcolor)
{
	if (getpixel(x,y) != bdcolor && getpixel(x,y) != colorfill){
        putpixel(x,y,colorfill);
		BoundaryFill(x+1,y,colorfill,bdcolor);
		BoundaryFill(x,y+1,colorfill,bdcolor);
		BoundaryFill(x-1,y,colorfill,bdcolor);
		BoundaryFill(x,y-1,colorfill,bdcolor);
	}
    return 0;
}

int FloodFill(int x,int y,int fillcolor,int old_color)
{
	if(getpixel(x,y)==old_color){
		putpixel(x,y, fillcolor);
		FloodFill(x+1,y, fillcolor, old_color);
		FloodFill(x-1,y, fillcolor, old_color);
		FloodFill(x,y+1, fillcolor, old_color);
		FloodFill(x,y-1, fillcolor, old_color);
	}
    return 0;
}
int main()
{
	int gd=DETECT, gm, i, xvertex[100], yvertex[100];
	initgraph(&gd,&gm,(char*)"");

    printf("Enter co-rdinates(x,y for four vertex):\n");
    for(i=0;i<4;i++)
    scanf("%d%d",&xvertex[i],&yvertex[i]);
	
    for(i=0;i<4;i++)
    {
		setcolor(WHITE);
        line(xvertex[i],yvertex[i],xvertex[(i+1)%4],yvertex[(i+1)%4]);
    }
	
	printf("\n\nFILLING COLOR IN THE POLYNOMIAL USING FLOOD FILL");
    outtextxy(xvertex[0], yvertex[0]-20, (char*)"Boundary Fill");
	BoundaryFill(xvertex[0]+1, yvertex[0]+1, WHITE, WHITE);
    delay(1000);
	setcolor(0);
	outtextxy(xvertex[0], yvertex[0]-20, (char*)"Boundary Fill");

    printf("\n\nFILLING COLOR IN THE POLYNOMIAL USING FLOOD FILL");
	setcolor(WHITE);
	outtextxy(xvertex[0], yvertex[0]-20, (char*)"FLOOD Fill");
	FloodFill(xvertex[0]+1, yvertex[0]+1, WHITE, WHITE);
	getch();
	closegraph();
    return 0;
}