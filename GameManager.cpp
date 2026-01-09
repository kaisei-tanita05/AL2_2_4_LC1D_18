//#include "GameManager.h"
//#include <Novice.h>
//
//GameManager::GameManager() {
//	//各シーンの配列
//	sceneArr_[TITLE] = std::make_unique<TitleScene>();
//	sceneArr_[STAGE] = std::make_unique<StageScene>();
//	sceneArr_[CLEAR] = std::make_unique<ClearScene>();
//
//	//初期シーンの設定
//	currentSceneNo_ = TITLE;
//	prevSceneNo_ = TITLE;
//
//	sceneArr_[TITLE]->Initialize();
//}
//
//GameManager::~GameManager() {}
//
//int GameManager::Run() {
//
//	char keys[256] = {0};
//	char preKeys[256] = {0};
//
//	while (Novice::ProcessMessage() == 0) {
//		Novice::BeginFrame();//フレームの開始
//
//		memcpy(preKeys, keys, 256);
//		Novice::GetHitKeyStateAll(keys);
//
//		//シーンのチェック
//		prevSceneNo_ = currentSceneNo_;
//		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();
//
//		//シーン変更チェック
//		if (prevSceneNo_ != currentSceneNo_) {
//			sceneArr_[currentSceneNo_]->Initialize();
//		}
//
//		//更新処理
//		sceneArr_[currentSceneNo_]->Update(keys,preKeys); // 必要な引数を追加
//
//		//描画処理
//		sceneArr_[currentSceneNo_]->Draw();
//
//		Novice::EndFrame();//フレームの終了
//	}
//	return 0;
//}