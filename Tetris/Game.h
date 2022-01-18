#include "framework.h"
#include "Board.h"

class Game
{
public:
    Game();
    ~Game();

public:
    


    void Update();
    void Init(HWND hWnd, HDC hDC);

private:
    Board m_board;
    bool m_valid = true;
};


