#include "../include/objects2d.h"
#include "../include/base.h"

int radius = 6, small_radius = 4, unit = 5;

void drawTrafficLight()
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
    bresenhamCircle(redLight, small_radius*unit, LIGHTRED);
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

    Point2D topRightUp (bottomRightUp.x, topLeftUp.y);
    bresenhamLine(topRightUp, topRight, WHITE);

    bresenhamLine(topRightUp, topLeftUp, WHITE);
    bresenhamLine(topRightUp, bottomRightUp, WHITE);

}

void ScaleTrafficLight(float sx, float sy, int light_number)
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
    //ve 2 ben le duong
    Point2D d1(pole_down.x - bottomLeft.x, pole_down.y - (pole_down.y - pole_top.y));
    Point2D d2(pole_down.x + bottomLeft.x, pole_down.y + (pole_down.y - pole_top.y));
    Point2D d3 = symmetryCompute(d1, 2);
    Point2D d4 = symmetryCompute(d2, 2);

    realToMachine(pole_down);
    realToMachine(pole_top);
    realToMachine(d1);
    realToMachine(d2);
    realToMachine(d3);
    realToMachine(d4);
    bresenhamLine(pole_down, pole_top, WHITE);
    bresenhamLine(d1, d2, WHITE);
    bresenhamLine(d3, d4, WHITE);
    //
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

    switch(light_number)
    {
        case 1:{
            realToMachine(redLight);
            bresenhamCircle(redLight, small_radius*unit*sx, LIGHTRED);
            setfillstyle(SOLID_FILL, LIGHTRED);
            floodfill(redLight.x, redLight.y, LIGHTRED);
            break;
        };
        case 2:{
            realToMachine(yellowLight);
            bresenhamCircle(yellowLight, small_radius*unit*sx, YELLOW);
            setfillstyle(SOLID_FILL, YELLOW);
            floodfill(yellowLight.x, yellowLight.y, YELLOW);
            break;
        };
        case 3:{
            realToMachine(greenLight);
            bresenhamCircle(greenLight, small_radius*unit*sx, GREEN);
            setfillstyle(SOLID_FILL, GREEN);
            floodfill(greenLight.x, greenLight.y, GREEN);
            break;
        };
        default: break;
    }
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
    //ve 2 ben le duong
    Point2D d1(pole_down.x - bottomLeft.x, pole_down.y - (pole_down.y - pole_top.y));
    Point2D d2(pole_down.x + bottomLeft.x, pole_down.y + (pole_down.y - pole_top.y));
    Point2D d3 = symmetryCompute(d1, 2);
    Point2D d4 = symmetryCompute(d2, 2);

    realToMachine(pole_down);
    realToMachine(pole_top);
    realToMachine(d1);
    realToMachine(d2);
    realToMachine(d3);
    realToMachine(d4);
    bresenhamLine(pole_down, pole_top, WHITE);
    bresenhamLine(d1, d2, WHITE);
    bresenhamLine(d3, d4, WHITE);
    //

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
    int alpha = 0;
    int time_to_change_mouth_shape = 2;
    while(alpha <= 360){
        Point2D faceEmoji (55, 20);//55, 28
        rotateCompute(faceEmoji,alpha);

        Point2D eyeLeftEmoji (faceEmoji.x - 5, faceEmoji.y + 5);
        Point2D eyesbrownLeftEmoji (eyeLeftEmoji.x, eyeLeftEmoji.y + 5);

        Point2D eyeRightEmoji (faceEmoji.x + 5, faceEmoji.y + 5);
        Point2D eyesbrownRightEmoji (eyeRightEmoji.x, eyeRightEmoji.y + 5);

        Point2D mouthEmoji (faceEmoji.x, faceEmoji.y - 5);


        //chuyen sang toa do may
        realToMachine(faceEmoji);
        realToMachine(eyeLeftEmoji);
        realToMachine(eyesbrownLeftEmoji);
        realToMachine(eyeRightEmoji);
        realToMachine(eyesbrownRightEmoji);
        realToMachine(mouthEmoji);

        //ve face
        ellipseMidPoint(faceEmoji, 14*unit, 14*unit,YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        floodfill(faceEmoji.x, faceEmoji.y, YELLOW);

        //mat trai, phai
        ellipseMidPoint(eyeLeftEmoji, 3*unit, 4*unit, BLACK);
        setfillstyle(SOLID_FILL, BLACK);
        floodfill(eyeLeftEmoji.x, eyeLeftEmoji.y, BLACK);

        ellipseMidPoint(eyeRightEmoji, 3*unit, 4*unit, BLACK);
        setfillstyle(SOLID_FILL, BLACK);
        floodfill(eyeRightEmoji.x, eyeRightEmoji.y, BLACK);

        if(time_to_change_mouth_shape==0)
        {
            ellipseMidPoint(mouthEmoji, 5*unit, 5*unit, BLACK);
            time_to_change_mouth_shape = 2;
        }
        else
            ellipseMidPoint(mouthEmoji, 4*unit, 7*unit, BLACK);
        setfillstyle(SOLID_FILL, BLACK);
        floodfill(mouthEmoji.x, mouthEmoji.y, BLACK);

        //chan may
        halfEllipseMidPoint(eyesbrownLeftEmoji, 3*unit, 1*unit,BLACK);
        setfillstyle(SOLID_FILL, BLACK);
        floodfill(eyesbrownLeftEmoji.x, eyesbrownLeftEmoji.y-2, BLACK);

        halfEllipseMidPoint(eyesbrownRightEmoji, 3*unit, 1*unit,BLACK);
        setfillstyle(SOLID_FILL, BLACK);
        floodfill(eyesbrownRightEmoji.x, eyesbrownRightEmoji.y-2, BLACK);

        //tang goc
        alpha = alpha + 10;
        time_to_change_mouth_shape--;
        delay(1000);

        setfillstyle(SOLID_FILL, BLACK);
        floodfill(faceEmoji.x, faceEmoji.y-15, BLACK);

        Point2D origin(0, 0);               //goc toa do
        realToMachine(origin);              //chuyen sang toa do thuc sang toa do may
        draw2DCoor(origin);
    }

}

