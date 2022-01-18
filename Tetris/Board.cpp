#include "Board.h"


Board::Board()
{
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLUMNS; ++c) {
            m_board[r][c].color = BLACK;
        }
    }
}

Board::~Board()
{

}

int Board::ClearRow()
{
    int ret = 0;
    for (int r = 0; r < ROWS; ++r) {
        bool rowFull = true;
        for (int c = 0; c < COLUMNS; ++c) {
            if (m_board[r][c].color == BLACK) {
                rowFull = false;
                break;
            }
        }
        if (rowFull) {
            for (int c = 0; c < COLUMNS; ++c) {
                m_board[r][c].color = BLACK;
            }
            for (int i = r; i > -1; --i) {
                for (int c = 0; c < COLUMNS; ++c) {
                    m_board[i][c].color = m_board[i - 1][c].color;
                }
            }
            ++ret;
        }
    }
    return ret;
}


void Board::Print()
{
    int shift = 3;
    
    COLORREF color = RGB(0, 0, 0);
    HBRUSH theBrush = CreateSolidBrush(color);
    // the board
    RECT rect;
    rect.left = 20 + 20 * shift;
    rect.right = 220 + 20 * shift;
    rect.top = 20 + 20 * shift;
    rect.bottom = 420 + 20 * shift;
    FillRect(m_hDC, &rect, theBrush);

    
    // draw tiles
    for (int row = 0; row < ROWS; ++row) {
        for (int column = 0; column < COLUMNS; ++column) {
            if (m_board[row][column].color == BLACK) { continue; }

            COLORREF color = RGB(0, 0, 0);

            if (m_board[row][column].color == RED) { color = RGB(255, 0, 0); }
            if (m_board[row][column].color == GREEN) { color = RGB(0, 255, 0); }
            if (m_board[row][column].color == YELLOW) { color = RGB(255, 255, 0); }
            if (m_board[row][column].color == ORANGE) { color = RGB(255, 165, 0); }
            if (m_board[row][column].color == PURPLE) { color = RGB(128, 0, 128); }
            if (m_board[row][column].color == BLUE) { color = RGB(0, 0, 255); }
            if (m_board[row][column].color == CYAN) { color = RGB(0, 255, 255); }

            HBRUSH theBrush = CreateSolidBrush(color);
            
            RECT tile;
            tile.left = 20 * (row + 1 + shift);
            tile.right = 20 * (row + 2 + shift);
            tile.top = 20 * (column + 1 + shift);
            tile.bottom = 20 * (column + 2 + shift);
            FillRect(m_hDC, &tile, theBrush);
        }
    }
}

void Board::Init(HWND hWnd, HDC hDC)
{
    m_hDC = hDC;
    m_hWnd = hWnd;
}
