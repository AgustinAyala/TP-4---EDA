/*** Viewer ***/
/*** Controla todo lo que es trabajar con allegro y la visualizacion de todos los objetos de la pantalla ***/

#ifndef VIEWER_H
#define VIEWER_H

#include "bird.h"
#include "simulation.h"

#include "allegro5\allegro.h"
#include "allegro5\display.h"
#include "allegro5\bitmap.h"
#include "allegro5\allegro_font.h"

typedef unsigned int uint;

class Viewer{
	public:

		Viewer(char* pic_dirs[], uint pic_count, Bird * birds_,Simulation *sim, unsigned int birdCount_ = 50, unsigned int width_ = 100, unsigned int height_ = 100);
		int is_init_ok();
		void update_display();
		~Viewer();
		ALLEGRO_DISPLAY *get_display();
		uint speed_shown_value;
		uint jiggle_shown_value;
		uint sight_show_value;
	private:

		uint width;
		uint height;
		uint birdCount;
		uint pic_cnt;

		bool is_okay;
		ALLEGRO_BITMAP*	background;
		ALLEGRO_BITMAP*	birdPic[10];
		Bird *	birds;
		ALLEGRO_DISPLAY* display;
		ALLEGRO_FONT*	font;
		Simulation *sim;

		
};

#endif // !_H_Viewer
