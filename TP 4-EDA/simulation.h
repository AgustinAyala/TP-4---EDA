#ifndef SIMULATION_H
#define SIMULATION_H

/*** Simluation ***/
/*** Se encarga de llamar a las actualizaciones de los bird
Y ademas les asigna a los bird el jiggle, que esta entre 0 y el max random jiggle configurado ***/


#include "bird.h"

typedef unsigned int uint;

class Simulation {		
	public:
		Simulation(Bird* birds, uint bird_cnt, uint max_random_jiggle);
		~Simulation();
		void update();
		void IncreaseRandomJiggle();
		void DecreaseRandomJiggle();
		uint GetMaxJiggleValue();
	private:
		Bird *birds;
		uint bird_cnt;
		uint max_random_jiggle;

};

#endif