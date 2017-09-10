#include "controller.h"

Controller::Controller(Bird* birds) {
	this->exit = 0;
	this->birds = birds;
}

void Controller::update() {
	ALLEGRO_EVENT ev;
	if (al_get_next_event(this->queue, &ev)) {
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			this->exit = 1;
		}
	}
}