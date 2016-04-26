#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define PI 3.14

class Circle {
	/*Data member*/
	double x;
	double y;
	double r;

	/*Function member*/
public:
	double getX() { return this->x; }
	double getY() { return this->y; }
	double getR() { return this->r; }
	double findArea() {
		double area = PI*r*r;
		std::cout << "The area of this circle: " << area << std::endl;
		return area;
	}
	double area() { return PI*r*r; }
	double findPerimeter() {
		double perimeter = 2 * PI*r;
		std::cout << "The perimeter of this circle: " << perimeter << std::endl;
		return perimeter;
	}
	double perimeter() { return 2 * PI*r; }

	//Constructors
	Circle(): //Synthesized default constructor
		x(0.0), y(0.0), r(0.0)
	{}
	Circle(double x0, double y0, double r0) :
		x(x0), y(y0), r(r0)
	{}

	void display(std::ostream& os) {
		//This function is used to print the information of this Circle to std::ostream os
		os << "Central point coordinate: (" << this->x << ", " << this->y << ")" << std::endl
			<< "Radius: " << this->r << std::endl;
		return;
	}
};

void sort(std::vector<Circle>::iterator beginIter, std::vector<Circle>::iterator endIter, std::vector<Circle> &circles);

int main() {
	//Some Circles
	Circle A(3.0, 4.0, 5.0);
	Circle B(1.0, 5.0, 100.0);
	Circle C(5.6, 788.88, 3.14);
	Circle D(45, 67, 628.0);
	Circle E(11, 11, 11.1);
	Circle F(45, 67.8, 100.0);

	//Testing some methods of the class Circle
	A.display(std::cout);
	A.findArea();
	A.findPerimeter();

	std::cout << "---------------Delimiter---------------" << std::endl;

	//Creating a vector of circles
	std::vector<Circle> circles;
	circles.push_back(A);
	circles.push_back(B);
	circles.push_back(C);
	circles.push_back(D);
	circles.push_back(E);
	circles.push_back(F);

	//Sorting the circles by their perimeter
	sort(circles.begin(), circles.end(), circles);

	//Output the sorted circles
	std::cout << "After sorting by perimeter, the circles are displayed as followed: " << std::endl;
	for (std::vector<Circle>::iterator iter = circles.begin(); iter != circles.end(); iter++) {
		iter->display(std::cout);
		std::cout << std::endl;
	}

	return 0;
}

void sort(std::vector<Circle>::iterator beginIter, std::vector<Circle>::iterator endIter, std::vector<Circle> &circles) {
	/*This function is used to sort a vetcor of circles by their perimeter*/
	//Store the perimeter of the circles into the vector<double> perimeter
	std::vector<double> perimeter;
	for (std::vector<Circle>::iterator iter = beginIter; iter != endIter; iter++) {
		perimeter.push_back(iter->perimeter());
	}

	//Sort the perimeter
	std::sort(perimeter.begin(), perimeter.end());

	//Sort the circles by their perimeter
	std::vector<Circle> temp;
	for (std::vector<double>::iterator iter = perimeter.begin(); iter != perimeter.end(); iter++) {
		if (iter == perimeter.begin()) {
			for (std::vector<Circle>::iterator cIter = beginIter; cIter != endIter; cIter++) {
				if (cIter->perimeter() == *iter) {
					temp.push_back(*cIter);
				}
			}
		}
		else if (*iter != *(iter - 1)) {
			for (std::vector<Circle>::iterator cIter = beginIter; cIter != endIter; cIter++) {
				if (cIter->perimeter() == *iter) {
					temp.push_back(*cIter);
				}
			}
		}
	}
	circles = temp;

	return;
}
