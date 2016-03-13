#include <iostream>
using namespace std;

void vote(){
	cout << "13. vote():" << endl;
	int age;
	cout << "age?" << endl;
	cin >> age;

	if (age >= 18){
		cout << "u may vote" << endl;
	}
	else{
		cout << "no vote for u!!" << endl;
	}
}