#include "../include/base.h"
#include <cmath>

void putpoint(const Point2D& point, int color)
{
    putpixel(point.x, point.y, color);
}

void draw2DCoor(const Point2D& mid)
{
    bresenhamLine(Point2D(0, mid.y), Point2D(width, mid.y), WHITE, false); outtextxy(width-12, mid.y, "X");   //X
    bresenhamLine(Point2D(mid.x, 0), Point2D(mid.x, height), WHITE, false); outtextxy(mid.x, 0, "Y");         //Y
}

void draw3DCoor()
{

    bresenhamLine(Point2D(width, midY), Point2D(midX, midY), WHITE, false); outtextxy(width-12, midY, "X");        //X
    bresenhamLine(Point2D(midX, 0), Point2D(midX, midY), WHITE, false); outtextxy(midX, 0, "Y");                   //Y
    Point3D origin_3D(0, 0, 0);
    Point3D endZ_3D(0, 0, 30*5);
    Point2D origin_2D = transformTo2D(origin_3D);
    Point2D endZ_2D = transformTo2D(endZ_3D);
    realToMachine(origin_2D);
    realToMachine(endZ_2D);
    bresenhamLine(origin_2D, endZ_2D, WHITE, false);
    outtextxy(endZ_2D.x, endZ_2D.y, "Z");
}

/*Ham nay se bi loai bo trong cac phien ban tiep theo*/
Point2D getPointOz(int unit_num)
{
    /*
        ham tra ve toa do cua don vi tren truc oz
    */
    Point2D point;
    //chuyen doi toa do cho truc z
    point.x = midX - unit_num*5*cos(45); //x = toa do tam.x - don vi * 5 px * cos(45)
    point.y = midY + unit_num*5*sin(45); //y = toa do tam.y + don vi * 5 px + sin(45)
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

Point2D transformTo2D(Point3D& point)
{
    float a = 0.5; //cabinet 1/2 do dai bi giam
    float phi = 60; //thay doi goc cua truc oz so voi truc ox
    float vector[4] = {
        point.x,
        point.y,
        point.z,
        point.h
    };
    float transformMaxtrix[4][4] = {
        { 1, 0, -1*a*cos(phi*PI/180.0), 0},
        { 0, 1, -1*a*sin(phi*PI/180.0), 0},
        { 0, 0, 0, 0},
        { 0, 0, 0, 1}
    };
    point.x =   vector[0] * transformMaxtrix[0][0] +
                vector[1] * transformMaxtrix[0][1] +
                vector[2] * transformMaxtrix[0][2] +
                vector[3] * transformMaxtrix[0][3];
    point.y =   vector[0] * transformMaxtrix[1][0] +
                vector[1] * transformMaxtrix[1][1] +
                vector[2] * transformMaxtrix[1][2] +
                vector[3] * transformMaxtrix[1][3];
    point.z =   vector[0] * transformMaxtrix[2][0] +
                vector[1] * transformMaxtrix[2][1] +
                vector[2] * transformMaxtrix[2][2] +
                vector[3] * transformMaxtrix[2][3];
    point.h =   vector[0] * transformMaxtrix[3][0] +
                vector[1] * transformMaxtrix[3][1] +
                vector[2] * transformMaxtrix[3][2] +
                vector[3] * transformMaxtrix[3][3];
    return Point2D(point.x, point.y);
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

static int count = 0;
void drawEllipse(Point2D center, int x, int y, int color, bool half_dotted){
    //cho hien thi roi cho 5 lan goi
    putpixel(center.x - x, center.y + y, color);
    putpixel(center.x + x, center.y + y, color);
    //neu ve nua vong ellipse ben trong su dung '.'
    if (half_dotted)
    {
        //neu da du 6 pixel thi putpixel hien thi
        if(count==5)
        {
            putpixel(center.x - x, center.y - y, color);
            putpixel(center.x + x, center.y - y, color);
            //reset lai count
            count = 0;
        }
    }else //nguoc lai putpixel binh thuong
    {
        putpixel(center.x - x, center.y - y, color);
        putpixel(center.x + x, center.y - y, color);
    }
    count++;
}

void bresenhamEllipse(Point2D center, int a, int b, int color){
    float p, a2, b2;
    int x, y;

    a2 = a * a;
    b2 = b * b;
    //Nhanh 1
    x = 0; y = b;
    p = 2 * b2/a2 - 2*b + 1;
    while(((b2/a2)*(x/y)) < 1 )
    {
        drawEllipse(center, x, y, color);
        if(p < 0)
        {
            p = p + 2 * (b2 / a2) * (2*x + 3);
        }
        else
        {
            p = p - 4*y + 2*(b2/a2)*(2*x + 3);
            y = y - 1;
        }
        x = x + 1;
    }
    //Nhanh 2
    x = a; y = 0;
    p = 2 * (a2/b2) - 2*a + 1;
    while(((a2/b2)*(y/x)) <= 1 )
    {
        drawEllipse(center, x, y, color);
        if(p < 0)
        {
            p = p + 2 * (a2 / b2) * (2*y + 3);
        }
        else
        {
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
    while(((b2/a2)*(x/y)) < 1 )
    {
        drawEllipse(center, x, y, color);
        if(p < 0)
        {
            p = p + 2 * (b2 / a2) * (2*x + 3);
        }
        else
        {
            p = p - 4*y + 2*(b2/a2)*(2*x + 3);
            y = y - 1;
        }
        x = x + 1;
    }
}

void ellipseMidPoint(Point2D center, int a, int b, int color, bool half_dotted)
{
    count = 0;
    int a2 = a*a;
    int b2 = b*b;
    int twoa2 = 2 * a2;
    int twob2 = 2 * b2;
    int p;
    int x = 0;
    int y = b;
    int px = 0;
    int py = twoa2 * y;
    drawEllipse(center, x, y, color);
    /* Vung 1 */
    p = round(b2 - (a2*b) + (0.25) * a2);
    while(px < py){
        x++;
        px += twob2;
        if(p < 0){
            p += b2 + px;
        }else{
            y--;
            py -= twoa2;
            p += b2 + px - py;
        }
        drawEllipse(center, x, y, color, half_dotted);
    }
    /* For Region 2*/
    p = round(b2 * (x + 0.5)*(x + 0.5) + a2 * (y - 1)*(y - 1) - a2 * b2);
    while(y > 0){
        y--;
        py -= twoa2;
        if(p > 0){
            p += a2 - py;
        }else{
            x++;
            px += twob2;
            p += a2 - py + px;
        }
        drawEllipse(center, x, y, color, half_dotted);
    }
}
