#include <iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int largestpalindrome(int digits){
    int high = pow(10,digits)-1;
    int low = pow(10,digits-1);
    int palindrome = 0;
    for(int i=high;i>low;i--){
        for(int j=i;j>low;j--){
            int product = i*j;
            if(product>palindrome){
                string str = to_string(product);
                string rev = str;
                reverse(rev.begin(),rev.end());
                if (str==rev){
                    palindrome = product;
                }
            }
        }
    }
    return palindrome;
}
    



int main(){
    int digits;
    cout<<"enter the number of digits: "<<endl;
    cin>>digits;
    cout<<"the largest palindrome is: "<<largestpalindrome(digits)<<endl;
    return 0;
}