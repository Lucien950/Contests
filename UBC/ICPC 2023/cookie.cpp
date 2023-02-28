#include <iostream>
#include <queue>
#include <cstring>


int dxs[] = { -1, 0, 1, 0 };
int dys[] = { 0, 1, 0, -1 };

using namespace std;
int main(){
    int height, width;
    cin >> height >> width;

    bool grid[height][width];
    memset(grid, false, sizeof grid);

    queue<pair<pair<int, int>, int>> toExplore;
    bool explored[height][width];
    memset(explored, false, sizeof explored);

    for(int y = 0; y < height; y++){
        toExplore.emplace(make_pair(-1, y), 0);
        toExplore.emplace(make_pair(width, y), 0);
    }
    for(int x = 0; x < width; x++){
        toExplore.emplace(make_pair(x, -1), 0);
        toExplore.emplace(make_pair(x, height), 0);
    }
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            char in;
            cin >> in;
            grid[y][x] = in == 'X';
            if(in != 'X') {
                explored[y][x] = true;
                toExplore.emplace(make_pair(x, y), 0);
            }
        }
    }

    int maxDepth = -1;
    while(!toExplore.empty()){
        pair<pair<int, int>, int> e = toExplore.front();
        toExplore.pop();
        pair<int, int> coords = e.first;
        int x = coords.first, y = coords.second, depth = e.second;
        maxDepth = max(maxDepth, depth);

        for(int i = 0; i < 4; i++){
            int dx = dxs[i], dy = dys[i];
            int newX = x + dx, newY = y + dy;
            if (!(0 <= newX && newX < width) || !(0 <= newY && newY < height)) continue;
            if (explored[newY][newX]) continue;
            explored[newY][newX] = true;
            toExplore.emplace(make_pair(newX, newY), depth + 1);
        }
    }

    cout << maxDepth;
    return 0;
}