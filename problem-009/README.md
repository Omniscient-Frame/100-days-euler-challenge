# Project Euler Problem 9 — Special Pythagorean Triplet

## Problem Statement

A Pythagorean triplet is a set of three natural numbers `a < b < c` such that:

`a² + b² = c²`

For this problem, we are given a number `n` and asked to find the product `a * b * c` for the unique triplet where:

`a + b + c = n`

For the classic Project Euler version, `n = 1000`.

---

## Example

For the triplet:

`3, 4, 5`

we have:

`3² + 4² = 5²`

and:

`3 + 4 + 5 = 12`

So the product is:

`3 * 4 * 5 = 60`

---

## Approach

The brute-force way is to try all values of `a`, `b`, and `c`, but that is too slow.

Instead, we use these observations:

- `a < b < c`
- `a + b + c = n`
- So `a < n / 3`
- Also, `b < n / 2`

This lets us reduce the search space a lot.

### Optimized logic

1. Loop `a` from `1` to `n / 3`.
2. Loop `b` from `a + 1` to `n / 2`.
3. Compute `c = n - a - b`.
4. Check whether `a² + b² = c²`.
5. If true, return `a * b * c`.

---

## Why This Works

Since `a < b < c`, the smallest value `a` cannot be too large, otherwise the sum would exceed `n`.

- If `a >= n/3`, then `a + b + c > n`, which is impossible.
- If `b >= n/2`, then `c` becomes too small to satisfy `b < c`.

So these bounds are safe and help eliminate many useless checks.

---

## Time Complexity

The original brute-force approach is roughly `O(n^2)` or worse depending on how `c` is handled.

This optimized version is still `O(n^2)`, but with much smaller loop ranges:

- `a` runs up to `n/3`
- `b` runs up to `n/2`

That makes it much faster in practice.

---

## Result for `n = 1000`

The product of the special Pythagorean triplet is:

`31875000`

---

## Notes

- Use `long long` for the product because `a * b * c` can become large.
- Avoid `pow()` for integer square checks; `a * a` is faster and cleaner.
- Since `c` is computed from the sum, there is no need to separately check `a + b + c == n`.