#include <cstring>
#include <iostream>
using namespace std;

void solve() {
  string a;
  cin >> a;
  for (auto b_head = a.length() / 2; b_head >= 1; b_head--) {
    if (a[b_head] == '0')
      continue;
    const string a_str = a.substr(0, b_head),
                 b_str = a.substr(b_head, a.length() - b_head);
    if (a_str.length() > b_str.length() ||
        (a_str.length() == b_str.length() && a_str >= b_str))
      continue;
    cout << a_str << " " << b_str << endl;
    return;
  }
  cout << -1 << endl;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}