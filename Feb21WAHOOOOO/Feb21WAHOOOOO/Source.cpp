#include<allegro5/allegro.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
#include<allegro5/allegro_image.h>
#include<iostream>
using namespace std;
enum KEYS { KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B, KEY_N, KEY_M };
int main() {
	//basic allegro game set up stuff
	al_init();
	al_install_audio();
	al_init_acodec_addon();
	al_install_keyboard();
	al_init_image_addon();


	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();	
	ALLEGRO_DISPLAY* display = al_create_display(575, 500);
	ALLEGRO_BITMAP* mario = al_load_bitmap("mario.png"); 


	bool key[7] = { false, false, false, false, false, false, false };
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_start_timer(timer);


	//sound stuff here!///////////////////////////////////////////////////////////
	ALLEGRO_SAMPLE* sample;
	ALLEGRO_SAMPLE* sample2;
	ALLEGRO_SAMPLE* sample3;
	ALLEGRO_SAMPLE* sample4;
	ALLEGRO_SAMPLE* sample5;
	ALLEGRO_SAMPLE* sample6;
	ALLEGRO_SAMPLE* sample7;
	ALLEGRO_SAMPLE* sample8;

	ALLEGRO_SAMPLE_INSTANCE* sampleInstance = NULL;
	ALLEGRO_SAMPLE_INSTANCE* sampleInstance2 = NULL;
	ALLEGRO_SAMPLE_INSTANCE* sampleInstance3 = NULL;
	ALLEGRO_SAMPLE_INSTANCE* sampleInstance4 = NULL;
	ALLEGRO_SAMPLE_INSTANCE* sampleInstance5 = NULL;
	ALLEGRO_SAMPLE_INSTANCE* sampleInstance6 = NULL;
	ALLEGRO_SAMPLE_INSTANCE* sampleInstance7 = NULL;
	ALLEGRO_SAMPLE_INSTANCE* sampleInstance8 = NULL;

	al_reserve_samples(8);


	sample = al_load_sample("music.wav");
	sample2 = al_load_sample("coin.wav");
	sample3 = al_load_sample("yipee.wav"); //loaded the same sound into different samples so they can overlap!
	sample4 = al_load_sample("waha.wav");
	sample5 = al_load_sample("breaking_box.wav");
	sample6 = al_load_sample("falling.wav");
	sample7 = al_load_sample("yahoo.wav");
	sample8 = al_load_sample("ps4.wav");
	//this will give help us debug our code- we should probably do stuff like this more often :/
	if (sample == NULL) { cout << "sample didn't load" << endl; system("pause"); }
	if (sample2 == NULL) { cout << "sample2 didn't load" << endl; system("pause"); }
	if (sample3 == NULL) { cout << "sample3 didn't load" << endl; system("pause"); }
	if (sample4 == NULL) { cout << "sample4 didn't load" << endl; system("pause"); }
	if (sample5 == NULL) { cout << "sample didn't load" << endl; system("pause"); }
	if (sample6 == NULL) { cout << "sample didn't load" << endl; system("pause"); }
	if (sample7 == NULL) { cout << "sample didn't load" << endl; system("pause"); }
	if (sample8 == NULL) { cout << "sample didn't load" << endl; system("pause"); }

	sampleInstance = al_create_sample_instance(sample);
	sampleInstance2 = al_create_sample_instance(sample2);
	sampleInstance3 = al_create_sample_instance(sample3);
	sampleInstance4 = al_create_sample_instance(sample4);
	sampleInstance5 = al_create_sample_instance(sample5);
	sampleInstance6 = al_create_sample_instance(sample6);
	sampleInstance7 = al_create_sample_instance(sample7);
	sampleInstance8 = al_create_sample_instance(sample8);

	al_set_sample_instance_playmode(sampleInstance, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_playmode(sampleInstance2, ALLEGRO_PLAYMODE_ONCE);
	al_set_sample_instance_playmode(sampleInstance3, ALLEGRO_PLAYMODE_ONCE);
	al_set_sample_instance_playmode(sampleInstance4, ALLEGRO_PLAYMODE_ONCE);
	al_set_sample_instance_playmode(sampleInstance5, ALLEGRO_PLAYMODE_ONCE);
	al_set_sample_instance_playmode(sampleInstance6, ALLEGRO_PLAYMODE_ONCE);
	al_set_sample_instance_playmode(sampleInstance7, ALLEGRO_PLAYMODE_ONCE);
	al_set_sample_instance_playmode(sampleInstance8, ALLEGRO_PLAYMODE_ONCE);

	al_attach_sample_instance_to_mixer(sampleInstance, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(sampleInstance2, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(sampleInstance3, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(sampleInstance4, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(sampleInstance5, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(sampleInstance6, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(sampleInstance7, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(sampleInstance8, al_get_default_mixer());

	al_play_sample_instance(sampleInstance); //plays the background music on a loop outside of the game loop

	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)////////////////////timer section
		{

			if (key[KEY_Z])
				al_play_sample_instance(sampleInstance2);

			if (key[KEY_X])
				al_play_sample_instance(sampleInstance3);

			if (key[KEY_C])
				al_play_sample_instance(sampleInstance4);

			if (key[KEY_V])
				al_play_sample_instance(sampleInstance5);

			if (key[KEY_B])
				al_play_sample_instance(sampleInstance6);

			if (key[KEY_N])
				al_play_sample_instance(sampleInstance7);

			if (key[KEY_M])
				al_play_sample_instance(sampleInstance8);
		}
		//input/output section////////////////////////////////////////////////////
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_Z:
				key[KEY_Z] = true;
				break;
			case ALLEGRO_KEY_X:
				key[KEY_X] = true;
				break;
			case ALLEGRO_KEY_C:
				key[KEY_C] = true;
				break;
			case ALLEGRO_KEY_V:
				key[KEY_V] = true;
				break;
			case ALLEGRO_KEY_B:
				key[KEY_B] = true;
				break;
			case ALLEGRO_KEY_N:
				key[KEY_N] = true;
				break;
			case ALLEGRO_KEY_M:
				key[KEY_M] = true;
				break;
			}
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_Z:
				key[KEY_Z] = false;
				break;
			case ALLEGRO_KEY_X:
				key[KEY_X] = false;
				break;
			case ALLEGRO_KEY_C:
				key[KEY_C] = false;
				break;
			case ALLEGRO_KEY_V:
				key[KEY_V] = false;
				break;
			case ALLEGRO_KEY_B:
				key[KEY_B] = false;
				break;
			case ALLEGRO_KEY_N:
				key[KEY_N] = false;
				break;
			case ALLEGRO_KEY_M:
				key[KEY_M] = false;
				break;
			}
		}
		//render section///////////////////////////////////////////
		al_draw_bitmap(mario, 50, 50, NULL);
		al_flip_display();
	}//end game loop
	//clear up memory
	al_destroy_event_queue(event_queue);
	al_destroy_sample_instance(sampleInstance);
	al_destroy_sample_instance(sampleInstance2);
	al_destroy_sample_instance(sampleInstance3);
	al_destroy_sample_instance(sampleInstance4);
	al_destroy_sample_instance(sampleInstance5);
	al_destroy_sample_instance(sampleInstance6);
	al_destroy_sample_instance(sampleInstance7);
	al_destroy_sample_instance(sampleInstance8);

	al_destroy_sample(sample);
	al_destroy_sample(sample2);
	al_destroy_sample(sample3);
	al_destroy_sample(sample4);
	al_destroy_sample(sample5);
	al_destroy_sample(sample6);
	al_destroy_sample(sample7);
	al_destroy_sample(sample8);

	al_destroy_bitmap(mario);

	al_destroy_display(display);
}