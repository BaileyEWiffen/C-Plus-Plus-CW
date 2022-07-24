#ifndef ROBOT_H
#define ROBOT_H


class robot {
	unsigned int _id, _team;
	int _xCord, _yCord;
	int _direction = 1;
	unsigned int _travelled = 0;

public:
	robot(unsigned int i, unsigned int t, int x, int y);
	
	const unsigned int id() const { return _id; }

	const unsigned int& team() const { return _team; }

	const int& xCord() const { return _xCord; }

	const int& yCord() const { return _yCord; }

	const int& direction() const { return _direction; }

	const unsigned int travelled() const { return _travelled; }


	void move(int i); //move robot 1 place in its direction

	
	void turnLeft();

	void turnRight();
		

};



#endif
