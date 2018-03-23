#include<iostream>
#include "Rectangle.h"

Rectangle::Rectangle() {
	width = 3;
	height = 3;
}

Rectangle::Rectangle(int width, int height) {
	this->width = width;
	this->height = height;
}

Rectangle::Rectangle(int width) {
	this->width = width;
	this->height = width;
}

bool Rectangle::isSquare() {
	if (this->width == this->height)
		return true;
	else
		return false;
}

void Rectangle::setWidth(int width)
{
	if (width < 0) this->width = 1;
	this->width = width;
}

void Rectangle::setHeight(int height)
{
	if (height < 0) this->height = 1;
	this->height = height;
}

int Rectangle::getWidth()
{
	return this->width;
}

int Rectangle::getHeight()
{
	return this->height;
}
int main(void)
{
	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3);

	if (rect1.isSquare())
		cout << "rect1은 정사각형이다." << endl;
	if (rect2.isSquare())
		cout << "rect2는 정사각형이다." << endl;
	if (rect3.isSquare())
		cout << "rect3는 정사각형이다." << endl;

	return 0;
}		// 늦게만든 개체부터 소멸자 호출되서 사라짐.