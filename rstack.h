#ifndef RSTACK_H
#define RSTACK_H
#include<vector>
#include "robot.h"


class rStack {

	std::vector<robot> _s;
public:
	
	void start();

private:

	void show();

	robot& get(unsigned int i);

	void within(int i);

	void hasTravelled();

	void collition(robot& r);

	void order();
};
#endif
