#include "StageScene.h"

void StageScene::Initialize() {

	inputHandler_ = new InputHandler();

	inputHandler_->AssignMoveLeftCommand2PressKeyA();
	inputHandler_->AssignMoveRightCommand2PressKeyD();

	player_ = new Player();
	player_->Initialize();
}

void StageScene::Update() {

	iCommand_ = inputHandler_->HandleInput();

	if (iCommand_) {
		iCommand_->Execute(*player_);
	}

	player_->Update();
}

void StageScene::Draw() { player_->Draw(); }