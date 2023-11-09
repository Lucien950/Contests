#include <iostream>

using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    for (int testCase = 0; testCase < testCases; testCase++) {
        int letterFreq[26] = {0};
        int stringLength, deleteCount;
        cin >> stringLength >> deleteCount;
        for (int i = 0; i < stringLength; i++) {
            char letter;
            cin >> letter;
            letterFreq[letter - 'a']++;
        }


        int oddFrequencies = 0;
        for (int i = 0; i < 26; i++) {
            if (letterFreq[i] % 2 == 1) {
                oddFrequencies++;
            }
        }

        cout << (deleteCount - oddFrequencies + 1 >= 0 ? "YES" : "NO") << endl;
    }
}