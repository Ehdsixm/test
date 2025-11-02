#include <iostream>
#include<string>
#include<cctype>
#include<algorithm>
#include<cmath>
using namespace std;


float func_x(float a1, float b1, float c1, float a2, float b2, float c2) {
	float x = 0;
	x = (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1);
	return x;
}
float func_y(float a1, float b1, float c1, float a2, float b2, float c2) {
	float y = 0;
	y = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);
	return y;
}
double angle(float x0, float y0, float x1, float y1, float x2, float y2) {
	double dx1 = x1 - x0, dy1 = y1 - y0;
	double dx2 = x2 - x0, dy2 = y2 - y0;

	double dot = dx1 * dx2 + dy1 * dy2;
	double cross = dx1 * dy2 - dy1 * dx2;
	double angle_rad = atan2(abs(cross), dot);

	return angle_rad;
}

int gcd(int a, int b) {
	if (a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}

int main() {
	float x1 = 0;
	float y1 = 0;
	float x2 = 0;
	float y2 = 0;
	float x3 = 0;
	float y3 = 0;
	double cita0 = (3.1415926535897 * 2) / 3600;
		

	cout << "输入点1横坐标：";
	cin >> x1;
	cout << endl;
	cout << "输入点1纵坐标：";
	cin >> y1;
	cout << endl;
	cout << "输入点2横坐标：";
	cin >> x2;
	cout << endl;
	cout << "输入点2纵坐标：";
	cin >> y2;
	cout << endl;
	cout << "输入点3横坐标：";
	cin >> x3;
	cout << endl;
	cout << "输入点3纵坐标：";
	cin >> y3;
	cout << endl;
	float cross_product = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
	if (abs(cross_product) < 1e-6) {
		cout << "三点共线，不存在三角形" << endl;
		return 0;
	}
	
	float k1, k2;
	double b1, b2;

	if (abs(y1 - y2) > 1e-6) {
		k1 = -(x2 - x1) / (y2 - y1);
		b1 = (pow(x2, 2) - pow(x1, 2) + pow(y2, 2) - pow(y1, 2)) / (2.0 * (y2 - y1));
	}
	else {
		k1 = 0;
		b1 = (y1 + y2) / 2.0;
	}

	if (abs(y2 - y3) > 1e-6) {
		k2 = -(x3 - x2) / (y3 - y2);
		b2 = (pow(x3, 2) - pow(x2, 2) + pow(y3, 2) - pow(y2, 2)) / (2.0 * (y3 - y2));
	}
	else {
		k2 = 0;
		b2 = (y2 + y3) / 2.0;
	}
	float x0 = func_x(k1, -1, b1, k2, -1, b2);
	float y0 = func_y(k1, -1, b1, k2, -1, b2);


	double cita1 = angle(x0, y0, x1, y1, x2, y2);
	double cita2 = angle(x0, y0, x2, y2, x3, y3);
	int fen1 = floor(cita1 / cita0);
	int fen2 = floor(cita2 / cita0);
	int fen0 = gcd(fen1, fen2);
	int bianshu = 3600 / fen0;
	float r = pow((pow(x0 - x1, 2) + pow(y0 - y1, 2)), 0.5);
	float s = 0.5*pow(r, 2) * sin(fen0 * cita0) * bianshu;
	cout << "面积为：" << s << endl;

	return 0;
}