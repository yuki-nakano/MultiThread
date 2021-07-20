#ifndef TITLT_SCENE_H
#define TITLT_SCENE_H

#include "DxLib.h"
#include "../Definition.h"
#include "../Scene/SceneBase.h"

class InputManager;
class TextureManager;

//タイトルシーン
class TitleScene : public SceneBase
{
public:
	TitleScene();
	~TitleScene();

public:
	void Exec();
	void Draw();

private:
	InputManager* inputManager = nullptr;
	TextureManager* textureManager = nullptr;

};

#endif // !TITLT_SCENE_H
