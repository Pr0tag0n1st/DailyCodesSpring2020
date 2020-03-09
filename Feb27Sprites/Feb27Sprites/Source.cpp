#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
using namespace std;

const int PLAYER_WIDTH = 48;
const int PLAYER_HEIGHT = 52;
const int SCREEN_W = 1280;
const int SCREEN_H = 960;
enum MYKEYS {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT};

int main() {
	al_init();
	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();

	cout << "Allegro loaded" << endl;

	double playerx = SCREEN_W / 2;
	double playery = SCREEN_H / 2;

	bool key[4] = { false, false, false, false }; //holds key clicks
	bool redraw = true; //variable needed for render section
	bool doexit = false; //handles game loop
	int spritecell = 0;
	int spriterow = 0;
	int spritetime = 0;

	cout << "Variables initialized" << endl;

	ALLEGRO_BITMAP* linkspritesheet = al_load_bitmap("linksheet.png");
	ALLEGRO_DISPLAY* display = al_create_display(SCREEN_W, SCREEN_H);
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();

	cout << "Allegro variables initialized" << endl;

	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_convert_mask_to_alpha(linkspritesheet, al_map_rgb(255, 255, 255));

	cout << "Spritesheet ready" << endl;

	al_start_timer(timer);

	cout << "Timer started" << endl;

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));

	cout << "Event sources ready" << endl;





	while (!doexit)//game loop!
	{
		ALLEGRO_EVENT ev;

		al_wait_for_event(event_queue, &ev);

		//timer (physics) section////////////////////////////////////////
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			//move player 4 pixels in a direction when key is pressed
			if (key[KEY_UP]) {

				spriterow = 6;

				spritetime++;
				if (spritetime > 8) {
					spritetime = 0;
					spritecell++;
					if (spritecell > 7)
						spritecell = 0;
				}

				playery -= 4.0;
			}	
			if (key[KEY_DOWN]) {

				spriterow = 4;

				spritetime++;
				if (spritetime > 8) {
					spritetime = 0;
					spritecell++;
					if (spritecell > 7)
						spritecell = 0;
				}

				playery += 4.0;
			}
			if (key[KEY_LEFT]) {

				spriterow = 5;

				spritetime++;
				if (spritetime > 8) {
					spritetime = 0;
					spritecell++;
					if (spritecell > 7)
						spritecell = 0;
				}

				playerx -= 4.0;
			}
			if (key[KEY_RIGHT]) {

				spriterow = 7;

				spritetime++;
				if (spritetime > 8) {
					spritetime = 0;
					spritecell++;
					if (spritecell > 7)
						spritecell = 0;
				}

				playerx += 4.0;
			}
			redraw = true;
		}
		//keyboard and screen sections//////////////////////////////////////////
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;
			}

		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;
			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}
		//render section//////////////////////////////////////////////////
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0)); //wipe screen black between drawing


			al_draw_bitmap_region(linkspritesheet, spritecell*PLAYER_WIDTH, PLAYER_HEIGHT*spriterow, PLAYER_WIDTH, PLAYER_HEIGHT, playerx, playery, NULL); //draw the player
			al_flip_display(); //flip everything from memory to gamescreen
		}//end render

	}//end game loop
	//clean up memory
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}
