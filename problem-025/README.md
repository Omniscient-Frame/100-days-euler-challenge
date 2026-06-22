# Thousand-Digit Fibonacci Number - Project Euler Problem 25

A C++ solution to **Project Euler Problem 25** - finding the index of the first Fibonacci number with 1000 digits, using **string-based addition** for large number arithmetic.

## Problem Statement

> The Fibonacci sequence is defined by the recurrence relation:
> 
> F_n = F_{n-1} + F_{n-2} 
> 
> where \( F_1 = 1 \) and \( F_2 = 1 \).
>
> The first 12 terms are:
> ```
> F₁ = 1
> F₂ = 1
> F₃ = 2
> F₄ = 3
> F₅ = 5
> F₆ = 8
> F₇ = 13
> F₈ = 21
> F₉ = 34
> F₁₀ = 55
> F₁₁ = 89
> F₁₂ = 144
> ```
>
> The 12th term, F₁₂, is the first term to contain **three digits**.
>
> **What is the index of the first term in the Fibonacci sequence to contain 1000 digits?**

---

## The Challenge: Numbers (Too Large!)

### Why Standard Types Fail
F₁₀₀₀ has approximately 209 digits

F₄₇₈₇ (the answer) has 1000 digits


**Standard C++ types:**
| Type | Max Value | Digits |
|------|-----------|--------|
| `int` | 2,147,483,647 | 10 |
| `long long` | 9,223,372,036,854,775,807 | 19 |
| `double` | ~1.8 × 10³⁰⁸ | 308 |

**Problem:** F₄₇₈₇ needs **1000 digits** but `long long` only holds **19 digits**! 

### Solution: String-Based Arithmetic

Store numbers as **strings** and implement our own addition:

```cpp
string F₁ = "1";
string F₂ = "1";
string F₃ = addString(F₁, F₂);  // "2"
string F₄ = addString(F₂, F₃);  // "3"
```

---

## Algorithm

### Step 1: String Addition Function

```cpp
string addString(string a, string b) {
    string result = "";
    int i = a.size() - 1;  // Start from last digit
    int j = b.size() - 1;  // Start from last digit
    int carry = 0;
    
    while (i >= 0 || j >= 0 || carry != 0) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i] - '0';  // Convert char to int
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';  // Convert char to int
            j--;
        }
        carry = sum / 10;
        result += (char)(sum % 10 + '0');  // Convert int to char
    }
    
    reverse(result.begin(), result.end());
    return result;
}
```

**How it works:**
1. Start from the **last digit** of both strings (rightmost)
2. Add digits + carry
3. Store `sum % 10` (last digit of sum)
4. Carry `sum / 10` to next position
5. Continue until both strings exhausted and no carry
6. **Reverse** the result (we built it backwards)

### Step 2: Fibonacci Sequence Generator

```cpp
string prev = "1",  // F₁
       curr = "1";  // F₂
int index = 2;

while (curr.size() < 1000) {  // Until we get 1000 digits
    string next = addString(prev, curr);  // Fₙ = Fₙ₋₁ + Fₙ₋₂
    prev = curr;
    curr = next;
    index++;
}

cout << index << endl;  // Output: 4782
```

**Process:**

```text
index = 2: prev = "1", curr = "1" (F₁, F₂)
index = 3: next = "1" + "1" = "2", curr = "2" (F₃)
index = 4: next = "1" + "2" = "3", curr = "3" (F₄)
index = 5: next = "2" + "3" = "5", curr = "5" (F₅)
index = 4782: curr has 1000 digits → STOP!
```


---

## Step-by-Step Example: String Addition

### Example 1: Add "123" + "456"
```
Initial:
a = "123", b = "456"
i = 2 (points to '3')
j = 2 (points to '6')
carry = 0
result = ""

Iteration 1:
sum = 0 + 3 + 6 = 9
carry = 9 / 10 = 0
result += '9' → "9"
i = 1, j = 1

Iteration 2:
sum = 0 + 2 + 5 = 7
carry = 7 / 10 = 0
result += '7' → "97"
i = 0, j = 0

Iteration 3:
sum = 0 + 1 + 4 = 5
carry = 5 / 10 = 0
result += '5' → "975"
i = -1, j = -1

Loop ends (i < 0, j < 0, carry = 0)

Reverse: "975" → "579"

Result: "579"
```


---

## Complexity Analysis

### Time Complexity

| Operation | Complexity | Explanation |
|-----------|------------|-------------|
| `addString()` | O(d) | d = number of digits |
| Fibonacci loop | O(n × d) | n iterations, each O(d) |
| **Total** | **O(n × d)** | n=4782, d≈500 (average) |

**Operations:**
4782 iterations × 500 digits (average) ≈ 2.4 million operations


**Runtime:** ~0.01 seconds (extremely fast!)

### Space Complexity

- **O(d)** for storing Fibonacci numbers
- **Max digits:** 1000
- **Memory:** ~1000 bytes per string × 2 strings = 2 KB

---
## Test Cases

| Input | Expected Output | Description |
|-------|----------------|-------------|
| First with 1 digit | 1 | F₁ = 1 |
| First with 2 digits | 7 | F₇ = 13 |
| First with 3 digits | 12 | F₁₂ = 144 |
| First with 10 digits | 45 | F₄ = 1,134,903,170 |
| First with 1000 digits | **4782** | Project Euler 25 answer |

---

## License

Free to use for learning purposes.