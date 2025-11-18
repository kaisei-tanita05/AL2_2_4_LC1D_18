#pragma once
#include "IScene.h"
class ClearScene : public IScene 
{

	void Initialize() override;
	void Update(char* keys, char* preKeys) override;
	void Draw() override;

};
