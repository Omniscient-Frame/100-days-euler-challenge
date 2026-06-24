# Project Euler – Problem 27: Quadratic Primes

## Problem Statement

Euler discovered the remarkable quadratic formula:

```
n² + n + 41
```

This formula produces 40 primes for consecutive values of `n` from `0` to `39`.

Another remarkable formula is:

```
n² − 79n + 1601
```

This produces 80 primes for consecutive values of `n` from `0` to `79`.

The general form of such a quadratic is:

```
n² + an + b,  where |a| < 1000 and |b| ≤ 1000
```

Find the product `a × b` for the coefficients `a` and `b` that produce the maximum number of primes for consecutive values of `n`, starting from `n = 0`.

---

## Approach

### Key Observations

**1. `b` must be prime.**

When `n = 0`, the formula gives:

```
0² + a(0) + b = b
```

For this to be prime, `b` itself must be prime. This means we only need to iterate over prime values of `b` in the range `[2, 1000]`, reducing the inner loop from ~2000 iterations to just ~168 (number of primes under 1000).

**2. Guard against negative formula values.**

Since `a` can be negative and large, the formula `n² + an + b` can produce negative numbers for certain values of `n`. Negative numbers cannot be prime, so the loop must terminate when the formula goes negative.

**3. Precompute primes using the Sieve of Eratosthenes.**

Instead of recomputing primality from scratch on every call, we build a boolean lookup table once upfront. Any primality check then becomes an O(1) index lookup.

The maximum value the formula can produce, given a chain length of ~80 and range 1000, is approximately:

```
80² + 1000 × 80 + 1000 ≈ 87,400
```

A sieve limit of **1,000,000** is more than sufficient.

---

## Algorithm

```
1. Build sieve of Eratosthenes up to limit (1,000,000)
2. For each a in [-1000, 1000]:
     For each b in [2, 1000] where b is prime:
       Set n = 0
       While (n² + a·n + b) > 0 AND is prime:
         Increment n
       If n > max_chain_length:
         Update max_chain_length, best_a, best_b
3. Return best_a × best_b
```

---

## Implementation (C++)

```cpp
int quadPrime(int range, const vector<bool>& prime) {
    int n = 0;
    int maxA = 0;
    int maxB = 0;

    for (int a = -range; a <= range; a++) {
        for (int b = -range; b <= range; b++) {
            int length = 0;
            if (prime[abs(b)]) {
                long eq = (long)length * length + a * length + b;
                while (eq > 0 && prime[eq]) {
                    length++;
                    eq = (long)length * length + a * length + b;
                }
                if (length > n) {
                    n = length;
                    maxA = a;
                    maxB = b;
                }
            }
        }
    }
    return maxA * maxB;
}

int main() {
    int range = 1000;
    long primeLimit = 1000000;
    vector<bool> primes(primeLimit + 1, true);
    primes[0] = false;
    primes[1] = false;

    for (long i = 2; i * i <= primeLimit; i++) {
        if (primes[i]) {
            for (long j = i * i; j <= primeLimit; j += i)
                primes[j] = false;
        }
    }

    cout << quadPrime(range, primes) << endl;
}
```

---

## Bugs Encountered & Fixed

| Bug | Cause | Fix |
|-----|-------|-----|
| `bad_alloc` / crash | `isPrime(-n)` called with negative input | Guard: `if (n < 2) return false` |
| Infinite loop | `eq` computed once outside loop, never updated | Recompute `eq` at start of each iteration |
| Wrong output | Integer overflow in `length*length + a*length` | Cast to `long` before multiplication |
| All composites marked non-prime | Sieve inner loop used `j++` instead of `j += i` | Changed to `j += i` |
| Slow performance | Vector passed by value (copied 1M bools per call) | Pass by `const vector<bool>&` |

---

## Complexity

| Step | Complexity |
|------|------------|
| Sieve construction | O(N log log N) |
| Outer loop (a) | O(2 × range) |
| Inner loop (b, primes only) | O(π(range)) ≈ O(range / ln range) |
| Chain check per (a, b) | O(max chain length) |
| **Total** | **O(N log log N + range² / ln range)** |

---

## Answer

The coefficients that produce the longest chain of consecutive primes are:

- **a = −61, b = 971** → 71 consecutive primes
- **Product: a × b = −59231**

---
### Reference

Project Euler Problem 27: https://projecteuler.net/problem=27

## License

Free to use for learning purposes.