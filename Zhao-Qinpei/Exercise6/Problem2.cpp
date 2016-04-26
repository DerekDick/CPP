#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Rectangle {
	/*Data member*/
	double x;
	double y;
	double width;
	double height;

	/*Function member*/
public:
	double getX() { return this->x; }
	double getY() { return this->y; }
	double getWidth() { return this->width; }
	double getHeight() { return this->height; }
	double findArea() {
		double area = width*height;
		std::cout << "The area of this rectangle: " << area << std::endl;
		return area;
	}
	double area() { return width*height; }
	double findPerimeter() {
		double perimeter = 2 * (width + height);
		std::cout << "The perimeter of this circle: " << perimeter << std::endl;
		return perimeter;
	}
	double perimeter() { return 2 * (width + height); }

	//Constructors
	Rectangle() : //Synthesized default constructor
		x(0.0), y(0.0), width(0.0), height(0.0)
	{}
	Rectangle(double x0, double y0, double w0, double h0) :
		x(x0), y(y0), width(w0), height(h0)
	{}

	void display(std::ostream& os) {
		//This function is used to print the information of this Circle to std::ostream os
		os << "Upper left point coordinate: (" << this->x << ", " << this->y << ")" << std::endl
			<< "Width: " << this->width << " Height: " << this->height << std::endl;
		return;
	}
};

void sort(std::vector<Rectangle>::iterator beginIter, std::vector<Rectangle>::iterator endIter, std::vector<Rectangle> &rectangles);

int main() {
	//Some rectangles
	Rectangle A(3.0, 4.0, 5.0, 2.0);
	Rectangle B(1.0, 5.0, 100.0, 3.4);
	Rectangle C(5.6, 788.88, 3.14, 1000.0);
	Rectangle D(45.0, 67.0, 628.0, 67.9);
	Rectangle E(11.0, 11.0, 11.1, 12.0);
	Rectangle F(45.0, 67.8, 100.0, 66.6);

	//Testing some methods of the class Circle
	A.display(std::cout);
	A.findArea();
	A.findPerimeter();

	std::cout << "---------------Delimiter---------------" << std::endl;

	//Creating a vector of rectangles
	std::vector<Rectangle> rectangles;
	rectangles.push_back(A);
	rectangles.push_back(B);
	rectangles.push_back(C);
	rectangles.push_back(D);
	rectangles.push_back(E);
	rectangles.push_back(F);

	//Sorting the rectangles by their area
	sort(rectangles.begin(), rectangles.end(), rectangles);

	//Output the sorted rectangles
	std::cout << "After sorting by perimeter, the circles are displayed as followed: " << std::endl;
	for (std::vector<Rectangle>::iterator iter = rectangles.begin(); iter != rectangles.end(); iter++) {
		iter->display(std::cout);
		std::cout << "Area: " << iter->area() << std::endl << std::endl;
	}

	return 0;
}

void sort(std::vector<Rectangle>::iterator beginIter, std::vector<Rectangle>::iterator endIter, std::vector<Rectangle> &rectangles) {
	/*This function is used to sort a vetcor of rectangles by their area*/
	//Store the area of the rectangles into the vector<double> area
	std::vector<double> area;
	for (std::vector<Rectangle>::iterator iter = beginIter; iter != endIter; iter++) {
		area.push_back(iter->area());
	}

	//Sort the area
	std::sort(area.begin(), area.end());

	//Sort the rectangles by their area
	std::vector<Rectangle> temp;
	for (std::vector<double>::iterator iter = area.begin(); iter != area.end(); iter++) {
		if (iter == area.begin()) {
			for (std::vector<Rectangle>::iterator cIter = beginIter; cIter != endIter; cIter++) {
				if (cIter->area() == *iter) {
					temp.push_back(*cIter);
				}
			}
		}
		else if (*iter != *(iter - 1)) {
			for (std::vector<Rectangle>::iterator cIter = beginIter; cIter != endIter; cIter++) {
				if (cIter->area() == *iter) {
					temp.push_back(*cIter);
				}
			}
		}
	}
	rectangles = temp;

	return;
}
