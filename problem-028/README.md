# Project Euler – Problem 28: Number Spiral Diagonals

## Problem Statement

Starting with the number 1 and moving to the right in a clockwise direction, a 5×5 spiral is formed like this:

```
21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13
```

The sum of both diagonals in this 5×5 spiral is:

```
1 + 3 + 5 + 7 + 9 + 13 + 17 + 21 + 25 = 101
```

Find the sum of the diagonals in a 1001×1001 spiral.

---

## Key Observation: The Four Corner Formulas

For each "ring" of the spiral with side length `n` (where `n = 3, 5, 7, ...`), the four corner elements follow a fixed pattern derived from `n²`:

| Diagonal     | Formula          | Example (n=3) | Example (n=5) |
|--------------|------------------|---------------|---------------|
| Up-right     | n²               | 9             | 25            |
| Up-left      | n² − (n−1)       | 7             | 21            |
| Down-left    | n² − 2(n−1)      | 5             | 17            |
| Down-right   | n² − 3(n−1)      | 3             | 13            |

These formulas were derived independently by observing how each corner relates to the top-right corner `n²` — each subsequent corner going counterclockwise is exactly `(n−1)` less than the previous one, since consecutive elements along the border of a ring differ by `(n−1)`.

### Combined Formula Per Ring

Summing all four corners for a given ring:

```
n² + (n²−(n−1)) + (n²−2(n−1)) + (n²−3(n−1))
= 4n² − 6(n−1)
= 4n² − 6n + 6
```

**Verification:**
- n=3: 4(9) − 18 + 6 = **24** → 3+5+7+9 = 24 ✓  
- n=5: 4(25) − 30 + 6 = **76** → 13+17+21+25 = 76 ✓

---

## Approach

```
Total = 1 (center)
For each odd n from 3 to grid_size:
    Total += 4n² − 6n + 6
```

This replaces four separate loops — one per diagonal — with a single clean loop. The center `1` is added separately since it belongs to no ring.

---

## Implementation (C++)

```cpp
long long Diagonal_sum(int grid_size) {
    long long sum = 1;
    for (int n = 3; n <= grid_size; n += 2) {
        sum += 4LL * n * n - 6 * n + 6;
    }
    return sum;
}

int main() {
    cout << Diagonal_sum(1001) << endl;
}
```

---

## What Went Wrong in the Original Approach

The original code derived four separate formulas- one per diagonal.

which were mathematically correct. The bug was purely in the loop control logic:

| Bug | Detail |
|-----|--------|
| Wrong termination condition | Loop checked `accumulated_sum <= some_corner_value` — comparing a running total against a single element |
| Four loops instead of one | Each loop was independently fragile; one combined loop eliminates the problem entirely |

The formulas themselves were right. The implementation wiring was wrong.

**Lesson:** When loop termination is wrong, print the first 2–3 values of each loop and compare against hand-calculated values. This catches control logic bugs without touching the formulas.

---

## Complexity

| Step | Complexity |
|------|------------|
| Loop over odd n up to grid_size | O(grid_size / 2) |
| Arithmetic per step | O(1) |
| **Total** | **O(n)** |

For a 1001×1001 grid, this runs in ~500 iterations — essentially instant.

---

## Answer

The sum of the diagonals in a 1001×1001 number spiral is **669171001**.