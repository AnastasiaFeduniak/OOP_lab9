#include "pch.h"
#include "../Project1/Functions.cpp"
//#include "../Project1/CSphere.h"
#include "../Project1/CSphere.cpp"
#include "../Project1/Errors.h"
using namespace std;
TEST(CSingleLinkedList, Dgetters) {
	CSingleLinkedList<double> a;
	EXPECT_EQ(a.getFirstEl(), 0);
	EXPECT_EQ(a.getLastEl(), 0);
	EXPECT_EQ(a.getNumOfEl(), 0);
	vector<double> test = { 5.7, 34, 0.4, 23.3, 5.4 };
	CSingleLinkedList<double> b(test);
	EXPECT_EQ(b.getFirstEl(), 5.7);
	EXPECT_EQ(b.getLastEl(), 5.4);
	EXPECT_EQ(b.getNumOfEl(), 5);
	a = b;
	EXPECT_EQ(a.getFirstEl(), 5.7);
	EXPECT_EQ(a.getLastEl(), 5.4);
	EXPECT_EQ(a.getNumOfEl(), 5);
}
TEST(CSingleLinkedList, DfindValue) {
	CSingleLinkedList<double> a;
	vector<double> test = { 40.3, 34, 0.4, 23.3, 0.1 };
	vector<double> test1 = { 0.1 , 34, 0.4, 6.5, 5.6, 23.3, 38.4 };
	CSingleLinkedList<double> b(test);
	CSingleLinkedList<double> c(test1);
	EXPECT_EQ(a.findMax(), NULL);
	EXPECT_EQ(b.findMax(), 40.3);
	EXPECT_EQ(c.findMax(), 38.4);
	EXPECT_EQ(a.findMin(), 0);
	EXPECT_EQ(b.findMin(), 0.1);
	EXPECT_EQ(c.findMin(), 0.1);
}
TEST(CSingleLinkedList, Dsorting) {
	CSingleLinkedList<double> a;
	vector<double> test = { 40.3, 34, 0.4, 23.3, 0.1 };
	vector<double> expected1_1 = { 40.3, 34, 23.3, 0.4, 0.1 };
	vector<double> expected1_2 = { 0.1, 0.4, 23.3, 34, 40.3 };
	CSingleLinkedList<double> b(test);
	EXPECT_NO_THROW(a.choiceSort());
	EXPECT_NO_THROW(a.choiceSort());
	b.choiceSort();
	for (int i = 0; i < b.getNumOfEl(); i++)
	{
		EXPECT_EQ(b[i], expected1_1[i]);
	}
	b.bubbleSort();
	for (int i = 0; i < b.getNumOfEl(); i++)
	{
		EXPECT_EQ(b[i], expected1_2[i]);
	}

}

