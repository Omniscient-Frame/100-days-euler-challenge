#include<iostream>

using namespace std;

int largestprimeFactor(int n){
    int temp1,temp2,i,j;
    for(i=2;i<=n;i++){
        if(n%i==0){
            temp1=i;
            bool isprime = true;
            for(j=2;j<temp1;j++){
                if(temp1%j==0){
                    isprime = false;
                    break;
                }
            
            }
            if(isprime == true){
                temp2 = temp1;
            }
        }
    }
    return temp2;
}

int main(){
    int n,factor;
    cout<<"enter the number: "<<endl;
    cin>>n;
    factor = largestprimeFactor(n);
    cout<<"the largest prime factor is : "<<factor<<endl;
    return 0;

}