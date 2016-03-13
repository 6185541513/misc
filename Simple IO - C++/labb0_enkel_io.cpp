#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "Header.h"
using namespace std;

int main(){
	cout.precision(3);

	no_01_key();
	no_02_int();
	no_03_threeInts();
	no_04_reelNo();
	no_05_intAndReel();
	no_06_string();
	no_07_wholeLine();
	no_08_intAndString();
	no_09_stringAndReel();
	no_10_lineAndNegative();

	cin.ignore();

	return 0;
}

void no_01_key(){
	char key;

	cout << "Write a key: ";
	cin >> key;
	cout << "\nYou wrote the key: " << key;
	space_between_functions();
}

void no_02_int(){
	int i;

	cout << "Write an int: ";
	cin >> i;
	cout << "\nYou wrote the int: " << i;
	space_between_functions();
}

void no_03_threeInts(){
	int i1, i2, i3;

	cout << "Write three ints: ";
	cin >> i1 >> i2 >> i3;
	cout << "\nYou wrote the ints: " << i1 << ", " << i2 << ", " << i3;
	space_between_functions();
}

void no_04_reelNo(){
	float f;

	cout << "Write a reel no: ";
	cin >> f;
	cout << "\nYou wrote the reel no: " << fixed << f;
	space_between_functions();
}

void no_05_intAndReel(){
	int i;
	float f;

	cout << "Write an int and a reel no: ";
	cin >> i >> f;
	cout << "\nYou wrote the int: " << i;
	cout << "\nYou wrote the reel no: " << fixed << f;
	space_between_functions();
}

void no_06_string(){
	string s;

	cout << "Write a string: ";
	cin >> s;
	cout << "\nThe string '" << s << "' has " << s.size() << " characters";
	space_between_functions();
}

void no_07_wholeLine(){
	string line;

	cout << "Write the whole line: ";
	getline(cin, line);
	cout << "\nYou wrote: '" << line << "'";
	space_between_functions();
}

void no_08_intAndString(){
	int i;
	string s;

	cout << "Write an int and a string: ";
	cin >> i >> s;
	cout << "\nYou wrote the int '" << i << "' and the string '" << s << "'";
	space_between_functions();
}

void no_09_stringAndReel(){
	string s;
	float f;

	cout << "Write a string and a reel no: ";
	cin >> s >> f;
	cout << "\nYou wrote the string '" << s << "' and the reel no '" << fixed << f << "'";
	space_between_functions();
}

void no_10_lineAndNegative(){
	string total_input;
	string s;
//	string segment;
//	vector<string> segment_list;
	cout << "Write a line ending with a negative int: ";
	getline(cin, total_input, '-');
	getline(cin, s);
/*
	stringstream line(total_input);
	while (getline(line, segment, '-')){
		segment_list.push_back(segment);
	}
*/
//	total_input += '-';
	cout << "\nYou wrote the line '" << total_input.substr(0, total_input.find('-')) << "' and the neg int '-"  << s << "'";
	space_between_functions();
}

void space_between_functions(){
	cout << endl << "*****************" << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
