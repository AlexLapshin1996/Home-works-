#pragma once
#include"Hand.h"

class GenericPlayer : public Hand
{
public:

	GenericPlayer(const string& name);

	GenericPlayer();

	virtual bool IsHitting() = 0;

	bool IsBoosted();
	
	void Bust();
	
	friend ostream& operator<<(ostream& os, const GenericPlayer& genericPlayer);
	
	virtual ~GenericPlayer();

protected:

	string p_Name;
};

ostream& operator<<(ostream& os, const GenericPlayer& genericPlayer);