#include <iostream>

#include "LevelGUI.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void LevelGUI::Draw() const
{
    MyTools::SetColor(CC_White);

    GotoXY(x, y);
    char* buf = new (nothrow) char[width + 1];
    if (buf == nullptr)
    {
        return;
    }
    memset(buf, '+', width);
    buf[width] = '\0';
    cout << buf;
    GotoXY(x, y + height);
    cout << buf;
    delete [] buf;
    buf = nullptr;
    
    for (size_t i = size_t(y); i < height + y; i++)
    {
        GotoXY(x, (double)i);
        cout << "+";
        GotoXY(x + width - 1, (double)i);
        cout << "+";
    }

    GotoXY(3, 1);
    cout << "FramePerSecond: " << static_cast<int>(fps / (passedTime / 1000.0));
    GotoXY(25, 1);
    cout << "PassedTime: " << static_cast<int>(passedTime / 1000.0) << " sec";
    GotoXY(46, 1);
    cout << "BombsNum: " << bombsNumber;
    GotoXY(62, 1);
    cout << "Score: " << score;
    GotoXY(6, 27);
    cout << "Tank crew message : " <<messages_memb;
}

void __fastcall LevelGUI::SetParam(uint64_t passedTimeNew, uint64_t fpsNew, uint16_t bombsNumberNew, int16_t scoreNew)
{
    passedTime = passedTimeNew;
    fps = fpsNew;
    bombsNumber = bombsNumberNew;
    score = scoreNew;
    if (!Messages_tank_memb.empty())
    {
        if (passedTime>1000 && rand() %1000 <=10)
        {
            messages_memb = Messages_tank_memb.front();
            Messages_tank_memb.pop();
        }
    }
    else
    {
        messages_memb = " ";
    }
}
