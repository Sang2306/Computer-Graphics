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

const int width = 1080, height = 700;
const float midX = width/2;
const float midY = height/2;
/* put diem tren man hinh */
void putpoint(const Point2D& point, int color = WHITE);
/*he toa do 2D va 3D*/
void draw2DCoor(const Point2D& mid);
void draw3DCoor();
/*Ham nay se bi loai bo trong cac phien ban tiep theo*/
Point2D getPointOz(int unit_num);

/*chuyen toa do the gioi thuc ve toa do may tinh*/
void realToMachine(Point2D& point);
Point2D transformTo2D(Point3D& point);
/*Thuc hien cac phep bien doi cho diem*/
void translateCompute(Point2D& point, float tr_x, float tr_y);
void scaleCompute(Point2D& point, float sx, float sy);
void rotateCompute(Point2D& point, float alpha);

/*ham ve duong thang va duong tron*/
void bresenhamLine(Point2D p1, Point2D p2, int color, bool solid=true);
void drawCircle(Point2D center, int x, int y, int color);
void bresenhamCircle(Point2D center, float radius, int color);
void drawEllipse(Point2D center, int x, int y, int color);
void haftBresenhamEllipse(Point2D center, int a, int b, int color);
void bresenhamEllipse(Point2D center, int a, int b, int color);

#endif // BASE_H
