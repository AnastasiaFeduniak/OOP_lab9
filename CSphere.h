#pragma once
#include <istream>
using namespace std;
class CSphere {
private:
	int c_x;
	int c_y;
	int c_z;
	double radius;

public:
	CSphere();
	CSphere(int c_x, int c_y, int c_z, double radius);
	CSphere(int c_x, int c_y, int c_z, int radius);
	double S();
	double V();
	void Print();
	double Rplus(double a);
	CSphere Move(int x, int y, int z);
	int getX();
	int getY();
	int getZ();
	double getR();
	void setX(int x);
	void setY(int y);
	void setZ(int z);
	void setR(double r);

	friend istream& operator >> (std::istream& in, CSphere& a);
	friend ostream& operator << (ostream& out, const CSphere& a);
	CSphere& operator=(const CSphere& a);
	CSphere& operator*(double a);
	bool operator!=(const CSphere& a) const;
	bool operator>(CSphere& a);
	bool operator<(CSphere& a);
	bool operator>=(CSphere& a);
	bool operator<=(CSphere& a);
	bool CSphere::operator==(const CSphere& a) const;
	CSphere& operator*=(double a);
	CSphere& operator+(CSphere& a);
	CSphere& operator-(CSphere& a);
};
