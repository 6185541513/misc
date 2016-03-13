#include <iostream>
using namespace std;

void calcSquares(){
	cout << "16. calcSquares():" << endl;
	int max;

	cout << "number you max want square of : " << endl;
	cin >> max;

	for (int i = 1; i <= max; i++){
		cout << i*i << endl;
	}
}