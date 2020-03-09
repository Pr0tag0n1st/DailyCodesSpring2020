#include <iostream>
#include <string>
using namespace std;

class Dinosaur {
public:
	void Dinoinit(string designation, bool diet, int heavy);
	void RAAAR();
	void PrintInfo();
	void Eat(int leafs);
private:
	string name;
	bool carnivore;
	int weight;
};

int main() {
	string input;
	int input1;
	bool input2;
	Dinosaur d1;
	Dinosaur d2;
	Dinosaur d3;



	cout << "Hello! I would like for you to create 3 dinosaurs!" << endl;
	cout << "Start off by naming this one." << endl;
	getline(cin, input);
	cout << "Is it a carnivore?  (1 for yes, 0 for no)" << endl;
	cin >> input2;
	cout << "How heavy is it?" << endl;
	cin >> input1;
	d1.Dinoinit(input, input2, input1);
	cout << "Alright, so here is its information:" << endl;
	d1.PrintInfo();
	cout << "How much food would you like to feed " << input << "?" << endl;
	cin >> input1;
	d1.Eat(input1);
	cout << "Now here is its updated information:" << endl;
	d1.PrintInfo();
	d1.RAAAR();
	cout << "Start of by naming two " << endl;
	getline(cin, input);
	getline(cin, input);
	cout << "Is it a carnivore? ( 1 for yes, 0 for no" << endl;
	cin >> input2;
	cout << "How heavy is it" << endl;
	cin >> input1;
	d2.Dinoinit(input, input2, input1);
	cout << "alright, so heres its information:" << endl;
	d2.PrintInfo();
	d2.RAAAR();
	cout << "how much food would you like to feed" << endl;
	cin >> input1;
	d2.Eat(input1);
	cout << "now here is its upadtated information" << endl;
	d2.PrintInfo();
	cout << "Now name number 3." << endl;
	getline(cin, input);
	getline(cin, input);
	cout << "Is it a carnivore?  (1 for yes, 0 for no)" << endl;
	cin >> input2;
	cout << "How heavy is it?" << endl;
	cin >> input1;
	d3.Dinoinit(input, input2, input1);
	d3.RAAAR();
	cout << "Alright, so here is its information:" << endl;
	d3.PrintInfo();
	cout << "How much food would you like to feed " << input << "?" << endl;
	cin >> input1;
	d3.Eat(input1);
	cout << "now here is its upadtated information" << endl;
	d3.PrintInfo();
}

void Dinosaur::Dinoinit(string designation, bool diet, int heavy) {
	name = designation;
	carnivore = diet;
	weight = heavy;
}
void Dinosaur::RAAAR() {
	cout << name << " says RAAAR" << endl;;
}
void Dinosaur::PrintInfo() {
	cout << "the Dinosaur name is " << name << ", carnivore is " << carnivore << " And it weighs " << weight << " pounds." << endl;
}
void Dinosaur::Eat(int leafs) {
	weight += leafs;
}