#include <iostream>
#include <queue>

using namespace std;

bool canMove[2000][2000] = {};
bool explored[2000][2000] = {};
int moves[4][2] = {{0,  1},
				   {0,  -1},
				   {1,  0},
				   {-1, 0}};
int mazeRows, mazeCols;

struct {
	const int row, col, leftMovesLeft, rightMovesLeft;
} typedef Square;

int main() {
	int startRow, startCol, maxLeftMoves, maxRightMoves;
	cin >> mazeRows >> mazeCols >> startRow >> startCol >> maxLeftMoves >> maxRightMoves;
	for (int row = 0; row < mazeRows; row++) {
		for (int col = 0; col < mazeCols; col++) {
			char c;
			cin >> c;
			canMove[row][col] = c == '.';
		}
	}

	int count = 0;
	deque<Square> toExplore;
	toExplore.push_front({startRow - 1, startCol - 1, maxLeftMoves, maxRightMoves});
	explored[startRow - 1][startCol - 1] = true;
	while (!toExplore.empty()) {
		Square s = toExplore.front();
		toExplore.pop_front();
		const int atRow = s.row, atCol = s.col, leftMovesLeft = s.leftMovesLeft, rightMovesLeft = s.rightMovesLeft;
		count += 1;
		for (auto move: moves) {
			const int dy = move[1], dx = move[0], newRow = atRow + dy, newCol = atCol + dx;
			// out of bounds check
			if (!(0 <= newRow && newRow < mazeRows && 0 <= newCol && newCol < mazeCols)) continue;
			if (!canMove[newRow][newCol]) continue;
			if (explored[newRow][newCol]) continue;
			// has enough moves check
			const bool movingLeft = dx == -1, movingRight = dx == 1;
			if (movingLeft && (leftMovesLeft == 0)) continue;
			if (movingRight && (rightMovesLeft == 0)) continue;

			explored[newRow][newCol] = true;
			const int newLeftMovesLeft = leftMovesLeft - movingLeft, newRightMovesLeft = rightMovesLeft - movingRight;
			const Square ns = {newRow, newCol, newLeftMovesLeft, newRightMovesLeft};
			if (!(movingRight || movingLeft)) {
				toExplore.push_front(ns);
			} else {
				toExplore.push_back(ns);
			}
		}
	}

	cout << count << endl;
	// print exploredQueued
	// for (int row = 0; row < mazeRows; row++) {
	// 	for (int col = 0; col < mazeCols; col++) {
	// 		cout << explored[row][col] << " ";
	// 	}
	// 	cout << endl;
	// }
}

// . . . * *
// * * . * *
// . . . . .
// . * * * .
// . . x . .

// * * . . .
// * * . * *
// . . . . .
// . * * * .
// . . x . .