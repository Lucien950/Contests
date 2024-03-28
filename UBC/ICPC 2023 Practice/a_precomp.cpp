#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(const int i) {
  for (int divisor = 2; divisor <= ceil(sqrt(i)); divisor++) {
	if (i % divisor == 0)
	  return false;
  }
  return true;
}

int main() {
  int primesFound = 1;
  int i;
  for (i = 2; primesFound < 2024; i++) {
	if (isPrime(i)) {
	  primesFound++;
	  cout << primesFound << " " << i << endl;
	}
  }
  cout << i << endl;
}