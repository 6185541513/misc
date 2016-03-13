#include <iostream>
using namespace std;

void evenPrint(){
	cout << "19b. evenPrint:" << endl;
	int num;
	cout << "gimme a num bitch:" << endl;
	cin >> num;

	for (int i = 0; i < num; i++){
		if (i % 2 == 0){
			cout << i<< endl;
		}
	}
}