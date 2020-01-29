#include <allegro5\allegro.h>
#include<allegro5/allegro_primitives.h>
#include<math.h>

int main() {
	al_init(); //sets up allegro
	al_init_primitives_addon(); //sets up shapes library

	ALLEGRO_DISPLAY* display = al_create_display(500, 500); //makes game screen
	int xpos, xpos2, xpos3; //x-coordinates
	int ypos, ypos2, ypos3; //y-coordinates
	int bxpos, bxpos2, bxpos3;
	int bypos, bypos2, bypos3;
	double alpha = 1; //angle

	while (1) { //game loop******************************************************

		//physics section/////////////////////////////////////
		alpha += .001;//increase angle

		xpos = 100 * sin(alpha) + 250;
		ypos = 100 * cos(alpha) + 250;

		xpos2 = 100 * sin(alpha + (2 * 3.14 / 3)) + 250;
		ypos2 = 100 * cos(alpha + (2 * 3.14 / 3)) + 250;

		xpos3 = 100 * sin(alpha + (4 * 3.14 / 3)) + 250;
		ypos3 = 100 * cos(alpha + (4 * 3.14 / 3)) + 250;

		bxpos = 50 * sin(alpha + (3.14/3)) + 250;
		bypos = 50 * cos(alpha + (3.14/3)) + 250;

		bxpos2 = 50 * sin(alpha + (3.14)) + 250;
		bypos2 = 50 * cos(alpha + (3.14)) + 250;

		bxpos3 = 50 * sin(alpha + (5 * 3.14 / 3)) + 250;
		bypos3 = 50 * cos(alpha + (5 * 3.14 / 3)) + 250;

		//render section////////////////////////////////////
		al_clear_to_color(al_map_rgb(0, 0, 0)); //wipe screen black


		al_draw_filled_triangle(xpos, ypos, xpos2, ypos2, xpos3, ypos3, al_map_rgb(250, 250, 100));
		al_draw_filled_triangle(bxpos, bypos, bxpos2, bypos2, bxpos3, bypos3, al_map_rgb(0, 0, 0));
		//al_draw_filled_circle(bxpos, bypos, 5, al_map_rgb(0, 0, 0));
		//al_draw_filled_circle(bxpos2, bypos2, 5, al_map_rgb(0, 0, 0));
		//al_draw_filled_circle(bxpos3, bypos3, 5, al_map_rgb(0, 0, 0));
		al_flip_display();
	}//end game loop***********************************************************


	al_destroy_display(display); //clear up memory
}