#ifndef MAIN_H
#define MAIN_H

#include "viewer.h"
#include "controller.h"
#include "bird.h"
#include "simulation.h"
#include "parser.h"
#include <iostream>

#define MAX_EYESIGHT 100
#define MAX_SPEED 100
#define MAX_RJ	10

#define DEFAULT_EYESIGHT 3
#define DEFAULT_SPEED 1
#define DEFAULT_RJ 5

typedef struct CONFIG_T {
	uint eye_sight;
	uint speed;
	uint max_RJ;

}config_t;

int callbackConfiguration(char * key, char* value, void * userData);		//Key validas: -e, -s, -r (o en mayusculas)
																			//Valores validos: -e: de 0 a 100 (3 por defecto o en caso de no ser valido)
																			//				   -s: de 1 a 100 (1 por defecto o en caso de no ser valido)
																			//				   -r: de 1 a 10 (5 por defecto o en caso de no ser valido)

void defaultConfig(config_t * config_ini);

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int BIRD_COUNT = 100;
const int MAP_WIDTH = 100;
const int MAP_HEIGHT = 70;
const int RANGE = 3;



char *birds_dirs[] = {
	"birds/frame_0_delay-0.08s.png",
	"birds/frame_1_delay-0.08s.png",
	"birds/frame_2_delay-0.08s.png",
	"birds/frame_3_delay-0.08s.png",
	"birds/frame_4_delay-0.08s.png",
	"birds/frame_5_delay-0.08s.png",
	"birds/frame_6_delay-0.08s.png",
	"birds/frame_7_delay-0.08s.png"
};

#endif // !MAIN_H