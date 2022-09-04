#pragma once
#include "Visitor.h"

class LogVisitor : public Visitor
{
public:
	void log(Bomb bomb) const;
	void log(Plane plane) const;
};

