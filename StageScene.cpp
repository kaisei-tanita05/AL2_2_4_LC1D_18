#include "GameScene.h"
#include "Novice.h"
#include <math.h>
#include "StageScene.h"


void StageScene::Initialize() {

	player = {600.0f, 350.0f, 25.0f, 5.0f};

	enemy = {600.0f, 100.0f, 20.0f, 5.0f, true};

	bullet = {player.pos, 10.0f, 10.0f, false};
}

void StageScene::Update(char* keys, char* preKeys) {

	UpdatePlayer(keys, preKeys);

	if (enemy.ALive) {

		enemy.pos.x += enemy.speed;
	}

	if (enemy.pos.x + enemy.radius > 1280.0f || enemy.pos.x - enemy.radius < 0.0f) {
		enemy.speed *= -1.0f;
	}

	UpdateBullet();

	Vector2 pos = enemy.pos - bullet.pos;
	float distance = sqrtf(pos.x * pos.x + pos.y * pos.y);
	float radius = enemy.radius + bullet.radius;

	if (distance <= radius) {
		enemy.ALive = false;
		bullet.isShot = false;
		bullet.pos = player.pos;
	}

	if (!enemy.ALive) {

		sceneNo = CLEAR;
	}
}

void StageScene::Draw() {

	Novice::DrawEllipse(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), static_cast<int>(player.radius), static_cast<int>(player.radius), 0.0f, WHITE, kFillModeSolid);

	if (enemy.ALive) {

		Novice::DrawEllipse(static_cast<int>(enemy.pos.x), static_cast<int>(enemy.pos.y), static_cast<int>(enemy.radius), static_cast<int>(enemy.radius), 0.0f, RED, kFillModeSolid);
	}

	if (bullet.isShot) {

		Novice::DrawTriangle(
		    static_cast<int>(bullet.pos.x), static_cast<int>(bullet.pos.y - bullet.radius), static_cast<int>(bullet.pos.x - bullet.radius), static_cast<int>(bullet.pos.y + bullet.radius),
		    static_cast<int>(bullet.pos.x + bullet.radius), static_cast<int>(bullet.pos.y + bullet.radius), GREEN, kFillModeSolid);
	}
}

void StageScene::UpdatePlayer(char* keys, char* preKeys) {

	if (keys[DIK_W]) {
		player.pos.y -= player.speed;
	}

	if (keys[DIK_S]) {
		player.pos.y += player.speed;
	}

	if (keys[DIK_A]) {
		player.pos.x -= player.speed;
	}

	if (keys[DIK_D]) {
		player.pos.x += player.speed;
	}

	if (!bullet.isShot) {

		if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {

			bullet.isShot = true;
		}
	}
}

void StageScene::UpdateBullet() {

	if (!bullet.isShot) {
		bullet.pos = player.pos;
		return;
	}

	bullet.pos.y -= bullet.speed;

	if (bullet.pos.y + bullet.radius < 0.0f) {
		bullet.isShot = false;
	}
}