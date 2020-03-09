#include <stdio.h>
#include<iostream>
#include <allegro5/allegro.h>
#include<allegro5\allegro_image.h>
#include<allegro5\allegro_primitives.h>
#include<allegro5\allegro_font.h>
#include<allegro5\allegro_ttf.h>
#include<ctime>
using namespace std;


const float FPS = 60;

enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE
};



int main()
{

	//set up Allegro
	al_init();
	al_init_image_addon();
	al_install_keyboard();
	al_init_primitives_addon();



	//ALLEGRO variables
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_BITMAP* Joey = al_load_bitmap("JOEY.jpg");
	ALLEGRO_BITMAP* map = al_load_bitmap("map.png");
	ALLEGRO_BITMAP* blueTre = al_load_bitmap("tre.png");
	al_convert_mask_to_alpha(blueTre, al_map_rgb(255, 255, 255)); //sets transparency so white doesn't show up

	timer = al_create_timer(1.0 / FPS);
	display = al_create_display(800, 800);

	int TreX = 500;
	int TreY = 500;

	int JoeyX = 1200;
	int JoeyY = 800;

	int player_x = 400; //notice these never change! the map moves behind the player, not the other way around
	int player_y = 400;

	bool key[5] = { false, false, false, false , false };
	bool redraw = true;
	bool doexit = false;

	//CAMERA STUFF------------------------------------------------------------
	// the screen size (the actual resolution of our display or window)
	int screenWidth = 800;
	int screenHeight = 800;

	// the world size
	int worldWidth = 1920;
	int worldHeight = 1200;

	// the camera's position
	int cameraX = 0;
	int cameraY = 0;
	//------------------------------------------------------------------------




	//create event queue and set it up to look for close window buttons, timer ticks, and keyboard input
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());


	al_start_timer(timer);


	//game loop
	while (!doexit)
	{

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		//timer section////////////////////////////////////////////////////////////////////////////////
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (key[KEY_UP]) {
				if (cameraY <= 0 || player_y != 400) {
					player_y -= 4.0;
				}
				if (cameraY != 0 && player_y <= 400) {
					cameraY -= 4.0;
					player_y = 400;
				}
				
			}
			if (key[KEY_DOWN]) {
				if (cameraY + 800 >= worldHeight || player_y != 400) {
					player_y += 4.0;
				}
				if (player_y >= 400 && cameraY + 800 != worldHeight) {
					cameraY += 4.0;
					player_y = 400;
				}
			}
			if (key[KEY_LEFT]) {
				if (cameraX <= 0 || player_x != 400) {
					player_x -=4.0;
				}
				if (cameraX!= 0 && player_x <= 400){
					 cameraX-= 4.0;
					 player_x = 400;
				}
			}
			if (key[KEY_RIGHT]){
				if (cameraX + 800 >= worldWidth || player_x != 400) {
					player_x += 4.0;
				}
				if (player_x >= 400 && cameraX + 800 != worldWidth) {
					cameraX += 4.0;
					player_x = 400;
				}
			}

			//check if you've collided with tre
			if (player_x + 30 > TreX - cameraX &&
				player_x < TreX - cameraX + 100 &&
				player_y + 30> TreY - cameraY &&
				player_y < TreY - cameraY + 130)
				cout << "AAAH!"; //normally you'd do something here, like warp somewhere or stop moving

						//check if you've collided with tre
			if (player_x + 30 > JoeyX - cameraX &&
				player_x < JoeyX - cameraX + 100 &&
				player_y + 30> JoeyY - cameraY &&
				player_y < JoeyY - cameraY + 130)
				cout << "Time to get my Motor running!"; //normally you'd do something here, like warp somew

			//don't let player move off side of map
			//later we'll make it so the player *does* move once we reach the edge of the moveable map
			//so you can actually reach the edges of the screen...

			
			if (cameraY < 0) {
				cameraY = 0;
				if (key[KEY_UP]) {
					player_y -= 4.0;
				}
			}
			if (cameraX > worldWidth - screenWidth) {
				cameraX = worldWidth - screenWidth;
				if (key[KEY_RIGHT]) {
					player_x += 4.0;
				}
			}
			if (cameraY > worldHeight - screenHeight) {
				cameraY = worldHeight - screenHeight;
				if (key[KEY_DOWN]) {
					player_y += 4.0;
				}
			}
		//	if (player_x = 400 &&)

			if (player_x < 0) {
				player_x = worldWidth - 30;
				cameraX = worldWidth - screenWidth;
			}
			if (player_y < 0) {
				player_y = worldHeight - screenHeight - 30;
				cameraY > worldHeight - screenHeight;
			}
			if (player_x + 30 > worldWidth) {
				player_x = 0;
				cameraX = 0;

			}
			if (player_y + 30 > worldHeight) {
				player_y = 0;
				cameraY = 0;
			}

			redraw = true;
		}//end timer seciton////////////////////////////////////////////////////////////////////////


		//IO sections///////////////////////////////////////////////////////////////////////////////
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

			case ALLEGRO_KEY_SPACE:
				key[KEY_SPACE] = true;
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
			case ALLEGRO_KEY_SPACE:
				key[KEY_SPACE] = false;
				break;
			}
		}
		//////////////////////////////////////////////////////////////////////////////////////////


		//render section/////////////////////////////////////////////////////////////////////////
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			//the map and anything stuck to it needs to have the "camera" subtracted from it
			if (cameraX > 0 || cameraY > 0 || cameraX < worldWidth - screenWidth || cameraY < worldHeight - screenHeight) {
				al_draw_bitmap(map, -cameraX, -cameraY, NULL);

			}


			al_draw_bitmap(blueTre, 500 - cameraX, 500 - cameraY, NULL);
			al_draw_bitmap(Joey, JoeyX - cameraX, JoeyY - cameraY, NULL);
			//player
			al_draw_filled_rectangle(player_x, player_y, player_x + 30, player_y + 30, al_map_rgb(255, 0, 255));




			al_flip_display();
		}//end render///////////////////////////////////////////////////////////////////////////////
	}//end game loop

	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}