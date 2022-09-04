#pragma once
#include"Bomb.h"
#include"Plane.h"

class Visitor
{
public:
	virtual ~Visitor() {}
	virtual void log(Bomb bomb) const = 0;
	virtual void log(Plane plane) const = 0;
};