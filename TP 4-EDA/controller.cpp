#include "controller.h"

Controller::Controller(ALLEGRO_DISPLAY *display,Bird* birds,uint cnt_birds) {
	this->exit_flag = 0;
	this->birds = birds;
	this->cnt_birds = cnt_birds;
	this->queue = al_create_event_queue();
	al_register_event_source(this->queue, al_get_display_event_source(display));
}

void Controller::update() {
	ALLEGRO_EVENT ev;
	if (al_get_next_event(this->queue, &ev)) {
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			this->exit_flag = 1;
		}
	}
}
bool Controller::is_not_exit() {
	return !this->exit_flag;
}
Controller::~Controller() {
	al_destroy_event_queue(this->queue);
}