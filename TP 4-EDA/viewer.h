#ifndef VIEWER_H
#define VIEWER_H

#include "bird.h"
#include "allegro5\allegro.h"
#include "allegro5\display.h"
#include "allegro5\bitmap.h"

typedef unsigned int uint;

class Viewer{
	public:

		Viewer(char* pic_dirs[], uint pic_count, Bird * birds_, unsigned int birdCount_ = 50, unsigned int width_ = 100, unsigned int height_ = 100);
		int is_init_ok();
		void update_display();
		~Viewer();
		ALLEGRO_DISPLAY *get_display();
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
		ALLEGRO_BITMAP*	font;
		
		
};

#endif // !_H_Viewer
