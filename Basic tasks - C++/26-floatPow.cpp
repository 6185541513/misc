#include <iostream>
using namespace std;

float powF(float f);
void floatPow(){
	float f;
	cout << "26. floatPow(): " << endl;
	cout << "Please give me a float number: " << endl;
	cin >> f;
	cout << f << " to " << 3 << " is " << powF(f) << "." << endl;
}

float powF(float f){
	float ff = f;
	for (int i = 0; i < 3; i++){
		f = f * ff;
	}
	return f;
}