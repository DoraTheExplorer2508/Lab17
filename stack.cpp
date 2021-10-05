#include <iostream>
#include "stack.h"

struct Point
{
	int x, y, z;

	friend ostream& operator<<(ostream& out, const Point& p);
};

int main()
{
	stack<int> st;

	st.push(10);
	st.push(34);
	st.push(22);
	st.push(11);

	cout << st;
	st.pop();
	cout << st;

	stack<int> st2(st);
	cout << st2;

	stack<int> st3;
	st3.push(55);
	st3.push(77);

	st3 = st2;
	cout << st3;

	st3.clear();
	cout << st3;

	stack<Point> points;

	Point p1;
	p1.x = 5;
	p1.y = 6;
	p1.z = 2;

	Point p2;
	p2.x = 1;
	p2.y = 1;
	p2.z = 5;

	Point p3;
	p3.x = 7;
	p3.y = 1;
	p3.z = 2;

	points.push(p1);
	points.push(p2);
	points.push(p3);

	cout << points;
}

ostream& operator<<(ostream& out, const Point& p)
{
	out << "(" << p.x << "," << p.y << "," << p.z << ")";
	return out;
}
