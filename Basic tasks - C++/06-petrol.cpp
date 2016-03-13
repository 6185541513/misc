#include <iostream>
using namespace std;

void petrolUsage(){
	cout << "\n06. petrolUsage(): " << endl;
	int meterStart;
	int meterGoal; 
	int petrol;

	cout << "whats teh meter at when u begun? (km)" << endl;
	cin >> meterStart;

	cout << "meter at now yo? (km)" << endl;
	cin >> meterGoal;

	cout << "how much petrol was spent? (liter)" << endl;
	cin >> petrol;

	cout << "you car drinks " << (meterGoal-meterStart)/petrol  << " l/mil" << endl;
}