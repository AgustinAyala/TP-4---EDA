
/*** Bird ***/

/*** Controla de realizar todas las cuentas para el movimiento de los pajaros ***/


#ifndef BIRD_H
#define BIRD_H


#include <ctime>
#include <cstdlib>
#include <cstdbool>

using namespace std;



#define PI 3.141592

typedef unsigned int uint;

//*******************************************************************************************************//
class Position {
public:
	float x;
	float y;
	float Xmax;
	float Ymax;
	Position(){}
	Position(float Xmax, float Ymax, float x, float y);
};


class Bird {

	private:
		double currentDirection;
		double newDirection;
		uint randomJ;
		uint eyeSight;

		uint speed;
		Position pos;
		uint animation_step;
		uint animation_count;
		uint animation_period;
		uint step_count;
	public:

		void init_Bird(uint eyeSight_ , uint speed_ , uint randomJ,
			uint period, uint step_count, uint width, uint height, uint x, uint y);
	

		void move();
		void incrementEyeSight();
		void decrementEyesight();
		void incrementSpeed();
		void decrementSpeed();
		void SetRJ(uint RJ);
		
		void increment_animation_step();
		uint get_animation_step();

		void calculate_new_dir(Bird * bird, unsigned int birdCount);
		bool is_equal_bird (Bird& bird) const;
		bool is_in_eyeSight(Bird bird);
		//getters
		double getDir();
		double getNewDir();
		unsigned int getEyeSight();
		double getRandomJ();
		uint getSpeed();
		Position getPosition();
		
};


//unsigned int Bird::birdCount = 0; //esto no estoy seguro todavia, pero creo q me setearia inicialmente a cero para despues
								  // en la simulacion incrementarlo;

#endif // !BIRD_H
