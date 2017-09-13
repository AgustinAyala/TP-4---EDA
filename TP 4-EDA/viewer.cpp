#include <iostream>
#include <string>
using namespace std;

#include "viewer.h"

#include "allegro5\allegro_primitives.h"
#include "allegro5\allegro_image.h"
#include "allegro5\allegro_font.h"
#include "allegro5\allegro_ttf.h"

Viewer::Viewer(char* pic_dirs[],uint pic_count,Bird * birds_, Simulation *sim,unsigned int birdCount_, unsigned int width_, unsigned int height_){
	
	this->is_okay = 1;

	this->birds = birds_;
	this->birdCount = birdCount_;
	this->width = width_;
	this->height = height_;
	this->pic_cnt = pic_count;
	this->sim = sim;

	if (!al_init()) {
		this->is_okay = 0;
		cout << "Failed to init allegro \n";
	}
	if (!al_init_primitives_addon()) {
		this->is_okay = 0;
		cout << "Failed to init primitives addon \n";
	}
	if (!al_init_image_addon()) {
		this->is_okay = 0;
		cout << "Failed to init image addon \n";
	}
	if (!al_init_font_addon()) {
		this->is_okay = 0;
		cout << "failed to init fonts \n";
	}
	if (!al_init_ttf_addon()) {
		this->is_okay = 0;
		cout << "failed to init fonts addon \n";
	}
	this->font = al_load_font("isocpeur.ttf", 20, 0);
	if (this->font == NULL) {
		cout << "failed to load fonts \n";
		this->is_okay = 0;
	}
	display = al_create_display(width_, height_);
	al_set_window_title(this->display, "TP4");

	if (display == NULL) {
		this->is_okay = 0;
	}
	
	for (int i = 0; i < (int)pic_cnt; i++) {
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
	for (int i = 0; i < (int)this->pic_cnt; i++) {
		al_destroy_bitmap(this->birdPic[i]);
	}
	al_destroy_font(this->font);
	al_destroy_display(this->display);
	al_shutdown_primitives_addon();
	al_shutdown_image_addon();
	al_shutdown_ttf_addon();
	al_shutdown_font_addon();
	
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
		
	for (int i = 0; i < (int)this->birdCount; i++) {
		//al_draw_circle(cx, cy, r, color, thickness);
		Position pos = this->birds[i].getPosition();
		ALLEGRO_BITMAP* pic = this->birdPic[this->birds[i].get_animation_step()];
		uint width = al_get_bitmap_width(pic);
		uint height = al_get_bitmap_height(pic);

		al_draw_bitmap(pic , pos.x * this->width / pos.Xmax - width/2, pos.y * this->height / pos.Ymax - height/2, 0);
		this->birds[i].increment_animation_step();

		if (i == 0) {
			// update shown values. As all birds have the same raidus there is no difference whether we use one or other bird
			this->jiggle_shown_value = this->sim->GetMaxJiggleValue();
			this->speed_shown_value = this->birds[i].getSpeed();
			this->sight_show_value = this->birds[i].getEyeSight();

		}
	}
	al_draw_text(this->font,
		al_map_rgb(255, 0, 0), 10, 10, 0,
		"Program cross -> exit");
	
	al_draw_text(this->font,
		al_map_rgb(255, 0, 0), 10, 40, 0,
		"+j -> increment jiggle -j decrement jigle ");
	al_draw_text(this->font,
		al_map_rgb(255, 0, 0), 10, 70, 0,
		"+s -> increment speed -s decrement speed ");
	al_draw_text(this->font,
		al_map_rgb(255, 0, 0), 10, 100, 0,
		"+e -> increment eye sight -e decrement eye sight ");
	al_draw_text(this->font ,
		al_map_rgb(0, 0, 255), 10, 120, 0,
		("Jigle: "+to_string(this->jiggle_shown_value)).c_str());
	al_draw_text(this->font,
		al_map_rgb(0, 0, 255), 10, 150, 0,
		("Speed: " + to_string(this->speed_shown_value)).c_str());
	al_draw_text(this->font,
		al_map_rgb(0, 0, 255), 10, 180, 0,
		("Eye sight: " + to_string(this->sight_show_value)).c_str());
	al_flip_display();
}
ALLEGRO_DISPLAY* Viewer::get_display() {
	return this->display;
}