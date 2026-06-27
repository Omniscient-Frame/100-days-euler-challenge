# Project Euler – Problem 29

**Distinct Powers**

> Consider all integer combinations of a^b for 2 ≤ a ≤ 5, 2 ≤ b ≤ 5.  
> How many distinct values of a^b are there for 2 ≤ a ≤ 100, 2 ≤ b ≤ 100?

**Answer: 9183**

---

## The Challenge

The sequence looks simple enough — raise every integer `a` (2–100) to every power `b` (2–100) and count the unique results. The catch is that the numbers involved are enormous. For example, 99^100 has over 198 digits — far beyond what any native integer type can hold.

A secondary subtlety is that different (a, b) pairs can produce identical values:

```
4^2 = 16 = 2^4
8^2 = 64 = 2^6 = 4^3
```

These collisions are exactly what makes a naïve count wrong.

---

## Approach: Big-Integer Strings + `std::set`

Rather than reaching for a big-integer library, we represent each result as a **decimal string** and implement just enough arithmetic to compute `a^b` by repeated multiplication. Each result is inserted into a `std::set<std::string>`, which handles deduplication automatically. The final answer is `distinct.size()`.

### Why strings?

- No external dependencies.
- `std::set` compares strings lexicographically, which is sufficient for deduplication (we don't need ordering by numeric value).
- The implementation is short and easy to verify.

### Algorithm

```cpp
for a in [2, 100]:
    for b in [2, 100]:
        val = big_power(a, b)   // computed as a decimal string
        insert val into a set

return size of set
```

`big_power(a, b)` runs `b` iterations of a grade-school string multiply — each pass carries through the digits of the accumulated result, multiplying by the single integer `a`.

---

## Code

```cpp
#include <iostream>
#include <set>
#include <string>

// Multiply a decimal string by a small integer
std::string multiply(const std::string& num, int x) {
    int carry = 0;
    std::string result = num;
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

// Compute base^exp as a decimal string
std::string power(int base, int exp) {
    std::string result = "1";
    for (int i = 0; i < exp; ++i)
        result = multiply(result, base);
    return result;
}

int main() {
    std::set<std::string> distinct;
    for (int a = 2; a <= 100; ++a)
        for (int b = 2; b <= 100; ++b)
            distinct.insert(power(a, b));
    std::cout << distinct.size() << std::endl;  // 9183
    return 0;
}
```

---

## Complexity

| | |
|---|---|
| Pairs computed | 99 × 99 = 9,801 |
| Digits in largest value (99^100) | ~198 |
| Time per multiplication | O(digits) ≈ O(200) |
| Total | O(9801 × 100 × 200) ≈ ~196M digit-ops |

In practice it runs in well under a second on any modern machine.

---

## Alternative Approach (no big integers)

Every integer `a` in [2, 100] can be expressed as `p^k` for some prime base `p` and integer exponent `k`. Then `a^b = p^(k*b)`. Two pairs (a₁, b₁) and (a₂, b₂) produce the same value if and only if they share the same prime base and their effective exponents `k*b` match.

This representation lets you work entirely with small integers and avoids big arithmetic. The trade-off is a more involved implementation. For a problem this size, the string approach is cleaner and fast enough.

---

## Related Problems

- [Problem 16](https://projecteuler.net/problem=16) — digit sum of 2^1000 (also requires big integers)
- [Problem 20](https://projecteuler.net/problem=20) — digit sum of 100! (same technique)