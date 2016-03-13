#include <iostream>
using namespace std;

int AreaOfBlock(int x, int y);
void blockArea(){
	cout << "27. blockArea(): " << endl;
	int x;
	int y;
	cout << "Give me the lenght and height of the rectangle: " << endl;
	cin >> x >> y;
	cout << "The area is " << AreaOfBlock(x, y) << "." << endl;
}

int AreaOfBlock(int x, int y){
	return x * y;
}