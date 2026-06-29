# Digit Fifth Powers - Project Euler Problem 30

A C++ solution to **Project Euler Problem 30** - finding the sum of all numbers that can be written as the sum of fifth powers of their digits.

## Problem Statement

> It can be seen that each number from 1 to 9 satisfies the condition that it equals the sum of fifth powers of its digits:
>
> $$\ 1 = 1^5 \$$
> $$\ 2 = 2^5 \$$
 (not equal, 2⁵ = 32)
>
> In fact, there are only a few numbers that can be written as the sum of fifth powers of their digits.
>
> **Find the sum of all numbers that can be written as the sum of fifth powers of their digits.**

**Note:** The problem excludes 1 since it's not a sum (just a single digit).

### Example

**4155** = 4⁵ + 1⁵ + 5⁵ + 5⁵
= 1024 + 1 + 3125 + 3125
= 4155 

4155 can be written as sum of fifth powers of its digits!


---

## Key Insight: Finding the Upper Limit

### Why 354,294?

We need to determine the **maximum possible number** to check.

**For a d-digit number:**
- Maximum sum of fifth powers = d × 9⁵ (all digits are 9)
- 9⁵ = 59,049

**For 6 digits:**
- Maximum sum = 6 × 9⁵ = 6 × 59,049 = **354,294**
- This fits within 6 digits 

**For 7 digits:**
- Maximum sum = 7 × 9⁵ = 7 × 59,049 = **413,343**
- But 413,343 only has 6 digits! 
- So no 7-digit number can satisfy the condition

**Conclusion:** The maximum number to check is **354,294**

| Digits | Max Sum (d × 9⁵) | Digits in Max Sum | Valid? |
|--------|-----------------|-------------------|--------|
| 1 | 59,049 | 5 | ❌ |
| 2 | 118,098 | 6 | ❌ |
| 3 | 177,147 | 6 | ❌ |
| 4 | 236,196 | 6 | ❌ |
| 5 | 295,245 | 6 | ❌ |
| **6** | **354,294** | **6** | ✅ |
| 7 | 413,343 | 6 | ❌ |

---

## Algorithm

### Step 1: Check if Number is Sum of Fifth Powers

```cpp
bool isFifthPower(int n) {
    int temp = n;
    int sum = 0;
    
    while (temp != 0) {
        int digit = temp % 10;  // Get last digit
        sum += pow(digit, 5);   // Add digit⁵ to sum
        temp /= 10;             // Remove last digit
    }
    
    return sum == n;  // True if sum equals original number
}
```

**How it works:**
1. Extract each digit using `temp % 10`
2. Add `digit⁵` to sum
3. Remove digit using `temp / 10`
4. Repeat until all digits processed
5. Check if sum equals original number


---

### Step 2: Sum All Valid Numbers

```cpp
int main() {
    int Limit = 354294;
    long sum = 0;
    
    for (int i = 1000; i <= Limit; i++) {
        if (isFifthPower(i)) {
            sum += i;
        }
    }
    
    cout << sum << endl;
    return 0;
}
```

**Process:**

- Check 1000 to 354,294:
    - 1000: isFifthPower(1000) → false
    - 1001: isFifthPower(1001) → false
    - ...
    - 4150: isFifthPower(4150) → true → sum += 4150
    - ...
    - 5474: isFifthPower(5474) → true → sum += 5474
    - ...

Total sum = All valid numbers added together


---

## Complexity Analysis

### Time Complexity

| Metric | Value | Explanation |
|--------|-------|-------------|
| **Loop iterations** | 353,294 | From 1000 to 354,294 |
| **Digits per number** | O(d) | d = 6 (max digits) |
| **Total** | **O(n × d)** | n = 353,294, d = 6 |

**Operations:**

353,294 iterations × 6 digits = ~2.1 million operations


**Runtime:** ~0.05 seconds (very fast!)

### Space Complexity

- **O(1)** - Only uses a few variables
- **Memory:** ~20 bytes

---

## References

- [Project Euler Problem 30](https://projecteuler.net/problem=30)
- [Narcissistic Numbers](https://en.wikipedia.org/wiki/Narcissistic_number) - Similar concept
- [Digit Power Sum](https://en.wikipedia.org/wiki/Digit_sum)

---

## Summary

| Metric | Value |
|--------|-------|
| **Valid numbers** | 6 (4150, 4151, 5474, 93084, 193160, 193161) |
| **Maximum to check** | 354,294 |
| **Total sum** | **443,839** |
| **Runtime** | ~0.05 seconds |
| **Time complexity** | O(n × d) |

**Answer:** 443,839 ✅

---

## License

Free to use for learning purposes.