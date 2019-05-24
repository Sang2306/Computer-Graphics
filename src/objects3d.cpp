#include "../include/objects3d.h"
#include <cmath>
#include <iomanip>
/*ox: dai, oy: cao, oz: rong*/
void drawCube(Point3D origin, int ox, int oy, int oz)
{
    Point3D O_3D(origin);
    //Thiet lap cac diem trong 3D
    Point3D A_3D(ox + O_3D.x, 0 + O_3D.y, 0 + O_3D.z);
    Point3D B_3D(ox + O_3D.x, 0 + O_3D.y, oz + O_3D.z);
    Point3D C_3D(0 + O_3D.x, 0 + O_3D.y, oz + O_3D.z);
    Point3D D_3D(0 + O_3D.x, oy + O_3D.y, 0 + O_3D.z);
    Point3D E_3D(ox + O_3D.x, oy + O_3D.y, 0 + O_3D.z);
    Point3D F_3D(ox + O_3D.x, oy + O_3D.y, oz + O_3D.z);
    Point3D G_3D(0 + O_3D.x, oy + O_3D.y, oz + O_3D.z);
    //chuyen doi sang toa do 2D
    Point2D O_2D = transformTo2D(O_3D);
    Point2D A_2D = transformTo2D(A_3D);
    Point2D B_2D = transformTo2D(B_3D);
    Point2D C_2D = transformTo2D(C_3D);
    Point2D D_2D = transformTo2D(D_3D);
    Point2D E_2D = transformTo2D(E_3D);
    Point2D F_2D = transformTo2D(F_3D);
    Point2D G_2D = transformTo2D(G_3D);
    //hien thi thong tin doi tuong
    bgiout << "O(" << std::setprecision(3) << O_2D.x << ", " << O_2D.y << ")";
    outstreamxy(20, 20);
    bgiout << "A(" << std::setprecision(3) << A_2D.x << ", " << A_2D.y << ")";
    outstreamxy(20, 40);
    bgiout << "B(" << std::setprecision(3) << B_2D.x << ", " << B_2D.y << ")";
    outstreamxy(20, 60);
    bgiout << "C(" << std::setprecision(3) << C_2D.x << ", " << C_2D.y << ")";
    outstreamxy(20, 80);
    bgiout << "D(" << std::setprecision(3) << D_2D.x << ", " << D_2D.y << ")";
    outstreamxy(20, 100);
    bgiout << "E(" << std::setprecision(3) << E_2D.x << ", " << E_2D.y << ")";
    outstreamxy(20, 120);
    bgiout << "F(" << std::setprecision(3) << F_2D.x << ", " << F_2D.y << ")";
    outstreamxy(20, 140);
    bgiout << "G(" << std::setprecision(3) << G_2D.x << ", " << G_2D.y << ")";
    outstreamxy(20, 160);
    //Chuyen sang toa do may
    realToMachine(O_2D); outtextxy(O_2D.x, O_2D.y, "O");
    realToMachine(A_2D); outtextxy(A_2D.x, A_2D.y, "A");
    realToMachine(B_2D); outtextxy(B_2D.x, B_2D.y, "B");
    realToMachine(C_2D); outtextxy(C_2D.x, C_2D.y, "C");
    realToMachine(D_2D); outtextxy(D_2D.x, D_2D.y, "D");
    realToMachine(E_2D); outtextxy(E_2D.x, E_2D.y, "E");
    realToMachine(F_2D); outtextxy(F_2D.x, F_2D.y, "F");
    realToMachine(G_2D); outtextxy(G_2D.x, G_2D.y, "G");
    //hien thi cac diem tren man hinh
    bresenhamLine(O_2D, A_2D, YELLOW, false);
    bresenhamLine(A_2D, B_2D, YELLOW);
    bresenhamLine(B_2D, C_2D, YELLOW);
    bresenhamLine(C_2D, O_2D, YELLOW, false);

    bresenhamLine(D_2D, E_2D, YELLOW);
    bresenhamLine(E_2D, F_2D, YELLOW);
    bresenhamLine(F_2D, G_2D, YELLOW);
    bresenhamLine(G_2D, D_2D, YELLOW);

    bresenhamLine(A_2D, E_2D, YELLOW);
    bresenhamLine(B_2D, F_2D, YELLOW);
    bresenhamLine(C_2D, G_2D, YELLOW);
    bresenhamLine(O_2D, D_2D, YELLOW, false);
}
/*ox: dai, oy: cao, oz: rong*/
void drawCylinder(Point3D origin, int r, int cao)
{
    Point3D O_3D_below(origin);
    int a, b, unit = 5;
    a = (r + O_3D_below.x)*unit;
    b = a;
    //Mat duoi
    Point2D O_2D_below = transformTo2D(O_3D_below);
    bgiout << "O " << std::setprecision(3) << O_2D_below.x << ", " << O_2D_below.y;

    realToMachine(O_2D_below);
    ellipseMidPoint(O_2D_below, a, b, YELLOW, true);

    outstreamxy(O_2D_below.x, O_2D_below.y);
    //Mat tren
    Point3D O_3D_above(O_3D_below.x, cao, O_3D_below.z);

    Point2D O_2D_above = transformTo2D(O_3D_above);
    bgiout << "O' " << std::setprecision(3) << O_2D_above.x << ", " << O_2D_above.y;

    realToMachine(O_2D_above);
    ellipseMidPoint(O_2D_above, a, b, YELLOW);

    outstreamxy(O_2D_above.x, O_2D_above.y);
    //ket noi hai mat
    int left_x_below = O_2D_below.x - a;
    int right_x_below = O_2D_below.x + a;
    int y_below = O_2D_below.y;

    int left_x_above = O_2D_above.x - a;
    int right_x_above = O_2D_above.x + a;
    int y_above = O_2D_above.y;

    Point2D p1 = Point2D(left_x_below, y_below);
    Point2D p2 = Point2D(left_x_above, y_above);
    bresenhamLine(p1, p2, YELLOW);

    Point2D p3 = Point2D(right_x_below, y_below);
    Point2D p4 = Point2D(right_x_above, y_above);
    bresenhamLine(p3, p4, YELLOW);
}
