//#include <iostream>
//using namespace std;
////Made by Diego and TJ (Don't worry about the math, Diego understood variables)
//int main() {
//	cout << "input a 5 digit integer" << endl;
//	int digit1;
//	int digit2;
//	int digit3;
//	int digit4;
//	int digit5;
//	int input = 00000;
//	cin >> input;
//	digit1 = (input % 100000)/10000;
//	digit2 = (input % 10000)/1000;
//	digit3 = (input % 1000)/100;
//	digit4 = (input % 100)/10;
//	digit5 = input % 10;
//	cout << digit1 << " " << digit2 << " " << digit3 << " " << digit4 << " " << digit5 << endl;
//	int sum = 0;
//	sum = digit1 + digit2 + digit3 + digit4 + digit5;
//	cout << "The sum is " << sum << "." << endl;
//
//
//}

//Made by TJ with some structuring help from Aidan
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main() {
	long input;
	long divide = 1;	
	long sum = 0;
	vector<int> digits;
	vector<int>::iterator iter;
	cout << "Input an integer." << endl;
	cin >> input;
	while (floor(input / divide) >= 1) {
		digits.push_back(input / divide % 10);
		divide *= 10;
		
	}
	for (iter = digits.end()-1; iter != digits.begin(); iter--){
		cout << *iter << " ";
		}
	iter = digits.begin();
	cout << *iter;
	cout << endl;

	for (iter = digits.begin(); iter != digits.end(); iter++) {
		sum += (*iter);
	}
	cout << "The sum of the digits is " << sum << endl;
}