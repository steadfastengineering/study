/*
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

/*
  for a binomial (x+1)^n, its expansion will have several terms, the term,
  x^k will have the some coefficient.

  For (x+1)^2, that is n == 2, the expansion is, (x^2 + 2x + 1). In this
  instance, for k==2 the coefficient is 1, and for k==1, the coefficient is 2.

  Thus we write, C(n, k).
  And for these instances we have C(2, 2) = 1, and C(2,1) = 2.

  k : the power of the expanded term.
  n : the power of the binomial.
*/
int binomialCoefficient(int n, int k) {
    if (k == 0 || k == n){
      return 1;
    } else {
      return binomialCoefficient(n-1, k-1) + binomialCoefficient(n-1, k);
    }
}

// TODO: Memoized binomialCoefficient.

int main(){

  cout << binomialCoefficient(2, 2) << endl;
  cout << binomialCoefficient(2, 1) << endl;
  cout << binomialCoefficient(4, 2) << endl;
  cout << binomialCoefficient(4, 3) << endl;
  cout << binomialCoefficient(10, 6) << endl;

  return 0;
}
