
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
<<<<<<< HEAD
public:
	float x;
	float y;
	float Xmax;
	float Ymax;


	Position() // Constructor: incializo los valores inciales (x,y)
		: Xmax(100.0),
		Ymax(70.0),
		x(5), //((float)(rand()) * Xmax / (float)(RAND_MAX)),
		y(2) //((float)(rand()) * Ymax / (float)(RAND_MAX)) 
	{}
=======
	public:
		float x;
		float y;
		float Xmax;
		float Ymax;


		Position() // Constructor: incializo los valores inciales (x,y)
			: Xmax(100.0),
			Ymax(70.0),
			x((float)(rand()) * Xmax / (float)(RAND_MAX)),
			y((float)(rand()) * Ymax / (float)(RAND_MAX)) {}
		Position(float Xmax, float Ymax, float x, float y);
>>>>>>> 5f427ba4590e90a6748353a2d015d563059177e4
};


class Bird {

	private:
		double currentDirection;
		double newDirection;
		double randomJ;
		uint eyeSight;
		uint maxRandomJiggle;
		uint speed;
		Position pos;
		uint animation_step;
		uint animation_count;
		uint animation_period;
		uint step_count;
	public:

<<<<<<< HEAD
		static unsigned int birdCount;

		Bird(unsigned int eyeSight_ = 0, unsigned int speed_ = 5, unsigned int maxRandomJiggle_ = 0)
			: eyeSight(eyeSight_),
			speed(speed_),
			maxRandomJiggle(maxRandomJiggle_),
			currentDirection((double) (15)), //( 360.0*rand()/RAND_MAX) ),
			pos(Position()) {}
=======
		//static unsigned int birdCount;
>>>>>>> 5f427ba4590e90a6748353a2d015d563059177e4

		void init_Bird(uint eyeSight_ , uint speed_ , uint maxRandomJiggle_ ,
			uint period, uint step_count, uint width, uint height, uint x, uint y);
	

		void move();                                   //falta
		void incrementEyeSight();
		void decrementEyesight();
		void incrementSpeed();
		void decrementSpeed();
		
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
		Position getPosition();

};


//unsigned int Bird::birdCount = 0; //esto no estoy seguro todavia, pero creo q me setearia inicialmente a cero para despues
								  // en la simulacion incrementarlo;

#endif // !BIRD_H
