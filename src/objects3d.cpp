#include "../include/objects3d.h"
#include "../include/base.h"
#include <cmath>
void veHinhHop(int dai, int rong, int cao)
{
    Point2D O(0, 0);
    realToMachine(O);

    Point2D A(dai, 0);
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

    Point2D B(midX + dai*5*cos(45), midY + rong*5*sin(45));

    bresenhamLine(B, A, WHITE);

    bresenhamLine(B, C, WHITE);

    Point2D D(midX - rong*5*cos(45), midY - cao*5*cos(80));

    bresenhamLine(D, E, WHITE);

    bresenhamLine(D, C, WHITE);

    Point2D G(midX + dai*5*cos(45), midY - rong*5*cos(80));

    bresenhamLine(G, F, WHITE, true);

    bresenhamLine(G, B, WHITE, true);

    bresenhamLine(G, D, WHITE, true);
}
