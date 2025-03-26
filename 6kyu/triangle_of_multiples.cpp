/*
See the following triangle:

____________________________________
 1                                      
 2   4   2                              
 3   6   9   6   3                      
 4   8   12  16  12  8   4             
 5   10  15  20  25  20  15  10  5   
 ___________________________________
 
The total sum of the numbers in the triangle, up to the 5th line included, is 225, part of it, 144, corresponds to the total sum of the even terms and 81 to the total sum of the odd terms.

Create a function that may output an array (in Haskell, a tuple) with three results for each value of n.

n  ---->  [total_sum, total_even_sum, total_odd_sum]
Our example will be:

5  ---->  [225, 144, 81]
Features of the random tests:

number of tests = 100
50 <= n <= 5000
Enjoy it!

*/

#include <array>

std::array<unsigned long, 3> multTriangle(const unsigned int n) {
  //your code here
  
  unsigned long odd = 0;
  unsigned long even = 0;
  int triangle_stop = 1;
  
  for(unsigned int i = 1; i <= n; i++){
    int j = 1;
    unsigned long val = i;
    while(j <= triangle_stop){
      if(val%2 == 0){
        even += val;
      }else{
        odd += val;
      }
      
      if(j <= triangle_stop/2){
        val += i;
      }else{
        val -= i;
      }
        
      j++;
    }
    triangle_stop += 2;
  }
  return {even+odd, even, odd};

