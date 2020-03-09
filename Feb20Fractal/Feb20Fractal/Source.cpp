#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
using namespace std;
int SCREEN_W = 1280;
int SCREEN_H = 960;

int main() {
	al_init();
	al_init_primitives_addon();
	double x = 128;
	double y = 88;
	double df = 0;
	double d = 0;
	double seed = 0;
	ALLEGRO_DISPLAY* display = al_create_display(SCREEN_W, SCREEN_H);

	cout << "Give seed" << endl;
	cin >> seed;

	/*for (double f = 0; f <= 5000; f += 0.1) {
		x = x + 10*cos(f * f);
		y = y + 10*sin(f * f);
		al_draw_pixel(x, y, al_map_rgb(20*f, 5 * f, 10 * f));
		al_flip_display();
	}*/

	for (int i = 0; i <= 5000; i += 0.1) {
		df = df + (seed * 2 * 3.14);
		d = d + df;
		x = x + cos(d)*2;
		y = y + sin(d)*2;
		al_draw_pixel(x +(SCREEN_W/2), y+ (SCREEN_H / 2), al_map_rgb(200, 5 * i, 10 * i));
		al_draw_pixel(y + (SCREEN_W / 2), x + (SCREEN_H / 2), al_map_rgb(20*i, 10 * i, 150));
		al_flip_display();
	}





	system("Pause");
	
	

}