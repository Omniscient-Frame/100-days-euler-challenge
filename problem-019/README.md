# Counting Sundays - Project Euler Problem 19

A C++ solution to **Project Euler Problem 19** - counting how many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000).

## Problem Statement

> How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

**Given Information:**
- 1 Jan 1900 was a **Monday**
- **Month lengths**:
  - 30 days: September, April, June, November
  - 31 days: All others (except February)
  - 28 days: February (rain or shine)
  - 29 days: February in leap years
- **Leap year rule**: 
  - Divisible by 4 ✓
  - But NOT by 100 ✗ (unless also divisible by 400 ✓)

## Approach: Tracking Weekdays

### Key Insight

Instead of trying to calculate the weekday for each date independently, we **track the weekday sequentially**:

First of Month N → Add days in Month N → First of Month N+1


### Weekday Representation

Use **0-6** to represent days:
| Number | Day |
|--------|-----|
| 0 | Monday |
| 1 | Tuesday |
| 2 | Wednesday |
| 3 | Thursday |
| 4 | Friday |
| 5 | Saturday |
| 6 | Sunday |

### Step 1: Find 1 Jan 1901

We start from **1 Jan 1900 = Monday (0)**.

1900 is **not a leap year** (divisible by 100, not by 400), so it has **365 days**.

365 mod 7 = 5


Therefore: **1 Jan 1901 = Monday + 5 = Saturday (6)**

### Step 2: Month Lengths Modulo 7

```cpp
Month:  Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec
Days:   31   28   31   30   31   30   31   31   30   31   30   31
Mod 7:   3    0    3    2    3    2    3    3    2    3    2    3
```

In leap years, February has 29 days (29 mod 7 = 1).

### Step 3: Algorithm

- Initialize: weekday = 6 (Saturday, 1 Jan 1901)
- For each year from 1901 to 2000:
- Set month lengths (February = 29 if leap year)
- For each month:
-     If weekday == 6 (Sunday): increment count
-     weekday = (weekday + days_in_month) % 7

- Return count

## How It Works (Example)

Start: 1 Jan 1901 = Saturday (6)

January (31 days):
- First = Saturday (not Sunday)
- Next first = (6 + 31) % 7 = (6 + 3) % 7 = 2 (Wednesday)

February (28 days in 1901):
- First = Wednesday (not Sunday)
- Next first = (2 + 28) % 7 = (2 + 0) % 7 = 2 (Wednesday)

March (31 days):
- First = Wednesday (not Sunday)
- Next first = (2 + 31) % 7 = (2 + 3) % 7 = 5 (Saturday)

... continue for all 1200 months (100 years × 12 months)


## Complexity Analysis

| Metric | Value |
|--------|-------|
| **Time** | O(n) where n = 100 years |
| **Operations** | 1200 iterations (100 × 12 months) |
| **Space** | O(1) - just a few variables |

Very efficient! Runs in milliseconds.

## Key Concepts

### Why This Works

1. **Modular arithmetic**: `(weekday + days) % 7` wraps around correctly
2. **Sequential tracking**: Each month's first day depends only on the previous
3. **No calendar library needed**: Pure math solution

### Leap Year Details

| Year | Divisible by 4? | Divisible by 100? | Divisible by 400? | Leap? |
|------|-----------------|-------------------|-------------------|-------|
| 1900 | ✓ | ✓ | ✗ | ❌ No |
| 1904 | ✓ | ✗ | - | ✓ Yes |
| 1996 | ✓ | ✗ | - | ✓ Yes |
| 2000 | ✓ | ✓ | ✓ | ✓ Yes |

## Test Cases

| Period | Expected Sundays on 1st |
|--------|------------------------|
| 1901 only | 2 |
| 1901-1910 | 17 |
| 1901-2000 | **171** |

## The Answer

**171 Sundays** fell on the first of the month during the twentieth century.

## Files

| File | Description |
|------|-------------|
| `counting_sundays.cpp` | Main implementation |
| `README.md` | This documentation |

## Learning Concepts

This project demonstrates:
- **Modular arithmetic** for day-of-week calculations
- **Leap year logic** with multiple conditions
- **Sequential state tracking** instead of recalculating
- **Array manipulation** for month lengths
- **Nested loops** for years and months


## References

- [Project Euler Problem 19](https://projecteuler.net/problem=19)
- [Leap Year Explanation](https://en.wikipedia.org/wiki/Leap_year)
- [Doomsday Algorithm](https://en.wikipedia.org/wiki/Doomsday_algorithm) - Alternative weekday calculation

## License

Free to use for learning purposes.