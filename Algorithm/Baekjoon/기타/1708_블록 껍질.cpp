#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Point {
	long long x = 0ll;
	long long y = 0ll;
	
	Point operator-(Point o) { 
		Point temp = { o.x - x, o.y - y };
		return temp;
	}
	long long operator*(Point o) {
		return x*o.y - y*o.x;
	}
};
Point stdPos;
vector<Point> points, convexHull;

long long dist(Point a, Point b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
bool comparePoints(Point a, Point b) {
	if (a.y == b.y) return a.x < b.x;
	else return a.y < b.y;
}
bool compareAngle(Point a, Point b) {
	a = stdPos - a;
	b = stdPos - b;
	long long c = a*b;
	
	if (c > 0) return true;
	else if (c < 0) return false;
	else
		return dist(a, stdPos) < dist(b, stdPos);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;

	cin >> N;

	for(int i=0; i<N; i++) {
		long long x, y;
		cin >> x >> y;
		points.push_back({ x, y });
	}
	
	sort(points.begin(), points.end(), comparePoints);
	stdPos = { points[0].x, points[0].y };
	sort(points.begin()+1, points.end(), compareAngle);

	convexHull.push_back( points[0] );
	convexHull.push_back( points[1] );

	long long resultOfOutProduct;
	for (int i = 2; i < N; i++) {
		if (convexHull.size() >= 2) {
			int sz = convexHull.size();
			Point p1 = convexHull[sz - 2];
			Point p2 = convexHull[sz - 1];
			Point next = points[i];

			Point v1 = { p2.x - p1.x , p2.y - p1.y };
			Point v2 = { next.x - p1.x , next.y - p1.y };

			resultOfOutProduct = v1*v2;

			while (resultOfOutProduct <= 0) {
					convexHull.pop_back();
					if (convexHull.size() < 2) break;
					sz = convexHull.size();
					p1 = convexHull[sz - 2];
					p2 = convexHull[sz - 1];
					v1 = { p2.x - p1.x , p2.y - p1.y };
					v2 = { next.x - p1.x , next.y - p1.y };
					resultOfOutProduct = v1*v2;
			}
			convexHull.push_back(next);

		}	
	}
	cout << convexHull.size();

	return 0;
}