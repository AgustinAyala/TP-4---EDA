#include "config.h"
#include "utils.h"
#include "main.h"

int main(int argc, char*argv[]) {
	cout << "TP 4 options \n";
	cout << "eyesight [" << MIN_EYESIGHT << "," << MAX_EYESIGHT << "]\n";
	cout << "maxspeed [" << MIN_SPEED << "," << MAX_SPEED << "]\n";
	cout << "randomJiggle [" << MIN_RJ << "," << MAX_RJ << "]\n";


	config_t config_ini;

	pCallback callBack = callbackConfiguration;

	defaultConfig(&config_ini);
	
	int parsing_ans = parseCmdLine(argc, argv, callBack, &config_ini);
	if (parsing_ans == PARSE_CMDL_ERROR) {
		cout << "Error in parser \n";
		return 0;
	}
	if (config_ini.eye_sight == -1) {
		config_ini.eye_sight = DEFAULT_EYESIGHT;
		cout << "Default eyesight: " << DEFAULT_EYESIGHT << " selected \n";
	}
	if (config_ini.speed == -1) {
		config_ini.speed = DEFAULT_SPEED;
		cout << "Default speed: " << DEFAULT_SPEED << " selected \n";
	}
	if (config_ini.max_RJ == -1) {
		config_ini.max_RJ = DEFAULT_RJ;
		cout << "Default random jiggle: " << DEFAULT_RJ << " selected \n";
	}

	Bird* birds = new Bird[BIRD_COUNT];
	if (birds == NULL) {
		cout << "Could't reserve memory \n";
		return 0;
	}
	for (int i = 0; i < BIRD_COUNT; i++) {
		double x = (rand() % 1000) * MAP_WIDTH / 1000.0;
		double y = (rand() % 1000) * MAP_HEIGHT / 1000.0;
		birds[i].init_Bird(config_ini.eye_sight, config_ini.speed, config_ini.max_RJ,  sizeof(birds_dirs) / sizeof(char*), 2, MAP_WIDTH, MAP_HEIGHT, x, y);
	}
	
	Simulation simulation(birds, BIRD_COUNT, config_ini.max_RJ);
	Viewer viewer(birds_dirs,sizeof(birds_dirs)/sizeof(char*),birds,&simulation, BIRD_COUNT, SCREEN_WIDTH , SCREEN_HEIGHT) ;

	if (!viewer.is_init_ok()) {
		printf("Error creating viewer");
		getchar();
		return 0;
	}
	Controller controller (viewer.get_display(), birds,&simulation, BIRD_COUNT);
	if (!controller.is_ok()) {
		printf("Could not init controller \n");
		getchar();
		return 0;
	}

	while (controller.is_not_exit()) {
		controller.update();
		viewer.update_display();
		simulation.update();
		al_rest(0.02);
	}
}

void defaultConfig(config_t * config_ini)
{
	config_ini->eye_sight = UINT_MAX;
	config_ini->max_RJ = UINT_MAX;
	config_ini->speed = UINT_MAX;
}

int callbackConfiguration(char * key, char* value, void * userData) {
	int retr_value = 0;				//se define por defecto el valor de retorno 0 (error)
	
					//se setea en -1 en caso de que no se pase ningun valor
	string key_;
	if (key != NULL) {
		lowerize(key);
		key_ = (string)key;
	}else {
		return 0; // no aceptamos si no hay keys. 
	}
	int value_;
	if (is_number(value)) {
		value_ = atoi(value);
	}else {
		return 0;
	}
	

	if (key_ == "eyesight") {
		//cout << (value_ >= MIN_EYESIGHT) && (value_ <= MAX_EYESIGHT) << '\n';

		if ((value_ >= MIN_EYESIGHT) && (value_ <= MAX_EYESIGHT) && ((config_t *)userData)->eye_sight == UINT_MAX) {					//verifico si la key y el valor son validos
			((config_t *)userData)->eye_sight = value_;
			retr_value = 1;
		}else {
			retr_value = 0;
		}
	}
	else if (key_ == "maxspeed") {
		if ((value_ >= MIN_SPEED) && (value_ <= MAX_SPEED) && ((config_t *)userData)->speed == UINT_MAX) {
			((config_t *)userData)->speed = value_;
			retr_value = 1;
		}else {
			retr_value = 0;
		}
	}
	else if (key_ == "randomjiggle") {
		if ((value_ >= MIN_RJ) && (value_ <= MAX_RJ) && ((config_t *)userData)->max_RJ == UINT_MAX) {
			((config_t *)userData)->max_RJ = value_;
			retr_value = 1;
		}else {
			retr_value = 0;
		}

	}
	
	return retr_value;
}