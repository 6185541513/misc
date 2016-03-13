#include <iostream>
#include <string>
using namespace std;

void squareTwist(){
	cout << "17. squareTwist():" << endl;
	int num;
	string answer;
	cout << "write a number you like squared: " << endl;
	cin >> num;

	do{
		cout << num << " squared: " << num*num << endl;
		cout << "do you wish to continue(yes/no)" << endl;
		cin >> answer;
	}while (answer == "yes");
}