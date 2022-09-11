
#include <iostream>

#include "Tank.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

bool Tank::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

void Tank::Draw() const
{
	MyTools::SetColor(CC_Brown);
	GotoXY(x, y - 3);
	cout << "    #####";
	GotoXY(x-2, y - 2);
	cout << "#######   #";
	GotoXY(x, y - 1);
	cout << "    #####";
	GotoXY(x,y);
	cout << " ###########";
	int seed = rand() % 100;
	string message;
	switch (seed)
	{
	case 1:
		message = "Victory will be ours";
		break;
	case 2:
		message = "Let's attack";
		break;
	case 3:
		message = "Armor is strong";
		break;
	case 4:
		message = "You shall not pass--PUFH--";
		break;
	default:
		message = " ";
		break;
	}
	if (message!=" ")
	{
		MediatorTank.ShowMessage(message);
	}
}