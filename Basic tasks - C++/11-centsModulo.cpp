#include <iostream>
using namespace std;

void centsModulo(){
	cout << "\ncentsModulo(): " << endl;
	int cents;

	cout << "give cents: " << endl;
	cin >> cents;
	float kr = cents / 100;
	float ce = (cents%100)/100.0;
	cout << cents << " cents is: " << kr+ce << " kr" << endl;
}