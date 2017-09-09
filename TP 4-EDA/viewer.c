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

Viewer(char * path, Bird * birds_, unsigned int birdCount_, unsigned int width_, unsigned int height_)
{

	birds = birds_;
	birdCount = birdCount_;
	width = width_;
	height = height_;
}


int isIntOk(Viewer * view)
