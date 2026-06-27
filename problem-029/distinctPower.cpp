#include <iostream>
#include <set>
#include <string>
using namespace std;

string multiply(const string& num, int x) {
    int carry = 0;
    string result = num;
    for (int i = result.size() - 1; i >= 0; --i) {
        int prod = (result[i] - '0') * x + carry;
        result[i] = '0' + (prod % 10);
        carry = prod / 10;
    }
    while (carry) {
        result.insert(result.begin(), '0' + (carry % 10));
        carry /= 10;
    }
    return result;
}

string power(int base, int exp) {
    string result = "1";
    for (int i = 0; i < exp; ++i)
        result = multiply(result, base);
    return result;
}

int main() {
    set<string> distinct;
    for (int a = 2; a <= 100; ++a)
        for (int b = 2; b <= 100; ++b)
            distinct.insert(power(a, b));
    cout << distinct.size() << endl; 
    return 0;
}