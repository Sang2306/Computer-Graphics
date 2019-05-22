#include "../include/objects2d.h"
#include "../include/base.h"

int radius = 6, small_radius = 4, unit = 5;

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

    //ve tru de giao thong
    Point2D pole_top((topLeft.x + bottomRight.x)/2, bottomRight.y);
    Point2D pole_down((topLeft.x + bottomRight.x)/2, bottomRight.y + (bottomRight.y - topLeft.y));
    realToMachine(pole_down);
    realToMachine(pole_top);
    bresenhamLine(pole_down, pole_top, WHITE);

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
    bresenhamCircle(redLight, small_radius*unit, RED);
    setfillstyle(SOLID_FILL, LIGHTRED);
    floodfill(redLight.x, redLight.y, LIGHTRED);

    realToMachine(yellowLight);
    bresenhamCircle(yellowLight, small_radius*unit, YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(yellowLight.x, yellowLight.y, YELLOW);

    realToMachine(greenLight);
    bresenhamCircle(greenLight, small_radius*unit, GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(greenLight.x, greenLight.y, GREEN);
}

void ScaleTrafficLight(float sx, float sy)
{
    Point2D topLeft (45, 50);
    Point2D bottomRight (65, 20);
    Point2D bottomLeft(topLeft.x, bottomRight.y);
    Point2D topRight(bottomRight.x, topLeft.y);

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
    //ve tru de giao thong
    Point2D pole_top((topLeft.x + bottomRight.x)/2, bottomRight.y);
    Point2D pole_down((topLeft.x + bottomRight.x)/2, bottomRight.y + (bottomRight.y - topLeft.y));
    realToMachine(pole_down);
    realToMachine(pole_top);
    bresenhamLine(pole_down, pole_top, WHITE);

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

    realToMachine(redLight);
    bresenhamCircle(redLight, small_radius*unit*sx, LIGHTRED);
    setfillstyle(SOLID_FILL, LIGHTRED);
    floodfill(redLight.x, redLight.y, LIGHTRED);

    realToMachine(yellowLight);
    bresenhamCircle(yellowLight, small_radius*unit*sx, YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(yellowLight.x, yellowLight.y, YELLOW);

    realToMachine(greenLight);
    bresenhamCircle(greenLight, small_radius*unit*sx, GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(greenLight.x, greenLight.y, GREEN);

    Point2D topRightUp (bottomRightUp.x, topLeftUp.y);
    bresenhamLine(topRightUp, topRight, WHITE);

    bresenhamLine(topRightUp, topLeftUp, WHITE);
    bresenhamLine(topRightUp, bottomRightUp, WHITE);
}

void translateTrafficLight(float tr_x, float tr_y, int light_number)
{
    Point2D topLeft (45, 50);
    Point2D bottomRight (65, 20);

    Point2D bottomLeft(topLeft.x, bottomRight.y); //(45, 20)
    Point2D topRight(bottomRight.x, topLeft.y); //(65, 50)
    Point2D bottomRightUp (bottomRight.x + 4, bottomRight.y + 4);
    Point2D topLeftUp (topLeft.x + 4, topLeft.y + 4);

    Point2D light ((topLeft.x + topRight.x)/2, ((topLeft.y + bottomLeft.y)/2 + topLeft.y)/2);

    //ve tru de giao thong
    Point2D pole_top((topLeft.x + bottomRight.x)/2, bottomRight.y);
    Point2D pole_down((topLeft.x + bottomRight.x)/2, bottomRight.y + (bottomRight.y - topLeft.y));
    realToMachine(pole_down);
    realToMachine(pole_top);
    bresenhamLine(pole_down, pole_top, WHITE);

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
    //thuc hien phep tinh tien den giao thong
    realToMachine(light);
    switch(light_number)
    {
        case 1:{
            //den do
            bresenhamCircle(light, radius*unit, LIGHTRED);
            setfillstyle(SOLID_FILL, LIGHTRED);
            floodfill(light.x, light.y, LIGHTRED);
            delay(1000);
            setfillstyle(SOLID_FILL, BLACK);
            floodfill(light.x, light.y, BLACK);
            break;
        }
        case 2:{
            //den vang
            translateCompute(light, tr_x*unit, tr_y*unit);
            bresenhamCircle(light, radius*unit, YELLOW);
            setfillstyle(SOLID_FILL, YELLOW);
            floodfill(light.x, light.y, YELLOW);
            delay(1000);
            setfillstyle(SOLID_FILL, BLACK);
            floodfill(light.x, light.y, BLACK);
            break;
        }
        case 3:{
            //den xanh
            translateCompute(light, tr_x*unit*2, tr_y*unit*2);
            bresenhamCircle(light, radius*unit, GREEN);
            setfillstyle(SOLID_FILL, GREEN);
            floodfill(light.x, light.y, GREEN);
            delay(1000);
            setfillstyle(SOLID_FILL, BLACK);
            floodfill(light.x, light.y, BLACK);
            break;
        }
        default:break;
    }

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
