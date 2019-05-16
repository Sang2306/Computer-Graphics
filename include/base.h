#ifndef BASE_H
#define BASE_H
#include <graphics.h>
#define PI 3.141592654

class Point2D{
    public:
        float x, y, h;
        Point2D(){
            x = y = h = -1;
        }
        Point2D(float x, float y){
            this->x = x;
            this->y = y;
            this->h = 1;
        }

};

const int width = 1080, height = 600;
const float midX = width/2;
const float midY = height/2;
/*he toa do 2D va 3D*/
void draw2DCoor(const Point2D& mid);
void draw3DCoor();
Point2D getPointOz(int unit);

/*chuyen toa do the gioi thuc ve toa do may tinh*/
void realToMachine(Point2D& point);

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
