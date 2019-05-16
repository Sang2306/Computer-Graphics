#include "../include/base.h"
#include <cmath>

void draw2DCoor(const Point2D& mid)
{
    bresenhamLine(Point2D(0, mid.y), Point2D(width, mid.y), WHITE, false); outtextxy(width-12, mid.y, "X");   //X
    bresenhamLine(Point2D(mid.x, 0), Point2D(mid.x, height), WHITE, false); outtextxy(mid.x, 0, "Y");         //Y
}

void draw3DCoor()
{

    bresenhamLine(Point2D(width, midY), Point2D(midX, midY), WHITE, false); outtextxy(width-12, midY, "X");        //X
    bresenhamLine(Point2D(midX, 0), Point2D(midX, midY), WHITE, false); outtextxy(midX, 0, "Y");                   //Y
    int total_unit = 65; //tong so don vi
    for(int unit = 0; unit <= total_unit; unit++)
    {
        Point2D temp = getPointOz(unit); //lay diem toa do tai moi cham
        putpixel(temp.x, temp.y, WHITE); //va hien thi len man hinh
    }
    Point2D temp = getPointOz(total_unit); //lay diem toa do tai moi cham
    outtextxy(temp.x, temp.y, "Z");            //Z
}

Point2D getPointOz(int unit)
{
    /*
        ham tra ve toa do cua don vi tren truc oz
    */
    Point2D point;
    //chuyen doi toa do cho truc z
    point.x = midX - unit*5*cos(45); //x = toa do tam.x - don vi * 5 px * cos(45)
    point.y = midY + unit*5*sin(45); //y = toa do tam.y + don vi * 5 px + sin(45)
    return point;
}

void realToMachine(Point2D& point)
{
    /*
        Chuyen diem x,y thanh toa do may tinh
        5 : don vi
    */
    point.x = point.x*5 + midX;
    if(point.y < 0)
        point.y = point.y*5*-1 + midY;
    else
        point.y = midY - point.y*5;
}

void translateCompute(Point2D& point, float tr_x, float tr_y)
{
    float vector[3] = {point.x, point.y, point.h};
    float translate[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {tr_x, tr_y, 1},
    };
    point.x = vector[0]*translate[0][0] + vector[1]*translate[1][0] + vector[2]*translate[2][0];
    point.y = vector[0]*translate[0][1] + vector[1]*translate[1][1] + vector[2]*translate[2][1];
    point.h = vector[0]*translate[0][2] + vector[1]*translate[1][2] + vector[2]*translate[2][2];
}

void scaleCompute(Point2D& point, float sx, float sy)
{
    float vector[3] = {point.x, point.y, point.h};
    float scale[3][3] = {
        {sx, 0, 0},
        {0, sy, 0},
        {0, 0, 1},
    };
    point.x = vector[0]*scale[0][0] + vector[1]*scale[1][0] + vector[2]*scale[2][0];
    point.y = vector[0]*scale[0][1] + vector[1]*scale[1][1] + vector[2]*scale[2][1];
    point.h = vector[0]*scale[0][2] + vector[1]*scale[1][2] + vector[2]*scale[2][2];
}

void rotateCompute(Point2D& point, float alpha)
{
    float vector[3] = {point.x, point.y, point.h};
    float rotate[3][3] = {
        {cos(alpha * PI/ 180), sin(alpha * PI/ 180), 0},
        {sin(alpha * PI/ 180)*-1, cos(alpha * PI/ 180), 0},
        {0, 0, 1},
    };
    point.x = vector[0]*rotate[0][0] + vector[1]*rotate[1][0] + vector[2]*rotate[2][0];
    point.y = vector[0]*rotate[0][1] + vector[1]*rotate[1][1] + vector[2]*rotate[2][1];
    point.h = vector[0]*rotate[0][2] + vector[1]*rotate[1][2] + vector[2]*rotate[2][2];
}


