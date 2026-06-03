# Project Euler Problem 11 — Largest Product in a Grid

## Problem Statement

Given a 2D grid of numbers, find the greatest product of four adjacent numbers in the same direction.

The four numbers can be adjacent in any of these directions:

- Left to right.
- Top to bottom.
- Diagonal down-right.
- Diagonal down-left.

---

## Approach

The solution is to check every cell in the grid and calculate the product of 4 numbers in each valid direction.

For each cell:

- Check if there is enough space to the **right** for 4 numbers.
- Check if there is enough space **downward** for 4 numbers.
- Check if there is enough space on the **down-right diagonal**.
- Check if there is enough space on the **down-left diagonal**.

If a direction is valid, multiply those 4 values and compare the result with the current maximum product.

---

## Why This Works

Every possible group of 4 adjacent numbers appears in one of the four directions listed above.

By scanning all cells and all valid directions, we ensure that no valid product is missed.

---

## Important Details

- Boundary checks are necessary to avoid going outside the grid.
- The grid may contain numbers with leading zeros, so they should be treated as normal integers.
- Keep a variable like `maxProduct` to store the largest product found so far.

---

## Time Complexity

If the grid has `rows x cols`, then each cell checks up to 4 directions.

So the time complexity is:

`O(rows * cols)`

This is efficient enough for a 20 x 20 grid.

---

## Example

If a cell has values:

- right: `8, 2, 22, 97`
- down: `8, 49, 81, 52`

the code computes both products and keeps the larger one.

---

## Result

For the classic Project Euler 11 grid, the greatest product of four adjacent numbers is:

`70600674`