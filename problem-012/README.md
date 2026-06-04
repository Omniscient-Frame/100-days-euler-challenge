# First Triangle Number with Over N Divisors

## Problem Statement

Find the first triangle number that has more than `n` divisors.

A triangle number is defined as:

\[
T_k = \frac{k(k+1)}{2}
\]

For example:

- `1, 3, 6, 10, 15, 21, 28, ...`

The 7th triangle number is `28`, and it has more than 5 divisors.

---

## Approach

The solution works in two steps:

1. Generate triangle numbers one by one using the formula:
   \[
   T_k = \frac{k(k+1)}{2}
   \]
2. Count the number of divisors for each triangle number using **prime factorization**.

We keep increasing `k` until we find a triangle number whose divisor count is greater than `n`.

---

## Why Prime Factorization Helps

If a number can be written as:

\[
x = p_1^{a_1} p_2^{a_2} \cdots p_m^{a_m}
\]

then the number of divisors of `x` is:

\[
(a_1 + 1)(a_2 + 1)\cdots(a_m + 1)
\]

This is much faster than checking every possible divisor one by one.

---

## Optimization for Triangle Numbers

Instead of factoring the whole triangle number directly, we use:

- If `k` is even:
  \[
  T_k = \left(\frac{k}{2}\right)(k+1)
  \]

- If `k` is odd:
  \[
  T_k = k\left(\frac{k+1}{2}\right)
  \]

These two factors are coprime, so the divisor count of the triangle number is the product of the divisor counts of the two parts.

This reduces the amount of work significantly.

---

## Complexity

For each triangle number, divisor counting is done using prime factorization, which is much faster than a naive divisor scan.

This makes the solution efficient enough for the typical Project Euler version of the problem.

---

## Example

For `n = 5`, the first triangle number with more than 5 divisors is:

`28`

because its divisors are:

`1, 2, 4, 7, 14, 28`

So it has `6` divisors.

---

## Notes

- Use `long long` for triangle numbers because values grow quickly.
- Prime factorization is used to avoid expensive brute-force divisor counting.
- The loop stops as soon as a triangle number with enough divisors is found.