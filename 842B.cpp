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

//Sobrecarga do operador << (para poder usar um ponto no cout)
ostream& operator<<(ostream& os, Point &p){
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}


int compDouble(double a, double b, double erro = EPS)
{
	if (abs(a - b) < erro)
		return 0;
	if (a < b)
		return -1;
	return 1;
}

//Dist�ncia entre dois pontos
double dist(Point a, Point b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main(){
    Point centro(0,0);
    int n, onCrust = 0,x,y,r,rp,rb;
    cin >> rb >> rp;
    rp = rb - rp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y >> r;
        Point s(x,y);
        //cout << (rp+r <= dist(centro,s)) << " " << (dist(centro,s)+r - rb <= 0) <<endl;
        if((rp+r <= dist(centro,s)) && dist(centro,s)+r - rb <= 0 )onCrust++;
    }
    cout << onCrust <<endl;
    return 0;
}