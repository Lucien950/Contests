#include <iostream>

using namespace std;

int p[1e9];

int main() {
  unsigned int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
  }
}