# Large Sum

## Problem Statement

Given 100 numbers, each 50 digits long, find the first 10 digits of their sum.

The numbers are too large to fit into normal integer types, so the solution must avoid overflow.

---

## Approach

The idea is to simulate **manual addition**.

Instead of adding the whole numbers as integers, we add them digit by digit from right to left, just like paper addition.

To do this safely, the numbers are stored as strings.

---

## Why Strings Are Used

A 50-digit number is much larger than `int` or `long long` can hold.

So each number is treated as a string such as:

```text
"37107287533902102798797998220837590246510135740250"
```

This lets us read one digit at a time without overflow.

---

## String Manipulation Logic

When adding two string numbers:

- Start from the last character of each string.
- Move left one digit at a time.
- Convert each character digit to its numeric value using `- '0'`.
- Add the digits and the carry.
- Store the result digit using `+ '0'`.
- Repeat until all digits and carry are processed.

### Example

If we add:

```text
"758"
"469"
```

we process it from right to left:

- `8 + 9 = 17` → write `7`, carry `1`
- `5 + 6 + 1 = 12` → write `2`, carry `1`
- `7 + 4 + 1 = 12` → write `2`, carry `1`
- final carry becomes the new leftmost digit

Result:

```text
1227
```

---

## Carry Logic

The carry is the extra value that remains after taking the last digit of a column sum.

If a column sum is:

- `sum = 7` → write `7`, carry `0`
- `sum = 17` → write `7`, carry `1`
- `sum = 123` → write `3`, carry `12`

In code:

- `sum % 10` gives the digit to store now.
- `sum / 10` gives the carry for the next column.

This is the same logic used in hand addition.

---

## How the Sum Is Built

A running total is kept as a string.

For each number in the list:

1. Add the current total and the new number using string addition.
2. Store the result back in `sum`.

After all 100 numbers are processed, the final sum is a very large string.

Then the first 10 digits are taken from the left.

---

## Important Notes

- `a[i] - '0'` converts a character digit like `'8'` into the number `8`.
- `(digit) + '0'` converts a number like `8` back into the character `'8'`.
- `const string&` is used in loops to avoid copying large strings unnecessarily.

---

## Result

The first 10 digits of the sum are:

`5537376230`