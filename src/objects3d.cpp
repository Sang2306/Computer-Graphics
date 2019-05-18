#include "../include/objects3d.h"
#include "../include/base.h"
#include <cmath>
void drawCube(int ox, int oy, int oz)
{
    Point3D O_3D(12, -12, 30);
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
    /*Point2D A(ox, 0);
    realToMachine(A);
    bresenhamLine(O, A, WHITE, false);

    Point2D F(dai, cao);
    realToMachine(F);
    bresenhamLine(F, A, WHITE, true);

    Point2D E(0, cao);
    realToMachine(E);
    bresenhamLine(O, E, WHITE, false);

    bresenhamLine(E, F, WHITE, true);

    Point2D C = getPointOz(rong);
    bresenhamLine(O, C, WHITE, false);

    Point2D B(midX + dai*5*cos(45), midY + rong*5*sin(80));
    bresenhamLine(B, A, WHITE);

    bresenhamLine(B, C, WHITE);

    Point2D D(midX - rong*5*cos(45), midY - cao*5*cos(80));
    bresenhamLine(D, E, WHITE);

    bresenhamLine(D, C, WHITE);

    Point2D G(midX + dai*5*cos(45), midY - rong*5*cos(80));
    bresenhamLine(G, F, WHITE, true);

    bresenhamLine(G, B, WHITE, true);

    bresenhamLine(G, D, WHITE, true);
    */
}
