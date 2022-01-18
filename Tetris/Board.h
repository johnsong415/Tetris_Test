#include "framework.h"


const int ROWS = 10;
const int COLUMNS = 20;


class Board
{
public:
    Board();
    ~Board();

public:
    int ClearRow();
    void Print();
    void Init(HWND hWnd, HDC hDC);

private:
    enum Color {
        BLACK = 0,
        RED, // Z-Block
        GREEN, // S-Block
        YELLOW, // Square
        ORANGE, // L-Block
        PURPLE, // T-BLock
        BLUE, // J-Block
        CYAN // I-Block
    };

    struct Tile {
        Color color;
    };

    Tile m_board[ROWS][COLUMNS];

    HWND m_hWnd;
    HDC m_hDC;
};
