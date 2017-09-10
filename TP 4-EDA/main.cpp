#include "viewer.h"
#include "controller.h"
#include "bird.h"
#include <iostream>

using namespace std;

const int SCREEN_WIDTH  = 800;
const int SCREEN_HEIGHT = 600;

int main() {
	Viewer viewer = Viewer("bird.png",NULL, 0, SCREEN_WIDTH , SCREEN_HEIGHT) ;
	if (!viewer.is_init_ok()) {
		printf("Error creating viewer");
		getchar();
		return 0;
	}
	Controller controller = Controller(viewer.get_display(),NULL,0);
	
	while (controller.is_not_exit()) {
		controller.update();
		viewer.update_display();

		al_rest(0.03);
	}
}