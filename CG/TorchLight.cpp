#include<stdio.h>
#include<graphics.h>
#include<math.h>

int FloodFill(int x,int y,int fillcolor,int old_color)
{
	if(getpixel(x,y)==old_color){
		putpixel(x,y, fillcolor);
		FloodFill(x,y+1, fillcolor, old_color);
		FloodFill(x,y-1, fillcolor, old_color);
		FloodFill(x+1,y, fillcolor, old_color);
		FloodFill(x+1,y, fillcolor, old_color);
	}
    return 0;
}

int main()
{
    int gd=DETECT, gm;
    int n, i, x[]={50,50,150,300,300,150,301,600,600,301}, y[]={50,150,150, 190,10,50,50,-250,300,150};
    initgraph(&gd, &gm, (char*)"");
    //printf("Enter the no. of sides: ");
    //scanf("%d", &n);
    //printf("\nEnter the coordinates (x, y) of each vertices: ");
    //for(i=0; i<6; i++)
    //    scanf("%d %d", &x[i], &y[i]);
    setcolor(WHITE);
    for(i=0; i<6; i++)
        line(x[i], y[i], x[(i+1)%6], y[(i+1)%6]);

    setcolor(YELLOW);
    for(i=6;i<9;i++)
        line(x[i], y[i], x[(i+1)], y[i+1]);
    line(x[9], y[9], x[6], y[6]);
    FloodFill(x[6]+1, y[6], YELLOW, BLACK);
    getch();
    closegraph();
    return 0;
}