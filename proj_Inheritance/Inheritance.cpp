/// @file Inheritance.cpp
/// @brief Includes prototypes and definitions for Shape, Rectangle, and Circle classes as well as main function
/// @author aiwhite@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++

#include <iostream>
#include <string>

const double pi = 3.1415926535;

class Shape
{
public:
	Shape();
	Shape(double dHeight, double dWidth);
	virtual ~Shape();
	virtual void scale(double dScaleFactor) = 0;
	virtual double area() = 0;
	virtual double perimeter() = 0;
	virtual void displayProperties();

protected:
	double m_dHeight;
	double m_dWidth;
	std::string m_strType;
};

class Rectangle : public Shape
{
public:
	Rectangle(double dHeight, double dWidth);
	~Rectangle();
	void scale(double dScaleFactor);
	double area();
	double perimeter();
};

class Circle : public Shape 
{
public:
	Circle(double dHeight, double dWidth);
	~Circle();
	void scale(double dScaleFactor);
	double area();
	double perimeter();
};

Shape::Shape()
{
	m_dHeight = 0;
	m_dWidth = 0;
	m_strType = "Shape";
}

Shape::Shape(double dHeight, double dWidth)
{
	m_dHeight = dHeight;
	m_dWidth = dWidth;
	m_strType = "Shape";
}

Shape::~Shape()
{
	delete this;
}

void Shape::displayProperties()
{
	std::cout << "Shape Type: " << m_strType << ", height: " << m_dHeight << ", width: " << m_dWidth << std::endl;
}

Rectangle::Rectangle(double dHeight, double dWidth)
{
	m_dHeight = dHeight;
	m_dWidth = dWidth;
	m_strType = "Rectangle";
}

Rectangle::~Rectangle()
{
	delete this;
}

void Rectangle::scale(double dScaleFactor)
{
	m_dHeight *= dScaleFactor;
	m_dWidth *= dScaleFactor;
}

double Rectangle::area()
{
	return m_dHeight * m_dWidth;
}

double Rectangle::perimeter()
{
	return (2 * m_dHeight) + (2 * m_dWidth);
}

Circle::Circle(double dHeight, double dWidth)
{
	m_dHeight = dHeight;
	m_dWidth = dWidth;
	m_strType = "Circle";
}

Circle::~Circle()
{
	delete this;
}

void Circle::scale(double dScaleFactor)
{
	m_dHeight *= dScaleFactor;
	m_dWidth *= dScaleFactor;
}

double Circle::area()
{
	return 0.25 * pi * m_dHeight * m_dHeight;
}

double Circle::perimeter()
{
	return pi * m_dHeight;
}

int main()
{
	Rectangle* p_shapeRectangle = new Rectangle(2.0, 3.0);
	Circle* p_shapeCircle = new Circle(2.0, 2.0);

	Shape* p_shapes[2];

	p_shapes[0] = p_shapeCircle;
	p_shapes[1] = p_shapeRectangle;

	for (int i = 0; i < 2; i++)
	{
		p_shapes[i]->displayProperties();
		std::cout << "Area: " << p_shapes[i]->area();
		std::cout << ", Perimeter: " << p_shapes[i]->perimeter() << std::endl;

		p_shapes[i]->scale(2.0);

		p_shapes[i]->displayProperties();
		std::cout << "Area: " << p_shapes[i]->area();
		std::cout << ", Perimeter: " << p_shapes[i]->perimeter() << std::endl;
	}

	return 0;
}

