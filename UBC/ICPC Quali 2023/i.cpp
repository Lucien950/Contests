#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int numberLength(int n) {
	return (int) floor(log10(n)) + 1;
}

int main() {
	int tc;
	cin >> tc;
	string n;
	for (int t = 0; t < tc; t++) {
		cin >> n;
		vector<int> missingNumbers;
		for (int startingStrLen = 1; startingStrLen < n.length() / 2; startingStrLen++) {
			missingNumbers = {};
			int atNum = stoi(n.substr(0, startingStrLen)), strPos;
			for (strPos = 1; strPos < n.length(); strPos += numberLength(atNum)) {
				//next number goes from strPos to strEnd inclusive (0 index)
				int nextNumLength = numberLength(atNum + 1), nextValue = stoi(n.substr(strPos, nextNumLength));
				bool fail = false;
				while (nextValue < atNum) {
					nextNumLength += 1;
					nextValue = stoi(n.substr(strPos, nextNumLength));
					if (strPos + nextNumLength > n.length()) {
						fail = true;
						break;
					}
				}
				if (fail) break;
				for (int i = atNum; i < nextValue; i++) {
					missingNumbers.push_back(i);
				}
				atNum += 1;
			}
			if (strPos != n.length()) {
				continue;
			}
			// int num = stoi(n.substr(0, strLen));
			// int nextNum = num + 1;
			// int nextNumLen = numberLength(nextNum);
			// int nextNumStart = strLen;
			// while (nextNumStart + nextNumLen <= n.length()) {
			// 	if (stoi(n.substr(nextNumStart, nextNumLen)) != nextNum) {
			// 		break;
			// 	}
			// 	nextNum++;
			// 	nextNumLen = numberLength(nextNum);
			// 	nextNumStart += nextNumLen;
			// }
			// if (nextNumStart == n.length()) {
			// 	cout << num << endl;
			// 	break;
			// }
		}
		cout << missingNumbers.size() << endl;
		for (auto n: missingNumbers) {
			cout << n << endl;
		}
	}
}