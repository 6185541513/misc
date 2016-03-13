#include <iostream>
using namespace std;

void poundKg(){
	cout << "\n07. poundKg(): " << endl;
	float ptk = 0.45359237;
	int pound;
	cout << "write pounds u want tarnsformed to kg: " << endl;
	cin >> pound;
	cout << pound << " pound(s) equals " << ptk*pound << " kg" << endl;
}