TEST(CSingleLinkedList, Dskalyar)
{
	CSingleLinkedList<double> a;
	vector<double> test = { 40.3, 34, 0.4, 23.3, 0.1 };
	vector<double> expected1_1 = { 0, 0, 0, 0, 0 };
	vector<double> expected1_2 = { 20.15, 17, 0.2, 11.65, 0.05 };
	vector<double> expected1_3 = { 4030, 3400, 40, 2330, 10 };
	CSingleLinkedList<double> b(test);
	a = b;
	b.skalyar(0);
	for (int i = 0; i < b.getNumOfEl(); i++) {
		EXPECT_NEAR(b[i], expected1_1[i], 0.01);
	}
	b = a;
	b.skalyar(0.5);
	for (int i = 0; i < b.getNumOfEl(); i++) {
		EXPECT_NEAR(b[i], expected1_2[i], 0.01);
	}
	b = a;
	b.skalyar(100);
	for (int i = 0; i < b.getNumOfEl(); i++) {
		EXPECT_NEAR(b[i], expected1_3[i], 0.01);
	}
}
TEST(operator, DplusAndMinus)
{
	CSingleLinkedList<double> a;
	vector<double> test = { 40.3, 34, 0.4, 23.3, 0.1 };
	vector<double> expected1_1 = { 40.3, 34, 0.4, 23.3, 0.1, 5.3, 0.2 };
	vector<double> expected1_2 = { 40.3, 34, 0.4 };
	CSingleLinkedList<double> b(test);
	EXPECT_NO_THROW(a.operator-());
	EXPECT_NO_THROW(a.operator+(5.3));
	EXPECT_EQ(a[0], 5.3);
	a.operator+(4.3);
	a.operator-();
	a.operator-();
	EXPECT_NO_THROW(a.operator-());
	b.operator+(5.3);
	b.operator+(0.2);
	for (int i = 0; i < expected1_1.size(); i++) {
		EXPECT_EQ(b[i], expected1_1[i]);
	}
	b.operator-();
	b.operator-();
	b.operator-();
	b.operator-();
	for (int i = 0; i < expected1_2.size(); i++) {
		EXPECT_EQ(b[i], expected1_2[i]);
	}
}
TEST(operator, Dequal)
{
	CSingleLinkedList<double> a;
	vector<double> test = { 40.3, 34, 0.4, 23.3, 0.1 };
	vector<double> test1 = { 4.3, 5.6, 1.3 };
	CSingleLinkedList<double> b(test); CSingleLinkedList<double> c(test1);
	a = b;
	for (int i = 0; i < a.getNumOfEl(); i++) {
		EXPECT_EQ(b[i], a[i]);
	}
	b = c;
	a = move(c);
	for (int i = 0; i < a.getNumOfEl(); i++) {
		EXPECT_EQ(b[i], a[i]);
	}
	EXPECT_EQ(c.getNumOfEl(), 0);
	EXPECT_EQ(a[2], 1.3);
	EXPECT_FALSE(a[6]);
}
TEST(CSingleLinkedList, Doutput) {
	ostringstream out;
	CSingleLinkedList<double> a;
	out << a;
	EXPECT_EQ("\n", out.str());
	std::ostringstream out1;
	vector<double> test = { 40.3, 34, 0.4 };
	CSingleLinkedList<double> b(test);
	out1 << b;
	EXPECT_EQ("40.3 34 0.4 \n", out1.str());
}
TEST(CSingleLinkedList, Dinput)
{
	CSingleLinkedList<double> test;
	istringstream input("3\n1.2\n3.4\n-5.6\n");
	input >> test;
	EXPECT_EQ(test.getNumOfEl(), 3);
	EXPECT_EQ(test[0], 1.2);
	EXPECT_EQ(test[1], 3.4);
	EXPECT_EQ(test[2], -5.6);
}
TEST(CSingleLinkedList, DinputOtputExcepton)
{
	CSingleLinkedList<double> test;
	istringstream input("3\nsdf\n5\n34\n");
	input >> test;
	EXPECT_FALSE(input);
}
TEST(CSingleLinkedList, DemptyCSingleLinkedListException)
{
	CSingleLinkedList<double> r;
	EXPECT_FALSE(r.findMin());
	EXPECT_EQ(r.findMin(), 0);
	EXPECT_FALSE(r.findMax());
	EXPECT_EQ(r.findMax(), 0);

	EXPECT_FALSE(r.getFirstEl());
	EXPECT_EQ(r.getFirstEl(), 0);
	EXPECT_FALSE(r.getLastEl());
	EXPECT_EQ(r.getLastEl(), 0);
}
TEST(CSingleLinkedList, DaadSubtException)
{
	vector<double> a = { 3.5, 4.5 };
	vector<double> b = { 4.5, 7.1, 4, 7 };
	vector<double> c = { 0, 1 };
	CSingleLinkedList<double> u(a);
	CSingleLinkedList<double> x(b);
	CSingleLinkedList<double> i(c);
	CSingleLinkedList<double> p;
	p = u + x;
	EXPECT_EQ(p.getNumOfEl(), 0);
	EXPECT_EQ(p.getFirstEl(), 0);
	EXPECT_EQ(p.getLastEl(), 0);
	p = u + i;
	for (int s = 0; s < u.getNumOfEl(); s++)
	{
		EXPECT_EQ(p[s], u[s] + i[s]);
	}
	p = u - x;
	EXPECT_EQ(p.getNumOfEl(), 0);
	EXPECT_EQ(p.getFirstEl(), 0);
	EXPECT_EQ(p.getLastEl(), 0);
	p = u - i;
	for (int s = 0; s < u.getNumOfEl(); s++)
	{
		EXPECT_EQ(p[s], u[s] - i[s]);
	}
}
TEST(CSingleLinkedList, DArrayException)
{
	vector<double> b = { 4.5, 7.1, 4, 7 };
	CSingleLinkedList<double> u(b);
	EXPECT_TRUE(u[2]);
	EXPECT_EQ(u[2], 4);
	EXPECT_FALSE(u[10]);
	EXPECT_EQ(u[6], 0);
}
TEST(CSingleLinkedList, DDynamicOverload)
{
	vector<CSingleLinkedList<double>> a;
	vector<double> r = { 34 };
	for (int i = 0; i < 100000; i++)
	{
		a.push_back(CSingleLinkedList<double>(r));
		//EXPECT_TRUE(a[i]);
	}
	CSingleLinkedList<double>* f = new CSingleLinkedList<double>[10000000];
}

    TEST(CSingleLinkedList, Igetters) {
		CSingleLinkedList<int> a;
		EXPECT_EQ(a.getFirstEl(), 0);
		EXPECT_EQ(a.getLastEl(), 0);
		EXPECT_EQ(a.getNumOfEl(), 0);
		vector<int> test = { 5, 34, 4, 23, 2 };
		CSingleLinkedList<int> b(test);
		EXPECT_EQ(b.getFirstEl(), 5);
		EXPECT_EQ(b.getLastEl(), 2);
		EXPECT_EQ(b.getNumOfEl(), 5);
		a = b;
		EXPECT_EQ(a.getFirstEl(), 5);
		EXPECT_EQ(a.getLastEl(), 2);
		EXPECT_EQ(a.getNumOfEl(), 5);
	}
	TEST(CSingleLinkedList, IfindValue) {
		CSingleLinkedList<int> a;
		vector<int> test = { 40, 34, 4, 23, 0 };
		vector<int> test1 = { 0 , 34, 4, 6, 5, 23, 38 };
		CSingleLinkedList<int> b(test);
		CSingleLinkedList<int> c(test1);
		EXPECT_EQ(a.findMax(), NULL);
		EXPECT_EQ(b.findMax(), 40);
		EXPECT_EQ(c.findMax(), 38);
		EXPECT_EQ(a.findMin(), 0);
		EXPECT_EQ(b.findMin(), 0);
		EXPECT_EQ(c.findMin(), 0);
	}
	TEST(CSingleLinkedList, Isorting) {
		CSingleLinkedList<int> a;
		vector<int> test = { 40, 34, 4, 23, 1 };
		vector<int> expected1_1 = { 40, 34, 23, 4, 1 };
		vector<int> expected1_2 = { 1, 4, 23, 34, 40 };
		CSingleLinkedList<int> b(test);
		EXPECT_NO_THROW(a.choiceSort());
		EXPECT_NO_THROW(a.choiceSort());
		b.choiceSort();
		for (int i = 0; i < b.getNumOfEl(); i++)
		{
			EXPECT_EQ(b[i], expected1_1[i]);
		}
		b.bubbleSort();
		for (int i = 0; i < b.getNumOfEl(); i++)
		{
			EXPECT_EQ(b[i], expected1_2[i]);
		}
	
	}
	
	TEST(CSingleLinkedList, Iskalyar)
	{
		CSingleLinkedList<int> a;
		vector<int> test = { 40, 34, 4, 23, 1 };
		vector<int> expected1_1 = { 0, 0, 0, 0, 0 };
		vector<int> expected1_2 = { 20, 17, 2, 11, 0 };
		vector<int> expected1_3 = { 4000, 3400, 400, 2300, 100 };
		CSingleLinkedList<int> b(test);
		a = b;
		b.skalyar(0);
		for (int i = 0; i < b.getNumOfEl(); i++) {
			EXPECT_EQ(b[i], expected1_1[i]);
		}
		b = a;
		b.skalyar(0.5);
		for (int i = 0; i < b.getNumOfEl(); i++) {
			EXPECT_EQ(b[i], expected1_2[i]);
		}
		b = a;
		b.skalyar(100);
		for (int i = 0; i < b.getNumOfEl(); i++) {
			EXPECT_EQ(b[i], expected1_3[i]);
		}
	}
	TEST(operator, IplusAndMinus)
	{
		CSingleLinkedList<int> a;
		vector<int> test = { 40, 34, 4, 23, 1 };
		vector<int> expected1_1 = { 40, 34, 4, 23, 1, 5, 2 };
		vector<int> expected1_2 = { 40, 34, 4 };
		CSingleLinkedList<int> b(test);
		EXPECT_NO_THROW(a.operator-());
		EXPECT_NO_THROW(a.operator+(5));
		EXPECT_EQ(a[0], 5);
		a.operator+(4);
		a.operator-();
		a.operator-();
		EXPECT_NO_THROW(a.operator-());
		b.operator+(5);
		b.operator+(2);
		for (int i = 0; i < expected1_1.size(); i++) {
			EXPECT_EQ(b[i], expected1_1[i]);
		}
		b.operator-();
		b.operator-();
		b.operator-();
		b.operator-();
		for (int i = 0; i < expected1_2.size(); i++) {
			EXPECT_EQ(b[i], expected1_2[i]);
		}
	}
	TEST(operator, Iequal)
	{
		CSingleLinkedList<int> a;
		vector<int> test = { 40, 34, 4, 23, 1 };
		vector<int> test1 = { 4, 5, 1 };
		CSingleLinkedList<int> b(test);
		CSingleLinkedList<int> c(test1);
		a = b;
		for (int i = 0; i < a.getNumOfEl(); i++) {
			EXPECT_EQ(b[i], a[i]);
		}
		b = c;
		a = move(c);
		for (int i = 0; i < a.getNumOfEl(); i++) {
			EXPECT_EQ(b[i], a[i]);
		}
		EXPECT_EQ(c.getNumOfEl(), 0);
		EXPECT_EQ(a[2], 1);
		EXPECT_FALSE(a[6]);
	}
	TEST(CSingleLinkedList, Ioutput) {
		ostringstream out;
		CSingleLinkedList<int> a;
		out << a;
		EXPECT_EQ("\n", out.str());
		std::ostringstream out1;
		vector<int> test = { 40, 34, 4 };
		CSingleLinkedList<int> b(test);
		out1 << b;
		EXPECT_EQ("40 34 4 \n", out1.str());
	}
	TEST(CSingleLinkedList, Iinput)
	{
		CSingleLinkedList<int> test;
		istringstream input("3\n1\n4\n-6\n");
		input >> test;
		EXPECT_EQ(test.getNumOfEl(), 3);
		EXPECT_EQ(test[0], 1);
		EXPECT_EQ(test[1], 4);
		EXPECT_EQ(test[2], -6);
	}
	TEST(CSingleLinkedList, IinputOtputExcepton)
	{
		CSingleLinkedList<int> test;
		istringstream input("3\nsdf\n5\n34\n");
		input >> test;
		EXPECT_FALSE(input);
	}
	TEST(CSingleLinkedList, IemptyCSingleLinkedListException)
	{
		CSingleLinkedList<int> r;
		EXPECT_FALSE(r.findMin());
		EXPECT_EQ(r.findMin(), 0);
		EXPECT_FALSE(r.findMax());
		EXPECT_EQ(r.findMax(), 0);
	
		EXPECT_FALSE(r.getFirstEl());
		EXPECT_EQ(r.getFirstEl(), 0);
		EXPECT_FALSE(r.getLastEl());
		EXPECT_EQ(r.getLastEl(), 0);
	}
	TEST(CSingleLinkedList, IaadSubtException)
	{
		vector<int> a = { 3, 4 };
		vector<int> b = { 4, 7, 4, 7 };
		vector<int> c = { 0, 1 };
		CSingleLinkedList<int> u(a);
		CSingleLinkedList<int> x(b);
		CSingleLinkedList<int> i(c);
		CSingleLinkedList<int> p;
		p = u + x;
		EXPECT_EQ(p.getNumOfEl(), 0);
		EXPECT_EQ(p.getFirstEl(), 0);
		EXPECT_EQ(p.getLastEl(), 0);
		p = u + i;
		for (int s = 0; s < u.getNumOfEl(); s++)
		{
			EXPECT_EQ(p[s], u[s] + i[s]);
		}
		p = u - x;
		EXPECT_EQ(p.getNumOfEl(), 0);
		EXPECT_EQ(p.getFirstEl(), 0);
		EXPECT_EQ(p.getLastEl(), 0);
		p = u - i;
		for (int s = 0; s < u.getNumOfEl(); s++)
		{
			EXPECT_EQ(p[s], u[s] - i[s]);
		}
	}
	TEST(CSingleLinkedList, IArrayException)
	{
		vector<int> b = { 4, 7, 4, 7 };
		CSingleLinkedList<int> u(b);
		EXPECT_TRUE(u[2]);
		EXPECT_EQ(u[2], 4);
		EXPECT_FALSE(u[10]);
		EXPECT_EQ(u[6], 0);
	}
	TEST(CSingleLinkedList, IDynamicOverload)
	{
		vector<CSingleLinkedList<int>> a;
		vector<int> r = { 34 };
		for (int i = 0; i < 100000; i++)
		{
			a.push_back(CSingleLinkedList<int>(r));
			//EXPECT_TRUE(a[i]);
		}
		CSingleLinkedList<int>* f = new CSingleLinkedList<int>[10000000];
	}

