#include "viewer.h"
#include "controller.h"
#include "bird.h"
#include "simulation.h"
#include <iostream>

using namespace std;

const int SCREEN_WIDTH  = 800;
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


int main() {
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