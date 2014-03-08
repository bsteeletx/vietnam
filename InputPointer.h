#pragma once

#include "Input.h"

class Pointer : public Input
{
public:
	Pointer();
	~Pointer();

	bool GetPressed(); 
	bool GetReleased();
	bool GetState(); 
	Point GetPosition();

private:
	float _GetX(); 
	float _GetY(); 
};