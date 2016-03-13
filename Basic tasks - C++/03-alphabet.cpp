#include <iostream>
using namespace std;

void letterSurrounding(){
	cout << "\n03. letterSurrounding():" << endl;
	char letters[7] {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	char chosenLetter;
	int i;
	cout << "Write a letter: " << endl;
	cin >> chosenLetter;
	for (i = 0; i < 7; i++){
		if (chosenLetter == letters[i]){
			break;
		}
	}
	cout << "Letter before is " << letters[i-1] << " & letter after is " << letters[i+1] << endl;
}