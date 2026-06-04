#include <iostream>
#include <cmath>
using namespace std;

long long divisorCount(long long num) {
    long long count = 1;

    for (long long p = 2; p * p <= num; p++) {
        int exp = 0;
        while (num % p == 0) {
            num /= p;
            exp++;
        }
        if (exp > 0) {
            count *= (exp + 1);
        }
    }

    if (num > 1) {
        count *= 2;
    }

    return count;
}

long long triangleNumberWithOverNDivisors(int n) {
    long long k = 1;

    while (true) {
        long long triangle;

        if (k % 2 == 0) {
            triangle = (k / 2) * (k + 1);
            if (divisorCount(k / 2) * divisorCount(k + 1) > n) {
                return triangle;
            }
        } else {
            triangle = k * ((k + 1) / 2);
            if (divisorCount(k) * divisorCount((k + 1) / 2) > n) {
                return triangle;
            }
        }

        k++;
    }
}

int main() {
    int n;
    cin >> n;

    cout << triangleNumberWithOverNDivisors(n) << endl;
    return 0;
}