void bresenhamLine(Point2D p1, Point2D p2, int color, bool solid)
{
     float x, y, dx, dy, dx1, dy1, px, py, xe, ye, count=5;

     dx = p2.x - p1.x;      //do thay doi x
     dy = p2.y - p1.y;      //do thay doi y
     dx1 = abs(dx);
     dy1 = abs(dy);
     px = 2*dy1 - dx1;  //px dau tien neu m < 1
     py = 2*dx1 - dy1;  //py dau tien neu m >= 1

     if(dy1 <= dx1)     //tim y theo x vi chieu doc nho hon (m < 1)
     {
          if(dx >= 0)   //diem cuoi ben phai hoac cung vi tri diem dau -> ve tu trai sang phai
          {
               x = p1.x;
               y = p1.y;
               xe = p2.x;
          }
          else          //diem cuoi ben trai -> ve tu phai sang trai
          {
               x = p2.x;
               y = p2.y;
               xe = p1.x;
          }
          while(x < xe) //loop tu x dau -> x cuoi, chon y trong qua trinh do
          {
                if(!solid)
                {
                    if (count==5)
                        putpixel(x, y, color);
                }
                else
                    putpixel(x, y, color);

               x = x + 1;
               if(px < 0)
                    px = px + 2*dy1;
               else
               {
                    if((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                        y = y + 1;
                    else
                        y = y - 1;
                    px = px + 2*(dy1 - dx1);
               }
               count = count==1 ? 5 : count-1;
          }
     }
     else //tim x theo y vi chieu ngang nho hon (m >= 1)
     {
          if(dy >= 0)
          {
               x = p1.x;
               y = p1.y;
               ye = p2.y;
          }
          else
          {
               x = p2.x;
               y = p2.y;
               ye = p1.y;
          }
          while(y < ye)
          {
                if(!solid)
                {
                    if (count==5)
                        putpixel(x, y, color);
                }
                else
                    putpixel(x, y, color);

               y = y + 1;
               if(py <= 0)
                    py = py + 2*dx1;
               else
               {
                    if((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                        x = x + 1;
                    else
                        x = x - 1;
                    py = py + 2*(dx1 - dy1);
               }
               count = count==1 ? 5 : count-1;
          }
     }
}


void drawCircle(Point2D center, int x, int y, int color)
{
    putpixel(center.x + x, center.y + y, color);
    putpixel(center.x - x, center.y + y, color);
    putpixel(center.x + x, center.y - y, color);
    putpixel(center.x - x, center.y - y, color);
    putpixel(center.x + y, center.y + x, color);
    putpixel(center.x - y, center.y + x, color);
    putpixel(center.x + y, center.y - x, color);
    putpixel(center.x - y, center.y - x, color);
}

void bresenhamCircle(Point2D center, float r, int color)
{
    int x = 0, y = r;
    int p = 3 - 2 * r;
    drawCircle(center, x, y, color);
    while (y >= x)
    {
        x++;
        if (p > 0)
        {
            y--;
            p = p + 4 * (x - y) + 10;
        }
        else
            p = p + 4 * x + 6;
        drawCircle(center, x, y, color);
    }
}


void drawEllipse(Point2D center, int x, int y, int color){
    putpixel(center.x + x, center.y + y, color);
    putpixel(center.x - x, center.y + y, color);
    putpixel(center.x - x, center.y - y, color);
    putpixel(center.x + x, center.y - y, color);
}

void bresenhamEllipse(Point2D center, int a, int b, int color){
    float p, a2, b2;
    int x, y;

    a2 = a * a;
    b2 = b * b;
    //Nhanh 1
    x = 0; y = b;
    p = 2 * b2/a2 - 2*b + 1;
    while(((b2/a2)*(x/y)) < 1 ){
        drawEllipse(center, x, y, color);
        if(p < 0){
            p = p + 2 * (b2 / a2) * (2*x + 3);
        }
        else{
            p = p - 4*y + 2*(b2/a2)*(2*x + 3);
            y = y - 1;
        }
        x = x + 1;
    }
    //Nhanh 2
    x = a; y = 0;
    p = 2 * (a2/b2) - 2*a + 1;
    while(((a2/b2)*(y/x)) <= 1 ){
        drawEllipse(center, x, y, color);
        if(p < 0){
            p = p + 2 * (a2 / b2) * (2*y + 3);
        }
        else{
            p = p - 4*x + 2*(a2/b2)*(2*y + 3);
            x = x - 1;
        }
        y = y + 1;
    }
}

void haftBresenhamEllipse(Point2D center, int a, int b, int color){
    float p, a2, b2;
    int x, y;

    a2 = a * a;
    b2 = b * b;
    //Nhanh 1
    x = 0; y = b;
    p = 2 * b2/a2 - 2*b + 1;
    while(((b2/a2)*(x/y)) < 1 ){
        drawEllipse(center, x, y, color);
        if(p < 0){
            p = p + 2 * (b2 / a2) * (2*x + 3);
        }
        else{
            p = p - 4*y + 2*(b2/a2)*(2*x + 3);
            y = y - 1;
        }
        x = x + 1;
    }
}
