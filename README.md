# c-problem-solving

This hobby project uses C to solve numeric puzzles as those proposed by Project Euler.

## Table of contents

**Project Euler problems:**
[1](#project-euler-001-multiples-of-3-or-5), ..., [5](#project-euler-005-smallest-multiple), [6](#project-euler-006-sum-square-difference).

## Project Euler 001: Multiples of 3 or 5

_If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23. Find the sum of all the multiples of 3 or 5 below 1000._
[(source)](https://projecteuler.net/problem=1)

``` C
int main(int argc, [[maybe_unused]] char* argv[argc+1])
{
  uint64_t sum = 0;
  for (uint64_t i = 1; i < 1000; i++) {
    if ((i % 3 == 0) || (i % 5 == 0)) {
        sum += i;
      }
  }
  printf("Solution: %llu\n", sum);
  return EXIT_SUCCESS;
}
```

## Project Euler 005: Smallest Multiple

_2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder. What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?_ [(source)](https://projecteuler.net/problem=5)

``` C
int main(int argc, [[maybe_unused]] char* argv[argc+1])
{
  uint64_t res = 1;
  for (uint64_t i = 1; i <= 20; i++) {
    res = lcm(res, i);
  }
  printf("Solution: %llu\n", res);
  return EXIT_SUCCESS;
}
```

## Project Euler 006: Sum Square Difference

_The sum of the squares of the first ten natural numbers is  
1^2 + 2^2 + ... + 10^2 = 385  
The square of the sum of the first ten natural numbers is  
(1 + 2 + ... + 10)^2 = 552 = 3025  
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.  
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum._  
[(source)](https://projecteuler.net/problem=6)

``` C
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, [[maybe_unused]] char* argv[argc+1])
{
  uint64_t res = 0;
  for (uint64_t i = 1; i <= 100; i++) {
    res = res + i;
  }
  res = res * res;
  for (uint64_t i = 1; i <= 100; i++) {
    res = res - i * i;
  }
  printf("Solution: %llu\n", res);
  return EXIT_SUCCESS;
}
```

(end of README)
