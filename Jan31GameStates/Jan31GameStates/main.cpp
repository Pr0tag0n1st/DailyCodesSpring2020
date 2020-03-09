#include<iostream>
using namespace std;

#include<allegro5/allegro.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_primitives.h>

const int SCREEN_W = 1280;
const int SCREEN_H = 960;
const double FPS = 1.0 / 60;

enum gamestates { INTRO, PLAYING, PAUSE, END, MENU };
enum mykeys { KEY_W, KEY_S, KEY_A, KEY_D, KEY_ESCAPE };

int main() {
	al_init();
	al_init_primitives_addon();
	al_install_keyboard();
	int player_x = 50;
	int player_y = 50;
	int player_size = 50;
	int movespeed = 5;
	ALLEGRO_DISPLAY* display = al_create_display(SCREEN_W, SCREEN_H);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_TIMER* timer = al_create_timer(FPS);
	al_start_timer(timer);
	bool key[4] = { false, false, false, false };
	int gamestate = INTRO;
	bool running = true;
	bool redraw = true;
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	char input;


	
	while (running) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		switch (gamestate) {
		case INTRO:
			cout << "welcome to the game!" << endl;
			cout << "press 's' to start or 'm' to open the menu" << endl << endl;
			if (key[KEY_S]) {
				//player_y += movespeed;
				gamestate = PLAYING;
				cout << "Key state s in the intro" << endl;
			}


			else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { ////////////////////////////////////
				switch (ev.keyboard.keycode) {
				case ALLEGRO_KEY_UP:
					key[KEY_W] = true;
					break;

				case ALLEGRO_KEY_DOWN:
					key[KEY_S] = true;
					cout << "S again" << endl;
					break;

				case ALLEGRO_KEY_LEFT:
					key[KEY_A] = true;
					break;

				case ALLEGRO_KEY_RIGHT:
					key[KEY_D] = true;
					break;
				}
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_UP) { //////////////////////////////////////
				switch (ev.keyboard.keycode) {
				case ALLEGRO_KEY_UP:
					key[KEY_W] = false;
					break;

				case ALLEGRO_KEY_DOWN:
					key[KEY_S] = false;
					break;

				case ALLEGRO_KEY_LEFT:
					key[KEY_A] = false;
					break;

				case ALLEGRO_KEY_RIGHT:
					key[KEY_D] = false;
					break;

				}
			}


			break;
		case PLAYING:
			cout << "Beep Boop you're playing the game!" << endl;
			cout << "press 'p' to pause, 'm' to open the menu, or 'q' to quit" << endl << endl;
			if (ev.type == ALLEGRO_EVENT_TIMER) {

				//move player 4 pixels in a direction when key is pressed
				if (key[KEY_W]) {
					player_y -= movespeed;
				}

				if (key[KEY_S]) {
					player_y += movespeed;
					cout << "S" << endl;
				}

				if (key[KEY_A]) {
					player_x -= movespeed;
				}

				if (key[KEY_D]) {
					player_x += movespeed;
				}

				redraw = true;
				cout << "we are here in the timer section" << endl;
				
			}
	

			if (redraw && al_is_event_queue_empty(event_queue)) {
				redraw = false;

				cout << "Render" << endl;
				al_clear_to_color(al_map_rgb(0, 0, 0)); //wipe screen black between drawing (without this things smear)

				al_draw_filled_rectangle(player_x, player_y, player_x + player_size, player_y + player_size, al_map_rgb(50, 120, 10)); //draw the player

				al_flip_display(); //flip everything from memory to gamescreen
			}//end render
			

			//keyboard and screen sections//////////////////////////////////////////
			else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				break;
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { ////////////////////////////////////
				switch (ev.keyboard.keycode) {
				case ALLEGRO_KEY_UP:
					key[KEY_W] = true;
					break;

				case ALLEGRO_KEY_DOWN:
					key[KEY_S] = true;
					cout << "S again" << endl;
					break;

				case ALLEGRO_KEY_LEFT:
					key[KEY_A] = true;
					break;

				case ALLEGRO_KEY_RIGHT:
					key[KEY_D] = true;
					break;
				}
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_UP) { //////////////////////////////////////
				switch (ev.keyboard.keycode) {
				case ALLEGRO_KEY_UP:
					key[KEY_W] = false;
					break;

				case ALLEGRO_KEY_DOWN:
					key[KEY_S] = false;
					break;

				case ALLEGRO_KEY_LEFT:
					key[KEY_A] = false;
					break;

				case ALLEGRO_KEY_RIGHT:
					key[KEY_D] = false;
					break;

				}
			}
			
			break; // case playing


			
		case MENU:
			cout << "This is the menu.  Press 'p' to play or 'i' to go back to the intro." << endl;
			break;
		case PAUSE:
			cout << "Game paused." << endl;
			cout << "press 'c' to continue" << endl << endl;
			break;
		case END:
			cout << "The end, thanks for playing." << endl;
			running = false;
			break;
		default:
			cout << "you should never see this message." << endl;
		}//game state switch

		if (running == true)
			cin >> input;

		if (gamestate == INTRO && input == 's')
			gamestate = PLAYING;
		if (gamestate == PLAYING && input == 'p')
			gamestate = PAUSE;
		if ((gamestate == INTRO && input == 'm') || (gamestate == PLAYING && input == 'm'))
			gamestate = MENU;
		if (gamestate == MENU && input == 'i')
			gamestate = INTRO;
		if (gamestate == MENU && input == 'p')
			gamestate = PLAYING;
		if (gamestate == PLAYING && input == 'q')
			gamestate = END;
		if (gamestate == PAUSE && input == 'c')
			gamestate = PLAYING;


	}//end game loop
	cout << "goodbye." << endl;
}// Main







////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//
//#include<iostream>
//
//
//#include<allegro5/allegro.h>
//#include<allegro5/allegro_font.h>
//#include<allegro5/allegro_ttf.h>
//#include<allegro5/allegro_primitives.h>
//
//
//using namespace std;
//
//
//
//
//const int SCREEN_W = 1280;
//const int SCREEN_H = 960;
//const double FPS = 1.0 / 60;
//
//enum gamestates { INTRO, PLAYING, PAUSE, END, MENU };
//enum mykeys { KEY_W, KEY_S, KEY_A, KEY_D, KEY_ESCAPE };
//
//int main() {
//
//
//	while (running) {
//
//
//
//
//
//
//	}//
//
//
//
//
//}// Main