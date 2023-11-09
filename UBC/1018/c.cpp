#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int c = 0; c < t; c++) {
        int setSize;
        cin >> setSize;
        int s[setSize];
        int maxX = 0;
        for (int i = 0; i < setSize; i++) {
            cin >> s[i];
            maxX = max(maxX, s[i]);
        }
        int lastVal = -1, firstNonAppearance = maxX + 1;
        for (int i = 0; i < setSize; i++) {
            if (s[i] != lastVal + 1) {
                firstNonAppearance = i;
                break;
            }
            lastVal = s[i];
        }

        int feedback = 0;
        int move = firstNonAppearance;
        while (feedback != -1) {
            cout << move << endl;
            cin >> feedback;
            if (feedback == -2) return 0;
            move = feedback;
        }
    }
}