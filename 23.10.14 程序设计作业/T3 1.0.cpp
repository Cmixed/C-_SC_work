#include <iostream>
#include <cmath>
#include <cstdio>
#include <iomanip>

using namespace std;

double num_s(double, double, double, double);

int main()
{
	double x1, y1, x2, y2, x3, y3;
	double side1, side2, side3, area, s;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	side1 = num_s(x1, y1, x2, y2);
	side2 = num_s(x2, y2, x3, y3);
	side3 = num_s(x3, y3, x1, y1);
	s = (side1 + side2 + side3) / 2;
	area = sqrt(s*(s-side1)*(s-side2)*(s-side3));
	
	printf("%.1lf",area);
}

double num_s(double x1, double y1, double x2, double y2)
{
	return sqrt(pow((y2 - y1),2) + pow((x2 - x1),2));
}