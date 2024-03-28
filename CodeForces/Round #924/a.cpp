#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int islandCount, bridgeDestroyCount;
	cin >> islandCount >> bridgeDestroyCount;
	cout << (bridgeDestroyCount >= islandCount - 1 ? 1 : islandCount) << endl;
  }
}