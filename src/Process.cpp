#include "Process.h"
#include<utility>
#include<vector>


void Process::Draw(){
grid.Draw();

}
void Process::setCellValue(int row,int column,int cellSize){

grid.setCellValue(row,column,cellSize);

}


__global__ void CountNeighbors(int value,int *output){

atomicAdd(output,value);
}

int Process::countNeighborsGPU(int row, int column) {

    int* d_output;
    int liveneighbors=0;
std::vector<std::pair<int,int>> neighbors = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
    {-1, -1},
    {-1, 1},
    {1, -1},
    {1, 1}
};
    cudaMalloc(&d_output, sizeof(int));
    cudaMemset(d_output, 0, sizeof(int));

    for(const auto& offset:neighbors){
    int liverow=(row+offset.first+grid.getRows())%grid.getRows();
    int livecolumn=(column+offset.second+grid.getColumns())%grid.getColumns();
    CountNeighbors<<<1,neighbors.size()>>>(grid.getValue(liverow,livecolumn),d_output);
    }

    int result;
    cudaMemcpy(&result, d_output, sizeof(int), cudaMemcpyDeviceToHost);


    cout << "Neighbor count: " << result << endl;

    cudaFree(d_output);
    return result;

}
void Process::update(){

for(int i=0;i<grid.getRows();i++){

   for(int j=0;j<grid.getColumns();j++){
    int live=CountN(i,j);
    int cellval=grid.GetValue(i,j);
    if(cellval==1){
        if(live>3||live<2){
            temp.SetValue(i,j,0);

        }
        else{
            temp.SetValue(i,j,1);
        }
    }
    else{
       if(live==3){
        temp.SetValue(i,j,1);
       }
       else{

        temp.SetValue(i,j,0);
       }
    }
   }
}
grid=temp;
}






