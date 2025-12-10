#include <iostream>
using namespace std;

int main() {
  for (int i = 0; i < 99; i++) {
	int x;
	cin >> x;
  }

  int y;
  cin >> y;

  cout << (y % 10 == 0 ? 10 : y % 10) << endl;
}