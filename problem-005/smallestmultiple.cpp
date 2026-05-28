#include<iostream>
#include<cmath>
#include <algorithm>
using namespace std;
int LCM(int a,int b){
    int high = max(a,b);
    int low = min(a,b);
    for(int i=high;;i+=high){
        if(i%low==0){
            return i;
        }
    }
    return 1;
}
int smallestMultiple(int n){
    int res=1;
    for(int i=1;i<=n;i++){
        res=LCM(res,i);
    }
    return res;
}
int main(){
    int n;
    cout<<"enter the number: "<<endl;
    cin>>n;
    cout<<"the smallest multiple is: "<<smallestMultiple(n)<<endl;
    return 0;
}