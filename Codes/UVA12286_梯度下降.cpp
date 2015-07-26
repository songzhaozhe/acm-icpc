#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;
const double eps = 1e-9;
struct Point {
	long double x, y;
	Point():x(0), y(0){}
	Point(long double x, long double y): x(x), y(y) {}
	friend Point operator + (const Point &a, const Point &b) {
		return Point(a.x + b.x, a.y + b.y);
	}
	friend Point operator - (const Point &a, const Point &b) {
		return Point(a.x - b.x, a.y - b.y);
	}
	friend Point operator * (const double &k, const Point &a) {
		return Point(k * a.x, k * a.y);
	}
	friend Point operator / (const Point &a, const double &k) {
		return Point(a.x / k, a.y / k);
	}
};
__inline long double sqr(long double x) {
	return x * x;
}
__inline long double dist(const Point &a, const Point &b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
const Point dir[4] = {Point(0, -1), Point(0, 1), Point(-1, 0), Point(1, 0)};
Point a[10];
long double c[3][3] = {{1, 2, 2}, {2, 1, 2}, {2, 2, 1}};

__inline long double get_val(Point cur, int k) {
	return c[k][0] * dist(cur, a[0]) + c[k][1] * dist(cur, a[1]) + c[k][2] * dist(cur, a[2]);
}
__inline long double solve() {
	Point p[3];
	p[0] = p[1] = p[2] = (a[0] + a[1] + a[2]) / 3;
	long double cur[3];
	for(int i = 0; i < 3; ++i)
		cur[i] = get_val(p[i], i);
	for(long double step = 2000;step > eps; step *= .5) {
		for(int i = 0; i < 3; ++i) {
			bool flag(true);
			for(;flag;) {
				flag = false;
				for(int j = 0; j < 4; ++j) {
					Point now = p[i] + step * dir[j];
					long double t = get_val(now, i);
					if(t < cur[i]) {
						 cur[i] = t;
						 p[i] = now;
						 flag = true;
						 break;
					}
				}
			}
			
		}
	}
	return min(min(cur[0], cur[1]), cur[2]);
}
int main() {
	for(int cas = 1;; ++cas) {
		for(int i = 0; i < 3; ++i) {
			scanf("%Lf%Lf", &a[i].x, &a[i].y);
		}
		if(a[0].x < -.5)
			break;
		printf("Case %d: %.8f\n",cas, (double)solve());
	}
	return 0;
}