#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <cmath>
using namespace std;
float brickollision(int x1, int y1, int x2, int y2);

int main() {
	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_mouse();

	int SCREEN_W = 1280;
	int SCREEN_H = 960;
	int bricksize = 100;
	double mouse_x = 0;
	double mouse_y = 0;
	int movecounter = 0;
	int movedir = 1;
	double brick_x = SCREEN_W / 3;
	double brick_y = SCREEN_H / 2;
	long bricks = 0;
	double bricksperclick = 1;
	double brickspersecond = 0; 
	bool clicked = false;
	bool redraw = true;

	ALLEGRO_FONT* brickfont = al_load_font("Brick.ttf", 32, 0);
	ALLEGRO_BITMAP* brickimage = al_load_bitmap("BRICK.png");
	ALLEGRO_DISPLAY* display = al_create_display(SCREEN_W, SCREEN_H);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60);

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_start_timer(timer);
	al_clear_to_color(al_map_rgb(255, 255, 255));
	while (true) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
			if (clicked) {
				clicked = false;

			}

			if (movedir == -1 && movecounter > 15) {
				movedir = 1;
				movecounter = 0;
			}
			if (movedir == 1 && movecounter > 15) {
				movedir = -1;
				movecounter = 0;
			}
			movecounter++;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES || ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
			mouse_x = ev.mouse.x;
			mouse_y = ev.mouse.y;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (brickollision(mouse_x, mouse_y, brick_x, brick_y) < bricksize) {
				clicked = true;
				bricks += bricksperclick;
				cout << "Brick clicked" << endl;
				cout << "Bricks = " << bricks << endl;
			}
		}
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(255, 255, 255));
			al_draw_bitmap(brickimage, brick_x - bricksize/2, brick_y + (movecounter * movedir) -bricksize/2, ALLEGRO_ALIGN_CENTER);
			al_draw_textf(brickfont, al_map_rgb(255, 50, 50), brick_x, brick_y, ALLEGRO_ALIGN_CENTER, "CLICK THIS");
			al_draw_textf(brickfont, al_map_rgb(255, 50, 50), brick_x, brick_y - 75, ALLEGRO_ALIGN_CENTER, "BRICKS PRODUCED: %i", bricks);
			al_flip_display();
		}
	}
}
float brickollision(int x1, int y1, int x2, int y2) {
	return(sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}
