
#include <conio.h>

#include "SBomber.h"
#include"MyTools.h"
#include"FileLoggerSingletone.h"
#include"LoggerSingleton.h"

using namespace std;

//========================================================================================================================

int main(void)
{
    Singleton::GetInstance().OpenLogFile("log.txt");
    SBomber game;

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }
        
        MyTools::ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();

        game.TimeFinish();
        
    } while (!game.GetExitFlag());

    Singleton::GetInstance().CloseLogFile();

    return 0;
}
