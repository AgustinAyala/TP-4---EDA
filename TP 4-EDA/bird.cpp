
#include "bird.h"
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std; 


// test

double calculate_distance(Position p1, Position p2);

Position::Position(float Xmax, float Ymax, float x, float y) {
	this->x = x;
	this->y = y;
	this->Xmax = Xmax;
	this->Ymax = Ymax;
}

/********************************Getters************************************/

double Bird::getDir() { return this->currentDirection; };

double Bird::getNewDir() { return this->newDirection; };

unsigned int Bird::getEyeSight() { return this->eyeSight; };

double Bird::getRandomJ() { return this->randomJ; };

Position Bird::getPosition() { return this->pos; };

uint Bird::get_animation_step() {
	return this->animation_step;
}
/***************************************************************************/

//Metodos Publicos: nescesito que los vea la simulacion (todavia hay q chekear!!!!!!)
void Bird::init_Bird(uint eyeSight_ , uint speed_ , uint maxRandomJiggle_ , uint step_count  , uint period , uint width , uint height, uint x , uint y){
	
	this->eyeSight = eyeSight_;
	this->speed = speed_;
	this->maxRandomJiggle = maxRandomJiggle_;
	this->currentDirection = (double)(rand() % 360);
	this->newDirection = this->currentDirection;
	this->pos = Position(width , height , x , y);
	this->animation_step = 0;
	this->animation_count = 0;
	this->animation_period = period;
	this->step_count = step_count;
}

void Bird::move() {
	this->currentDirection = this->newDirection;
	this->pos.x += cos(this->getDir()*PI / 180.0) * this->speed;
	this->pos.y += sin(this->getDir()*PI / 180.0) * this->speed;
	if (this->pos.x < 0) {
		this->pos.x = this->pos.Xmax;
	}
	if (this->pos.x > this->pos.Xmax) {
		this->pos.x = 0;
	}
	if (this->pos.y < 0) {
		this->pos.y = this->pos.Ymax;
	}
	if (this->pos.y > this->pos.Ymax) {
		this->pos.y = 0;
	}
}

void Bird::calculate_new_dir(Bird * bird, unsigned int birdCount)
{
	//double prom = ( (this->currentDirection) + (this->randomJ) )/birdCount; //seteo el valor promedio para la nueva direccion del objeto bird
	double prom = 0;

	//cout << this->eyeSight << '\n';
	int tot_sum = 0;
	for (int i = 0; i < (int)(birdCount); i++)
	{
		if ((this->is_in_eyeSight(bird[i]))){
			// es otro bird distinto al cual quiero calcular newDir? y esta en su alcance? si es asi, lo promedio para calcular su nueva direccion;
			prom += ((bird[i].getDir()));
			tot_sum++;
		}
	}

	this->newDirection = prom / tot_sum + (double)(rand() % this->maxRandomJiggle);
}

bool Bird::is_equal_bird(Bird& bird) const
{
	return (this == &bird);
}

//Calculates distance between positions of two birds objects, and returns 'true' if it is less than eyeSight or 'false' otherwise;
bool Bird::is_in_eyeSight(Bird bird)
{
	//cout << calculate_distance(this->getPosition(), bird.getPosition()) << (double)(this->eyeSight) << '\n';
	if ( calculate_distance(this->getPosition(), bird.getPosition()) < (double)(this->eyeSight) + 1e-5)
		return true;
	else
		return false;
}
void Bird::increment_animation_step() {
	this->animation_count++;
	//cout << this->animation_period << '\n';
	if (this->animation_count == this->animation_period) {
		this->animation_count = 0;
		this->animation_step++;
		if (this->animation_step == this->step_count) {
			this->animation_step = 0;
		}
	}
}
double calculate_distance(Position p1, Position p2)
{
	double distance = sqrt(pow((p1.x - p2.x),2.0) + pow((p1.y - p2.y),2.0)); 
	return distance;
}

