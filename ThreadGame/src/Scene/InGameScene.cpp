#include "InGameScene.h"

#include "../Manager/InputManager.h"
#include "../Manager/SceneManager.h"
#include "../Manager/TextureManager.h"

GameScene::GameScene()
	:inputManager(InputManager::GetInstance())
	, textureManager(TextureManager::GetInstance())
	, count(0)
	, textureNum(0)
{

}

GameScene::~GameScene()
{
	textureManager->DeleteTextures();
}

void GameScene::Exec()
{
	count++;
	if (count % 30 == 29)
	{
		textureNum++;
		textureNum %= MaxTexture;
	}

	if (InputManager::GetInstance()->IsKeyPushed(KEY_INPUT_RETURN))
	{
		SceneManager::GetInstance()->FinishedScene(SceneID::Title);
	}
}

void GameScene::Draw()
{
	DrawString(0, 0, "InGame", GetColor(255, 0, 0));

	DrawGraph(0, 30, textureManager->GetTextureDate(textureNum), TRUE);
}
