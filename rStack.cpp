#include "rstack.h"
#include<iostream>
#include <algorithm>
#include<fstream>

using namespace std;



void rStack::order() {sort(_s.begin(), _s.end(), [](const robot a, const robot b) {return a.id() < b.id(); }); } //order stack by id

void rStack::show() {// print whole stack
	order();
	for (auto& r : _s) {
		cout << r.id() << " " << r.team() << " " << r.xCord() << " " << r.yCord() << "\n";
	}
}

robot& rStack::get(unsigned int i) { // return robot by id, if miss return NULL
	auto t = find_if(_s.begin(), _s.end(), [&i](const robot a) {return a.id() == i; });
	if (t != _s.end()) {
		return *t;
	}
	
}

void rStack::within(int i) { //reuturn number of robots within i of the origin 
	cout << count_if(_s.cbegin(), _s.cend(), [&i]( const robot a) {return (abs(a.xCord()) + abs(a.yCord())) <= i; }) << "\n";
	
}

void rStack::hasTravelled() {
	order();
	sort(_s.begin(), _s.end(), [](robot a, robot b) {return a.travelled() < b.travelled(); });
	for (auto& r : _s) {
		cout << r.id() << " " << r.travelled() << "\n";
	}
}

void rStack::collition(robot& r) {// check for collitions of robot r
	if (&r != NULL) {
		auto t = find_if(_s.cbegin(), _s.cend(), [&r](const robot a) {return (((r.xCord() == a.xCord()) && (r.yCord() == a.yCord())) && (r.id() != a.id())); });
		if (t != _s.end()) {//if another robot is hit
			robot a = *t;
			if (a.team() != r.team()) {
				_s.erase(t);//remove hit robot

			}
			else {
				r.move(-1);//undo the move

			}
		}
	}
}

void rStack::start() {//fills the stack with robots from start.txt and runs command.txt
	unsigned int i, t;
	int x, y;
	ifstream start("start.txt");
	while (start >> i >> t >> x >> y)
	{
		_s.push_back(robot(i, t, x, y));
	}

	unsigned int j =0;
	string c;
	ifstream command("commands.txt");
	while (command >> c) {
		if (c == "show") {
			show();
		}
		else if (c == "travelled") {
			hasTravelled();
		}
		else {
			command >> j;
		}
		if (c == "within") {
			within(j);
		}
		else if (c == "turnleft") {
			get(j).turnLeft();
		}
		else if (c == "turnright") {
			get(j).turnRight();
		}
		else if (c == "move") {

			get(j).move(1);
			collition(get(j));
		}

	}
}