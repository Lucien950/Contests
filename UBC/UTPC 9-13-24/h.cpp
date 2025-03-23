#include <iostream>
#include <vector>

using namespace std;

int main() {
  int speedway_length, query_count;
  cin >> speedway_length >> query_count;

  std::vector has_student(speedway_length - 1, false);
  for (int i = 0; i < speedway_length; i++) {
	int a;
	cin >> a;
	has_student[a - 1] = true;
  }
  std::vector l_psa(speedway_length - 1, 0);
  l_psa[0] = has_student[0] ? 1 : 0;
  for (int i = 1; i < speedway_length - 1; i++) {
	l_psa[i] = l_psa[i - 1] + (has_student[i] ? 1 : 0);
  }
  std::vector r_psa(speedway_length - 1, 0);
  r_psa[speedway_length - 2] = has_student[speedway_length - 2] ? 1 : 0;
  for (int i = speedway_length - 3; i >= 0; i--) {
	r_psa[i] = r_psa[i + 1] + (has_student[i] ? 1 : 0);
  }

  for (int q = 0; q < query_count; q++) {
	int t;
	cin >> t;
	if (t > (speedway_length - 1 - 1) / 2) {
	  cout << -1 << endl;
	  continue;
	}
	// output the number of students at a[:t] and a[-t:]
	cout << l_psa[t] + r_psa[speedway_length - 1 - t] << endl;
  }
}