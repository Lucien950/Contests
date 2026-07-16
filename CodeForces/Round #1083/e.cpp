#include <iostream>
using namespace std;

int main() {
  int c;
  cin >> c;
  static array<int, 8000> t_buf{};
  while (c--) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
	  cin >> t_buf[i];
	}
	span t(t_buf.data(), n);

	//
  }
}