#include <iostream>
using namespace std;

int main() {
  int b, t, p;
  cin >> b >> t >> p;
  t -= p;
  if (t >= b) {
	cout << 'Y' << ' ' << t - b << endl;
  } else {
	cout << 'N' << endl;
  }
}