#include "Game.h"



Game::Game()
{
}

Game::~Game()
{
}

void Game::Update()
{
    m_board.ClearRow();
    m_board.Print();
}

void Game::Init(HWND hWnd, HDC hDC)
{
    m_board.Init(hWnd, hDC);
    m_board.Print();

}
