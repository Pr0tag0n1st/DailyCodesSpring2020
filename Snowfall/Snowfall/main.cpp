#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>
int main() {

	al_init();
	al_init_image_addon();
	al_init_primitives_addon();

	double x1 = 0; double y1 = 0;

	ALLEGRO_DISPLAY* screen = al_create_display(1000, 800); //screen size
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0); //60 FPS
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_BITMAP* JUSTICE = al_load_bitmap("justice.jfif");
	ALLEGRO_BITMAP* text = al_load_bitmap("JUSTICE.jpg");

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_start_timer(timer);

	double flakeX[100];
	for (int i = 0; i < 100; i++)
		flakeX[i] = rand() % 1000;
	double flakeY[100];
	for (int i = 0; i < 100; i++)
		flakeY[i] = rand() % 800;


	while (1) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			for (int i = 0; i < 100; i++) {
				flakeY[i] += 1;
				if (flakeY[i] > 800)
					flakeY[i] = 0;
			}

			al_clear_to_color(al_map_rgb(0, 0, 50)); //this is the background color (0,0,0 is black)

			for (int i = 0; i < 100; i += 1) {
				al_draw_bitmap(JUSTICE, flakeX[i], flakeY[i], 0);
			}
			al_draw_bitmap(text, 100, 100, 0);


			al_flip_display();
		}
	}


}
