#pragma once
#include "IScene.h"
#include <Vector2.h>



struct Player {

	Vector2 pos;
	float radius;
	float speed;
};

struct Enemy {

	Vector2 pos;
	float radius;
	float speed;
	bool ALive;
};

struct Bullet {

	Vector2 pos;
	float radius;
	float speed;
	bool isShot;
};

class StageScene : public IScene {
public:
	void Initialize() override;

	void Update(char* keys, char* preKeys) override;

	void Draw() override;

private:
	Player player;

	Enemy enemy;

	Bullet bullet;

	void UpdatePlayer(char* keys, char* preKeys);

	void UpdateBullet();
};

//class StageScene : public IScene {
//
//public:
//	void Initialize() override;
//	void Update(char* keys, char* preKeys) override;
//	void Draw() override;
//};