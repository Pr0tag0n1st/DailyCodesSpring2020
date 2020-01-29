#include <iostream>
using namespace std;
int main() {
	int dysentery=0;
	int influenza=0;
	int chickenpox=0;
	int tuberculosis=0;

	cout << "Would you like to take a simple quiz to get a diagnosis? (Y/N, uppercase only) " << endl; 
	char input = 'z';
	cin >> input;
	if (input == 'Y') {

		cout << "Alright, let's start." << endl;
		cout << "Do you have an intense cough (wheezing, throat pain, etc.)?" << endl;
		cin >> input;
		if (input == 'Y') {
			influenza++;
			tuberculosis++;
		}
		else {
			cout << "Onto the next question!" << endl;
		}
		cout << "Do you have unusually dry/itchy skin?" << endl;
		cin >> input;
		if (input == 'Y') {
			dysentery++;
			chickenpox++;
		}
		else {
			cout << "Onto the next question!" << endl;
		}
		cout << "Do you have consistent chest pain?" << endl;
		cin >> input;
		if (input == 'Y') {
			influenza++;
			tuberculosis++;
		}
		else {
			cout << "Onto the next question!" << endl;
		}
		cout << "Are you abnormally nauseous?" << endl;
		cin >> input;
		if (input == 'Y') {
			influenza++;
			dysentery++;
		}
		else {
			cout << "Onto the next question!" << endl;
		}
		cout << "Have you developed a rash?" << endl;
		cin >> input;
		if (input == 'Y') {
			chickenpox++;
		}
		else {
			cout << "Onto the next question!" << endl;
		}
		cout << "Do you have a headache?" << endl;
		cin >> input;
		if (input == 'Y') {
			influenza++;
		}
		else {
			cout << "Onto the next question!" << endl;
		}
		cout << "Have you recently coughed up any discharge/plegm?" << endl;
		cin >> input;
		if (input == 'Y') {
			tuberculosis++;
		}
		else {
			cout << "Onto the next question!" << endl;
		}
		cout << "Do you have unusually painful abdominal pain?" << endl;
		cin >> input;
		if (input == 'Y') {
			influenza++;
			tuberculosis++;
		}
		else {
			cout << "Onto the next question!" << endl;
		}
		cout << "The result is..." << endl;
		if (influenza > dysentery && influenza > tuberculosis && influenza > chickenpox) {
			cout << "You may have influenza. Contact us for more information." << endl;
		}
		else if (dysentery > influenza && dysentery > tuberculosis && dysentery > chickenpox) {
			cout << "You may have dysentery. Contact us for more information." << endl;
		}
		else if (tuberculosis > dysentery && tuberculosis > influenza && tuberculosis > chickenpox) {
			cout << "You may have tuberculosis. Contact us for more information." << endl;
		}
		else if (chickenpox > dysentery && chickenpox > tuberculosis && chickenpox > influenza) {
			cout << "You may have chickenpox. Contact us for more information." << endl;
		}
		else
			cout << "You may have multiple illnesses.  Please check with a physician." << endl;

	}
	else if (input == 'N') {
		cout << "Sorry we couldn't help! Have a good day!" << endl;
	}
}