#include <array>
#include <cassert>
#include <iostream>
using namespace std;

static constexpr size_t MAX_N = 2e5;
static array<uint32_t, MAX_N> a_buf{};

int main() {
  int t;
  cin >> t;
  while (t--) {
	size_t n;
	cin >> n;
	span a(a_buf.data(), n);
	for (size_t i = 0; i < n; i++) {
	  cin >> a[i];
	}

	uint64_t extra_books = 0;
	bool works = true;
	for (size_t i = 0; i < n; i++) {
	  if (a[i] + extra_books >= i + 1) {
		extra_books += a[i] - (i + 1);
	  } else {
		works = false;
	  }
	}
	cout << (works ? "YES" : "NO") << endl;
  }
}