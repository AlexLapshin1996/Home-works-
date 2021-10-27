#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>
#include<string>
#include<fstream>

using namespace std;

enum Cell : char
{ 
    CROSS = 'X',
    ZERO = '0',
    EMPTY = '_'

};

struct Coord {
    size_t y{ 0 };
    size_t x{ 0 };
};

enum Progress {
    In_PROGRESS,
    WON_HUMAN,
    WON_AI,
    DRAW
};

#pragma pack(push, 1)
struct Game 
{
    Cell** ppField = nullptr;
    const size_t SIZE = 3;
    Cell human;
    Cell ai;
    size_t turn = 0;
    Progress progress = In_PROGRESS;
};
#pragma pack (pop)

void clearScr()
{
    system("cls");
}

int32_t __fastcall getRandomNum(int32_t min, int32_t max)
{
    const static auto seed = chrono::system_clock::now().time_since_epoch().count();
    static mt19937_64 generator(seed);
    uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}

void __fastcall initGame(Game& g)
{
    g.ppField = new Cell * [g.SIZE];
    for (size_t i = 0; i < g.SIZE; i++)
    {
       g.ppField[i] =new Cell[g.SIZE];
    }
    
    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            g.ppField[y][x] = EMPTY;
        }
    }
    if (getRandomNum(0,1000) >500)
    {
        g.human = CROSS;
        g.ai = ZERO;
        g.turn = 0;
    }
    else
    {
        g.human = ZERO;
        g.ai = CROSS;
        g.turn = 1;
    }

}

void __fastcall deinitGame(Game& g)
{
    for (size_t i = 0; i < g.SIZE; i++)
    {
        delete[] g.ppField[i];
    }
    delete[]  g.ppField;
    g.ppField = nullptr;
}

void __fastcall drawGame(const Game& g)
{
    cout<< endl << "      ";
    for (size_t x = 0; x < g.SIZE; x++)
    {
        cout<< x+1 << "   ";
    }
    cout << endl;

    for (size_t y = 0; y < g.SIZE; y++)
    {
        cout <<"  "<< y + 1 << " | ";
        for (size_t x = 0; x < g.SIZE; x++)
        {
            cout<< g.ppField[y][x]<< " | ";
        }
        cout << endl;
    }
    cout << endl << "Human :" << g.human << endl << "Computer :" << g.ai << endl;
}

Progress __fastcall getWon(const Game& g)
{
    for (size_t y = 0; y < g.SIZE; y++)
    {
        if (g.ppField[y][0] == g.ppField[y][1] && g.ppField[y][0] == g.ppField[y][2])
        {
            if (g.ppField[y][0] == g.human)
                return WON_HUMAN;
            if (g.ppField[y][0] == g.ai)
                return WON_AI;
        }
    }

    for (size_t x = 0; x < g.SIZE; x++)
    {
        if (g.ppField[0][x] == g.ppField[1][x] && g.ppField[0][x] == g.ppField[2][x])
        {
            if (g.ppField[0][x] == g.human)
                return WON_HUMAN;
            if (g.ppField[0][x] == g.ai)
                return WON_AI;
        }
    }

        if (g.ppField[0][0] == g.ppField[1][1] && g.ppField[0][0] == g.ppField[2][2])
        {
            if (g.ppField[1][1] == g.human)
                return WON_HUMAN;
            if (g.ppField[1][1] == g.ai)
                return WON_AI;
        }

        if (g.ppField[2][0] == g.ppField[1][1] && g.ppField[1][1] == g.ppField[0][2])
        {
            if (g.ppField[1][1] == g.human)
                return WON_HUMAN;
            if (g.ppField[1][1] == g.ai)
                return WON_AI;
        }

        bool draw = true;
        for (size_t y = 0; y < g.SIZE; y++)
        {
            for (size_t x = 0; x <g.SIZE; x++)
            {
                if (g.ppField[y][x] == EMPTY)
                {
                    draw = false;
                    break;
                }
            }
            if (!draw)
               break;
            
        }
        if (draw)
            return DRAW;

    return In_PROGRESS;
}

Coord __fastcall getHumanCoord(const Game& g)
{
    Coord c;
    do
    {
        cout << "Enter x (1..3):";
        cin >> c.x;
        cout << "Enter y (1..3)";
        cin >> c.y;
        c.x--;
        c.y--;
    } while (c.x >2 || c.y >2 || g.ppField[c.y][c.x]!=EMPTY );
    return c;
}

