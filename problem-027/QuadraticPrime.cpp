
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

int quadPrime(int range,const vector<bool>& prime){
    int n =0;
    int maxA =0;
    int maxB =0;
    for(int a= -range;a<=range;a++){
        
        for(int b =2;b<=range;b++){
            int lenght =0;
            if(prime[abs(b)]){
                long eq =lenght*lenght+a*lenght+b;
                while(eq>0 && prime[eq]){
                    lenght++;
                    eq =(lenght*lenght+a*lenght+b);
                }

                if(lenght>n){
                    n = lenght;
                    maxA =a;
                    maxB=b;
                }
            }
            
        }
    }
    return (maxA*maxB);
}
int main(){
    int n = 1000;
    long primelimit = 1000000;
    vector<bool> primes(primelimit+1,true);
    primes[0] = false;
    primes[1] = false;
    for(long i =2;i*i<=primelimit;i++){
        if(primes[i]){
            for(long j=i*i;j<=primelimit;j =j+i) primes[j]=false;
        }
    }
    cout<<quadPrime(n,primes)<<endl;
}