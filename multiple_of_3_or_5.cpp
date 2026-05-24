#include<iostream>

using namespace std;

int multipleof3or5(int n){
    int sum=0;
    for(int i=1;i<n;i++){
        if(i%3==0||i%5==0){
            sum+=i;
        }
    }
    return sum;

}
int main(){
    int number;
    cout<<"enter your number :"<<endl;
    cin>>number;
    int total = multipleof3or5(number);
    cout<<"sum of all multiple of 3 & 5 is : "<<total<<endl;
    return 0;
}
    