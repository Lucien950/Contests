#include <iostream>
#include <cmath>

using namespace std;

struct Plant {
	int x, y, v;
};

const double PI = 2 * acos(0.0);
const double TPI = 2 * PI;

int main() {
	int n, r, w, h;
	cin >> n >> r >> w >> h;
	Plant plants[n];
	for (int p = 0; p < n; p++) {
		cin >> plants[p].x >> plants[p].y >> plants[p].v;
	}

	double xv = 0;
	int total_area = w * h;
	for (Plant p: plants) {
		const double dxP = abs(p.x - 0), dxN = abs(p.x - w), dyP = abs(p.y - 0), dyN = abs(p.y - h);
		const double minDx = min(dxP, dxN), minDy = min(dyP, dyN);
		const bool closeToXEdge = minDx < r, closeToYEdge = minDy < r;
		const bool overLapAllEdges = (dxP < r && dxN < r) && (dyN < r && dyP < r);
		double area;
		if (overLapAllEdges) {
			area = total_area;
			cout << "Z ";
		} else if (closeToXEdge && closeToYEdge) {
			// circle in corner
			double s_x = sqrt(pow(r, 2) - pow(minDx, 2));
			double s_y = sqrt(pow(r, 2) - pow(minDy, 2));
			double sector_p = (2 * PI - (PI / 2 + acos(minDx / r) + acos(minDy / r))) / TPI;
			area = minDx * minDy + minDx * s_x / 2 + minDy * s_y / 2 + PI * r * r * sector_p;
			cout << "A ";
		} else if (closeToXEdge) {
			// cutoff the circle at the left/right
			double s_x = sqrt(pow(r, 2) - pow(minDx, 2));
			double sector_p = (2 * PI - 2 * acos(minDx / r)) / TPI;
			area = s_x * minDx + PI * r * r * sector_p;
			cout << "B ";
		} else if (closeToYEdge) {
			// cutoff the circle at the top/bottom
			double s_y = sqrt(pow(r, 2) - pow(minDy, 2));
			double sector_p = (2 * PI - 2 * acos(minDy / r)) / TPI;
			area = s_y * minDy + PI * r * r * sector_p;
			cout << "C ";
		} else {
			// easiest case, just draw a circle
			area = PI * r * r;
			cout << "D ";
		}
		cout << area << endl;

		xv += area / (total_area) * p.v;
	}

	cout << xv << endl;
}