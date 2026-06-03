#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n =5, product=1,max_product =1;
    vector<vector<int>> grid(5,vector<int>(6));
    grid = {
        {40, 17, 81, 18, 57},
        {74, 4, 36, 16, 29},
        {36, 42, 69, 73, 45},
        {51, 54, 69, 16, 92},
        {7, 97, 57, 32, 16},
    };
    int rows = grid.size();
    int column = grid[0].size();
    for(int r =0;r<rows;r++){
        for(int c =0;c<column;c++){
            //Horizontal
            if(c+3<column){
                product = grid[r][c]*grid[r][c+1]*grid[r][c+2]*grid[r][c+3];
            }

            if(product>max_product) max_product=product;

            //Vertical
            if(r+3<rows){
                product = grid[r][c]*grid[r+1][c]*grid[r+2][c]*grid[r+3][c];
            }

            if(product>max_product) max_product=product;

            //Diagonal(down-right)
            if(r+3<rows && c+3 < column){
                product = grid[r][c]*grid[r+1][c+1]*grid[r+2][c+2]*grid[r+3][c+3];
            }
            
            if(product>max_product) max_product=product;

            //Daigonal(down-left)
            if(r+3<rows && c-3>=0){
                product = grid[r][c]*grid[r+1][c-1]*grid[r+2][c-2]*grid[r+3][c-3];
            }

            if(product>max_product) max_product=product;
        }
    }
    cout<<"Largest Product In a Grid = "<<max_product<<endl;
    return 0;

    
}