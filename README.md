# c-problem-solving

This hobby project uses C to solve numeric puzzles as those proposed by Project Euler.

## Table of contents

**Project Euler problems:**
[1](#project-euler-1-multiples-of-3-or-5), ..., [5](#project-euler-5-smallest-multiple), [6](#project-euler-6-sum-square-difference), ... , [9](#project-euler-9-special-pythagorean-triplet).

## Project Euler 1: Multiples of 3 or 5

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

## Project Euler 5: Smallest Multiple

_2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder. What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?_  
[(source)](https://projecteuler.net/problem=5)

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

## Project Euler 6: Sum Square Difference

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

## Project Euler 9: Special Pythagorean Triplet
    
_A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2  
For example, 32 + 42 = 9 + 16 = 25 = 52.  
There exists exactly one Pythagorean triplet for which a + b + c = 1000.  
Find the product abc._  
[(source)](https://projecteuler.net/problem=9)

``` C
int main(int argc, [[maybe_unused]] char* argv[argc+1]) {
  uint64_t n = 1000;
  uint64_t nbSolutions = 0;
  uint64_t res = 0;
  for (uint64_t c = n; c >= 3; c--) {
    // upper limit for b:
    //   (i) b < c
    //   (ii) b = 1000-c-a with a >= 1 thus b <= 1000-c-1
    // lower limit for b:
    //   (i) 1 <= a < b thus b > 1
    //   (ii) 1000-c = a+b with a < b thus 1000-c < 2b  
    uint64_t bmax = min(c-1, n-c-1);
    uint64_t bmin = max(2, (n-c)/2);
    for (uint64_t b = bmax; b >= bmin; b--) {
      uint64_t a = n-b-c;
      if (c*c == a*a + b*b) {
        nbSolutions++;
        res = a*b*c;
      }
    }
  }
  printf("Solution: %llu (%llu solution)\n", res, nbSolutions);
  return EXIT_SUCCESS;
}
```

<!-- 31875000 --> 

(end of README)
