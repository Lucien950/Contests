#include <iostream>
#include <algorithm>

using namespace std;

int problemLengths[50];

int main() {
	int problemCount, codeSpeed, linesCanWrite;
	cin >> problemCount >> codeSpeed;
	linesCanWrite = codeSpeed * 5;
	for (int i = 0; i < problemCount; i++) {
		cin >> problemLengths[i];
	}
	sort(problemLengths, problemLengths + problemCount);

	int problemsCanSolve = 0;
	for (int pc = 0; pc < problemCount; pc++) {
		if (linesCanWrite < problemLengths[pc]) break;
		linesCanWrite -= problemLengths[pc];
		problemsCanSolve += 1;
	}
	cout << problemsCanSolve << endl;
}