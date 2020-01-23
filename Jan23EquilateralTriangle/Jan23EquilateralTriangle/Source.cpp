#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
using namespace std;
int main() {
	al_init();
	al_init_primitives_addon();
	ALLEGRO_DISPLAY* display = al_create_display(400, 400);
	al_draw_filled_triangle(100, 300, 300, 300, 200, 126.8, al_map_rgb(200, 200, 200));
	al_flip_display();
	al_rest(5.0);
}