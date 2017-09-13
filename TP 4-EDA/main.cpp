#include "main.h"

int main(int argc, char*argv[]) {

	config_t config_ini;

	pCallback callBack = callbackConfiguration;

	defaultConfig(&config_ini);

	parseCmdLine(argc, argv, callBack, &config_ini);
	
	Bird* birds = new Bird[BIRD_COUNT];
	for (int i = 0; i < BIRD_COUNT; i++) {
		double x = (rand() % 1000) * MAP_WIDTH / 1000.0;
		double y = (rand() % 1000) * MAP_HEIGHT / 1000.0;
		birds[i].init_Bird(RANGE, 1, 5, 8, 2, MAP_WIDTH, MAP_HEIGHT, x, y);
	}
	Viewer viewer = Viewer(birds_dirs,sizeof(birds_dirs)/sizeof(char*),birds, BIRD_COUNT, SCREEN_WIDTH , SCREEN_HEIGHT) ;
	if (!viewer.is_init_ok()) {
		printf("Error creating viewer");
		getchar();
		return 0;
	}
	Controller controller = Controller(viewer.get_display(),birds, BIRD_COUNT);
	Simulation simulation = Simulation(birds, BIRD_COUNT);

	while (controller.is_not_exit()) {
		controller.update();
		viewer.update_display();
		simulation.update();
		al_rest(0.02);
	}
}

void defaultConfig(config_t * config_ini)
{
	config_ini->eye_sight = DEFAULT_EYESIGHT;
	config_ini->max_RJ = DEFAULT_RJ;
	config_ini->speed = DEFAULT_SPEED;
}

int callbackConfiguration(char * key, char* value, void * userData) {
	int retr_value = 0;				//se define por defecto el valor de retorno 0 (error)
	int value_ = -1;				//se setea en -1 en caso de que no se pase ningun valor
	string key_ = (string) key;

	if ((key_ == "e") || (key_ == "E")) {
		if ((value_ > 1) && (value_ < MAX_EYESIGHT)) {					//verifico si la key y el valor son validos
			((config_t *)userData)->eye_sight = value_;
			retr_value = 1;
		}
		else
			retr_value = 0;
	}
	else if ((key_ == "s") || (key_ == "S")) {
		if ((value_ > 0) && (value_ < MAX_SPEED)) {
			((config_t *)userData)->speed = value_;
			retr_value = 1;
		}
		else
			retr_value = 0;
	}
	else if (( key_ == "r") || (key_ == "R")) {
		if ((value_ > 0) && (value_ < MAX_RJ)) {
			((config_t *)userData)->max_RJ = value_;
			retr_value = 1;
		}
		else
			retr_value = 0;
	}
	return retr_value;
}