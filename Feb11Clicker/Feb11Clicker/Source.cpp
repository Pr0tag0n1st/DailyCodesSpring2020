#include <stdio.h>
#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
#include<math.h>
#include <ctime>
float distance(int x1, int y1, int x2, int y2);
int main()
{
	al_init();
	al_init_primitives_addon();
	al_install_mouse();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_acodec_addon();
	al_install_audio();
	srand(time(NULL));
	al_reserve_samples(1);
	ALLEGRO_SAMPLE* bip = al_load_sample("bip.wav");
	ALLEGRO_DISPLAY_MODE disp_data;
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60);
	ALLEGRO_FONT* font = al_create_builtin_font();
	al_get_display_mode(al_get_num_display_modes() - 1, &disp_data);

	al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	display = al_create_display(disp_data.width, disp_data.height);
	float xPos = 200;
	float yPos = 200;
	float x = 200;
	float y = 200;
	float size = 20;
	bool clicked = false;
	int clickNum = 0;
	int timeLeft = 1200;
	bool redraw = true;
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_start_timer(timer);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_textf(font, al_map_rgb(180, 45, 210), 40, 400, NULL, "Stupid Clicker Game");
	al_draw_textf(font, al_map_rgb(180, 45, 210), 40, 500, NULL, "By Dr. Mo for Andrew and Armando. *edited by TJ*");
	al_flip_display();
	al_rest(5);
	while (timeLeft > 0)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
			if (clicked) {
				x = rand() % disp_data.width;
				y = rand() % disp_data.height;
				size = rand() % 15 + 10;
				
				clicked = false;
				al_play_sample(bip, 5.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			}
			timeLeft--;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
			xPos = ev.mouse.x;
			yPos = ev.mouse.y;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (distance(x, y, xPos, yPos) < size) {
				clicked = true;
				clickNum++;

			}
		}
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_filled_circle(x, y, size, al_map_rgb(rand()%255, rand()%155 + 100, rand()%100 + 155));
			al_draw_textf(font, al_map_rgb(180, 45, 210), 40, 10, NULL, "Clicks:");
			al_draw_textf(font, al_map_rgb(180, 45, 210), 100, 10, NULL, "%d", clickNum);
			al_draw_textf(font, al_map_rgb(180, 45, 210), 300, 10, NULL, "Time Left:");
			al_draw_textf(font, al_map_rgb(180, 45, 210), 390, 10, NULL, "%d", timeLeft / 60);
			al_flip_display();
		}
	}
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_textf(font, al_map_rgb(180, 45, 210), 40, 400, NULL, "Game Over!");
	al_draw_textf(font, al_map_rgb(180, 45, 210), 40, 500, NULL, "Total Clicks:");
	al_draw_textf(font, al_map_rgb(180, 45, 210), 200, 500, NULL, "%d", clickNum);
	
	al_flip_display();
	al_rest(2.5);
	if (clickNum >= 15) {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_textf(font, al_map_rgb(180, 45, 210), 40, 400, NULL, "Game Over!");
		al_draw_textf(font, al_map_rgb(180, 45, 210), 40, 500, NULL, "Total Clicks:");
		al_draw_textf(font, al_map_rgb(180, 45, 210), 200, 500, NULL, "%d", clickNum);
		al_draw_textf(font, al_map_rgb(180, 45, 210), 250, 500, NULL, "Wow, you're good at this!");
		al_flip_display();
		al_rest(2.5);
	}
	else if (clickNum >= 5 && clickNum < 15) {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_textf(font, al_map_rgb(180, 45, 210), 40, 400, NULL, "Game Over!");
		al_draw_textf(font, al_map_rgb(180, 45, 210), 40, 500, NULL, "Total Clicks:");
		al_draw_textf(font, al_map_rgb(180, 45, 210), 200, 500, NULL, "%d", clickNum);
		al_draw_textf(font, al_map_rgb(180, 45, 210), 250, 500, NULL, "You did a good job here.");
		al_flip_display();
		al_rest(2.5);
	}
	else if (clickNum < 5) {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_textf(font, al_map_rgb(180, 45, 210), 40, 400, NULL, "Game Over!");
		al_draw_textf(font, al_map_rgb(180, 45, 210), 40, 500, NULL, "Total Clicks:");
		al_draw_textf(font, al_map_rgb(180, 45, 210), 200, 500, NULL, "%d", clickNum);
		al_draw_textf(font, al_map_rgb(180, 45, 210), 250, 500, NULL, "C'mon, pick up the pace!");
		al_flip_display();
		al_rest(2.5);
	}
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	return 0;
}
float distance(int x1, int y1, int x2, int y2) {
	return(sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}