#include "simulation.h"
#include "config.h"

Simulation::Simulation(Bird* birds,uint bird_cnt,uint max_random_jiggle) {
	this->birds = birds;
	this->bird_cnt = bird_cnt;
	this->max_random_jiggle = max_random_jiggle;
	for (int i = 0; i < bird_cnt; i++) {
		birds[i].SetRJ( (rand()+1) % this->max_random_jiggle);
	}
}
void Simulation::update() {
	for (int i = 0; i < this->bird_cnt; i++) {
		this->birds[i].calculate_new_dir(this->birds,this->bird_cnt);
	}
	for (int i = 0; i < this->bird_cnt; i++) {
		this->birds[i].move();
	}
}
void Simulation::IncreaseRandomJiggle() {
	if (this->max_random_jiggle < MAX_RJ) {
		this->max_random_jiggle ++;
	}
	for (int i = 0; i < bird_cnt; i++) {
		birds[i].SetRJ((rand() + 1) % this->max_random_jiggle);
	}
}
void Simulation::DecreaseRandomJiggle() {
	if (this->max_random_jiggle > 1) {
		this->max_random_jiggle--;
	}
	for (int i = 0; i < bird_cnt; i++) {
		birds[i].SetRJ((rand() + 1) % this->max_random_jiggle);
	}
}
uint Simulation::GetMaxJiggleValue() {
	return this->max_random_jiggle;
}
Simulation::~Simulation() {
}