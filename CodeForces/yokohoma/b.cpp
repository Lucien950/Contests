#include <cassert>
#include <cstdint>
#include <iostream>

using namespace std;

int main() {
  uint64_t a, b;
  cin >> a >> b;
  if (a == b) {
	cout << a << endl;
	return EXIT_SUCCESS;
  }
  // we know that a ^ b != 0, thus __builtin_clzll(a ^ b) is defined behaviour
  const uint8_t first_non_matching = 64 - __builtin_clzll(a ^ b) - 1;
  // this mask preserves all the bits that are not matching
  const uint64_t lower_mask = (1ULL << first_non_matching + 1) - 1;
  // this is defined behaviour as if a&lower_mask == 0, then the values of pos_first_1 and pos_last_1 are not used
  const uint8_t pos_first_1 = 64 - __builtin_clzll(a & lower_mask) - 1, pos_last_1 = __builtin_ctzll(a & lower_mask);
  const bool has_no_1s = (a & lower_mask) == 0, is_pow_2 = pos_first_1 == pos_last_1;
  const uint64_t out = has_no_1s || is_pow_2 ? a : a & ~lower_mask | 1ULL << pos_first_1 + 1;
  cout << out << endl;
}
