#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	stack <char> r;
	string input;
	cout << "Give me a string." << endl;
	getline(cin, input);
	for (int i = 0; i != input.size(); i++) {
		r.push(input[i]);
		cout << r.top();
	}
	cout << endl;
	cout << "When reversed, that should read: ";
	for (int i = r.size(); i != 0; i--) {
		cout << r.top();
		r.pop();
	}
}