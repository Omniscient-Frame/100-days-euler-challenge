#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

long long Diagonal_sum(int grid_size){
    long diff = grid_size-2;

    //up right
    long long sum_up_right =0;
    for(long i =3;i<=grid_size;i+=2){
        sum_up_right+= i*i;
    }

    //up left
    long long sum_up_left = 0;
    long it = 1;
    long up_curr_left =0;
    for(long i =3;up_curr_left<grid_size*grid_size-(diff+1);i+=2){
        up_curr_left = i*i - 2*it;
        sum_up_left+= up_curr_left;
        it++;
    }

    //down right
    long long sum_down_right =0;
    long down_prev = 1;
    long down_curr = 3;
    
    while(down_curr<=grid_size*grid_size-3*diff+3){
        sum_down_right +=down_curr;
        long next_elem = (down_curr-down_prev)+8+down_curr;
        down_prev = down_curr;
        down_curr = next_elem;
    }

    //dwon left
    long long sum_down_left =0;
    long down_prev_left = 1;
    long down_curr_left = 5;
    
    while(down_curr_left<=grid_size*grid_size-2*diff+2){
        sum_down_left +=down_curr_left;
        long next_elem = (down_curr_left-down_prev_left)+8+down_curr_left;
        down_prev_left = down_curr_left;
        down_curr_left = next_elem;
    }

    return sum_up_right+sum_up_left+sum_down_right+sum_down_left+1;

}
int main(){
    int grid_size = 1001;
    cout<<Diagonal_sum(grid_size)<<endl;
}