#include <iostream>

using namespace std;

int main() {
  while (true) {
	int n;
	cin >> n;
	if (n == 0) {
	  break;
	}
	int out = 0;
	for (int i = 0; i < n; i++) {
	  int a;
	  cin >> a;
	  if (out + a <= 300)
		out += a;
	}

	cout << out << endl;
  }
}