#include "circle.h"
#include "circle.cpp"
#include <iostream>

using namespace std;
 
int main()
{
    circle<int> c;
    c.setRadius(5);
    cout << "integer typed class:" << c.getArea() << endl;

    cout << endl;

    circle<double> c2;
    c2.setRadius(5.512);
    cout << "double typed class:" << c2.getArea() << endl;

    cout << endl;

     return 0;
}
