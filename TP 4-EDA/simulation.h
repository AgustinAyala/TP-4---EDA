#ifndef SIMULATION_H
#define SIMULATION_H

#include "bird.h"

typedef unsigned int uint;

class Simulation {		
	public:
		Simulation(Bird* birds, uint bird_cnt);
		~Simulation();
		void update();
	private:
		Bird *birds;
		uint bird_cnt;

};

#endif