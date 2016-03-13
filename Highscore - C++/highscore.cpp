#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

struct Player{
	string name;
	int score;
	Player() {}
	Player(string str, int i) : name(str), score(i){}
};

void getList(Player sortedList[5]);
void add(Player p, Player sortedList[5]);
void sort(Player sortedList[5]);

int main(){
//prepare initial list
	string names[5] = { "Starbuck", "Perka", "Arseface", "Arwen", "Dagobah" };
	int scores[5] = {1100, 999, 500, 450, 1};
	Player sortedList[5];
	
	for (int i = 0; i < 5; i++){
		sortedList[i] = Player(names[i], scores[i]);
	}

	string input = "";

//start high score...
	do{
		input.empty();
	//print head
		cout << "\n********************\n  High score, dude!\n********************" << endl;

	//print list
		getList(sortedList);

	//ask if continue
		cout << "\nSir, Do you wish to continue? (yes/no)" << endl;
		cin >> input;
		while (input != "yes" && input != "no"){
			cout << "Why, I didn't catch that. I'm special, one might say. A simple yes or no, please:" << endl;
			cin >> input;
		}

	//if continue
		if (input == "yes"){
			char name[20];
			int score;

			cout << "Enter name: " << endl;
			cin >> name;

			cout << "Enter score: " << endl;
			cin >> score;

			add(Player(name, score), sortedList);
		}
	} while (input == "yes");
	cin.ignore();
	cout << "Farewell, old chap!";
	cin.ignore();
	return 0; 
}

void getList(Player sortedList[5]){
	cout << left << setw(10) << "name";
	cout << right << setw(10) << "score\n" << endl;

	for (int i = 0; i < 5; i++){
		cout << left << setw(10) << sortedList[i].name;
		cout << right << setw(10) << sortedList[i].score << endl;
	}
}

void add(Player p, Player sortedList[5]){
//finding lowest score in current list
	int lowestScore = numeric_limits<int>::max();
	int index = 0;

	for (int i = 0; i < 5; i++){
		if (sortedList[i].score < lowestScore){
			lowestScore = sortedList[i].score;
			index = i;
		}
	}

//if new score bigger than lowest score - replace
	if (p.score > lowestScore){
		sortedList[index] = p;
	}

//sort (new) list
	sort(sortedList);
}

//insertion sort algorithm
void sort(Player sortedList[5]){
	//since first element is always "sorted" we ignore it
	for (int i = 1; i < 5; i++){

	/*storing value of current element since that's the one we're going to
	* move around (and not have access to when moving away from it)*/
		Player temp = sortedList[i];

	//initialize j outside for-loop since we need it later
		int j;
	
	/*inner loop is used if element needs to move back in the list, here we do
	* a bit of an optimized loop and put an if directly in it so the loop only
	* starts when necessary*/
		for (j = i - 1; j >= 0 && sortedList[j].score < temp.score; j--){
			sortedList[j + 1] = sortedList[j];
		}
	
	/*if inner for-loop has initialized it's changing the value of the current 
	* element, otherwise just giving it what it already is*/
		sortedList[j + 1] = temp;
	}
}