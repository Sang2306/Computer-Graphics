#include "../include/objects2d.h"
#include "../include/base.h"
void drawTrafficLight()
{
    Point2D topLeft (45, 50);
    Point2D bottomRight (65, 20);

    Point2D bottomLeft(topLeft.x, bottomRight.y); //(45, 20)
    Point2D topRight(bottomRight.x, topLeft.y); //(65, 50)

    Point2D bottomRightUp (bottomRight.x + 4, bottomRight.y + 4);
    Point2D topLeftUp (topLeft.x + 4, topLeft.y + 4);

    Point2D yellowLight ((topLeft.x + topRight.x)/2, (topLeft.y + bottomLeft.y)/2);
    Point2D greenLight ((topLeft.x + topRight.x)/2, ((topLeft.y + bottomLeft.y)/2 + bottomLeft.y)/2);
    Point2D redLight ((topLeft.x + topRight.x)/2, ((topLeft.y + bottomLeft.y)/2 + topLeft.y)/2);

    realToMachine(topLeft);
    realToMachine(bottomRight);
    realToMachine(bottomLeft);
    realToMachine(topRight);

    bresenhamLine(topLeft, topRight, WHITE);
    bresenhamLine(bottomRight, topRight, WHITE);
    bresenhamLine(bottomLeft, bottomRight, WHITE);
    bresenhamLine(topLeft, bottomLeft, WHITE);

    realToMachine(topLeftUp);
    bresenhamLine(topLeftUp, topLeft, WHITE);

    realToMachine(bottomRightUp);
    bresenhamLine(bottomRightUp, bottomRight, WHITE);

    Point2D topRightUp (bottomRightUp.x, topLeftUp.y);
    bresenhamLine(topRightUp, topRight, WHITE);

    bresenhamLine(topRightUp, topLeftUp, WHITE);
    bresenhamLine(topRightUp, bottomRightUp, WHITE);

    realToMachine(redLight);
    bresenhamCircle(redLight, 3*5, WHITE);
    setfillstyle(SOLID_FILL, LIGHTRED);
    floodfill(redLight.x, redLight.y, WHITE);

    realToMachine(yellowLight);
    bresenhamCircle(yellowLight, 3*5, WHITE);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(yellowLight.x, yellowLight.y, WHITE);

    realToMachine(greenLight);
    bresenhamCircle(greenLight, 3*5, WHITE);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(greenLight.x, greenLight.y, WHITE);
}

void drawEmojiWow(){
    Point2D faceEmoji (55, 28);
    realToMachine(faceEmoji);
    ellipseMidPoint(faceEmoji,70,100,WHITE);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(faceEmoji.x, faceEmoji.y, WHITE);

    Point2D eyeLeftEmoji (48, 34);
    realToMachine(eyeLeftEmoji);
    ellipseMidPoint(eyeLeftEmoji,12,20,WHITE);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(eyeLeftEmoji.x, eyeLeftEmoji.y, WHITE);

    Point2D eyeRightEmoji (63, 34);
    realToMachine(eyeRightEmoji);
    ellipseMidPoint(eyeRightEmoji,12,20,WHITE);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(eyeRightEmoji.x, eyeRightEmoji.y, WHITE);

    Point2D mouthEmoji (55, 18);
    realToMachine(mouthEmoji);
    ellipseMidPoint(mouthEmoji,25,45,WHITE);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(mouthEmoji.x, mouthEmoji.y, WHITE);


    Point2D eyesbrownLeftEmoji (48, 35);
    realToMachine(eyesbrownLeftEmoji);
    halfEllipseMidPoint(eyesbrownLeftEmoji,12,25,BLACK);

    Point2D eyesbrownRightEmoji (63, 35);
    realToMachine(eyesbrownRightEmoji);
    halfEllipseMidPoint(eyesbrownRightEmoji,12,25,BLACK);
}

void ScaleTrafficLight(float sx, float sy)
{
    Point2D topLeft (45, 50);
    Point2D bottomRight (65, 20);

    Point2D bottomLeft(topLeft.x, bottomRight.y); //(45, 20)
    Point2D topRight(bottomRight.x, topLeft.y); //(65, 50)

    Point2D bottomRightUp (bottomRight.x + 4, bottomRight.y + 4);
    Point2D topLeftUp (topLeft.x + 4, topLeft.y + 4);

    Point2D yellowLight ((topLeft.x + topRight.x)/2, (topLeft.y + bottomLeft.y)/2);
    Point2D greenLight ((topLeft.x + topRight.x)/2, ((topLeft.y + bottomLeft.y)/2 + bottomLeft.y)/2);
    Point2D redLight ((topLeft.x + topRight.x)/2, ((topLeft.y + bottomLeft.y)/2 + topLeft.y)/2);

    scaleCompute(topLeft, sx, sy);
    scaleCompute(bottomRight, sx, sy);
    scaleCompute(bottomLeft, sx, sy);
    scaleCompute(topRight, sx, sy);
    scaleCompute(bottomRightUp, sx, sy);
    scaleCompute(topLeftUp, sx, sy);
    scaleCompute(yellowLight, sx, sy);
    scaleCompute(greenLight, sx, sy);
    scaleCompute(redLight, sx, sy);

    realToMachine(topLeft);
    realToMachine(bottomRight);
    realToMachine(bottomLeft);
    realToMachine(topRight);

    bresenhamLine(topLeft, topRight, WHITE);
    bresenhamLine(bottomRight, topRight, WHITE);
    bresenhamLine(bottomLeft, bottomRight, WHITE);
    bresenhamLine(topLeft, bottomLeft, WHITE);

    realToMachine(topLeftUp);
    bresenhamLine(topLeftUp, topLeft, WHITE);

    realToMachine(bottomRightUp);
    bresenhamLine(bottomRightUp, bottomRight, WHITE);

    Point2D topRightUp (bottomRightUp.x, topLeftUp.y);
    bresenhamLine(topRightUp, topRight, WHITE);

    bresenhamLine(topRightUp, topLeftUp, WHITE);
    bresenhamLine(topRightUp, bottomRightUp, WHITE);

    realToMachine(redLight);
    bresenhamCircle(redLight, 3*5*sx, WHITE);
    setfillstyle(SOLID_FILL, LIGHTRED);
    floodfill(redLight.x, redLight.y, WHITE);

    realToMachine(yellowLight);
    bresenhamCircle(yellowLight, 3*5*sx, WHITE);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(yellowLight.x, yellowLight.y, WHITE);

    realToMachine(greenLight);
    bresenhamCircle(greenLight, 3*5*sx, WHITE);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(greenLight.x, greenLight.y, WHITE);
}
