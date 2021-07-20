#include "TitleScene.h"
#include "../Manager/SceneManager.h"
#include "../Manager/InputManager.h"
#include "../Manager/TextureManager.h"

TitleScene::TitleScene()
	:inputManager(InputManager::GetInstance())
	, textureManager(TextureManager::GetInstance())
{

}

TitleScene::~TitleScene()
{
	textureManager->DeleteTextures();
}

void TitleScene::Exec()
{
	if (inputManager->IsKeyPushed(KEY_INPUT_RETURN))
	{
		SceneManager::GetInstance()->FinishedScene(SceneID::InGame);
	}
}

void TitleScene::Draw()
{
	DrawString(0, 0, "title", GetColor(255, 0, 0));
}
