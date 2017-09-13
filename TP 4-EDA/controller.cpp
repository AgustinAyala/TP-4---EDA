#include "controller.h"

#include <iostream>

Controller::Controller(ALLEGRO_DISPLAY *display, Bird* birds, Simulation *sim, uint cnt_birds) {
	this->is_ok_flag = 1;

	this->exit_flag = 0;
	this->birds = birds;
	this->cnt_birds = cnt_birds;
	this->queue = al_create_event_queue();
	this->sim = sim;

	if (!this->queue) {
		this->is_ok_flag = 0;

	}
	al_register_event_source(this->queue, al_get_display_event_source(display));

	if (!al_install_keyboard()) {
		this->is_ok_flag = 0;

	}

	al_register_event_source(this->queue, al_get_keyboard_event_source());
}

void Controller::update() {
	ALLEGRO_EVENT ev;
	int	operation = NONE;
	static int action = ALLEGRO_KEY_S;		//Default option

	if (al_get_next_event(this->queue, &ev)) {

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			this->exit_flag = 1;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {

			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_DOWN: case ALLEGRO_KEY_PAD_MINUS: operation = SUBSTRACT; break;
			case ALLEGRO_KEY_UP: case ALLEGRO_KEY_PAD_PLUS: operation = ADD; break;	
			case ALLEGRO_KEY_J: case ALLEGRO_KEY_S: case ALLEGRO_KEY_E: action = ev.keyboard.keycode; break;	
			}						//Se selecciona la variable a modificar y como se la modificara
			
									/*
				printf("OPERATION : %d\n", operation);
				printf("OLD RJ : %f\n", this->birds->getRandomJ());
				printf("OLD EYE : %d\n", this->birds->getEyeSight());
				printf("OLD SP : %d\n", this->birds->getSpeed());
			*/
			if (action == ALLEGRO_KEY_J) {
				if (operation == ADD) {
					this->sim->IncreaseRandomJiggle();
				}else if (operation == SUBSTRACT) {
					this->sim->DecreaseRandomJiggle();
				}
			}
			for (uint i = 0; i < (this->cnt_birds); i++)
			{
				
				if (action == ALLEGRO_KEY_S) {
					if (operation == ADD) {
						((this->birds) + i)->incrementSpeed();
					}
					else if (operation == SUBSTRACT) {
						((this->birds) + i)->decrementSpeed();
					}
				}
				else if (action == ALLEGRO_KEY_E) {
					if (operation == ADD) {
						((this->birds) + i)->incrementEyeSight();
					}
					else if (operation == SUBSTRACT) {
						((this->birds) + i)->decrementEyesight();
					}
				}
			}

			/*
			printf("NEW RJ : %f\n", this->birds->getRandomJ());
			printf("NEW EYE : %d\n", this->birds->getEyeSight());
			printf("NEW SP : %d\n", this->birds->getSpeed());
			*/
		}
	}
}
bool Controller::is_not_exit() {
	return !this->exit_flag;
}
bool Controller::is_ok() {
	return this->is_ok_flag;
}
Controller::~Controller() {
	al_destroy_event_queue(this->queue);
}