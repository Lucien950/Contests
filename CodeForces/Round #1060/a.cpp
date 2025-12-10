#include <cassert>
#include <cstdint>
#include <iostream>
#include <optional>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n, k;
	cin >> n >> k;

	optional<int32_t> last_one_pos = nullopt;
	uint32_t out = 0;
	for (int i = 0; i < n; i++) {
	  char c;
	  cin >> c;
	  if (c == '0')
		continue;
	  assert(c == '1');
	  out += !last_one_pos.has_value() || i - last_one_pos.value() > k - 1;
	  last_one_pos = i;
	}
	cout << out << "\n";
  }
  cout << flush;
}