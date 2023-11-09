#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int c = 0; c < t; c++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int bstring[n];
        for (int i = 0; i < n; i++) {
            bstring[i] = s[i] - '0';
        }

        int mismatches = 0, matches = 0; // mismatches is a lower bound
        for (int i = 0; i < n / 2; i++) {
            if (bstring[i] != bstring[n - i - 1]) {
                mismatches++;
            } else {
                matches++;
            }
        }
        bool isOdd = n % 2 != 0;
        for (int i = 0; i < mismatches; i++) {
            cout << 0;
        }
        for (int i = mismatches; i < n + 1; i++) {
            // mismatches + x * 2 = i or mismatches + x * 2 + 1 = i
            if ((i - mismatches) % 2 == 0 && (i - mismatches) / 2 <= matches) {
                cout << 1;
            } else if (isOdd && (i - mismatches - 1) % 2 == 0 && ((i - mismatches - 1) / 2 <= matches)) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
        cout << endl;
    }
}