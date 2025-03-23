#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int bowl_count, colour_count;
  cin >> bowl_count >> colour_count;

  vector<long long> colour_sizes(colour_count, 0);
  for (int i = 0; i < colour_count; i++) {
	cin >> colour_sizes[i];
  }
  ranges::sort(colour_sizes);
  const long long max_gap = bowl_count - colour_sizes[1];
  const long long max_bowl_count = max(1ll, (colour_sizes[0] + 1) / (max_gap + 1));
  cout << max_bowl_count << endl;
}