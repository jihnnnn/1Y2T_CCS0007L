#include <iostream>
#include <string>
using namespace std;

class Shape{
	public:
		double areaTriangle;
		double areaRectangle;
};

class Triangle: public Shape{
	public:
		double base;
		double height;
};

class Rectangle: public Shape{
	public:
		double length;
		double width;
};

void triangleAreaCalc();
void rectangleAreaCalc();

int main() {
	triangleAreaCalc();
	rectangleAreaCalc();
	return 0;
}

void triangleAreaCalc(){
	Triangle triangle;
	cout << "\tTriangle\n";
	cout << string(30, '-') << endl;
	cout << "Enter base and height: ";
	cin >> triangle.base >> triangle.height;
	triangle.areaTriangle = (triangle.base * triangle.height)/2;
	cout << "\nArea of triangle is " << triangle.areaTriangle << endl;
}

void rectangleAreaCalc(){
	Rectangle rectangle;
	cout << "\n\tRectangle\n";
	cout << string(30, '-') << endl;
	cout << "Enter length and width: ";
	cin >> rectangle.length >> rectangle.width;
	rectangle.areaRectangle = rectangle.length * rectangle.width;
	cout << "\nArea of rectangle is " << rectangle.areaRectangle << endl;
 	
}