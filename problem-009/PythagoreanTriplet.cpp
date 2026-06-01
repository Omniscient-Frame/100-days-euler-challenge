#include<iostream>
#include<cmath>
using namespace std;
long long SpecialPythagoeantriplet(int n){
    long long p;
    for(long long a = 1;a<=n/3;a++){
        for(long long b=1;b<=n/2;b++){
            long long c = n - (a+b);
            if (c*c==a*a+b*b && b>a){
                return a*b*c;
            }          
        }
    }
    return 0;
}

int main(){
    cout<<SpecialPythagoeantriplet(1000)<<endl;
    return 0;
}