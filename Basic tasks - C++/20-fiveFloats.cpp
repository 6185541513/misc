#include <iostream>
#include <limits>
using namespace std;

void fiveFloats(){
	cout << "20. fiveFloats():" << endl;
	float current;
	float avg;
	float sum = 0;
	float largest = numeric_limits<float>::min();
	float floats[5];
	for (int i = 0; i < 5; i++){
		cout << "give floatnumber: " << endl;
		cin >> floats[i];
		current = floats[i];
		sum += current;
		if (current > largest){
			largest = current;
		}
	}
	avg = sum / 5;
	cout << "avrage: " << avg << "\nsum: " << sum << "\nlargest: " << largest << endl;
}