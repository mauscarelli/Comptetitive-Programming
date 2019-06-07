#include <stdio.h>
#include<bits/stdc++.h>
#include<cmath>
#define PI 3.141592653589793
#define EPS 1e-9
#define degreesToRadians(angleDegrees) ((angleDegrees) * M_PI / 180.0)
#define radiansToDegrees(angleRadians) ((angleRadians) * 180.0 / M_PI)

using namespace std;

int main(){
	double x1, y1, x2, y2, CMD, ENF, AB, dist;
	while(cin>> x1 >> y1 >> x2 >> y2 >> CMD >> ENF){
		AB = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		dist = AB*(1/tan(degreesToRadians(CMD))+1/tan(degreesToRadians(ENF)));
		printf("%.3f\n",dist);
	}
	return 0;
}
