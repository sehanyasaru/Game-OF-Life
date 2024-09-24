#include "Grid.h"
#include<raylib.h>

void Grid::Draw(){
for(int i=0;i<rows;i++){

    for(int j=0;j<columns;j++){
        Color color=cells[i][j]?Color{0,255,0,255}:Color{55,55,55,255};
        DrawRectangle(j*cellSize,i*cellSize,cellSize-1,cellSize-1,color);
    }
}

}
void Grid::setCellValue(int row,int column,int val){
if(row>0&&row<rows&&column>0&&column<columns){
    cells[row][column]=val;
}


}
int Grid::getValue(int row,int column){
if(row>0&&row<rows&&column>0&&column<columns){
   return  cells[row][column];
}

}
void Grid::Rand(){
for(int i=0;i<rows;i++){
    for(int j=0;j<columns;j++){
       int randval=GetRandomValue(0,4);
        cells[i][j]=(randval==4)?1:0;
    }
}

}
/*void Grid::Draw(){

for(int i=0;i<rows;i++){

    for(int j=0;j<columns;j++){
        Color color=cells[i][j]?Color{0,255,0,255}:Color{55,55,55,255};
        DrawRectangle(j*cellSize,i*cellSize,cellSize-1,cellSize-1,color);

    }
}

}
void Grid:: SetValue(int row,int column, int value){

 if(row>=0&&row<rows&&column>=0&& column<columns){

    cells[row][column]=value;
 }
}
int Grid::GetValue(int row, int column){
 if(row>=0&&row<rows&&column>=0&& column<columns){
         return cells[row][column];

}
return 0;
}
void Grid:: rand(){
for(int i=0;i<rows;i++){

   for(int j=0;j<columns;j++){
       int randval=GetRandomValue(0,4);
        cells[i][j]=(randval==4)?1:0;

   }
}*/



