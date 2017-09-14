#ifndef CONFIG_H
#define CONFIG_H

/*** Configuracion de todos los parametros del programa **/

typedef unsigned int uint;

const uint MAX_EYESIGHT = 50;
const uint MAX_SPEED = 30;
const uint MAX_RJ = 10;

const uint MIN_EYESIGHT = 0;
const uint MIN_SPEED = 1;
const uint MIN_RJ = 1;

const uint DEFAULT_EYESIGHT = 3;
const uint DEFAULT_SPEED = 5;
const uint DEFAULT_RJ = 5;


const uint SCREEN_WIDTH = 800;
const uint SCREEN_HEIGHT = 600;
const uint BIRD_COUNT = 100;
const uint MAP_WIDTH = 800; // al final hicimos que las dimensiones de la pantalla coincidieran con las de la simulacion.
const uint MAP_HEIGHT = 600;


#endif