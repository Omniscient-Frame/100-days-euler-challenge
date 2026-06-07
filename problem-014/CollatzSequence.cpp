#include <iostream>
#include <vector>
using namespace std;

int collatzLength(long long n, vector<int>& cache) {
    if (n == 1) return 1;

    if (n < (long long)cache.size() && cache[n] != 0) {
        return cache[n];
    }

    long long next;
    if (n % 2 == 0) {
        next = n / 2;
    } else {
        next = 3 * n + 1;
    }

    int len = 1 + collatzLength(next, cache);

    if (n < (long long)cache.size()) {
        cache[n] = len;
    }

    return len;
}

int main() {
    int limit = 77777;
    vector<int> cache(limit + 1, 0);
    cache[1] = 1;

    int bestNumber = 1;
    int bestLength = 1;

    for (int i = 1; i < limit; i++) {
        int len = collatzLength(i, cache);
        if (len > bestLength) {
            bestLength = len;
            bestNumber = i;
        }
    }

    cout << bestNumber << " " << bestLength << endl;
    return 0;
}