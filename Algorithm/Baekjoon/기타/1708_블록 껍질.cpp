#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct Point {
	int x;
	int y;
};
Point stdPos;
vector<Point> points, convexHull;

bool comparePoints(Point a, Point b) {
	if (a.y == b.y) return a.x < b.x;
	else return a.y < b.y;
}
bool compareCos(Point a, Point b) {

	return (a.x - stdPos.x)*(b.y - stdPos.y) - (a.y - stdPos.y)*(b.x - stdPos.x) > 0;

}

int outerProduct(Point a, Point b) {
	return a.x * b.y - a.y * b.x;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int N;
	
	cin >> N;

	stdPos = { 40001, 40001 };
	int stdIdx;

	for(int i=0; i<N; i++) {
		int x, y;
		cin >> x >> y;
		points.push_back({ x, y });
	}
	sort(points.begin(), points.end(), comparePoints);
	stdPos = { points[0].x, points[0].y };
	sort(points.begin()+1, points.end(), compareCos);

	convexHull.push_back( points[0] );
	convexHull.push_back( points[1] );
	bool check = false;
	for (int i = 2; i < N; i++) {
		
	
		while (convexHull.size() >= 2) {
			int sz = convexHull.size();
			Point p1 = convexHull[sz - 2];
			Point p2 = convexHull[sz - 1];
			Point next = points[i];

			Point v1 = { p2.x - p1.x , p2.y - p1.y };
			Point v2 = { next.x - p1.x , next.y - p1.y };

			int resultOfOutProduct = outerProduct(v1, v2);


			if (resultOfOutProduct < 0 || check) {
				Point top = convexHull.back();
				convexHull.pop_back();
				if (check) {
					convexHull.pop_back();
					convexHull.push_back(top);
					check = resultOfOutProduct == 0 ? true : false;
				}
			} else {
				if (resultOfOutProduct == 0) check = true;
				convexHull.push_back(next);
				break;
			}
		}

		
	}

	cout << convexHull.size() << endl;

	/*for (auto p : convexHull) {
		cout << p.x << " " << p.y << endl;
	}*/

	return 0;
}