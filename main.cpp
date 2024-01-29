#include <bits/stdc++.h>
#include <graphics.h>
#include <conio.h>

using namespace std;

void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    if (dy <= dx)
    {
        int d = 2 * dy - dx;
        int x = x1, y = y1;
        int xEnd = x2, yEnd = y2;
        if (x > xEnd)
        {
            swap(x, xEnd);
            swap(y, yEnd);
        }

        while (x <= xEnd)
        {
            putpixel(x, y, WHITE);

            if (d < 0)
            {
                d += 2 * dy;
            }
            else if (d >= 0)
            {
                d += 2 * (dy - dx);
                if (yEnd > y)
                {
                    y++;
                }
                else
                {
                    y--;
                }
            }

            x++;
        }
    }
    else
    {
        int d = 2 * dx - dy;
        int x = x1, y = y1;
        int xEnd = x2, yEnd = y2;
        if (y > yEnd)
        {
            swap(y, yEnd);
            swap(x, xEnd);
        }
        while (y <= yEnd)
        {
            putpixel(x, y, WHITE);

            if (d < 0)
            {
                d += 2 * dx;
            }
            else if (d >= 0)
            {
                d += 2 * (dx - dy);
                if (xEnd > x)
                {
                    x++;
                }
                else
                {
                    x--;
                }
            }
            y++;
        }
    }
}

void drawDottedLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    if (dy <= dx)
    {
        int d = 2 * dy - dx;
        int x = x1, y = y1;
        int xEnd = x2, yEnd = y2;
        if (x > xEnd)
        {
            swap(x, xEnd);
            swap(y, yEnd);
        }
        int even = 5;
        while (x <= xEnd)
        {
            if(even % 5 == 0)
            {
                even++;
            }
            else
            {
                putpixel(x, y, WHITE);
                even++;
            }

            if (d < 0)
            {
                d += 2 * dy;
            }
            else if (d >= 0)
            {
                d += 2 * (dy - dx);
                if (yEnd > y)
                {
                    y++;
                }
                else
                {
                    y--;
                }
            }

            x++;
        }
    }
    else
    {
        int d = 2 * dx - dy;
        int x = x1, y = y1;
        int xEnd = x2, yEnd = y2;
        if (y > yEnd)
        {
            swap(y, yEnd);
            swap(x, xEnd);
        }
        while (y <= yEnd)
        {
            putpixel(x, y, WHITE);

            if (d < 0)
            {
                d += 2 * dx;
            }
            else if (d >= 0)
            {
                d += 2 * (dx - dy);
                if (xEnd > x)
                {
                    x++;
                }
                else
                {
                    x--;
                }
            }
            y++;
        }
    }
}

void drawCircle(int h, int k, int r)
{
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;

    while (x <= y)
    {
        putpixel(h + x, k + y, WHITE);
        putpixel(h - x, k - y, WHITE);
        putpixel(h + y, k + x, WHITE);
        putpixel(h - y, k - x, WHITE);
        putpixel(h + y, k - x, WHITE);
        putpixel(h - y, k + x, WHITE);
        putpixel(h - x, k + y, WHITE);
        putpixel(h + x, k - y, WHITE);

        if (d < 0)
        {
            d += 4 * x + 6;
        }
        else
        {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void grid()
{
    int x = 50;
    for (; x < 500; x += 50)
    {
        drawLine(x, 0, x, 400);
    }

    int y = 50;
    for (; y < 400; y += 50)
    {
        drawLine(0, y, 500, y);
    }
}

int main()
{
    initwindow(800, 600);

    // Question 1
    drawCircle(400, 300, 100);
// left side
    drawLine(250, 500, 250, 150);
    drawLine(200, 500, 200, 150);
    drawLine(200, 150, 250, 150);
    drawLine(200, 500, 250, 500);

// right side
    drawLine(550, 500, 600, 500);
    drawLine(600, 500, 600, 150);
    drawLine(550, 500, 550, 150);
    drawLine(550, 150, 600, 150);

    drawLine(100, 500, 700, 500); // top line
    drawLine(200, 590, 600, 590); //below line
    drawLine(200, 590, 150, 550);
    drawLine(600, 590, 650, 550); // connecting line dot

    drawDottedLine(150, 550, 650, 550); // dotted line
    drawDottedLine(150, 550, 100, 500);
    drawDottedLine(650, 550, 700, 500);

// below circle
    drawLine(400, 400, 400, 500);
    drawLine(350, 500, 350, 386);
    drawLine(450, 500, 450, 386);

// above circle
    drawLine(350, 150, 350, 214);
    drawLine(450, 150, 450, 214);
    drawLine(400, 150, 400, 200);

// top curve

    drawLine(350, 150, 400, 50);
    drawLine(400, 150, 450, 50);
    drawLine(450, 150, 500, 50);
    drawLine(400, 50, 500, 50);

   // getchar();
   // closegraph();

    initwindow(900, 600);


// image 1
    drawLine(150, 400, 300, 300);
    drawDottedLine(300, 300, 155, 250);
    drawDottedLine(150, 400, 295, 450);

// image 2
    drawLine(350, 450, 500, 450);
    drawLine(350, 450, 350, 250);
    drawLine(350, 250, 500, 250);
    drawLine(500, 250, 500, 450);

// image 3
    drawDottedLine(550, 400, 700, 300);
    drawLine(700, 300, 550, 250);
    drawLine(550, 400, 700, 450);

// image 4
    drawLine(750, 250, 750, 350);
    drawLine(750, 350, 870, 350);
    drawLine(850, 340, 850, 450);

    getchar();
    closegraph();
}
