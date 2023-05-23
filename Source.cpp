#include <iostream>
#include "Functions.cpp"
#include "Errors.h"
#include "CSphere.h"
#include <vector>
using namespace std;
int main(void)
{
	vector<CSphere> d = { CSphere(5, 6,1, 4), CSphere(-1, 5, 2, 6), CSphere(0, 0, 0, 10) };
	vector<CSphere> e = { CSphere(9, 6,1, 4), CSphere(-1, 5, 2, 20), CSphere(0, 0, 0, 10) };
	vector<CSphere> u = { CSphere(5, 7, 2, 1), CSphere(7,8 ,3, 2)};
	vector<CSphere> l = { CSphere(5, 6,2, 4), CSphere(-1, 5, 2, 6), CSphere(0, 0, 0, 10) };
	vector<CSphere> r = { CSphere(5, 6,2, 4), CSphere(5, 5, 2, 6), CSphere(0, 0, 0, 10) };
	CSingleLinkedList<CSphere> a[] = {CSingleLinkedList<CSphere>(d), CSingleLinkedList<CSphere>(e), CSingleLinkedList<CSphere>(u) };
	CSingleLinkedList<CSphere> b(e);
	//cout << FindElementInArray(a, sizeof(a)/sizeof(a[0]), b);
	b.choiceSort();
	cout << b;
//	CSingleLinkedList<CSphere> a(d);
//	a.show();
//	CSingleLinkedList<CSphere> b;
	//vector<double> u = { 5, 53, 1 };
	//vector<double> i = { 5, 1, 1 };
	/*CSingleLinkedList<CSphere> a1(u);
	CSingleLinkedList<CSphere> a2(u);*/
//	CSingleLinkedList<CSphere> a1(d);
//	CSingleLinkedList<CSphere> a2(d);
//	CSingleLinkedList<CSphere> a3(e);
	/*if(a1 == a2)
	{
		cout << "xui";
	}
	*/
}