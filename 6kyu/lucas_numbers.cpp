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