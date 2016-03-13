#include <iostream>
#include <sstream>
using namespace std;

void backwards(){
	cout << "21. backwards():" << endl;

	int num;
	cout << "write a number and i shall reverse it for you: " << endl;
	cin >> num;

	ostringstream convert;
	convert << num;
	string s = convert.str();
	int toAppend;
	string reverse = "";

	for (int i = 0; i < s.length(); i++){
		toAppend = num % 10;
		convert.str("");
		convert << toAppend;
		reverse += convert.str();
		num = num / 10;
	}
	cout << reverse << endl;
}