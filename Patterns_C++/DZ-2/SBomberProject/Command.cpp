#include<vector>
#include<string>
#include<iostream>

#include"Command.h"
#include"MyTools.h"
#include"SBomber.h"

using namespace MyTools;

void __fastcall DeleteDynamObjCommand::Execute()
{
    auto it = vecDynamicObj_memb.begin();
    for (; it != vecDynamicObj_memb.end(); it++)
    {
        if (*it == pObj_memb)
        {
            vecDynamicObj_memb.erase(it);
            break;
        }
    }
    
}

void __fastcall DeleteStaticObjCommand::Execute()
{
    {
        auto it = vecStaticObj_memb.begin();
        for (; it != vecStaticObj_memb.end(); it++)
        {
            if (*it == pObj_memb)
            {
                vecStaticObj_memb.erase(it);
                break;
            }
        }
    }
}

void __fastcall DropBombCommand::Execute()
{
        if (bombsNumber_memb > 0)
        {
            WriteToLog(string(__FUNCTION__) + " was invoked");

            //Plane* pPlane = FindPlane();
            double x = Plane_memb->GetX() + 4;
            double y = Plane_memb->GetY() + 2;

            Bomb* pBomb = new Bomb;
            pBomb->SetDirection(0.3, 1);
            pBomb->SetSpeed(2);
            pBomb->SetPos(x, y);
            pBomb->SetWidth(SMALL_CRATER_SIZE);

            vecDynamicObj_memb.push_back(pBomb);
            bombsNumber_memb--;
            score_memb -= Bomb::BombCost;
        }
    
}





