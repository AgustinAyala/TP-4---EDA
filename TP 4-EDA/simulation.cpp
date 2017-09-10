#include "simulation.h"

Simulation::Simulation(Bird* birds,uint bird_cnt) {
	this->birds = birds;
	this->bird_cnt = bird_cnt;
}
void Simulation::update() {
	for (int i = 0; i < this->bird_cnt; i++) {
		this->birds[i].calculate_new_dir(this->birds,this->bird_cnt);
	}
	for (int i = 0; i < this->bird_cnt; i++) {
		this->birds[i].move();
	}
}
Simulation::~Simulation() {
}