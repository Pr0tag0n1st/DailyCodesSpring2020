#include <iostream>
using namespace std;

bool PythCheck(int a, int b, int c);

int main() {
	int input1 = 1;
	int input2 = 1;
	int input3 = 1;
	cout << "This program will check if the sides of a triangle make a right triangle." << endl;
	cout << "To exit, input all three sides as 0." << endl;
	while (input1 != 0 && input2 != 0 && input3 != 0) {
		cout << "Give me side a of your triangle. (Whole numbers only please)" << endl;
		cin >> input1;
		cout << "Give me side b of your triangle. (Whole numbers only please)" << endl;
		cin >> input2;
		cout << "Give me side c of your triangle. (Whole numbers only please)" << endl;
		cin >> input3;
		if (input1 == 0 && input2 == 0 && input3 == 0) {
			return 0;
		}
		if (PythCheck(input1, input2, input3) == true)
			cout << "That is a right triangle!" << endl;
		else
			cout << "HEY! THAT'S NOT A RIGHT TRIANGLE!" << endl;
	}
}

bool PythCheck(int a, int b, int c) {
	if ((a * a) + (b * b) == (c * c))
		return true;
	else if (a == 0 && b == 0 && c == 0)
		return false;
	else
		return false;
}