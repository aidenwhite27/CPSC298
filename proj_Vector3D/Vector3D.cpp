#include "Vector3D.h"
#include <iostream>

Vector3D::Vector3D() {
	m_vector = { 0, 0, 0 };
}

Vector3D::Vector3D(double dX, double dY, double dZ) {
	m_vector = { dX, dY, dZ };
}

void Vector3D::display() {
	std::cout << m_vector.at(0) << " x, " << m_vector.at(1) << " y, " << m_vector.at(2) << " z" << std::endl;
}

double Vector3D::dot(Vector3D vec3d){
	double dDotProduct = 0.0;
	for (unsigned int i = 0; i < this->m_vector.size(); i++) {
		dDotProduct += m_vector.at(i) * vec3d.m_vector.at(i);
	}
	return dDotProduct;
}
