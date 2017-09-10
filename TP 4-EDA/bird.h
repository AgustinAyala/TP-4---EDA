
#ifndef BIRD_H
#define BIRD_H


#include <ctime>
#include <cstdlib>
#include <cstdbool>
#define PI 3.14159265

//*******************************************************************************************************//
class Position {
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
};


class Bird {

	private:
		double currentDirection;
		double newDirection;
		double randomJ;
		unsigned int eyeSight;
		unsigned int maxRandomJiggle;
		unsigned int speed;
		Position pos;

	public:

		//static unsigned int birdCount;

		Bird(unsigned int eyeSight_ = 0, unsigned int speed_ = 5, unsigned int maxRandomJiggle_ = 0)
			: eyeSight(eyeSight_),
			speed(speed_),
			maxRandomJiggle(maxRandomJiggle_),
			currentDirection((double)( 360.0*rand()/RAND_MAX) ),
			pos(Position()) {}


		void move(Bird * bird, unsigned int birdCount);                                   //falta
		void incrementEyeSight();
		void decrementEyesight();
		void incrementSpeed();
		void decrementSpeed();
		
		double calculate_new_dir(Bird * bird, unsigned int birdCount);
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
