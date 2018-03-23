//#include<iostream>
//using namespace std;
//
//class Circle {
//public:
//	int radius;
//	Circle(int r);
//	Circle();
//};
//
//Circle::Circle() {
//}
//
//Circle::Circle(int r) {
//	radius = r;
//}
//
//
//
//int main(void)
//{
//	Circle p(5), b;
//	return 0;
//}

#include<iostream>
using namespace std;

class Rectangle {
private:
	int width;
	int height;
public:
	void setWidth(int width);
	void setHeight(int height);
	int getWidth();
	int getHeight();

	Rectangle();
	Rectangle(int width, int height);
	Rectangle(int width);
	bool isSquare();
};

#pragma once
