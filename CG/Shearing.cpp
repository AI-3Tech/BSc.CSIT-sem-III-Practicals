#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int n,xs[100],ys[100],i;
float shearX,shearY;

void DrawFn()
{
    for(i=0;i<n;i++)
        line(xs[i],ys[i],xs[(i+1)%n],ys[(i+1)%n]);
}

void shearingX()
{
    for(i=0;i<n;i++)
        xs[i]=xs[i]+shearX*ys[i];
}

void shearingY()
{
    for(i=0;i<n;i++)
        ys[i]=ys[i]+shearY*xs[i];
}

int main()
{
    int graDriver=DETECT,graMode;
    initgraph(&graDriver,&graMode, (char*)"");
    printf("Enter number of sides: ");
    scanf("%d",&n);
    printf("Enter co-rdinates: x,y for each vertex:\n");
    for(i=0;i<n;i++)
    scanf("%d%d",&xs[i],&ys[i]);
    printf("Enter x shear factor: ");
    scanf("%f",&shearX);
    printf("Enter y shear factor: ");
    scanf("%f",&shearY);
    setcolor(RED);
    outtextxy(xs[0]-20, ys[0]-20, (char*) "Original Polygon");
    DrawFn();//original
    shearingX();
    setcolor(BLUE);
    outtextxy(xs[0], ys[0]-20, (char*) "Sheared Along X");
    DrawFn();//Xshear
    shearingY();
    setcolor(GREEN);
    outtextxy(xs[0], ys[0]-20, (char*) "Sheared Along X and Y");
    DrawFn();//Yshear
    getch();
    return 0;
}