void drawEmojiHaha()
{
    for(short truc = 0; truc <= 3; truc++)
    {
        Point2D faceEmoji (55, 20);//55, 28
        Point2D mouthEmoji (faceEmoji);
        Point2D tongueEmoji(mouthEmoji.x, mouthEmoji.y - 4.1);

        Point2D leftEyeEmoji(faceEmoji.x - 4, faceEmoji.y + 4);
        Point2D leftUpEyeEmoji(faceEmoji.x - 6, faceEmoji.y + 6);
        Point2D leftDownEyeEmoji(faceEmoji.x - 6, faceEmoji.y + 2);
        Point2D rightEyeEmoji(faceEmoji.x + 4, faceEmoji.y + 4);
        Point2D rightUpEyeEmoji(faceEmoji.x + 6, faceEmoji.y + 6);
        Point2D rightDownEyeEmoji(faceEmoji.x + 6, faceEmoji.y + 2);

        if(truc != 3)
        {
            //doi xung truc x//
            faceEmoji = symmetryCompute(faceEmoji, truc);
            mouthEmoji = symmetryCompute(mouthEmoji, truc);
            tongueEmoji = symmetryCompute(tongueEmoji, truc);
            leftEyeEmoji = symmetryCompute(leftEyeEmoji, truc);
            leftUpEyeEmoji = symmetryCompute(leftUpEyeEmoji, truc);
            leftDownEyeEmoji = symmetryCompute(leftDownEyeEmoji, truc);
            rightEyeEmoji = symmetryCompute(rightEyeEmoji, truc);
            rightUpEyeEmoji = symmetryCompute(rightUpEyeEmoji, truc);
            rightDownEyeEmoji = symmetryCompute(rightDownEyeEmoji, truc);
        }

        //chuyen sang toa do may
        realToMachine(faceEmoji);
        realToMachine(mouthEmoji);
        realToMachine(tongueEmoji);
        realToMachine(leftEyeEmoji);
        realToMachine(leftUpEyeEmoji);
        realToMachine(leftDownEyeEmoji);
        realToMachine(rightEyeEmoji);
        realToMachine(rightUpEyeEmoji);
        realToMachine(rightDownEyeEmoji);
        /*ve face*/
        bresenhamCircle(faceEmoji, 10*unit, YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        floodfill(faceEmoji.x, faceEmoji.y, YELLOW);
        /*ve eye*/
        bresenhamLine(leftEyeEmoji, leftUpEyeEmoji, BLACK);
        bresenhamLine(leftEyeEmoji, leftDownEyeEmoji, BLACK);
        bresenhamLine(rightEyeEmoji, rightUpEyeEmoji, BLACK);
        bresenhamLine(rightEyeEmoji, rightDownEyeEmoji, BLACK);
        /*ve mieng*/
        if(truc == 1 || truc == 0)
        {
            halfEllipseMidPoint(mouthEmoji, 6*unit, 6*unit, BLACK, true, true);
            setfillstyle(SOLID_FILL, BLACK);
            floodfill(mouthEmoji.x, mouthEmoji.y-2, BLACK);
        }
        else
        {
            halfEllipseMidPoint(mouthEmoji, 6*unit, 6*unit, BLACK, true, false);
            setfillstyle(SOLID_FILL, BLACK);
            floodfill(mouthEmoji.x, mouthEmoji.y+2, BLACK);
        }
        /*ve luoi*/
        ellipseMidPoint(tongueEmoji, 4.3*unit, 1.8*unit, LIGHTRED);
        setfillstyle(SOLID_FILL, LIGHTRED);
        floodfill(tongueEmoji.x, tongueEmoji.y, LIGHTRED);
    }
}
