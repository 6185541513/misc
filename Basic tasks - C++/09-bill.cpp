#include <iostream>
using namespace std;

void printBill(){
	cout << "\n09. printBill():" << endl;
	int units;
	int price;

	cout << "how many bitch?" << endl;
	cin >> units;

	cout << "how much per unit??" << endl;
	cin >> price;

	cout << "Bill, bitch" << "\n---------\n" << endl;
	cout << "Units: " << units << "\nPrice: " << price << "\nTotal: " << units*price << "\nTax: " << units*price*0.25 << endl;
}