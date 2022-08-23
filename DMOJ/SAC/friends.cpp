#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int atIndex = 0;
int firstIndex[100000 + 1], nodeHeight[100000 + 1];
vector<int> friends[100000 + 1];
vector<int[2]> euler;
int root[100000 + 1];
vector<int[3]> queries;

void dfs(int atNode, int fromNode = -1, int height = 0){
	firstIndex[atNode] = atIndex;
	atIndex += 1;
	nodeHeight[atNode] = height;

	vector<int> subNodes = friends[atNode];
	if(subNodes.size() == 1 && subNodes[0] == fromNode){
		euler.push_back({atNode, height});
		return;
	}
	for(int newNode: subNodes){
		if(newNode == fromNode) continue;
		euler.push_back({atNode, height});
		dfs(newNode, atNode, height + 1);
	}
	euler.push_back({atNode, height});
}

int findFriendDistance(int a, int b){
	// TODO DO IT NOW
	return 0;
}

int getRoot(int a){
	int parent = root[a];
	if(parent == a) return a;
	return root[a] = getRoot(a);
}
bool isJoined(int a, int b){return getRoot(a) == getRoot(b);}

int main() {
	cin.sync_with_stdio(NULL);
	cin.tie(NULL);
	// vars
	int studentCount, queryCount;
	cin >> studentCount >> queryCount;

	for(int i = 0; i < studentCount - 1; i++){
		int a, b;
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	for(int i = 0; i < queryCount; i++){
		int a, b, c;
		cin >> a >> b >> c;
		queries.push_back({a, b, c});
	}

	// euler
	dfs(1);
	int out[queryCount];
	for(int i = queries.size(); i >= 0; i--){
		int action, a, b;
		action = queries[i][0];
		a = queries[i][1];
		b = queries[i][2];
		if(action == 1){
			if(!isJoined(a, b))
				out[i] = -1;
			else
				out[i] = findFriendDistance(a, b);
		}
		else if (action == 2){
			int rootA = getRoot(a);
			int rootB = getRoot(b);
			if(rootA != rootB)
				root[rootB] = rootA;
		}
		else
			throw "Action Value Not Valid";
	}

	for(int i = 0; i < queryCount; i++){
		cout << out[i];
	}

	return 0;
}