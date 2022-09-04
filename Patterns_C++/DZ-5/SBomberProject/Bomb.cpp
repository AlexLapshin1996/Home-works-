
#include <iostream>

#include "Bomb.h"
#include "MyTools.h"
#include"Visitor.h"

using namespace std;
using namespace MyTools;

void Bomb::Draw() const
{
    MyTools::SetColor(CC_LightMagenta);
    GotoXY(x, y);
    cout << "*";
}

void __fastcall Bomb::Accept(const Visitor & V)
{
    V.log(*this);
}