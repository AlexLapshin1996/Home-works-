#include"BombIterator.h"
#include"SBomber.h"

void BombIterator::Reset()
{
	CurIndex = -1;
	ptr = nullptr;
}

BombIterator& BombIterator::operator++()
{
	CurIndex++;
	if (CurIndex==-1)
	{
		CurIndex = 0;
	}
	Bomb* PBomb;
	for (;CurIndex<vecDynamicObj.size();CurIndex++)
	{
		PBomb = dynamic_cast<Bomb*>(vecDynamicObj[CurIndex]);
		if (PBomb!=nullptr)
		{
			ptr = vecDynamicObj[CurIndex];
			break;
		}
	}

	if (CurIndex==vecDynamicObj.size())
	{
		CurIndex = -1;
		ptr = nullptr;
	}
	return *this;
}

BombIterator& BombIterator::operator--()
{
	if (CurIndex==-1)
	{
		CurIndex = vecDynamicObj.size() - 1;
	}
	Bomb* PBomb;
	for (;CurIndex>=0;CurIndex--)
	{
		PBomb = dynamic_cast<Bomb*>(vecDynamicObj[CurIndex]);
		if (PBomb!=nullptr)
		{
			ptr = vecDynamicObj[CurIndex];
			break;
		}
	}
	if (CurIndex==-1)
	{
		ptr == nullptr;
	}
	return *this;
}

DynamicObject* BombIterator::operator*()
{
	return vecDynamicObj[CurIndex];
}

bool BombIterator::operator==(BombIterator Biter)
{
	if (CurIndex==Biter.CurIndex && ptr == Biter.ptr && vecDynamicObj == Biter.vecDynamicObj)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BombIterator::operator!=(BombIterator Biter)
{
	return !(*this == Biter);
}

