#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
using namespace std;
#include <string>
enum ROOMS{BOB, LOSTWOODS, DISTORTION, GREENGREENS, ARENA, NORFAIR, NINE};

void help();
int main() {
	al_init();
	al_init_image_addon();
	ALLEGRO_DISPLAY* display = al_create_display(320, 300);
	ALLEGRO_BITMAP* background = al_create_bitmap(320, 300);
	int room = BOB;
	string input = "z";
	cout << "You appear to be lost in a maze of familiar locations, but they don't seem to lead where you expect them to..." << endl;
	cout << "Good luck getting out!" << endl;
	cout << "Use help to get information regarding controls." << endl;
	background = al_load_bitmap("battlefield.jfif");
	
	while (input != "quit"){
		
		switch (room) {
		case BOB:
			cout << "You are in bob-omb battlefield from Super Mario 64.  You can go north and west." << endl;
			getline(cin, input);
			if (input.compare("north") == 0) {
				room = LOSTWOODS;
				background = al_load_bitmap("duDuDUU.png");
			}
			else if (input.compare("west") == 0) {
				room = GREENGREENS;
				background = al_load_bitmap("greengreen.jfif");
			}
			else if (input.compare("help") == 0) {
				help();
			}
			else
				cout << "I'm sorry, I don't understand." << endl;
			break;
		case LOSTWOODS:
			cout << "You are in the lost woods from the Legend of Zelda:  Ocarina of Time.  You can go south and east." << endl;
			getline(cin, input);
			if (input.compare("south") == 0) {
				room = BOB;
				background = al_load_bitmap("battlefield.jfif");
			}
			else if (input.compare("east") == 0) {
				room = DISTORTION;
				background = al_load_bitmap("Distort.jfif");
			}
			else if (input.compare("help") == 0) {
				help();
			}
			else
				cout << "I'm sorry, I don't understand." << endl;
			break;
		case DISTORTION:
			cout << "You are in the distortion realm from Pokemon Platinum version.  You can go in any direction." << endl;
			getline(cin, input);
			if (input.compare("north") == 0 || input.compare("south") == 0 || input.compare("east") == 0 || input.compare("west") == 0) {
				room = BOB;
				background = al_load_bitmap("battlefield.jfif");
			}
			else if (input.compare("help") == 0) {
				help();
			}
			else
				cout << "I'm sorry, I don't understand." << endl;
			break;
		case GREENGREENS:
			cout << "You are in green greens from Kirby's Adventure.  You can go east or south." << endl;
			getline(cin, input);
			if (input.compare("east") == 0) {
				room = BOB;
				background = al_load_bitmap("battlefield.jfif");
			}
			else if (input.compare("south") == 0) {
				room = ARENA;
				background = al_load_bitmap("MARCUS.jfif");
			}
			else if (input.compare("help") == 0) {
				help();
			}
			else
				cout << "I'm sorry, I don't understand." << endl;
			break;
		case ARENA:
			cout << "You are in an arena from Fire Emblem: The Binding Blade.  You can go north or east." << endl;
			getline(cin, input);
			if (input.compare("north") == 0) {
				room = GREENGREENS;
				background = al_load_bitmap("greengreen.jfif");
			}
			else if (input.compare("east") == 0) {
				room = NORFAIR;
				background = al_load_bitmap("Neitherfun.png");
			}
			else if (input.compare("help") == 0) {
				help();
			}
			else
				cout << "I'm sorry, I don't understand." << endl;
			break;
		case NORFAIR:
			cout << "You are in Norfair from Super Metroid.  You can go west or south." << endl;
			getline(cin, input);
			if (input.compare("west") == 0) {
				room = ARENA;
				background = al_load_bitmap("MARCUS.jfif");
			}
			else if (input.compare("south") == 0) {
				room = NINE;
				background = al_load_bitmap("NEIN.jfif");
			}
			else if (input.compare("help") == 0) {
				help();
			}
			else
				cout << "I'm sorry, I don't understand." << endl;
			break;
		case NINE:
			cout << "You are overlooking Colony Nine from Xenoblade Chronicles.  You have reached the end of your journey." << endl;
			break;
		default:
			cout << "How in the world did you get out of the map?" << endl;
			return 0;
			break;
		}
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_bitmap(background, 0, 0, 0);
		al_flip_display();
		

	}
}
void help() {
	cout << "Use north, west, south, and east to move.  Use quit to exit the game." << endl;
}