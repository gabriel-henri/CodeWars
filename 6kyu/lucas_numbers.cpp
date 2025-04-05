/*
Lucas numbers are numbers in a sequence defined like this:

L(0) = 2
L(1) = 1
L(n) = L(n-1) + L(n-2)
Your mission is to complete the function that returns the 
nth term of this sequence.

Note: It should work for negative numbers as well; how you
 do this is you flip the equation around, so for negative 
 numbers: L(n) = L(n+2) - L(n+1)
*/

long long int lucasnum(int n){
    long long int l0 = 2;
    long long int l1 = 1;
    long long int prox;
    
    if(n == 0)
      return l0;
    if(n == 1)
      return l1;
    
    if(n > 0){
      for(int i = 2; i <= n; i++){
        prox = l0 + l1;
        l0 = l1;
        l1 = prox;
      }
    }else{
      for(int i = -1; i >= n; i--){
        prox = l1 - l0;
        l1 = l0;
        l0 = prox;
      }
    }
    return prox;
  }