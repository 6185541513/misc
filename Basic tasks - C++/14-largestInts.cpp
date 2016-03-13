#include <iostream>
using namespace std;

void largestOfTwo(){
	cout << "14. largestOfTwo():" << endl;
	int i1; 
	int i2;
	cout << "write two numbers" << endl;
	cin >> i1 >> i2;

	if (i1 > i2){
		cout << "largest: " << i1 << endl;
	}
	else{
		cout << "largest: " << i2 << endl;
	}
}