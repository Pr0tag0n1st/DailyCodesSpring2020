#include <iostream>
#include <string>
using namespace std;

class Koopa {
private://Variables
	int x;
	int y;
	int speed;
	string name;
	bool alive;
public://Functions
	void KoopaInit(int xpos, int ypos, string initname, bool living, int move);
	void Print();
};

int main() {
	cout << "Let's study some koopas." << endl;
	Koopa koopa1;//Creates a koopa object
	Koopa koopa2;
	koopa1.KoopaInit(50, 100, "dean", true, 1);//Initializes a koopa
	koopa2.KoopaInit(100, 145, "alan", false, 5);
	cout << "In fact, there's two of them right there!" << endl;
	koopa1.Print();//Prints information
	koopa2.Print();
}

void Koopa::KoopaInit(int xpos, int ypos, string initname, bool living, int move) {//Sets up variables
	x = xpos;
	y = ypos;
	name = initname;
	alive = living;
	speed = move;
}

void Koopa::Print() {
	cout << "This koopa is at " << x << ", " << y << ", is named " << name << ", and his life is " << alive << ". He is moving at "<<speed<<" tiles per second."<<endl;
} 