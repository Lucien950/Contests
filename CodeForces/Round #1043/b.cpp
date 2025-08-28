#include <cmath>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	uint64_t n;
	cin >> n;

	vector<uint64_t> out{};
	for (int k = 1; static_cast<uint64_t>(pow(10, k)) + 1ull <= n; k++) {
	  if (n % (static_cast<uint64_t>(pow(10, k)) + 1ull) == 0) {
		out.push_back(n / (static_cast<uint64_t>(pow(10, k)) + 1ull));
	  }
	}

	cout << out.size() << "\n";
	for (const auto& at : std::ranges::reverse_view(out)) {
	  cout << at << " ";
	}
	cout << (!out.empty() ? "\n" : "");
  }
  cout << flush;
}