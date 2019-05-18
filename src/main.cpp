#include <iostream>
#include <cstdio>
#include <graphics.h>
#include "../include/base.h"
#include "../include/consolelib.h"
#include "../include/objects2d.h"
#include "../include/objects3d.h"
void initMenuWindow(); //Menu hien thi tuy chon va hien thi thong tin cua doi tuong
void chooseCoorSystem();
void chooseObject2Draw();
//////////////////////////////////////MAIN FUNC////////////////////////////////////////////////////
int main(int argc, char* argv[]){
    initwindow(width, height, "KYTHUATDOHOA");
    initMenuWindow();
    getch();
    closegraph();
    return EXIT_SUCCESS;
}
//////////////////////////////////////END MAIN////////////////////////////////////////////////////
//////////////////////////////////////START BASIC FUNCTION////////////////////////////////////////
void initMenuWindow()
{
    int width, height;
    GetWindowSize(width, height);
    //Separate main menu from information pannel
    for(int y = 0; y < height; y++)
        Print_at(width/2, y, (char)124);
    Print_at(width/2, 0, "< THONG TIN >");
    chooseCoorSystem();
}

void chooseCoorSystem()
{
    again:
    Print_at(0, 0, "---CHON HE TOA DO---");
    Print_at(5, 1, "1: 2D");
    Print_at(5, 2, "2: 3D");
    Print_at(0, 3, ">>>");
    short choice;
    std::cin >> choice;
    if(choice != 1 && choice !=2)
    {
        Clear_at(0, 0, 20, 20);
        goto again;
    }
    if(choice == 1)
    {
        cleardevice();
        Point2D origin(0, 0);               //goc toa do
        realToMachine(origin);              //chuyen sang toa do thuc sang toa do may
        draw2DCoor(origin);
        chooseObject2Draw();                //Menu hien thi chon do vat 2d de ve
    }
    else if (choice == 2)
    {
        cleardevice();
        draw3DCoor();
        drawCube(50, 50, 50);
    }
}

void chooseObject2Draw()
{
    again:
    Clear_at(0, 0, 20, 20);
    Print_at(0, 0, "---CHON VAT THE DE VE 2D---");
    Print_at(5, 1, "1: TRAFFIC LIGHTS");
    Print_at(5, 2, "2: EMOJI");
    Print_at(5, 3, "3: ...");
    Print_at(0, 4, ">>>");
    short choice;
    std::cin >> choice;
    if(choice != 1 && choice !=2 && choice !=3)
    {
        Clear_at(0, 0, 20, 20);
        goto again;
    }
    switch(choice)
    {
        case 1: {
                drawTrafficLight();
                break;
            }
        case 2: {
                drawEmojiWow();
                break;
            }
        case 3: {
            Clear_at(0, 0, 20, 20);
            return chooseCoorSystem();
        }
    }
}
