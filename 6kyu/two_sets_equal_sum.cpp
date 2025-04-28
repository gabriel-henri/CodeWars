/*
vTask
If possible, divide the integers 1,2,…,n into two sets of equal sum.

Input
A positive integer n <= 1,000,000.

Output
If it's not possible, return [ ] (Python, Javascript, Swift, 
Ruby) or ( ) (Python) or [ [],[] ] (Java, C#, C++, Kotlin) 
or None (Scala) or Nothing (Haskell) or nil (Lua).
If it's possible, return two disjoint sets. Each integer 
from 1 to n must be in one of them. The integers in the first 
set must sum up to the same value as the integers in the 
second set. The sets can be returned in a tuple, list, or 
array, depending on language.

Examples:
For n = 8, valid answers include:
[1, 3, 6, 8], [2, 4, 5, 7] (or [[1, 3, 6, 8], [2, 4, 5, 7]])
[8, 1, 3, 2, 4], [5, 7, 6]
[7, 8, 3], [6, 1, 5, 4, 2], and others.

For n = 9 it is not possible. For example, try [6, 8, 9] 
and [1, 2, 3, 4, 5, 7], but the first sums to 23 and the 
second to 22. No other sets work either.

Source: CSES
*/

#include <vector>

std::array<std::vector<int>, 2> createTwoSetsOfEqualSum(int n) {
    std::array<std::vector<int>, 2> sets; // Create array of 2 vectors of integers.
    
    long long num = n;
    long long total = ((num+1)* num)/2;
    
    if(total%2 != 0)
      return sets;
    
    long long first_vector_total = 0;
    for(int i = n; i >= 1; i--){
      if(first_vector_total + i <= total/2){
        sets[0].push_back(i);
        first_vector_total += i;
      }
      else{
        sets[1].push_back(i);
      }
    }
    
    // Write code here to divide the numbers 1,2,…,n into two vectors of equal sum, if possible.
    // If it's not possible, return two empty vectors, i.e. [ [ ], [ ] ].
    
    return sets;
}