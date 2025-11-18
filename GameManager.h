#pragma once
#include "ClearScene.h"
#include "IScene.h"     //シーンの基底クラスに加えて
#include "StageScene.h" //各シーンを積み込む
#include "TitleScene.h"
#include <memory> //std::unique_ptrを使うために必要

class GameManager {
private:
	// シーンを保持するメンバ変数
	std::unique_ptr<IScene> sceneArr_[3];

	// どのステージを呼び出すかを管理する要素
	int currentSceneNo_; // 現在のシーン
	int prevSceneNo_;    // 前のシーン

public:
	GameManager();//コンストラクタ
	~GameManager();//デストラクタ

	int Run();//この関数でゲームループ
};