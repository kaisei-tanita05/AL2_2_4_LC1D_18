#pragma once

#include "Command.h"
#include "InputHandler.h"
#include "Player.h"

class StageScene {

public:
	void Initialize();
	void Update();
	void Draw();

private:
	InputHandler* inputHandler_ = nullptr;
	ICommand* iCommand_ = nullptr;
	Player* player_;
};