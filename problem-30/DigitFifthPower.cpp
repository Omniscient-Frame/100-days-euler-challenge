#include <iostream>
#include<cmath>
using namespace std;

bool isFifthPower(int n){
    int temp = n;
    int sum =0;
    while(temp!=0){
        int res = temp%10;
        sum += pow(res,5);
        temp /=10;
    }
    if(sum==n) return true;
    return false;
}

int main(){
    int Limit = 354294;
    long sum = 0;
    for(int i =1000;i<=Limit;i++){
        if(isFifthPower(i)){
            sum+=i;
        }
    }
    cout<<sum<<endl;
}