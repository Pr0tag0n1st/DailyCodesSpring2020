#include <iostream>
#include <ctime>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
using namespace std;
void calculation(int w, int l);
int main() {
	srand(time(NULL));
	int startx = rand() % (1280 / 2);
	int starty = rand() % (960 / 2);
	int r = rand() % 255+1;
	int g = rand() % 255;
	int b = rand() % 255;
	al_init();
	al_init_primitives_addon();
	ALLEGRO_DISPLAY* display = al_create_display(1280, 960);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	int length = 0;
	int width = 0;
	while (true) {
		startx = rand() % (1280 / 2);
		starty = rand() % (960 / 2);
		r = rand() % 255 + 1;
		g = rand() % 255 + 1;
		b = rand() % 255 + 1;
		cout << "Can you give me the length of your rectangle?" << endl;
		cin >> length;
		cout << "Width?" << endl;
		cin >> width;
		calculation(width, length);
		al_draw_rectangle(startx, starty, startx + length, starty + width, al_map_rgb(r, g, b), 1);
		al_flip_display();
	}
}
void calculation(int w, int l) {
	cout << ((2 * w) + (2 * l)) << " is the perimeter of the rectangle." << endl;
	cout << (w * l) << " is the area of the rectangle." << endl;
}