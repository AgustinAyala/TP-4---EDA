/*** Controller ***/
/*** Controla todo lo que es la interaccion con el usuario ***/


#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "simulation.h"
#include "allegro5\allegro.h"
#include "allegro5\events.h"
#include "bird.h"

#define ADD 1
#define NONE 0
#define SUBSTRACT -1

typedef unsigned int uint;

class Controller {
	public:
		Controller(ALLEGRO_DISPLAY *display,Bird* birds,Simulation* sim,uint cnt_birds);
		bool is_not_exit();
		bool is_ok();
		void update();				//Possible options: E (change Eye Sight), J (cahnge Jiggle),
									//S (change Speed), UP KEY / + (increase), DOWN KEY / - (decrease)
									//Default option: S
		
		~Controller();
	private:
		ALLEGRO_EVENT_QUEUE *queue;
	
		bool exit_flag;
		bool is_ok_flag;
		Bird *birds;
		Simulation *sim;

		uint cnt_birds;
};

#endif