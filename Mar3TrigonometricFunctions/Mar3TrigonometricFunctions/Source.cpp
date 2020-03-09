#include <allegro5/allegro.h>
#include<allegro5\allegro_primitives.h>
#include<allegro5/allegro_image.h>
#include<math.h>
//constants: variables that shouldn't change once the game starts
const float FPS = 60;
const int SCREEN_W = 800;
const int SCREEN_H = 800;
//enumeration to help you remember what numbers represent which directions
enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE
};
int main()
{
	//set up allegro
	al_init();
	al_install_keyboard();
	al_init_primitives_addon();
	al_init_image_addon();
	//set up game screen, event queue, and timer
	ALLEGRO_DISPLAY* display = al_create_display(SCREEN_W, SCREEN_H);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);
	ALLEGRO_BITMAP* pic = al_load_bitmap("spaceship.png");
	al_start_timer(timer);
	//position of player
	double xPos = 50;
	double yPos = 400;
	double alpha = 0;
	double BeamX = xPos;
	double BeamY = yPos;
	double Beam2X = xPos;
	double Beam2Y = yPos;
	bool isShooting = false;
	//game variables
	bool key[5] = { false, false, false, false, false }; //holds key clicks
	bool redraw = true; //variable needed for render section
	bool doexit = false; //handles game loop
	//tell event queue what to look for
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	while (!doexit)//game loop!
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		//timer (physics) section////////////////////////////////////////
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			alpha += .1;
			if (BeamX > SCREEN_W) {
				BeamX = xPos;
				alpha = 0;
			}
			if (Beam2X > SCREEN_W) {
				Beam2X = xPos;
				alpha = 0;
			}
			//move player 4 pixels in a direction when key is pressed
			if (isShooting == false) {
				if (key[KEY_UP]) {
					yPos -= 4.0;
				}
				if (key[KEY_DOWN]) {
					yPos += 4.0;
				}
				if (key[KEY_LEFT]) {
					xPos -= 4.0;
				}
				if (key[KEY_RIGHT]) {
					xPos += 4.0;
				}
			}
			if (key[KEY_SPACE]) {
				//HERE'S THE MOST IMPORTANT PART!
				BeamX += 10;
				BeamY = 50 * sin(1 * alpha + 0) + yPos +8;
				isShooting = true;

				Beam2X += 10;
				Beam2Y = 50 * -sin(1 * alpha + 0) + yPos + 8;
			}
			else {
				isShooting = false;
				BeamX = xPos + 25; //resets x position when space isn't pressed
				Beam2X = xPos + 25;
				alpha = 0; //resets angle when space isn't pressed
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
			case ALLEGRO_KEY_SPACE:
				key[KEY_SPACE] = false;
				break;
			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}
		//render section//////////////////////////////////////////////////
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			if (isShooting == false)//turn off screen wiping so you can see bullet's path
				al_clear_to_color(al_map_rgb(255, 255, 255));
			if (isShooting) {
				al_draw_filled_circle(BeamX, BeamY, 5, al_map_rgb(180, 0, 0)); //draw bullet
				al_draw_filled_circle(Beam2X, Beam2Y, 5, al_map_rgb(0, 0, 180));
			}
			al_draw_bitmap(pic, xPos, yPos, NULL);
			al_flip_display(); //flip everything from memory to gamescreen
		}//end render
	}//end game loop
	//clean up memory
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_bitmap(pic);
	al_destroy_event_queue(event_queue);
	return 0;
}