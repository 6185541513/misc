#include <iostream>
using namespace std;

void circleArea(){
	cout << "\n05. circleArea(): " << endl;
	float pi = 3.14159;
	int radius;
	cout << "gimme the radius punk: " << endl;
	cin >> radius;
	cout << "Area: " << pi*radius*radius << endl;
	cout << "Omkrets: " << 2*pi*radius << endl;
}