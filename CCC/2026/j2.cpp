#include <iostream>
#include <numeric>
using namespace std;

int main() {
  std::array<int, 5> a{};
  for (int i = 0; i < 5; i++) {
	cin >> a[i];
  }
  int d;
  cin >> d;
  sort(a.begin(), a.end());
  const auto sum = accumulate(a.begin() + 1, a.end() - 1, 0);
  cout << sum * d << endl;
}