#include <iostream>
#include <deque>
#include <map>

using namespace std;

struct Team {
	int id, school;
};

int main() {
	int teamsInComp = 0, teamsToTake, limitFromSchool;
	cin >> teamsInComp >> teamsToTake >> limitFromSchool;

	Team orderedTeams[teamsInComp];
	for (int t = 0; t < teamsInComp; t++) {
		cin >> orderedTeams[t].id >> orderedTeams[t].school;
	}

	//take everyone from every school how many people do you take
	int maximumTake = 0;
	map<int, int> teamsFromSchool0;
	for (Team t: orderedTeams) {
		if (teamsFromSchool0.count(t.school) == 0) teamsFromSchool0[t.school] = 0;
		if (teamsFromSchool0[t.school] < limitFromSchool) {
			teamsFromSchool0[t.school]++;
			maximumTake++;
		}
	}

	map<int, int> teamsFromSchool1;
	int overLimitTeamsToTake = max(0, teamsToTake - maximumTake);
	for (Team t: orderedTeams) {
		if (teamsToTake == 0) continue;

		if (teamsFromSchool1.count(t.school) == 0) teamsFromSchool1[t.school] = 0;
		if (teamsFromSchool1[t.school] >= limitFromSchool) {
			if (overLimitTeamsToTake > 0) {
				overLimitTeamsToTake--;
			} else {
				continue;
			}
		}
		teamsFromSchool1[t.school]++;
		teamsToTake--;
		cout << t.id << endl;
	}
}