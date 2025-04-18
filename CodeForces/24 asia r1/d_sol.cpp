#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n) {
    long long curX, curY, curD, d;
    int x, y, tmp;
    set<pair<int, int>> obs;
    unordered_map<int, int> path;
    cin >> curX >> curY >> d;
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      obs.insert(pair<int, int>(x, y));
    }
    curD = 0;
    int dx = 1;
    int dy = 0;
    //rotate
    while (obs.find(pair<int, int>(curX+dx, curY+dy)) != obs.end()) {
      tmp = -dy;
      dy = dx;
      dx = tmp;
    }
    while (curD < d) {
      // loop
      auto it = path.find(curX*10000+curY*10+dx*2+dy);
      if (it != path.end()) {
        curD = d - (d-curD) % (curD-it->second);
        if (curD == d) break;
      }
      path.emplace(curX*10000+curY*10+dx*2+dy, curD);
      // move
      curX += dx;
      curY += dy;
      curD++;
      // outside
      if (curX>100 || curX<0 || curY>100 || curY<0) {
        curX += (d-curD) * dx;
        curY += (d-curD) * dy;
        break;
      }
      // rotate
      while (obs.find(pair<int, int>(curX+dx, curY+dy)) != obs.end()) {
        tmp = -dy;
        dy = dx;
        dx = tmp;
      }
    }
    cout << curX << " " << curY << "\n";
    cin >> n;
  }
}
