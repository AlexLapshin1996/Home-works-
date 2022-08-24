#pragma once
#include<vector>

#include"SBomber.h"

using namespace std;

class Command
{
public:
    virtual ~Command() {}
    virtual void Execute() = 0;
};

class DeleteDynamObjCommand : public Command
{
private:
    vector<DynamicObject*>& vecDynamicObj_memb;
    DynamicObject* pObj_memb;
public:
    DeleteDynamObjCommand(vector<DynamicObject*>& vecDynamicObj, DynamicObject* pObj) : vecDynamicObj_memb(vecDynamicObj) {}
    void __fastcall Execute() override;  
};

class DeleteStaticObjCommand : public Command
{
private:
    GameObject* pObj_memb;
    vector<GameObject*>& vecStaticObj_memb;
public:
    DeleteStaticObjCommand(vector<GameObject*> vecStaticObj, GameObject* pObj) :vecStaticObj_memb(vecStaticObj), pObj_memb(pObj) {}
    void __fastcall Execute() override;  
};

class DropBombCommand : public Command
{
private:
    vector<DynamicObject*>& vecDynamicObj_memb;
    Plane *Plane_memb;
    uint16_t bombsNumber_memb;
    int16_t *score_memb;
public:
    DropBombCommand(Plane *const plane, vector<DynamicObject*>& vecDynamicObj, uint16_t const& BombsNumber) : Plane_memb(plane), vecDynamicObj_memb(vecDynamicObj), bombsNumber_memb(BombsNumber) {}
    void __fastcall Execute() override;  
};

