#include <cstring>
#include <iostream>
using namespace std;

int main() {
  string s;
  std::getline(cin, s);
  if (s == "Are you a verified human?") {
	cout << "Yes, I can attest to my status as a thoroughly validated, carbon-based biological entity." << endl;
  } else {
	cout << "Yes" << endl;
  }
}