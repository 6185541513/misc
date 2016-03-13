#include <iostream>
using namespace std;

void printFor(){
	cout << "18a. printHello():" << endl;
	int times;
	cout << "how many time u wanna see Hello" << endl;
	cin >> times;

	for (int i = 0; i < times; i++){
		cout << "Hello" << endl;
	}
}