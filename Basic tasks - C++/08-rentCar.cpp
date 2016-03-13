#include <iostream>
using namespace std;

void calcCarRent(){
	cout << "\n08. calcCarRent():" << endl;
	
	int price;
	int days;
	int pesetas;

	cout << "how much is car per day?" << endl;
	cin >> price;

	cout << "how many day in car?" << endl;
	cin >> days;

	cout << "exchange course:" << endl;
	cin >> pesetas;

	cout << "it will cost " << (price*days + 2000) << " pesetas (" << (price*days + 2000) / pesetas << " kr)" << endl;
}