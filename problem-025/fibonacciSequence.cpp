#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string addString(string a,string b){
    string result = "";
    int i = a.size()-1;
    int j = b.size()-1;
    int carry = 0;
    while (i>=0||j>=0||carry!=0)
    {
        int sum = carry;
        if(i>=0){
            sum+= a[i] - '0';
            i--;
        }
        if(j>=0){
            sum+= b[j] - '0';
            j--;
        }
        carry = sum/10;
        result+= (char)(sum%10+'0');
    }
    reverse(result.begin(),result.end());
    return result;
    
}
int main(){
    string prev="1",curr="1";
    int index = 2;
    while (curr.size()<1000)
    {
        string next = addString(prev,curr);
        prev = curr;
        curr = next;
        index++;
    }
    cout<<index<<endl;
    return 0;
    
}