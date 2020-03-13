#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main() {
	vector<string> names;
	vector<string>::iterator nameiter;
	string entry = "z";
	int nameslot = 0;
	cout << "Welcome to the tournament!  Please sign up here. (Use \"quit\" when all names have been entered.)" << endl;
	while (entry.compare("quit") != 0) {
		getline(cin, entry);
		if (entry.compare("quit") != 0) {
			cout << entry << " Has been included in the tournament." << endl;
			names.push_back(entry);
		}
		else {
			cout << "We will stop taking names." << endl;
		}

	}
	cout << "Now that everyone's names are in, let's review." << endl;
	for (nameiter = names.begin(); nameiter != names.end(); nameiter++) {
		cout << *nameiter << endl;
	}
	random_shuffle(names.begin(), names.end());
	cout << "Now, we will see how the competitors are paired up." << endl;
	if (names.size() % 2 != 0) {
		cout << "We seem to have an odd number of competitors.  Therefore, one will be left out of this round." << endl;
		for (nameiter = names.begin(); nameiter != (names.end()-1); nameiter += 2) {
			cout << *nameiter << " | " << *(nameiter + 1)<< endl;
		}
		nameiter = (names.end()-1);
		cout<< *nameiter<< " Has been left out.";
	}
	if (names.size() % 2 == 0) {
		cout << "The tournament will be underway with these matchups:" << endl;
		for (nameiter = names.begin(); nameiter != names.end(); nameiter+=2) {
				cout << *nameiter << " | " << *(nameiter + 1) << endl;
		}

	}

}