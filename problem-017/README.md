# Number Letter Counter

A C++ solution to **Project Euler Problem 17** - counting the total number of letters used when writing out numbers from 1 to a given limit in words.

## Problem Statement

> If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = **19 letters** used in total.
>
> If all the numbers from 1 to a given limit (inclusive) were written out in words, how many letters would be used?

**Notes:**
- Do not count spaces or hyphens
- The use of "and" follows British usage (e.g., 342 = "three hundred and forty-two" = 23 letters)
- Example: 115 = "one hundred and fifteen" = 20 letters

## Example

| Number | In Words | Letter Count |
|--------|----------|--------------|
| 1 | one | 3 |
| 5 | five | 4 |
| 342 | three hundred and forty-two | 23 |
| 115 | one hundred and fifteen | 20 |
| 1000 | one thousand | 11 |

## Features

- ✅ Counts letters for a single number (`LetterCounter(int n)`)
- ✅ Sums letters from 1 to any limit (`TotalLetters(int limit)`)
- ✅ Handles all numbers 1–1000 correctly
- ✅ Follows British English number formatting (with "and")
- ✅ No spaces or hyphens counted

## Algorithm Overview

The solution uses precomputed letter counts for:

| Category | Array | Examples |
|----------|-------|----------|
| 1–9 | `once_counts[]` | one(3), two(3), three(5), four(4) |
| 10, 20–90 | `tens_counts[]` | ten(3), twenty(6), thirty(6) |
| 11–19 | `eleven_counts[]` | eleven(6), twelve(6), thirteen(7) |

For numbers 100–999:
```
count = (hundreds digit) + "hundred"(7) + "and"(3) + (remainder)
```

## License

Free to use for learning purposes.

## References

- [Project Euler Problem 17](https://projecteuler.net/problem=17)
- [Project Euler - Stack Overflow Discussion](https://stackoverflow.com/questions/8192969/project-euler-17)