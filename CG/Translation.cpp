#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int n,xs[100],ys[100],i,xshift,yshift;

void DrawPolygon();
void translate();

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm, (char*)"");
    printf("Enter number of sides of polygon: ");
    scanf("%d",&n);
    printf("Enter co-rdinates(x,y for each vertex):\n");
    for(i=0;i<n;i++)
    scanf("%d%d",&xs[i],&ys[i]);
    printf("Enter distances for translation (in x and y directions): ");
    scanf("%d%d",&xshift,&yshift);
    //drawing original polygon in RED color
    setcolor(RED);
    DrawPolygon();
    //Doing translation
    translate();
    //drawing translated polygon in BLUE color
    setcolor(BLUE);
    DrawPolygon();
    getch();
    return 0;
}

void DrawPolygon()
{
    for(i=0;i<n;i++)
    {
        line(xs[i],ys[i],xs[(i+1)%n],ys[(i+1)%n]);
    }
}

void translate()
{
    for(i=0;i<n;i++)
    {
        xs[i]+=xshift;
        ys[i]+=yshift;
    }
}