#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include <stdio.h>
#include <stdlib.h>
#include "prota.h"

#define DELTA 0.25

enum { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT };

int main(void)
{
    Prota mi_sonic;
    bool tecla[4] = {false, false, false, false};
    //variables
    int width = 1024;
    int height = 720;
    bool done = false;

    int x = width / 2;
    int y = height / 2;

    const int maxFrame = 8;
    int curFrame = 0;
    int frameCount = 0;
    int frameDelay = 5;
    int frameWidth = 102;
    int frameHeight = 123;

    //allegro variable
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer;
    ALLEGRO_BITMAP *image;
    ALLEGRO_BITMAP *background;

    //program init
    if(!al_init())										//initialize Allegro
	return -1;

    display = al_create_display(width, height);			//create our display object

    if(!display)										//test display object
	return -1;

    //addon init
    al_install_keyboard();
    al_init_image_addon();

    image = al_load_bitmap("sprites/captain.png");
    background = al_load_bitmap("sprites/background.png");
    al_convert_mask_to_alpha(image, al_map_rgb(106, 76, 48));

    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0 / 60);

    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_start_timer(timer);

    while(!done)
    {
	ALLEGRO_EVENT ev;
	al_wait_for_event(event_queue, &ev);

	if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
	{
	    switch(ev.keyboard.keycode)
	    {
		case ALLEGRO_KEY_ESCAPE:
		    done = true;
		    break;
		case ALLEGRO_KEY_LEFT:
		    tecla[KEY_LEFT] = true;
		    break;
		case ALLEGRO_KEY_RIGHT:
		    tecla[KEY_RIGHT] = true;
		    break;
		case ALLEGRO_KEY_UP:
		    tecla[KEY_UP] = true;
		    break;
		case ALLEGRO_KEY_DOWN:
		    tecla[KEY_DOWN] = true;
		    break;
	    
	}

	}

	if(ev.type == ALLEGRO_EVENT_KEY_UP)
	{
	    switch(ev.keyboard.keycode)
	    {
		case ALLEGRO_KEY_ESCAPE:
		    done = true;
		    break;
		case ALLEGRO_KEY_LEFT:
		    tecla[KEY_LEFT] = false;
		    break;
		case ALLEGRO_KEY_RIGHT:
		    tecla[KEY_RIGHT] = false;
		    break;
		case ALLEGRO_KEY_UP:
		   tecla[KEY_UP] = false;
		   break;
		case ALLEGRO_KEY_DOWN:
		   tecla[KEY_DOWN] = false;
		   break;
	    }
	}



	else if(ev.type == ALLEGRO_EVENT_TIMER)
	{
	    if(++frameCount >= frameDelay)
	    {
		if(++curFrame >= maxFrame)
		    curFrame = 0;

		frameCount = 0;
	    }

	    x -= 5;

	    if(x <= 0 - frameWidth)
		x = width;
	}


	if (tecla[KEY_UP])
	    mi_sonic.change_vy(-DELTA);

	if (tecla[KEY_DOWN])
	    mi_sonic.change_vy(DELTA);

	if (tecla[KEY_LEFT])
	    mi_sonic.change_vx(-DELTA);

	if (tecla[KEY_RIGHT])
	    mi_sonic.change_vx(DELTA);

	mi_sonic.actualizate();

	al_draw_bitmap_region(image, curFrame * frameWidth, 1, frameWidth, frameHeight, mi_sonic.get_x (), mi_sonic.get_y (), 0);

	al_flip_display();

	
	al_draw_bitmap(background, 0, 0, 0);
    }


    al_destroy_event_queue(event_queue);
    al_destroy_display(display);						//destroy our display object

    return 0;
}
