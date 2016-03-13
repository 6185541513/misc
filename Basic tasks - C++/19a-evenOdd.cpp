#include <iostream>
using namespace std;

void evenOdd(){
	cout << "19a. evenOdd():" << endl;
	int num;

	cout << "write a num and lets see if its even or odd: " << endl;
	cin >> num;

	if (num % 2 == 0){
		cout << "is even" << endl;
	}
	else{
		cout << "is odd" << endl;
	}
}