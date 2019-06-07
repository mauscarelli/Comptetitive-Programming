//Dog and Gopher
#include <stdio.h>
#include<bits/stdc++.h>
#define PI 3.141592653589793
#define EPS 1e-9
#define degreesToRadians(angleDegrees) ((angleDegrees) * M_PI / 180.0)
#define radiansToDegrees(angleRadians) ((angleRadians) * 180.0 / M_PI)

using namespace std;

struct Point{
	double x;
	double y;
	
	Point(double x = 0, double y = 0){
		this->x = x;
		this->y = y;
	}
	
	//Sobrecarga dos operadores +=, -=, *= e /=
	struct Point& operator+=(const Point& p){
		x += p.x;
		y += p.y;
		return *this;
	}

	struct Point& operator-=(const Point& p){
		x -= p.x;
		y -= p.y;
		return *this;
	}
	
	struct Point& operator*=(const double& k){
		x *= k;
		y *= k;
		return *this;
	}
	
	struct Point& operator/=(const double& k){
		x /= k;
		y /= k;
		return *this;
	}
	
	
};

double dis2(Point a, Point b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int main() {
    int n;
    double x1,y1, x2, y2;
    while(cin >> n >> x1 >> y1 >> x2 >> y2) {
        Point gopher(x1,y1), dog(x2,y2);
		int find = 0;
        double x, y, resx, resy;
        while(n--) {
            cin >> x >> y;
            Point hole(x,y);
            if(find)
                continue;
            if(4*dis2(gopher,hole) <= dis2(dog,hole)) {
                find = 1;
                resx = x;
                resy = y;
            }
        }
        if(find) {
            printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", resx, resy);
        } else {
            puts("The gopher cannot escape.");
        }
    }
    return 0;
}
