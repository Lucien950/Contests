#include <iostream>

using namespace std;

enum class query_type { MIN = 1, MEX = 2 };
static array<bool, 100> minned{}, mexxed{};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
	minned.fill(false);
	mexxed.fill(false);

	int out_len, k, q_count;
	cin >> out_len >> k >> q_count;

	for (int i = 0; i < q_count; i++) {
	  int c, l, r;
	  cin >> c >> l >> r;
	  l--;
	  r--;
	  switch (static_cast<query_type>(c)) {
	  case query_type::MEX:
		fill(mexxed.begin() + l, mexxed.begin() + r + 1, true);
		break;
	  case query_type::MIN:
		fill(minned.begin() + l, minned.begin() + r + 1, true);
		break;
	  default:
		break;
	  }
	}

	// output
	// if you are mexxed, you cannot have k, and must have 0->k-1
	// if you are minned, you must have k, and must NOT have 0->k-1
	for (int i = 0; i < out_len; i++) {
	  if (minned[i] && mexxed[i]) {
		cout << k + 1;
	  } else if (minned[i]) {
		cout << k;
	  } else if (mexxed[i]) {
		cout << i % k;
	  } else {
		cout << 0;
	  }
	  cout << ' ';
	}
	cout << '\n';
  }
  cout << flush;
}