#include<iostream>
#include<vector>
using namespace std;

int LetterCounter(int n){
    if (n==1000) return 11;

    int ones_counts[10] = {0,3,3,5,4,4,3,5,5,4};
    int tens_counts[10] = {0,3,6,6,5,5,5,7,6,6};
    int eleven_counts[10] = {0,6,6,7,8,7,7,9,8,8};

    if(n<=9) return ones_counts[n];

    if(n>=11 && n<=19) return eleven_counts[(n%10)];

    if(n%10==0 && n<100) return tens_counts[n/10];

    if (n < 100 && n%10!=0) {
        int tens = n / 10;
        int ones = n % 10;
        return tens_counts[tens] + ones_counts[ones];
    }

    if(n%100==0) {
        int val = n/100;
        return ones_counts[val]+7;
    }

    if(n>100 && n<=999){
        
        int val = n/100;
        
        int rem = n%100;
        
        int val_count = ones_counts[val]+7;
        
        int rem_count = LetterCounter(rem);
        
        return val_count+3+rem_count;
    }

    return 0;
}

int main(){
    int n =1000;
    int sum =0;
    if(n>1000){
        cout<<"invalid input number should be under 1000"<<endl;
        return 0;
    }
    for(int i = 1;i<=n;i++){
        sum += LetterCounter(i);
    }
    cout<<"total letters count is : "<<sum<<endl;
    return 0;
}
