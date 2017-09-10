#include "viewer.h"


/*
private:

unsigned int	width;
unsigned int	heigth;
AL_BITMAP *	background;
AL_BITMAP *	birdPic;
Bird *	birds;
AL_DISPLAY *	display;
AL_FONT	*	font;

};

*/

Viewer::Viewer(char * path, Bird * birds_, unsigned int birdCount_, unsigned int width_, unsigned int height_){
	this->is_okay = 1;

	this->birds = birds_;
	this->birdCount = birdCount_;
	this->width = width_;
	this->height = height_;

	display = al_create_display(width_, height_);
	if (display == NULL) {
		this->is_okay = 0;
	}

}

int Viewer::isIntOk() {
	return this->is_okay;
}
