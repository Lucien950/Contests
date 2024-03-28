#include <iostream>
using namespace std;

unsigned int bit_multiset[30] = {0};

bool get_check(int v) {
  unsigned int copy[30] = {0};
  for (int i = 0; i < 30; i++) {
    copy[i] = bit_multiset[i];
  }

  for (int start_search_i = 0; v != 0; start_search_i++) {
    if (const bool last_digit_is_zero = v % 2 == 0; last_digit_is_zero) {
      v >>= 1;
      continue;
    }

    int search_i = start_search_i;
    unsigned int need = 1;
    for (; need != 0 && search_i >= 0; need *= 2, search_i--) {
      // take as much as needed, however at least as many as is available
      const unsigned int should_take = min(need, copy[search_i]);
      copy[search_i] -= should_take;
      need -= should_take;
    }
    if (need != 0)
      return false;
    v >>= 1;
  }

  return true;
}

int main() {
  unsigned int m;
  cin >> m;
  while (m--) {
    int t, v;
    cin >> t >> v;
    // t == 1 -> ADD
    if (t == 1)
      bit_multiset[v]++; // v is in [0, 29]
    // t == 2 -> GET
    else {
      cout << (get_check(v) ? "YES" : "NO") << endl;
    }
  }
}

// 4, 1, then 5
// 2, 2, then 4
