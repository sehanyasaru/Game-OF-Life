#pragma once
#include "Grid.h"

class Process{

public:
    Process(int width,int height,int cellSize):grid(width,height,cellSize),temp(width,height,cellSize){
    grid.Rand();
    };
    void Draw();
    void setCellValue(int row,int column,int cellSize);
    int countNeighborsGPU(int row, int column);
    void update();
private :
    Grid grid;
    Grid temp;

};

