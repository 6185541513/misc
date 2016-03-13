#include <iostream>
using namespace std;

void celsFahr(){
	cout << "24. celsFahr():" << endl;
	
	int start, stop, intervall;

	cout << "give a start, stop and interval value plaese whore: " << endl;
	cin >> start >> stop >> intervall;

	cout << "Celsius\t\tFahrenheit\n---------------" << endl;
	for (int i = start; i <= stop; i += intervall){
		float in = (float)i;
		cout << i << "\t\t" << (9.0 / 5.0 * in) + 32.0 << endl;
	}
}