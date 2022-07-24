#include "robot.h"
#include <cstddef>

using namespace std;

robot::robot(unsigned int i, unsigned int t, int x, int y) :
	_id(i), _team(t), _xCord(x), _yCord(y) {}

void robot::move(int i) { //move robot 1 place in its direction
	if (this != NULL) {
		++_travelled;
		switch (_direction) {
		case 1:
			_yCord +=(1*i);
			break;
		case 2:
			_xCord +=(1 * i);
			break;
		case 3:
			_yCord -=(1 * i);
			break;
		case 4:
			_xCord -=(1 * i);
			break;
		}
	}
}



void robot::turnLeft() {
	if (this != NULL) {
		switch (_direction) {
		case 1:
			_direction = 4;
			break;
		default:
			--_direction;
		}
	}
}

void robot::turnRight() {
	if (this != NULL) {
		switch (_direction) {
		case 4:
			_direction = 1;
			break;
		default:
			++_direction;
		}
	}
}