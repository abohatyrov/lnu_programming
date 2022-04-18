#include <iostream>
#include <fstream>
#include "triangle.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"

using namespace std;

int main()
{
    Triangle t1;
    t1.print();
	Triangle t2(1, 2, 3);
	t2.print();
	Triangle t3(t1);
	t3.print();
	Triangle t4(10, 5, 8);
	t4.print();
	
	cout << endl;
	
	Rectangle r1;
	r1.print();
	Rectangle r2(4, -9);
	r2.print();
	Rectangle r3(r1);
	r3.print();
	Rectangle r4(5, 2);
	r4.print();
	
	cout << endl;
	
	Square s1;
	s1.print();
	Square s2(-9);
	s2.print();
	Square s3(s1);
	s3.print();
	Square s4(3);
	s4.print();
	
	cout << endl;
	
	Circle c1;
    c1.print();
	Circle c2(-3);
	c2.print();
	Circle c3(c1);
	c3.print();
	Circle c4(2);
	c4.print();
}