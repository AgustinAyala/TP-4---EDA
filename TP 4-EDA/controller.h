#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "allegro5\allegro.h"
#include "allegro5\events.h"
#include "bird.h"

class Controller {
	public:
		bool isNotExit();
		void update();
		Bird *birds;

	private:
		ALLEGRO_EVENT_QUEUE *queue;
	
		bool exit;
};

#endif