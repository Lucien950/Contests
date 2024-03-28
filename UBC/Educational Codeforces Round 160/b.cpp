#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    int zero_count = 0, one_count = 0;
    for (basic_string<char>::size_type i = 0; i < s.length(); i++) {
      if (s[i] == '1') {
        one_count++;
      } else {
        zero_count++;
      }
    }

    basic_string<char>::size_type last_valid = 0;
    for (; last_valid < s.length(); last_valid++) {
      int *opposite_count = s[last_valid] == '1' ? &zero_count : &one_count;
      if (*opposite_count == 0) {
        break;
      }
      (*opposite_count)--;
    }

    cout << s.length() - last_valid << endl;
  }
}