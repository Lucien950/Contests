#include <iostream>

using namespace std;
int main(){
	int cases;
	cin >> cases;
	while (cases--){
		unsigned long long at, sum = 1;
		cin >> at;
		while (at != 1){ sum += at; at = at >> 1; }
		cout << sum << endl;
	}
}