#include "pch.h"
#include "Game.h"
#include "TimeManager.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_hdc = ::GetDC(hwnd);

	GET_SINGLE(TimeManager)->Init();
}

void Game::Update()
{
	GET_SINGLE(TimeManager)->Update();
}

void Game::Render()
{
	uint32 fps = GET_SINGLE(TimeManager)->GetFps();
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	WCHAR buffer[100];
	int bIdx = 0;
	bIdx = swprintf(buffer, 100, L"fps: %d   ", fps);
	bIdx += swprintf(buffer + bIdx, 100, L"DT: %d", static_cast<int>(deltaTime * 1000));
	::TextOut(_hdc, 1300, 10, buffer, bIdx);
}
