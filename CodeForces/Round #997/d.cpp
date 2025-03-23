#include <array>
#include <cstdint>
#include <iostream>
using namespace std;

static array<int, static_cast<size_t>(1e5 + 1)> a;

/**
 * @param subarr_len length of the subarray (even)
 * @param freq Frequency array (NOTE NOT MODIFIED, ONLY ADD 0s IF NOT PRESENT)
 * @return if medians are matching
 */
static bool matching_medians(const int subarr_len, const array<int, 11>& freq) {
  uint64_t seen = 0;
  for (int at = 1; at <= 10; at++) {
	seen += freq[at];
	if (seen >= subarr_len / 2) { // subarr_len/2 should be an integer
	  return seen > subarr_len / 2;
	}
  }

  throw std::invalid_argument("you fucked up buddy");
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
	  cin >> a[i];
	}

	int out = 0;
	for (int sub_arr_size = 1; sub_arr_size <= n; sub_arr_size++) {
	  if (sub_arr_size % 2 == 1) {
		out += n - sub_arr_size + 1;
		continue;
	  }

	  // sub_arr_size is even
	  array<int, 11> freq{0};
	  for (int i = 0; i < sub_arr_size - 1; i++) { // fill up to but not including last one
		freq[a[i]]++;
	  }

	  // slide window
	  for (int start = 0; start < n - sub_arr_size + 1; start++) {
		freq[a[start + sub_arr_size - 1]]++;
		out += matching_medians(sub_arr_size, freq); // O(1) (constant factor?)
		freq[a[start]]--;
	  }
	}
	cout << out << "\n";
  }
  cout << endl;
}