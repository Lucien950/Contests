#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int num_count, target;
	cin >> num_count >> target;

	std::unordered_map<int, int> the_map;
	for (int i = 0; i < num_count; i++) {
	  int x;
	  cin >> x;
	  the_map[x]++;
	}

	// const int turn_count = num_count / 2;
	int out = 0;
	for (int i = 1; i <= target / 2; i++) {
	  if (2 * i == target)
		out += the_map[i] / 2;
	  else
		out += min(the_map[i], the_map[target - i]);
	}
	cout << out << endl;
  }
}