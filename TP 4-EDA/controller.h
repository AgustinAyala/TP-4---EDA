#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "allegro5\allegro.h"
#include "allegro5\events.h"
#include "bird.h"

typedef unsigned int uint;

class Controller {
	public:
		Controller(ALLEGRO_DISPLAY *display,Bird* birds,uint cnt_birds);
		bool is_not_exit();
		bool is_ok();
		void update();
		Bird *birds;
		uint cnt_birds;
		~Controller();
	private:
		ALLEGRO_EVENT_QUEUE *queue;
	
		bool exit_flag;
		bool is_ok_flag;
};

#endif