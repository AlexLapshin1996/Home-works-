#pragma once

#include<vector>

#include"Bomb.h"

using namespace std;

class BombIterator 
{
public:
	BombIterator();
	BombIterator(const vector<DynamicObject*>& DymRef) : vecDynamicObj(DymRef), CurIndex(-1), ptr(nullptr)
	{
		++(*this);
	}
	void Reset();
	BombIterator& operator++();
	BombIterator& operator--();
	DynamicObject* operator*();
	bool operator==(BombIterator Biter);
	bool operator!=(BombIterator Biter);
	
private:
	int CurIndex;
	DynamicObject* ptr;
	const vector<DynamicObject*>& vecDynamicObj;
};


