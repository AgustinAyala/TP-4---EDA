#ifndef _H_Viewer

#define _H_Viewer

class Viewer{
	public:

		Viewer(char * path, Bird * birds_, unsigned int birdCount_ = 50, unsigned int width_ = 100, unsigned int height_ = 100);
		//~Viewer();
		int isIntOk (Viewer * view);
		//updateDisplay();

	private:

		unsigned int	width;
		unsigned int	heigth;
		AL_BITMAP *	background;
		AL_BITMAP *	birdPic;
		Bird *	birds;
		AL_DISPLAY *	display;
		AL_FONT	*	font;
	
};

#endif // !_H_Viewer
