#pragma once

enum class KeyState
{
	None,
	Press,
	Down,
	Up
};

class InputManager
{
	DECLARE_SINGLE(InputManager)

public:
	void Init(HWND hwnd);
	void Update();

private:
	HWND _hwnd = 0;
	vector<KeyState> _state;
	POINT _mousePos{};
};

