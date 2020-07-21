#pragma once
#include <iostream>
using namespace std;

class Apple {

private:
	int color; // 1 if the apple is green, 0 if the apple is red

public:
	Apple();
	Apple(int _color);

	friend ostream& operator << (ostream& os, Apple& a);

	void setColor(int _color);
	int getColor() const;
};