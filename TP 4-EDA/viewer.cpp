#include <iostream>

using namespace std;

#include "viewer.h"

#include "allegro5\allegro_primitives.h"
#include "allegro5\allegro_image.h"

Viewer::Viewer(char* pic_dir,Bird * birds_, unsigned int birdCount_, unsigned int width_, unsigned int height_){
	

	this->is_okay = 1;

	this->birds = birds_;
	this->birdCount = birdCount_;
	this->width = width_;
	this->height = height_;

	if (!al_init()) {
		this->is_okay = 0;
	}
	if (!al_init_primitives_addon()) {
		this->is_okay = 0;
	}
	if (!al_init_image_addon()) {
		this->is_okay = 0;
	}

	display = al_create_display(width_, height_);
	al_set_window_title(this->display, "TP4");

	if (display == NULL) {
		this->is_okay = 0;
	}
	
	this->birdPic = al_load_bitmap(pic_dir);
	if (!this->birdPic) {
		cout << "Failed to load pictures " << pic_dir << '\n';
		this->is_okay = 0;
	}

}

int Viewer::is_init_ok() {
	return this->is_okay;
}

Viewer::~Viewer() {
	al_destroy_display(this->display);
	al_shutdown_primitives_addon();
	al_shutdown_image_addon();
	al_destroy_bitmap(this->birdPic);
}

void Viewer::update_display() {
	/// draw all birds on screen
	al_clear_to_color(al_map_rgb(255, 255, 255));
	//al_draw_bitmap(this->birdPic, this->width / 2, this->height/ 2, 0);
	//int w = al_get_bitmap_width(this->birdPic);
	//int h = al_get_bitmap_height(this->birdPic);

	//al_draw_scaled_bitmap(this->birdPic,
	//	0, 0, w, h,
	//	this->width / 2, this->height / 2, 50, 50, 0);
		
	//for (int i = 0; i < this->birdCount; i++) {
		//al_draw_circle(cx, cy, r, color, thickness);
	
	//}
	al_flip_display();
}
ALLEGRO_DISPLAY* Viewer::get_display() {
	return this->display;
}