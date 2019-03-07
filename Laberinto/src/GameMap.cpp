#include "GameMap.h"

GameMap::GameMap()
{
    //ctor
}

GameMap::~GameMap()
{
    //dtor
}

void GameMap::Draw()
{
    DrawMap(MapData,15,10);
}

void GameMap::DrawMap(MapCell gameMap[15][10], int width, int height)
{
    for(int i = 0; i < height; i++)
    {
        for(int p = 0; p < width; p ++)
        {
            if(p != width -1)
            {
                 gameMap[p][i].DrawCell();
            }
            else
            {
                 gameMap[p][i].DrawCell(true);
            }

        }
    }
}

bool GameMap::TryMovePlayer(int NewX, int NewY)
{
    if(MapData[NewX][NewY].GetType() != 1)
    {
        SetPlayerCell(NewX,NewY);
        return true;
    }
    else
    {
        return false;
    }
}

void GameMap::SetPlayerCell(int x, int y)
{
    if(PlayerCell != NULL)
    {
        PlayerCell->CleanCell();
    }

    PlayerCell = &MapData[x][y];
    PlayerCell->SetType(2);
}
