#include <array>
#include <iostream>
#include <ranges>

using namespace std;

// assume that all arrays passed in are sorted
bool solve(const array<int, 3>& one, const array<int, 3>& two, const array<int, 3>& three) {
  for (const int x : ranges::iota_view(0, 3)) {
	array perm1{0, 1, 2};
	do {
	  array perm2{0, 1, 2};
	  do {
		const auto [x1, w1, y] = perm1;
		const auto [x2, w2, z] = perm2;
		if (two[x1] + three[x2] != one[x])
		  continue;
		if (two[w1] + three[w2] != 180)
		  continue;
		array comp{one[x], two[y], three[z]};
		sort(comp.begin(), comp.end());
		if (equal(comp.begin(), comp.end(), one.begin()))
		  return true;
	  } while (next_permutation(perm2.begin(), perm2.end()));
	} while (next_permutation(perm1.begin(), perm1.end()));
  }
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	int a1, b1, c1, a2, b2, c2, a3, b3, c3;
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> a3 >> b3 >> c3;
	const array<int, 3> one{a1, b1, c1}, two{a2, b2, c2}, three{a3, b3, c3};
	// assume mthat they are already sorted
	const bool solvable = solve(one, two, three) || solve(one, two, two) || solve(one, three, three);
	cout << (solvable ? "YES\n" : "NO\n");
  }
  cout << flush;
}