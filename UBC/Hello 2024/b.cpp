#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    int pen = 0;
    for (int i = 0; i < n; i++) {
      pen += (s[i] == '+') ? 1 : -1;
    }
    cout << abs(pen) << endl;
  }
}