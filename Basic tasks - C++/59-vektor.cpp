#include <iostream>
using namespace std;

void vektor(){
	int vektor[] = { 2, 3, 4, 5, 6 };
	int *p = vektor;

	cout << *p << endl;
	cout << *(p + 1) << endl;
}