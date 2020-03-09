#include <iostream>
#include <string>
using namespace std;

namespace Britain {
	string potato = "chips";
	string bread = "English Muffin";
}
namespace France {
	string potato = "Fries";
	string bread = "Baguette";
}
namespace Ireland {
	string potato = "Mashed";
	string bread = "Soda bread";
}
namespace Russia {
	string potato = "Pampushki";
	string bread = "Black bread";
}
namespace America {
	string potato = "Tots";
	string bread = "Texas Toast";
}

int main() {
	char input = 'z';
	while (true) {
		cout << "Let's pick a country:  (B)ritain, (F)rance, (I)reland, (R)ussia, or (A)merica." << endl;
		cin >> input;
		if (input == 'B') {
			cout << "Pick either (B)read or (P)otato." << endl;
			cin >> input;
			if (input == 'B')
				cout << "You have received " << Britain::bread << endl;
			else if (input == 'P')
				cout << "You have received " << Britain::potato << endl;
		}
		else if (input == 'F') {
			cout << "Pick either (B)read or (P)otato." << endl;
			cin >> input;
			if (input == 'B')
				cout << "You have received " << France::bread << endl;
			else if (input == 'P')
				cout << "You have received " << France::potato << endl;
		}
		else if (input == 'I') {
			cout << "Pick either (B)read or (P)otato." << endl;
			cin >> input;
			if (input == 'B')
				cout << "You have received " << Ireland::bread << endl;
			else if (input == 'P')
				cout << "You have received " << Ireland::potato << endl;
		}
		else if (input == 'R') {
			cout << "Pick either (B)read or (P)otato." << endl;
			cin >> input;
			if (input == 'B')
				cout << "You have received " << Russia::bread << endl;
			else if (input == 'P')
				cout << "You have received " << Russia::potato << endl;
		}
		else if (input == 'A') {
			cout << "Pick either (B)read or (P)otato." << endl;
			cin >> input;
			if (input == 'B')
				cout << "You have received " << America::bread << endl;
			else if (input == 'P')
				cout << "You have received " << America::potato << endl;
		}
	}
}