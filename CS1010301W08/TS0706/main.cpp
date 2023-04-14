/***********************************************************************
 * File: main.cpp
 * Author: ·¨¶v¦w
 * Create Date: 2023/04/13
 * Editor: Brendon
 * Update Date: 2023/04/13
 * Description: Levenshtein Distance
***********************************************************************/
#define MAX 6
#define TURN_MAX 2
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> gameBoard(MAX + 2, vector<int>(MAX + 2, 0));

struct Pos
{
    int x, y;
};

void deleTile(Pos cur, Pos target)
{
    gameBoard[cur.y][cur.x] = 0;
    gameBoard[target.y][target.x] = 0;
}

void initGameBoard()
{
    for (int i = 1; i < MAX + 1; i++)
    {
        for (int j = 1; j < MAX + 1; j++)
        {
            cin >> gameBoard[i][j];
        }
    }
}

bool nextValid(Pos next, Pos target)
{
    if (next.x<0 || next.x>MAX + 1 || next.y<0 || next.y>MAX + 1) return false;
    if (gameBoard[next.y][next.x] == 0 || next.x == target.x && next.y == target.y) return true;
    return false;
}

bool isValid(Pos cur, Pos target, int turns, int dir)
{
    if (gameBoard[target.y][target.x] == 0 ||
        cur.x<0 || cur.x>MAX + 1 || cur.y<0 || cur.y>MAX + 1 ||
        target.x<1 || target.x>MAX+1 || target.y<0 || target.y>MAX+1||
        turns > TURN_MAX)return false;
    if (cur.x == target.x && cur.y == target.y && turns <= TURN_MAX)return true;
    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,1,-1 };
    for (int i = 1; i <= 4; i++)
    {
        Pos next;
        next.x = cur.x + dx[i - 1];
        next.y = cur.y + dy[i - 1];
        if (nextValid(next, target))
        {
            if (isValid(next, target, turns + ((dir == i || dir == 5) ? 0 : 1), i))return true;
        }
    }
    return false;
}

bool isSameStyle(Pos cur, Pos target)
{
    if ((gameBoard[cur.y][cur.x] == gameBoard[target.y][target.x]) &&
        (cur.x != target.x || cur.y != target.y))
    {
        return true;
    }
    return false;
}

int main()
{
    initGameBoard();
    Pos cur, target;
    int curX, curY, targetX, targetY;
    while (cin >> curX >> curY >> targetX >> targetY)
    {
        cur.x = curX + 1;
        cur.y = curY + 1;
        target.x = targetX + 1;
        target.y = targetY + 1;
        if (isSameStyle(cur, target) && isValid(cur, target, 0, 5) )
        {
            deleTile(cur, target);
            cout << "pair matched";
        }
        else
        {
            cout << "bad pair";
        }
        cout << endl;
    }
    return 0;
}