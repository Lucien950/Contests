#include <array>
#include <cassert>
#include <iostream>

using namespace std;

static array<int, 10> x;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
	cin >> x[i];

  assert(x[0] % 3 == 0);
  assert(x[n - 1] % 3 == 0);
  const int a = x[0] / 3, c = x[n - 1] / 3, b = x[1] - 2 * a;
  cout << a << " " << b << " " << c << endl;
}