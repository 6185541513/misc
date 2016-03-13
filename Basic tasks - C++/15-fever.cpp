#include <iostream>
using namespace std;

void fever(){
	cout << "15. fever(): " << endl;
	double temp;

	cout << "whats your temp?" << endl;
	cin >> temp;

	if (temp < 36 || temp > 40){
		cout << "jesus chorst, call the doc" << endl;
	}
	else if(temp < 37.5){
		cout << "normal" << endl;
	}
	else{
		cout << "stay at home and chill^^" << endl;
	}
}