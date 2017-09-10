#include "viewer.h"

#include "allegro5\allegro_primitives.h"
#include "allegro5\allegro_image.h"

Viewer::Viewer(char * path, Bird * birds_, unsigned int birdCount_, unsigned int width_, unsigned int height_){
	this->is_okay = 1;

	this->birds = birds_;
	this->birdCount = birdCount_;
	this->width = width_;
	this->height = height_;

	al_init_primitives_addon();
	al_init_image_addon();

	display = al_create_display(width_, height_);

	if (display == NULL) {
		this->is_okay = 0;
	}

}

int Viewer::isIntOk() {
	return this->is_okay;
}

Viewer::~Viewer() {
	al_destroy_display(this->display);
	al_shutdown_primitives_addon();
	al_shutdown_image_addon();
}

void Viewer::updateDisplay() {
	/// draw all birds on screen
	al_clear_to_color(al_map_rgb(255, 255, 255));
	//for (int i = 0; i < this->birdCount; i++) {
		//al_draw_circle(cx, cy, r, color, thickness);
	
	//}
	al_flip_display();
}
