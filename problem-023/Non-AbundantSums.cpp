#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isabundant(int n){
    int sum = 1; 
    for (int j = 2; j*j <= n; j++) {
        if (n % j == 0) {
            sum += j;
            if (j * j != n) {
                sum += n / j;
            }
        }
    }
    return sum > n;
}

bool issumof2abundantnum(int n,vector<int>& abundantNums){
    for (int a : abundantNums) {
        int b = n - a;
        if (b < a) break;  
        if (isabundant(b)) {
            return true;
        }
    }
    return false;
}

int main(){
    int num = 28123;
    int sum = 1;
    vector<int> abundant;
    for (int i = 12; i <= num; i++) { 
        if (isabundant(i)) {
            abundant.push_back(i);
        }
    }
    for(int i = 2;i<=num;i++){
        if (!issumof2abundantnum(i, abundant)) {
            sum += i;
        }
    }

    cout<<sum<<endl;
    return 0;
}

