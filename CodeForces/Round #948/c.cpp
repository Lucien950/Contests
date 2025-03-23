#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a) {
	  cin >> i;
	}
  }
}