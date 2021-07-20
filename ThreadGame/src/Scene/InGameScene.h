#ifndef IN_GAME_SCENE_H
#define IN_GAME_SCENE_H

#include "DxLib.h"
#include "../Definition.h"
#include "SceneBase.h"

class InputManager;
class TextureManager;

//ゲームシーン
class GameScene : public SceneBase
{
public:
	GameScene();
	~GameScene();

public:
	void Exec();
	void Draw();

private:
	InputManager* inputManager = nullptr;
	TextureManager* textureManager = nullptr;

	int count = 0;
	int textureNum = 0;
};

#endif // !IN_GAME_SCENE_H