TEST(CSingleLinkedList, CSgetters) {
		CSingleLinkedList<CSphere> a;
		EXPECT_EQ(a.getFirstEl(), CSphere());
		EXPECT_EQ(a.getLastEl(), CSphere());
		EXPECT_EQ(a.getNumOfEl(), 0);
		vector<CSphere> test = { CSphere(4, 6, 2, 1), CSphere(90, 34, 1, 13), CSphere(6, 8 ,2, 12), CSphere(3, 5, 2, 2)};
		CSingleLinkedList<CSphere> b(test);
		EXPECT_EQ(b.getFirstEl(), CSphere(4, 6, 2, 1));
		EXPECT_EQ(b.getLastEl(), CSphere(3, 5, 2, 2));
		EXPECT_EQ(b.getNumOfEl(), 4);
		a = b;
		EXPECT_EQ(a.getFirstEl(), CSphere(4, 6, 2, 1));
		EXPECT_EQ(a.getLastEl(), CSphere(3, 5, 2, 2));
		EXPECT_EQ(a.getNumOfEl(), 4);
	}
	TEST(CSingleLinkedList, CSfindValue) {
		CSingleLinkedList<CSphere> a;
		vector<CSphere> test =  { CSphere(4, 6, 2, 1), CSphere(90, 34, 1, 13), CSphere(6, 8 ,2, 12), CSphere(3, 5, 2, 80)};
		vector<CSphere> test1 = { CSphere(4, 6, 2, 37), CSphere(90, 34, 1, 13), CSphere(6, 8 ,2, 12), CSphere(3, 5, 2, 2) };
		CSingleLinkedList<CSphere> b(test);
		CSingleLinkedList<CSphere> c(test1);
		EXPECT_EQ(a.findMax(), CSphere());
		EXPECT_EQ(b.findMax(), CSphere(3, 5, 2, 80));
		EXPECT_EQ(c.findMax(), CSphere(4, 6, 2, 37));
		EXPECT_EQ(a.findMin(), CSphere());
		EXPECT_EQ(b.findMin(), CSphere(4, 6, 2, 1));
		EXPECT_EQ(c.findMin(), CSphere(3, 5, 2, 2));
	}
	TEST(CSingleLinkedList, CSsorting) {
		CSingleLinkedList<CSphere> a;
		vector<CSphere> test = { CSphere(4, 6, 2, 1), CSphere(90, 34, 1, 13), CSphere(6, 8 ,2, 12), CSphere(3, 5, 2, 80) };
		vector<CSphere> expected1_1 = { CSphere(3, 5, 2, 80),CSphere(90, 34, 1, 13), CSphere(6, 8 ,2, 12),  CSphere(4, 6, 2, 1) };
		vector<CSphere> expected1_2 = { CSphere(4, 6, 2, 1), CSphere(6, 8 ,2, 12), CSphere(90, 34, 1, 13), CSphere(3, 5, 2, 80) };
		CSingleLinkedList<CSphere> b(test);
		EXPECT_NO_THROW(a.choiceSort());
		EXPECT_NO_THROW(a.choiceSort());
		b.choiceSort();
		for (int i = 0; i < b.getNumOfEl(); i++)
			{
				EXPECT_EQ(b[i], expected1_1[i]);
			}
		b.bubbleSort();
		for (int i = 0; i < b.getNumOfEl(); i++)
		{
			EXPECT_EQ(b[i], expected1_2[i]);
		}
	}
	
	TEST(CSingleLinkedList, CSskalyar)
	{
		CSingleLinkedList<CSphere> a;
		vector<CSphere> test = { CSphere(4, 6, 2, 1), CSphere(90, 34, 1, 13), CSphere(6, 8 ,2, 12), CSphere(3, 5, 2, 80) };
		vector<CSphere> expected1_1 = { CSphere(4, 6, 2, 0), CSphere(90, 34, 1, 0), CSphere(6, 8 ,2, 0), CSphere(3, 5, 2, 0) };
		vector<CSphere> expected1_2 = { CSphere(4, 6, 2, 0.5), CSphere(90, 34, 1, 6.5), CSphere(6, 8 ,2, 6), CSphere(3, 5, 2, 40) };
		vector<CSphere> expected1_3 = { CSphere(4, 6, 2, 100), CSphere(90, 34, 1, 1300), CSphere(6, 8 ,2, 1200), CSphere(3, 5, 2, 8000) };
		CSingleLinkedList<CSphere> b(test);
		a = b;
		b.skalyar(0);
		for (int i = 0; i < b.getNumOfEl(); i++) {
			EXPECT_EQ(b[i], expected1_1[i]);
		}
		b = a;
		b.skalyar(0.5);
		for (int i = 0; i < b.getNumOfEl(); i++) {
			EXPECT_EQ(b[i], expected1_2[i]);
		}
		b = a;
		b.skalyar(100);
		for (int i = 0; i < b.getNumOfEl(); i++) {
			EXPECT_EQ(b[i], expected1_3[i]);
		}
	}

	TEST(operator, CSplusAndMinus)
	{
		CSingleLinkedList<CSphere> a;
		vector<CSphere> test = { CSphere(4, 6, 2, 1), CSphere(90, 34, 1, 13), CSphere(6, 8 ,2, 12), CSphere(3, 5, 2, 80) };
		vector<CSphere> expected1_1 = { CSphere(4, 6, 2, 1), CSphere(90, 34, 1, 13), CSphere(6, 8 ,2, 12), CSphere(3, 5, 2, 80), CSphere(1, 4, 1, 4), CSphere(1, 1, 4, 3 )};
		vector<CSphere> expected1_2 = { CSphere(4, 6, 2, 1)};
		CSingleLinkedList<CSphere> b(test);
		EXPECT_NO_THROW(a.operator-());
		EXPECT_NO_THROW(a.operator+(CSphere(0, 0, 4, 3)));
		EXPECT_EQ(a[0], CSphere(0, 0, 4, 3));
		a.operator+(CSphere(2, 4, 4, 10));
		a.operator-();
		a.operator-();
		EXPECT_NO_THROW(a.operator-());
		b.operator+(CSphere(1, 4, 1, 4));
		b.operator+(CSphere(1, 1, 4, 3));
		for (int i = 0; i < expected1_1.size(); i++) {
			EXPECT_EQ(b[i], expected1_1[i]);
		}
		b.operator-();
		b.operator-();
		b.operator-();
		b.operator-();
		for (int i = 0; i < expected1_2.size(); i++) {
			EXPECT_EQ(b[i], expected1_2[i]);
		}
	}
	TEST(operator, CSequal)
	{
		CSingleLinkedList<CSphere> a;
		vector<CSphere> test = { CSphere(4, 6, 2, 1), CSphere(90, 34, 1, 13), CSphere(6, 8 ,2, 12), CSphere(3, 5, 2, 80)  };
		vector<CSphere> test1 = { CSphere(3, 5, 2, 80), CSphere(1, 4, 1, 4), CSphere(1, 1, 4, 3)  };
		CSingleLinkedList<CSphere> b(test);
		CSingleLinkedList<CSphere> c(test1);
		a = b;
		for (int i = 0; i < a.getNumOfEl(); i++) {
			EXPECT_EQ(b[i], a[i]);
		}
		b = c;
		a = move(c);
		for (int i = 0; i < a.getNumOfEl(); i++) {
			EXPECT_EQ(b[i], a[i]);
		}
		EXPECT_EQ(c.getNumOfEl(), 0);
		EXPECT_EQ(a[2], CSphere(1, 1, 4, 3));
	}

	TEST(CSingleLinkedList, CSoutput) {
		ostringstream out;
		CSingleLinkedList<CSphere> a;
		out << a;
		EXPECT_EQ("\n", out.str());
		std::ostringstream out1;
		vector<CSphere> test = { CSphere(4, 6, 2, 1), CSphere(90, 34, 1, 13), CSphere(6, 8 ,2, 12) };
		CSingleLinkedList<CSphere> b(test);
		out1 << b;
		EXPECT_EQ("(x - (4))^2 + (y - (6))^2 + (z - (2))^2 = 1\nx = 4, y = 6, z = 2, R = 1\n (x - (90))^2 + (y - (34))^2 + (z - (1))^2 = 169\nx = 90, y = 34, z = 1, R = 13\n (x - (6))^2 + (y - (8))^2 + (z - (2))^2 = 144\nx = 6, y = 8, z = 2, R = 12\n \n", out1.str());
	}
	TEST(CSingleLinkedList, CSinput)
	{
		CSingleLinkedList<CSphere> test;
		istringstream input("1\n1\n4\n-6\n3\n");
		input >> test;
		EXPECT_EQ(test.getNumOfEl(), 1);
		EXPECT_EQ(test[0], CSphere(1, 4, -6, 3));

	}
	TEST(CSingleLinkedList, CSinputOtputExcepton)
	{
		CSingleLinkedList<CSphere> test;
		istringstream input("3\nsdf\n5\n34\n45");
		input >> test;
		EXPECT_FALSE(input);
	}
	TEST(CSingleLinkedList, CSemptyCSingleLinkedListException)
	{
		CSingleLinkedList<CSphere> r;
		EXPECT_EQ(r.findMin(), CSphere());
		EXPECT_EQ(r.findMax(), CSphere());
		EXPECT_EQ(r.getFirstEl(), CSphere());
		EXPECT_EQ(r.getLastEl(), CSphere());
	}
	TEST(CSingleLinkedList, CSArrayException)
	{
		vector<CSphere> b = { CSphere(4, 6, 2, 1), CSphere(90, 34, 1, 13), CSphere(6, 8 ,2, 12) };
		CSingleLinkedList<CSphere> u(b);
		EXPECT_EQ(u[2], CSphere(6, 8, 2, 12));
		EXPECT_EQ(u[6], CSphere());
	}
	TEST(CSingleLinkedList, CSDynamicOverload)
	{
		vector<CSingleLinkedList<CSphere>> a;
		vector<CSphere> r = { CSphere()};
		for (int i = 0; i < 100000; i++)
		{
			a.push_back(CSingleLinkedList<CSphere>(r));
			//EXPECT_TRUE(a[i]);
		}
		CSingleLinkedList<CSphere>* f = new CSingleLinkedList<CSphere>[10000000];
	}