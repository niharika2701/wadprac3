// PRACTICAL ASSIGNMENT 7
// Name: Niharika Jadhav
// Roll No: 2326
// Batch: S2
#include <graphics.h>
#include <math.h>

void drawBezier(double x[], double y[], int n)
{
    if (n == 1) {
        line(x[0], y[0], x[1], y[1]);
        return;
    }
    double midx[n], midy[n];
    for (int i = 0; i < n - 1; i++) {
        midx[i] = (x[i] + x[i + 1]) / 2.0;
        midy[i] = (y[i] + y[i + 1]) / 2.0;
    }
    double newx[n], newy[n];
    newx[0] = x[0];
    newy[0] = y[0];
    newx[n - 1] = x[n - 1];
    newy[n - 1] = y[n - 1];
    for (int i = 1; i < n - 1; i++) {
        newx[i] = (midx[i - 1] + midx[i]) / 2.0;
        newy[i] = (midy[i - 1] + midy[i]) / 2.0;
    }
    drawBezier(x, y, n - 1);
    drawBezier(newx, newy, n - 1);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int width = getmaxx();
    int height = getmaxy();
    double x[4] = {0.1*width, 0.3*width, 0.7*width, 0.9*width};
    double y[4] = {0.1*height, 0.7*height, 0.3*height, 0.9*height};
    drawBezier(x, y, 4);
    getch();
    closegraph();
    return 0;
}

