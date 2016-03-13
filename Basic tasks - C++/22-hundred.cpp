#include <iostream>
using namespace std;

void hundred(){
	cout << "22. hundred():" << endl;

	double countBig = 0;
	double sumBig = 0;
	double countSmall = 0;
	double sumSmall = 0;
	double countHundred = 0;
	double number;
	do{
		cout << "write a number, if you want to finish write a neg:" << endl;
		cin >> number;
		if (number > 100){
			sumBig += number;
			++countBig;
		}
		else if (number < 100 && number >= 0){
			sumSmall += number;
			++countSmall;
		}
		else if (number == 100){
			++countHundred;
		}
	} while (number >= 0);

	cout << "Big: " << countBig << ", small: " << countSmall << " & exact: " << countHundred << endl;
	cout << "Big, avg: " << sumBig / countBig << ", small, avg: " << sumSmall / countSmall << " & hundred, avg: " << 100 << endl;
}