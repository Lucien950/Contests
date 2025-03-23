#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int r, g;
  cin >> r >> g;

  int h = floor(sqrt(2 * (r + g) + 0.25) - 0.5);
  cout << h << endl;
}