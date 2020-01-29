#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
int main() {
	double angle = 0;
	al_init();
	al_init_primitives_addon();
	al_init_image_addon();
	ALLEGRO_BITMAP* Tridelta = al_load_bitmap("Tridelta.png");
	ALLEGRO_DISPLAY* display = al_create_display(400, 400);
	al_draw_filled_triangle(100, 300, 300, 300, 200, 126, al_map_rgb(255, 255, 100));
	al_draw_filled_triangle(200, 300, 150, 213, 250, 213, al_map_rgb(0, 0, 0));
	al_flip_display();
	al_rest(2.0);
	while (true) {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_rotated_bitmap(Tridelta, 110, 110, 200, 213, angle, 0);
		al_flip_display();
		angle+=.001;
	}
}