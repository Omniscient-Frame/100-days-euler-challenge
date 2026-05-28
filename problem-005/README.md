#problem approach

~ prolem states that "What is the smallest positive number that is evenly
divisible by all of the numbers from 1 to n?"

solution - The smallest positive number evenly divisible by all numbers
from 1 to n is the Least Common Multiple (LCM) of those numbers.

Mathematical Solution

The LCM of 1 to n is found by:

	Finding all prime numbers ≤ n

	For each prime p, take the largest power of p that is ≤ n

	Multiply all these prime powers together

Formula:

	LCM(1,2,…,n)= p≤n∏p^⌊log_base(p) n⌋

looking tedious but easy once understood

for example:n=10 
| Prime | Largest power ≤ 10 | Value |
| ----- | ------------------ | ----- |
| 2     | 2³ = 8             | 8     |
| 3     | 3² = 9             | 9     |
| 5     | 5¹ = 5             | 5     |
| 7     | 7¹ = 7             | 7     |


#LCM=8×9×5×7=2520
let another example: n=20

| Prime | Largest power ≤ 20 | Value |
| ----- | ------------------ | ----- |
| 2     | 2⁴ = 16            | 16    |
| 3     | 3² = 9             | 9     |
| 5     | 5¹ = 5             | 5     |
| 7     | 7¹ = 7             | 7     |
| 11    | 11¹ = 11           | 11    |
| 13    | 13¹ = 13           | 13    |
| 17    | 17¹ = 17           | 17    |
| 19    | 19¹ = 19           | 19    |

enough maths let's understand my code :

the question is simply asking for LMC so I created a LCM fuction 

if you want you can create LCM function using GCD:
	LCM(a,b) = (a*b)/GCD(a,b)

what does smallest mutliple function do ?
	0. res = 1 #since every number is multiple of 1
	1. looping i from 2 to n
	2. res stores the LCM of res and i

for example: n=5
	1.res=1,i=2:
	  res = LCM(1,2)
	  res = 2
	2.res=2,i=3:
	  res = LCM(2,3) = 6
	3.res=6,i=4:
	  res = LCM(6,4) = 12
	4.rer=12,i=5:
	  res = LCM(12,5) = 60

and thats the answer.
