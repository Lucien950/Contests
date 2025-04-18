#include <array>
#include <cstdint>
#include <iostream>

using namespace std;

static array<int, 26> s;
constexpr int MOD = 998244353;

int fact(int a) {
  for (int i = a; i > 1; i--) {
	a = a * i % MOD;
  }
  return a;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	uint64_t sum = 0;
	for (int i = 0; i < 26; i++) {
	  cin >> s[i];
	  sum += s[i];
	}
  }
}