#include <iostream>

using namespace std;

#include "viewer.h"

#include "allegro5\allegro_primitives.h"
#include "allegro5\allegro_image.h"


Viewer::Viewer(char* pic_dirs[],uint pic_count,Bird * birds_, unsigned int birdCount_, unsigned int width_, unsigned int height_){
	

	this->is_okay = 1;

	this->birds = birds_;
	this->birdCount = birdCount_;
	this->width = width_;
	this->height = height_;
	this->pic_cnt = pic_count;

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
	for (int i = 0; i < pic_cnt; i++) {
		this->birdPic[i] = al_load_bitmap(pic_dirs[i]);
		if (!this->birdPic[i]) {
			cout << "Failed to load pictures " << pic_dirs[i] << '\n';
			this->is_okay = 0;
		}
	}

}

int Viewer::is_init_ok() {
	return this->is_okay;
}

Viewer::~Viewer() {
	al_destroy_display(this->display);
	al_shutdown_primitives_addon();
	al_shutdown_image_addon();
	for (int i = 0; i < this->pic_cnt; i++) {
		al_destroy_bitmap(this->birdPic[i]);
	}
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
		
	for (int i = 0; i < this->birdCount; i++) {
		//al_draw_circle(cx, cy, r, color, thickness);
		Position pos = this->birds[i].getPosition();
		ALLEGRO_BITMAP* pic = this->birdPic[this->birds[i].get_animation_step()];
		uint width = al_get_bitmap_width(pic);
		uint height = al_get_bitmap_height(pic);

		al_draw_bitmap(pic , pos.x * this->width / pos.Xmax - width/2, pos.y * this->height / pos.Ymax - height/2, 0);
		this->birds[i].increment_animation_step();
	}

	al_flip_display();
}
ALLEGRO_DISPLAY* Viewer::get_display() {
	return this->display;
}