#include <iostream>
#include <ctime>
using namespace std;



int Judge();

int main() {
	srand(time(NULL));
	char input = 'z';
	int tempjudge = 0;
	int testpercent = 0;

	cout << "You are a playtester for Super Smash Brothers Ultimate and must determine whether or not Mr. Game and Watch's Judge is working correctly.  Thus, the move will be used repeatedly." << endl;
	while (input != 'n') {
		cout << "The enemy's percent is " << testpercent << " right now." << endl;
		tempjudge = Judge();
		cout << "The result of this Judge was " << tempjudge << endl;
		switch(tempjudge){
			case 1: cout << "You took damage, and the enemy took 1% damage." << endl;
			testpercent++;
			break;
			case 2: cout << "Your opponent takes 4% damage." << endl;
				testpercent += 4;
				break;
			case 3: if (testpercent < 496) {
				cout << "Your opponent took 6% damage." << endl;
				testpercent += 6;
			}
					else{
				cout << "Your opponent is dead." << endl;
				testpercent = 0; 
				cout << "Now for the next stock." << endl;
					}
				break;
			case 4: if (testpercent < 483) {
				cout << "Your opponent takes 8% damage." << endl;
				testpercent += 8;
			}
					else {
				cout << "Your opponent is dead." << endl;
				testpercent = 0;
				cout << "Now for the next stock." << endl;
			}
				break;
			case 5: if (testpercent < 482) {
				cout << "Your opponent takes 12% damage." << endl;
				testpercent += 12;
			}
					else {
				cout << "Your opponent is dead." << endl;
				testpercent = 0;
				cout << "Now for the next stock." << endl;
			}
				break;
			case 6: if (testpercent < 156) {
				cout << "Your opponent takes 12% damage." << endl;
				testpercent += 12;
			}
					else {
				cout << "Your opponent is dead." << endl;
				testpercent = 0;
				cout << "Now for the next stock." << endl;
			}
				break;
			case 7: if (testpercent < 264) {
				cout << "Your opponent takes 14% damage." << endl;
				testpercent += 14;
				cout << "You also notice apples on the ground." << endl;
			}
					else {
				cout << "Your opponent is dead." << endl;
				testpercent = 0;
				cout << "Now for the next stock." << endl;
				cout << "You also notice apples on the ground." << endl;
			}
				break;
			case 8:
				cout << "Your opponent is frozen and takes 0 damage." << endl;
				break;
			case 9: if (testpercent < 11) {
				cout << "Your opponent somehow survives and takes 32% damage." << endl;
				testpercent += 32;
				cout << "Nice lucky 9 though" << endl;
			}
					else {
				cout << "Surprise, surprise.  Your opponent is dead." << endl;
				testpercent = 0;
				cout << "Onto the next stock." << endl;
			}
				break;
			default:
				cout << "So that didn't work, we need to patch that." << endl;
		}
		cout << "Alright, want to keep testing?  (y/n)" << endl;
		cin >> input;
		if (input == 'y')
			cout << "Alright, let's go again." << endl;
		else if (input == 'n')
			cout << "That ends that then." << endl;
		else
			cout << "I don't understand. let's do this again anyways." << endl;
	}
}


int Judge() {
	int JudgeResult = rand() % 9 + 1;
	return JudgeResult;
}