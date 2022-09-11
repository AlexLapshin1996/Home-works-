#include "Mediator.h"

void Mediator::ShowMessage(string message)
{
	LevelGUI::Messages_tank_memb.push(message);
}