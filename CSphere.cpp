#include "CSphere.h"

#include <iostream>
#include <cmath>

CSphere::CSphere() {
	c_x = 0;
	c_y = 0;
	c_z = 0;
	radius = 2;
}
CSphere::CSphere(int c_x, int c_y, int c_z, double radius) {
	this->c_x = c_x;
	this->c_y = c_y;
	this->c_z = c_z;
	this->radius = radius;
}
CSphere::CSphere(int c_x, int c_y, int c_z, int radius) {
	this->c_x = c_x;
	this->c_y = c_y;
	this->c_z = c_z;
	this->radius = radius;
}
double CSphere::S() {
	double s = 4 * 3.14 * pow(radius, 2);
	std::cout << "S = " << s << std::endl;
	return s;
}
double CSphere::V() {
	double V = 1.3333333 * 3.14 * pow(radius, 3);
	std::cout << "V = " << V << std::endl;
	return V;
}
void CSphere::Print() {
	std::cout << "(x - (" << c_x << "))^2 + (y - (" << c_y << "))^2 + (z - (" << c_z << "))^2 = " << pow(radius, 2) << std::endl;
	std::cout << "x = " << c_x << ", y = " << c_y << ", z = " << c_z << ", R = " << radius << std::endl;

}
double CSphere::Rplus(double a) {
	std::cout << "Changed radius - " << (radius * a) << std::endl;
	return radius * a;
}
CSphere CSphere::Move(int x, int y, int z) {
	CSphere a(c_x - x, c_y - y, c_z - z, radius);
	std::cout << "Prevoius center coordinates: x = " << c_x << ", y = " << c_y << ", z = " << c_z << std::endl;
	std::cout << "New center coordinats: x = " << a.c_x << ", y = " << a.c_y << ", z = " << a.c_z << std::endl;
	return a;
}
int CSphere::getX() { return c_x; }
int CSphere::getY() { return c_y; }
int CSphere::getZ() { return c_z; }
double CSphere::getR() { return radius; }
void CSphere::setX(int x) { c_x = x; }
void CSphere::setY(int y) { c_y = y; }
void CSphere::setZ(int z) { c_z = z; }
void CSphere::setR(double r) { radius = r; }

istream& operator >> (std::istream& in, CSphere& a)
{
	cout << "Enter x, y, z and radius:";
	in >> a.c_x >> a.c_y >> a.c_z >> a.radius;
	return in;
}
ostream& operator << (ostream& out, const CSphere& a)
{
	out << "(x - (" << a.c_x << "))^2 + (y - (" << a.c_y << "))^2 + (z - (" << a.c_z << "))^2 = " << pow(a.radius, 2) << std::endl;
	out << "x = " << a.c_x << ", y = " << a.c_y << ", z = " << a.c_z << ", R = " << a.radius << std::endl;
	return out;
}
CSphere& CSphere::operator=(const CSphere& a)
{
	c_x = a.c_x;
	c_y = a.c_y;
	c_z = a.c_z;
	radius = a.radius;
	return *this;
}
bool CSphere::operator!=(const CSphere& a) const
{
	if(a.c_x == c_x && a.c_y == c_y && a.c_z == c_z && radius == a.radius)
	{
		return false;
	} else
	{
		return true;
	}
}
bool CSphere::operator==(const CSphere& a) const
{
	if (a.c_x == c_x && a.c_y == c_y && a.c_z == c_z && radius == a.radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool CSphere::operator>(CSphere& a)
{
	if(radius > a.radius)
	{
		return true;
	} else
	{
		return false;
	}
}
bool CSphere::operator<(CSphere& a)
{
	return !(radius > a.radius);
}
bool CSphere::operator>=(CSphere& a)
{
	if(radius >= a.radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool CSphere::operator<=(CSphere& a)
{
	return !(radius >= a.radius);
}
CSphere& CSphere::operator*(double a)
{
	radius *= a;
	return *this;
}
CSphere& CSphere::operator*=(double a)
{
	radius *= a;
	return *this;
}

CSphere& CSphere::operator+(CSphere& a)
{
	CSphere d((c_x + a.c_x) / 2, (c_y + a.c_y) / 2, (c_z + a.c_z) / 2, radius + a.radius);
	return d;
}
CSphere& CSphere::operator-(CSphere& a)
{
	CSphere d((c_x + a.c_x) / 2, (c_y + a.c_y) / 2, (c_z + a.c_z) / 2, radius - a.radius);
		return d;
}