#include <iostream>
using namespace std;

int sumOA(int i);
void sumofall(){
	int roof;
	cout << "28. sumofall(): " << endl;
	cout << "Gimme a roof: " << endl;
	cin >> roof;
	cout << "Sum of all numbers up to " << roof << " is " << sumOA(roof) << endl;
}

int sumOA(int roof){
	int sum = 0;
	for (int i = 1; i <= roof; i++){
		sum += i;
	}
	return sum;
}