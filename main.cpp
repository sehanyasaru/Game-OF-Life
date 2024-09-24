#include<iostream>
#include<raylib.h>
#include "Grid.h"

using namespace std;
int main(){

Color GREY ={29,29,29,255};

const int WIN_WIDTH=750;
const int WIN_HEIGHT=750;
const int CELL_SIZE=25;
int fps=12;

InitWindow(WIN_HEIGHT,WIN_WIDTH,"game of Life");
SetTargetFPS(fps);

Process process{WIN_WIDTH,WIN_HEIGHT,CELL_SIZE};

while(WindowShouldClose()==false){
    process.update();
    BeginDrawing();
    ClearBackground(GREY);
    process.Draw();
    EndDrawing();
}
CloseWindow();

}
