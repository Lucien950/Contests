#include <iostream>
#include <vector>

using namespace std;

int main(){
	int cases;
	cin >> cases;
	for(int caseNum = 0; caseNum < cases; caseNum++){
		int n;
		cin >> n;
		int l[n];
		for(int i = 0; i < n; i++){
			cin >> l[i];
			cout << n - l[i] + 1 << " ";
		}
		cout << endl;
	}
}