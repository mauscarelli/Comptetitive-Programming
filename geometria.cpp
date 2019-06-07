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

//Sobrecarga dos operadores +, -, * e =
Point operator+(Point p, const Point& q){
	return p += q;
}

Point operator-(Point p, const Point& q){
	return p -= q;
}

Point operator*(Point p, const double& k){
	return p *= k;
}

Point operator*(const double& k, Point p){
	return p *= k;
}

Point operator/(Point p, const double& k){
	return p /= k;
}

Point operator/(const double& k, Point p){
	return p /= k;
}

//Comparar double considerando uma margem de erro EPS
//retorna 0  se a = b
//		  -1 se a < b
//		  1  se a > b
int compDouble(double a, double b, double erro = EPS)
{
	if (abs(a - b) < erro)
		return 0;
	if (a < b)
		return -1;
	return 1;
}


//M�dulo do produto vetorial
	//Se cross(v, u) = 0 => vetores colineares
	//Se cross(v, u) < 0 => andando no sentido hor�rio
	//Se cross(v, u) > 0 => andando no sentido anti-hor�rio
double cross(Point v, Point u){
	return v.x * u.y - u.x * v.y;
}

//M�dulo do produto vetorial entre ab e ac
	//Se cross(a, b, c) = 0 => pontos colineares
	//Se cross(a, b, c) < 0 => c est� � direita de ab
	//Se cross(a, b, c) > 0 => c est� � esquerda de ab
double cross(Point a, Point b, Point c){
	return ((b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y)); 
}

//Produto escalar
	//Se dot(v, u) = 0 => o �ngulo entre u e v � de 90�
	//Se dot(v, u) < 0 => o �ngulo entre u e v � maior que 90�
	//Se dot(v, u) > 0 => o �ngulo entre u e v � menor que 90�
double dot(Point v, Point u){
	return v.x * u.x + v.y * u.y;
}

//Verifica se c est� dentro da "caixa" formada por a e b (m�todo auxiliar para segIntersec)
bool dentroDaCaixa(Point a, Point b, Point c){
	return (min(a.x, b.x) <= c.x) and (c.x <= max(a.x, b.x)) and
		   (min(a.y, b.y) <= c.y) and (c.y <= max(a.y, b.y));
}

//Se x = 0 => retorna 0
//Se x < 0 => retorna -1
//Se x > 0 => retorna 1
int sinal(double x){
	if (abs(x) < EPS)
		return 0;
	if (x < 0) 
		return -1;
	return 1;
}

//Verifica se h� a intersec��o entre os segmentos a1a2 e b1b2
bool segIntersec(Point a1, Point a2, Point b1, Point b2){
	int d1, d2, d3, d4;
	d1 = sinal(cross(a2 - a1, b1 - a2));
	d2 = sinal(cross(a2 - a1, b2 - a2));
	d3 = sinal(cross(b2 - b1, a1 - b2));
	d4 = sinal(cross(b2 - b1, a2 - b2));
	return ((d1 * d2 == -1) and (d3 * d4 == -1)) or
		   ((d1 == 0) and dentroDaCaixa(a1, a2, b1)) or
		   ((d2 == 0) and dentroDaCaixa(a1, a2, b2)) or
		   ((d3 == 0) and dentroDaCaixa(b1, b2, a1)) or
		   ((d4 == 0) and dentroDaCaixa(b1, b2, a2));
}

//Retorna o m�dulo/norma do vetor
double norma(Point v){
	return sqrt(v.x*v.x + v.y*v.y);
}

//Retorna o m�dulo/norma do vetor ao quadrado
double norma2(Point v){
	return v.x*v.x + v.y*v.y;
}

//Dist�ncia entre dois pontos
double dist(Point a, Point b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

//Dist�ncia ao quadrado (normalmente � melhor para fazer compara��es)
double dist2(Point a, Point b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

//Dist�ncia de ponto(c) a reta (formada pelos pontos a e b)
double distPontoReta(Point a, Point b, Point c){
	return cross(a, b, c)/dist(a, b);
}

Point proj(Point u, Point v){
	return (dot(u,v)/norma2(v))*v;
}

//Dist�ncia de ponto(c) ao segmento de reta ab (ESSA FUN��O TEM QUE SER MELHOR TESTADA)
double distPontoSeg(Point a, Point b, Point c){
	Point p = a + proj(c-a,b-a);
	double da, db;
	da = dist2(p, a);
	db = dist2(p, b);
	if (da + db > dist2(a,b))
	{
		if (da < db)
			p = a;
		else
			p = b;
	}
	return dist(c, p);
}

//Radial Sort com cen como ponto central
Point cen;
bool radialComp(const Point &a, const Point &b){
	Point v = a - cen,
		  u = b - cen;
	return atan2(v.y, v.x) < atan2(u.y, u.x);
}

//Teste das fun��es
int main()
{
	Point a(0, 4), b(2, 2), c(5, 5), d;
	vector<Point> vet;
	
	cout << "A: " << a << endl;
	cout << "B: " << b << endl;
	cout << "C: " << c << endl;
	cout << "D: " << d << endl;
	cout << "dot(B, C): " << dot(b, c) << endl;
	cout << "cross(B, C): " << cross(b, c) << endl;
	cout << "cross(A, B, C): " << cross(a, b, c) << endl;
	cout << "|A|: " << norma(a) << endl;
	cout << "dist(C, B): " << dist(c, b) << endl;
	
	cout << "distReta(A, B, C): " << distPontoReta(a, b, c) << endl;
	cout << "distSeg(A, B, C): " << distPontoSeg(a, b, c) << endl;

	vet.push_back(*(new Point(4, 0)));
	vet.push_back(*(new Point(3, -1)));
	vet.push_back(*(new Point(2, -1)));
	vet.push_back(*(new Point(1, -2)));
	vet.push_back(*(new Point(2, -2)));
	vet.push_back(*(new Point(-1, -2)));
	vet.push_back(*(new Point(-2, -1)));
	vet.push_back(*(new Point(-2, 1)));
	vet.push_back(*(new Point(-3, 2)));
	vet.push_back(*(new Point(-1, 3)));
	vet.push_back(*(new Point(1, 3)));
	vet.push_back(*(new Point(2, 2)));
	cen.x = 1;
	cen.y = 1;
	sort(vet.begin(), vet.end(), radialComp);
	for(int i = 0; i < vet.size(); i++)
		cout << vet[i] << " ";
}
