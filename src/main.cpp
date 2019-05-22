#include <iostream>
#include <cstdio>
#include <graphics.h>
#include "../include/base.h"
#include "../include/consolelib.h"
#include "../include/objects2d.h"
#include "../include/objects3d.h"
int chooseCoorSystem();
void chooseObject2Draw();
void chooseObject3Draw();
//////////////////////////////////////MAIN FUNC////////////////////////////////////////////////////
int main(int argc, char* argv[]){
    initwindow(width, height, "KY THUAT DO HOA");
    while(true)
    {
        if (chooseCoorSystem()==-1)
            break;
        Clear_at(0, 0, 60, 40);
    }
    closegraph();
    return EXIT_SUCCESS;
}
//////////////////////////////////////END MAIN////////////////////////////////////////////////////
//////////////////////////////////////START BASIC FUNCTION////////////////////////////////////////
int chooseCoorSystem()
{
    again:
    Print_at(0, 0, "---CHON HE TOA DO---");
    Print_at(5, 1, "1: 2D");
    Print_at(5, 2, "2: 3D");
    Print_at(5, 3, "3: Thoat");
    Print_at(0, 4, ">>>");
    short choice;
    std::cin >> choice;
    if(choice != 1 && choice !=2 && choice != 3)
    {
        Clear_at(0, 0, 60, 40);
        goto again;
    }
    clearviewport();
    if(choice == 1)
    {
        Point2D origin(0, 0);               //goc toa do
        realToMachine(origin);              //chuyen sang toa do thuc sang toa do may
        draw2DCoor(origin);
        chooseObject2Draw();                //Menu hien thi chon do vat 2d de ve
        return 0;
    }
    else if (choice == 2)
    {
        draw3DCoor();
        chooseObject3Draw();
        return 0;
    }
    return -1;
}

void chooseObject2Draw()
{
    again:
    Clear_at(0, 0, 60, 40);
    Print_at(0, 0, "---CHON VAT THE DE VE 2D---");
    Print_at(5, 1, "1: TRAFFIC LIGHTS");
    Print_at(5, 2, "2: EMOJI");
    Print_at(5, 3, "3: SCALED TRAFFIC LIGHTS");
    Print_at(5, 4, "4: TRANSLATE TRAFFIC LIGHTS");
    Print_at(0, 6, ">>>");
    short choice;
    std::cin >> choice;
    switch(choice)
    {
        case 1:{
            drawTrafficLight();
            break;
        }
        case 2: {
            drawEmojiWow();
            break;
        }
        case 3: {
            //tao hieu ung chuyen dong
            float sx = 0.1, sy = 0.1;
            while(true)
            {
                ScaleTrafficLight(sx, sy);
                sx = sx > 1.2 ? 0.1 : sx + 0.1;
                sy = sy > 1.2 ? 0.1 : sy + 0.1;
                delay(300);
                clearviewport();
                Point2D origin(0, 0);               //goc toa do
                realToMachine(origin);              //chuyen sang toa do thuc sang toa do may
                draw2DCoor(origin);
            }
            break;
        }
        case 4:{
            int light_number = 1;
            while(true)
            {
                translateTrafficLight(0, 7, light_number);
                light_number++;
                light_number = light_number == 4 ? 1 : light_number;
            }
            break;
        }
        default:{
            Clear_at(0, 0, 60, 40);
            goto again;
        }
    }
}

void chooseObject3Draw()
{
    again:
    Clear_at(0, 0, 60, 40);
    Print_at(0, 0, "---CHON VAT THE DE VE 3D---");
    Print_at(5, 1, "1: Hinh hop(cube)");
    Print_at(5, 2, "2: Hinh tru tron(cylinder)");
    Print_at(0, 4, ">>>");
    short choice;
    std::cin >> choice;
    if(choice != 1 && choice !=2)
    {
        Clear_at(0, 0, 60, 40);
        goto again;
    }
    Print_at(0, 4, "Nhap toa do diem goc(0 0 0): ");
    Point3D origin;
    std::cin >> origin.x >> origin.y >> origin.z;
    Print_at(0, 5, "Nhap vao dai, cao, rong(15 30 10): ");
    int dai, cao, rong;
    std::cin >> dai >> cao >> rong;
    switch(choice)
    {
        case 1: {
                drawCube(origin, dai, cao, rong);
                break;
            }
        case 2: {
                drawCylinder(origin, dai, cao, rong);
                break;
            }
        default: break;
    }
}
