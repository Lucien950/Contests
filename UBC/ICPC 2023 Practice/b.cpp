#include <cmath>
#include <iostream>

using namespace std;

int main() {
  double r, f;
  cin >> r >> f;
  const int flip_count = static_cast<int>(round(f / r));
  const bool isUp = flip_count % 2 == 0;
  cout << (isUp ? "up" : "down") << endl;
}