Coord __fastcall getAICoord( Game& g)
{
    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            if (g.ppField[y][x] == EMPTY)
            {
                g.ppField[y][x] = g.ai;
                if (getWon(g) == WON_AI)
                {
                    g.ppField[y][x] = EMPTY;
                    return { y,x };
                }
                g.ppField[y][x] = EMPTY;
            }
        }
    }

    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            if (g.ppField[y][x] == EMPTY)
            {
                g.ppField[y][x] = g.human;
                if (getWon(g) == WON_HUMAN)
                {
                    g.ppField[y][x] = EMPTY;
                    return { y,x };
                }
                g.ppField[y][x] = EMPTY;
            }
        }
    }

    if (g.ppField[1][1] == EMPTY)
        return{ 1,1 };

    Coord arr[4];
    size_t num = 0;
    if (g.ppField[0][0] == EMPTY)
    {
        arr[num++] = { 0,0 };
    }

    if (g.ppField[0][2] == EMPTY)
    {
        arr[num++] = { 0,2 };
    }

    if (g.ppField[2][0] == EMPTY)
    {
        arr[num++] = { 2,0 };
    }

    if (g.ppField[2][2] == EMPTY)
    {
        arr[num++] = { 2,2 };
    }
    if (num>0)
    {
        const size_t index = getRandomNum(0, 1000) % num;
        return arr[index];
    }

    num = 0; 

    if (g.ppField[0][1] == EMPTY)
    {
        arr[num++] = { 0,1 };
    }

    if (g.ppField[2][1] == EMPTY)
    {
        arr[num++] = { 2,1 };
    }

    if (g.ppField[1][0] == EMPTY)
    {
        arr[num++] = { 1,0 };
    }

    if (g.ppField[1][2] == EMPTY)
    {
        arr[num++] = { 1,2 };
    }
    if (num > 0)
    {
        const size_t index = getRandomNum(0, 1000) % num;
        return arr[index];
    }
}

void __fastcall congrats(const Game& g)
{  
    if (g.progress == WON_HUMAN)
     cout << "Humanity defeated machines!" << endl;      
    
    else if (g.progress == WON_AI)
    cout << "Humanity has been defeated" << endl;       
    
    else if (g.progress == DRAW)
    cout << "Oh,have again a DRAW" << endl;

}

void _fastcall score(Game& g)
{   
    int s = 100;
    int l = 50;
    if (g.progress == WON_HUMAN)
    cout << "Your score:" << g.turn * s << endl;
       
    else if (g.progress== WON_AI)   
    cout << "Your score:" << g.turn * l << endl;
    
    else if (g.progress== DRAW)
    cout << "Your don't have points" << endl;
 
}

void __fastcall WriteNickName(Game& g)
{
    setlocale(LC_ALL, "ru");
    string ld = "Leaderboard.txt";
    fstream fs;
    fs.open(ld, fstream::in | fstream::out |fstream::app);
    if (!fs.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
    }
    else
    {
        string mg;
        int val;
        cout << "Файл открыт" << endl;
        cout << "Нажмите 1 для записи никнейма в таблицу" << endl;
        cout << "Нажмите 2 для простра таблицы лидеров" << endl;
        cin >> val;

        if (val==1)
        {
            cout << "Введите ваш никнейм" << endl;
            cin >> mg;
            fs << mg << endl;
        }
        if (val==2)
        {
            cout << "Показана таблица лидеров" << endl;

            while (!fs.eof())
            {              
                mg = "";
                fs >> mg;
                cout << mg << endl;
            }
        }
    }
    fs.close();
}

int main()

{
    char KP;
    do {   
        system("color 06");
        Game g;
        initGame(g);
        clearScr();
        drawGame(g);
        do
        {
            if (g.turn % 2 == 0)
            {
                Coord c = getHumanCoord(g);
                g.ppField[c.y][c.x] = g.human;
            }

            else
            {
                Coord c = getAICoord(g);
                g.ppField[c.y][c.x] = g.ai;
            }

            clearScr();
            drawGame(g);
            g.turn++;
            g.progress = getWon(g);

        } while (g.progress == In_PROGRESS);
        congrats(g);
        score(g);
        WriteNickName(g);
        deinitGame(g);

        cout << "You want play again - y/n ?" << endl;
        cin >> KP;
       
    } while (KP  == 'y');
                          
    return 0;
}
/* вообще я еще думал сделать сложность, ну алгоритм который писали на вебинаре разделить на 2 части,
* легкий и сложный,но потом подумал,а какой смысл от этого?
* Но если что вот еще была такая идея) 
*/
