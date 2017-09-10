#include "bird.h"
// test


/********************************Getters************************************/

double Bird::getDir() { return this->currentDirection; };

double Bird::getNewDir() { return this->newDirection; };

unsigned int Bird::getEyeSight() { return this->eyeSight; };

double Bird::getRandomJ() { return this->randomJ; };

Position Bird::getPosition() { return this->pos; };

/***************************************************************************/

//Metodos Publicos: nescesito que los vea la simulacion (todavia hay q chekear!!!!!!)
void Bird::move(Bird * bird, unsigned int birdCount)
{
	this->newDirection = this->calculate_new_dir(bird, birdCount);

}

void Bird::move(Bird * bird, unsigned int birdCount)
{
	this->newDirection = this->calculate_new_dir(bird, birdCount); //variable auxiliar para calcular el promedio de las direcciones de los birds en el rango del bird del cual quiero saber su newDir.
}


double Bird::calculate_new_dir(Bird * bird, unsigned int birdCount)
{
	double prom = ( (this->currentDirection) + (this->randomJ) )/birdCount; //seteo el valor promedio para la nueva direccion del objeto bird

	for (int i = 0; i < (birdCount - 1); i++)
	{

		if (!(this->is_equal_bird(bird[i]))  &&  (this->is_in_eyeSight(bird[i])) )  
			// es otro bird distinto al cual quiero calcular newDir? y esta en su alcance? si es asi, lo promedio para calcular su nueva direccion;
			prom += prom + ( (bird[i].getDir()) / (double)birdCount );
	}
	return prom;
}

bool Bird::is_equal_bird(Bird& bird) const
{
	return (this == &bird);
}

//Calculates distance between positions of two birds objects, and returns 'true' if it is less than eyeSight or 'false' otherwise;
bool Bird::is_in_eyeSight(Bird bird)
{
	if ( calculate_distance(this->getPosition(), bird.getPosition()) < (double)(this->eyeSight) )
		return true;
	else
		return false;
}

double calculate_distance(Position p1, Position p2)
{
	double distance = sqrt(pow((p1.x - p2.x),2.0) + pow((p1.y - p2.y),2.0)); 
	return distance;
}




////******************codigo para prueba*********************/////////
int main(void)
{





}
