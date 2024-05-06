#include <stdio.h>
#include <graphics.h>
#include <math.h>

void drawPolygon(int xs[], int ys[], int n);
void rotatePolygon(int xs[], int ys[], int n, float angle);
int xs[100], ys[100], xmid, ymid;

int main() {
    initwindow(700, 600, "Polygon Rotation About Origin");

    int n, i;
    float angle;

    printf("Enter the number of sides of the polygon: ");
    scanf("%d", &n);

    printf("Enter the coordinates (x, y) for each vertex of the polygon:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &xs[i], &ys[i]);
    }

    xmid= getmaxx()/2;
    ymid= getmaxy()/2;
    line(5,ymid,getmaxx()-5,ymid);
    line(xmid+3,5,xmid+3,getmaxy()-5);

    setcolor(WHITE);
    outtextxy(xs[0]+xmid, ymid-ys[0]-ys[1]-20, (char*)"ORIGINAL OBJECT");
    drawPolygon(xs, ys, n);

    printf("Enter the angle of rotation: ");
    scanf("%f", &angle);

    // Perform rotation
    rotatePolygon(xs, ys, n, angle);

    setcolor(RED);
    drawPolygon(xs, ys, n);

    // Wait for a key press before closing the graphics window
    while (!kbhit()) {
        delay(200);
    }

    return 0;
}

void drawPolygon(int xs[], int ys[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        line(xs[i]+xmid, ymid-ys[i], xmid+xs[(i + 1) % n], ymid-ys[(i + 1) % n]);
    }
}

void rotatePolygon(int xs[], int ys[], int n, float angle) {
    int i;
    float t = angle * (3.14 / 180);

    for (i = 0; i < n; i++) {
        int x = xs[i];
        int y = ys[i];
        xs[i] = (int)((x * cos(t)) - (y * sin(t)));
        ys[i] = (int)((x * sin(t)) + (y * cos(t)));
    }
}