#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;

	vector<vector<int>> blogs(n);
	for (int i = 0; i < n; i++) {
	  int l;
	  cin >> l;

	  vector<int> temp(l);
	  for (int j = 0; j < l; j++) {
		cin >> temp[j];
	  }
	  reverse(temp.begin(), temp.end());

	  blogs[i].reserve(l);
	  set<int> seen{};
	  for (const auto b : temp) {
		if (seen.contains(b))
		  continue;
		blogs[i].push_back(b);
		seen.emplace(b);
	  }
	}

	set<int> seen{};
	vector<int> out{};
	for (int i = 0; i < n; i++) {
	  // pop min
	  const auto m = min_element(blogs.begin(), blogs.end());
	  vector<int> mm = std::move(*m);
	  blogs.erase(m);

	  // add and remove
	  for (const int x : mm) {
		if (seen.contains(x))
		  continue;
		out.push_back(x);
		seen.insert(x);
		for (vector<int>& b : blogs) {
		  erase(b, x);
		}
	  }
	}

	for (const int i : out) {
	  cout << i << ' ';
	}
	cout << '\n';
  }
  cout << flush;
}