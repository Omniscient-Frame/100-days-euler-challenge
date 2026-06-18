# Non-Abundant Sums - Project Euler Problem 23

A C++ solution to **Project Euler Problem 23** - finding the sum of all positive integers that cannot be written as the sum of two abundant numbers.

## Problem Statement

> A **perfect number** is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 is 1 + 2 + 4 + 7 + 14 = 28. Hence, 28 is a perfect number.
>
> A number **n** is called **deficient** if the sum of its proper divisors is less than **n**, and it is called **abundant** if this sum exceeds **n**.
>
> As 12 is the smallest abundant number (1 + 2 + 3 + 4 + 6 = 16), the smallest number that can be written as the sum of two abundant numbers is 24 (12 + 12 = 24). By mathematical analysis, it can be shown that all integers greater than **28,123** can be written as the sum of two abundant numbers. However, this minimum limit can be reduced.
>
> **Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.**

## Key Definitions

### Proper Divisors
Divisors of n that are **less than n**.

**Example:** Proper divisors of 12 are 1, 2, 3, 4, 6

### Abundant Number
Sum of proper divisors **>** number itself.

**Example:** 12 is abundant
- Proper divisors: 1, 2, 3, 4, 6
- Sum = 1 + 2 + 3 + 4 + 6 = 16
- 16 > 12 → 12 is ABUNDANT

### Perfect Number
Sum of proper divisors **=** number itself.

**Example:** 28 is perfect

- Proper divisors: 1, 2, 4, 7, 14
- Sum = 1 + 2 + 4 + 7 + 14 = 28
- 28 = 28 → 28 is PERFECT


### Deficient Number
Sum of proper divisors **<** number itself.

**Example:** 8 is deficient

- Proper divisors: 1, 2, 4
- Sum = 1 + 2 + 4 = 7
- 7 < 8 → 8 is DEFICIENT


---

## Algorithm Overview
1. Find all abundant numbers up to 28,123

2. For each number from 2 to 28,123:

        Check if it can be written as sum of two abundant numbers

        If NOT, add it to the total

3. Output the total sum

---

## Complexity Analysis

### Time Complexity

| Step | Complexity | Operations |
|------|------------|------------|
| Find abundant numbers | O(n × √n) | 28,123 × 168 ≈ 4.7M |
| Check each number | O(n × m) | 28,123 × 5,700 ≈ 160M |
| **Total** | **O(n × √n + n × m)** | ~165M operations |

Where:
- n = 28,123 (max number)
- m = 5,700 (count of abundant numbers)
- √n ≈ 168 (sqrt of max number)

**Runtime:** ~2 seconds on modern CPU

### Space Complexity

- **O(n)** for storing abundant numbers
- **Vector size:** 5,700 integers ≈ 23 KB

---

## License

Free to use for learning purposes.