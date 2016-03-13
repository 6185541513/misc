#include <iostream>
using namespace std;

void floatInt(){
	cout << "23. floatInt():" << endl;

	float f;
	int i;
	do{
		cout << "write a float: " << endl;
		cin >> f;
		if (f >= 0){
			i = (int)(f + 0.5);
		}
		else{
			i = (int)(f - 0.5);
		}
		cout << i << endl;
	} while (f != 0);
}