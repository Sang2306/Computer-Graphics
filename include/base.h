#ifndef BASE_H
#define BASE_H
#include <graphics.h>
#define PI 3.141592654

class Point2D
{
    public:
        float x, y, h;
        Point2D()
        {
            x = y = h = -1;
        }
        Point2D(float x, float y)
        {
            this->x = x;
            this->y = y;
            this->h = 1;
        }

};

class Point3D : public Point2D
{
    public:
        float z;
        Point3D(): Point2D(), z(0){}
        Point3D(float x, float y, float z) : Point2D(x, y), z(z){}
};

const int width = 1080, height = 720;
const float midX = width/2;
const float midY = height/2;
/* put diem tren man hinh */
void putpoint(const Point2D& point, int color = WHITE);
/*he toa do 2D va 3D*/
void draw2DCoor(const Point2D& mid);
void draw3DCoor();

/*chuyen toa do the gioi thuc ve toa do may tinh*/
void realToMachine(Point2D& point);
Point2D transformTo2D(Point3D& point);
/*Thuc hien cac phep bien doi cho diem*/
void translateCompute(Point2D& point, float tr_x, float tr_y);
void scaleCompute(Point2D& point, float sx, float sy);
void rotateCompute(Point2D& point, float alpha);

/*ham ve duong thang va duong tron*/
void bresenhamLine(Point2D p1, Point2D p2, int color, bool solid=true);
/*Put cac pixel trong circle*/
void drawCircle(Point2D center, int x, int y, int color);
void bresenhamCircle(Point2D center, float radius, int color);
/*Put cac pixel trong ellipse*/
void drawEllipse(Point2D center, int x, int y, int color, bool half_dotted = false); /*half_dotted : nua trong ellipse bi "...." */
void drawHalfEllipse(Point2D center, int x, int y, int color, bool half_above = true); /*Put pixel nua tren hay nua duoi cua ellipse*/
/*ham ve duong ellipse su dung thuat toan mid point*/
void halfEllipseMidPoint(Point2D center, int a, int b, int color, bool have_line = true, bool half_above = true);
void ellipseMidPoint(Point2D center, int a, int b, int color, bool half_dotted = false);
#endif // BASE_H
