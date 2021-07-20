#include "Load.h"
#include <Windows.h>

#include "Manager/SceneManager.h"
#include "Manager/TextureManager.h"

void Load::Exec()
{
	while (!finishedGame)
	{
		//１秒ごとに実行
		Sleep(1 * 1000);

		if (!isLoading) { continue; }

		//処理
		TextureManager::GetInstance()->LoadTextures();

		//ロード処理がないのでスリープで代用
		Sleep(3 * 1000);

		SceneManager::GetInstance()->FinishedLoading();
		isLoading = false;
	}
}
