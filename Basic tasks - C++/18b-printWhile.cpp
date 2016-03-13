#include <iostream>
#include <string>
using namespace std;

void printWhile(){
	cout << "18b. printWhile():" << endl;
	string answer = "yes";

	while (answer == "yes"){
		cout << "Hello" << "\nWanna go again?" << endl;
		cin >> answer;
	}
}