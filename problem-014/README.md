# Longest Collatz Sequence (Project Euler)

## Problem

We define the following iterative sequence for positive integers:

- If `n` is even:  
  `n → n / 2`
- If `n` is odd:  
  `n → 3n + 1`

Example starting from 13:

`13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1`

This sequence has 10 terms (including both 13 and 1).

It is *believed* (Collatz Conjecture) that every positive integer eventually reaches 1 using this rule.

**Task:**  
For a given `limit`, find the starting number `< limit` that produces the **longest** Collatz chain.

---

## Naive Approach

A straightforward solution is:

1. For each starting number `i` from `1` to `limit - 1`:
   - Set `temp = i` and `count = 1`.
   - While `temp != 1`:
     - If `temp` is even, set `temp = temp / 2`.
     - Else, set `temp = 3 * temp + 1`.
     - Increment `count`.
   - Keep track of the maximum `count` and the `i` that produced it.

This works logically but is slow for large limits because it recomputes many sequences again and again.

Example: the chain for 13 goes through 40, 20, 10, 5, 16, 8, 4, 2.  
Later, when you start from 10 or 5, you recompute the same parts of the sequence. [web:367]

---

## Optimization Idea: Memoization (Caching)

Key observation:

- Many Collatz sequences **overlap**.
- If you already know the length of the chain starting at some number `m`,  
  and later a new sequence reaches `m`, you don’t need to continue from there.

You can save a lot of work by **caching** the chain lengths.

### What we cache

We use an array (or map) `cache`:

- `cache[n]` = length of the Collatz chain starting at `n` (including `n` itself).
- Initialize `cache[1] = 1` because the chain starting at 1 has length 1.

### Collatz length function with memoization

Conceptual function:

```cpp
int collatzLength(long long n, vector<int>& cache) {
    if (n == 1) return 1;

    // If we've seen n before and it fits in the cache, reuse it
    if (n < cache.size() && cache[n] != 0) {
        return cache[n];
    }

    long long next;
    if (n % 2 == 0) next = n / 2;
    else           next = 3 * n + 1;

    int len = 1 + collatzLength(next, cache);

    if (n < cache.size()) {
        cache[n] = len;
    }

    return len;
}
```

How this matches your idea:

- When computing the chain for `i`, as soon as you hit a number whose length is already stored in `cache`, the recursion returns that length.
- The `+ 1` in `1 + collatzLength(next, cache)` accounts for the step from `n` to `next`.
- As the recursion unwinds, it fills the cache for all the intermediate numbers you visited.

So the “extra addition of count it takes to go from `i` to that already computed number” happens automatically through recursive returns and `+ 1`.

---

## Main Loop

With the helper above, the main logic is:

1. Create a cache sized to `limit` and set `cache[1] = 1`.
2. For every starting number `i` from `1` to `limit - 1`:
   - Compute `len = collatzLength(i, cache)`.
   - If `len` is greater than the best found so far, update:
     - `bestLength = len`
     - `bestNumber = i`
3. Return `bestNumber` as the answer.

We typically use `long long` for the running `n` inside the Collatz computation because values can grow larger than the starting value before coming back down. 

---

## Why This Is Faster

- **Naive method:** recomputes entire chains for overlapping sequences.
- **Memoized method:** each distinct number’s chain length is computed **once**, then reused whenever it appears again.

This drastically reduces the total amount of work, especially for large limits such as 1,000,000.

---

## Notes

- The problem is related to the famous **Collatz Conjecture**, which is still unproved.
- In practice, this memoized approach is the standard way to solve the “longest Collatz sequence under `limit`” efficiently.
- For safety with larger limits, the internal Collatz variable should be `long long`.
