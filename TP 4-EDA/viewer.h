#ifndef VIEWER_H
#define VIEWER_H

#include "bird.h"
#include "allegro5\allegro.h"
#include "allegro5\display.h"
#include "allegro5\bitmap.h"

class Viewer{
	public:

		Viewer(char * path, Bird * birds_, unsigned int birdCount_ = 50, unsigned int width_ = 100, unsigned int height_ = 100);
		//~Viewer();
		int isIntOk ();
		//updateDisplay();

	private:

		unsigned int width;
		unsigned int heigth;
		unsigned int birdCount;

		bool is_okay;
		ALLEGRO_BITMAP*	background;
		ALLEGRO_BITMAP*	birdPic;
		Bird *	birds;
		ALLEGRO_DISPLAY* display;
		ALLEGRO_BITMAP*	font;
		
};

#endif // !_H_Viewer
