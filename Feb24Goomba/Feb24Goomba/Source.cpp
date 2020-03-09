#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <string>
#include <iostream>
using namespace std;

class Goomba {
public:
	void initGoomba(int x, int y, bool c, string n, ALLEGRO_BITMAP*one, ALLEGRO_BITMAP*two);
	void draw();
	void print();
private:
	int xpos;
	int ypos;
	bool color; //0 = brown, 1 = blue
	string name;
	ALLEGRO_BITMAP* picturebr;
	ALLEGRO_BITMAP* picturebl;
};

int main() {
	al_init();
	al_init_image_addon();
	ALLEGRO_DISPLAY* display = al_create_display(1280, 960);
	ALLEGRO_BITMAP* brown = al_load_bitmap("goombrown.png");
	ALLEGRO_BITMAP* blue = al_load_bitmap("goomblue.png");
	al_clear_to_color(al_map_rgb(50, 255, 100));
	al_flip_display();
	cout << "Flag1" << endl;
	Goomba g1;
	Goomba g2;
	Goomba g3;
	Goomba g4;
	cout << "Flag2" << endl;
	g1.initGoomba(200, 300, true, "Goombruh", brown, blue);
	g2.initGoomba(660, 560, false, "Goom", brown, blue);
	g3.initGoomba(890, 680, true, "Broomba", brown, blue);
	g4.initGoomba(100, 700, false, "Doomba", brown, blue);
	cout << "Flag3" << endl;
	g1.draw();
	g2.draw();
	g3.draw();
	g4.draw();
	cout << "Flag4" << endl;
	g1.print();
	g2.print();
	g3.print();
	g4.print();
	cout << "Flag5" << endl;
	al_flip_display();
	al_rest(9.0);
}


void Goomba::initGoomba(int x, int y, bool c, string n, ALLEGRO_BITMAP*one, ALLEGRO_BITMAP*two) {
	xpos = x;
	ypos = y;
	color = c;
	name = n;
	picturebl = one;
	picturebr = two;
}

void Goomba::draw() {
	if (color == true)
		al_draw_bitmap(picturebl, xpos, ypos, 0);
	if (color == false)
		al_draw_bitmap(picturebr, xpos, ypos, 0);
}

void Goomba::print() {
	cout << "This goomba is " << name << ". He is at " << xpos << ", " << ypos << ".  ";
	if (color == true)
		cout << "He is blue." << endl;
	if (color == false)
		cout << "He is brown." << endl;
}