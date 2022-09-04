#include<string>
#include<iostream>

#include "LogVisitor.h"
#include"MyTools.h"

using namespace std;
using namespace MyTools;

void LogVisitor::log(Bomb bomb) const
{
	WriteToLog("Bomb coordinates : X " + to_string(bomb.GetX()) + " Y :" + to_string(bomb.GetY()));
	WriteToLog("Bomb direction : X " + to_string(bomb.GetDirectionX()) + " Y : " + to_string(bomb.GetDirectionY()));
	WriteToLog("Bomb speed = ", bomb.GetSpeed());
}

void __fastcall LogVisitor::log(Plane plane) const
{
	WriteToLog("Bomb coordinates : X " + to_string(plane.GetX()) + " Y :" + to_string(plane.GetY()));
	WriteToLog("Bomb direction : X " + to_string(plane.GetDirectionX()) + " Y : " + to_string(plane.GetDirectionY()));
	WriteToLog("Bomb speed = ", plane.GetSpeed());
}
