#include <thread>
#include "DxLib.h"
#include "Definition.h"
#include "Manager/InputManager.h"
#include "Manager/SceneManager.h"
#include "Manager/TextureManager.h"
#include "Load.h"

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	SetOutApplicationLogValidFlag(false);
	ChangeWindowMode(true);
	SetGraphMode(Widht, Height, 16);
	SetBackgroundColor(255, 255, 255);
	SetMainWindowText("thread");

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1) { return -1; }

	//描画先を裏の画面に設定
	SetDrawScreen(DX_SCREEN_BACK);

	//管理クラスの作成
	InputManager::CreateInstance();
	InputManager* inputManager = InputManager::GetInstance();
	TextureManager::CreateInstance();
	Load::CreateInstance();
	SceneManager::CreateInstance();
	SceneManager* sceneManager = SceneManager::GetInstance();

	//スレッドの生成
	std::thread loadTh(&Load::Exec, Load::GetInstance());

	while (true)
	{
		// メッセージループに代わる処理をする
		if (ProcessMessage() == -1 ||
			inputManager->IsKeyPushed(KEY_INPUT_ESCAPE))
		{
			//ロード用スレッドの破棄
			Load::GetInstance()->FinishedGame();

			break;        // エラーが起きたらループを抜ける
		}
		else
		{
			//フレームごとにキーの状態更新
			inputManager->UpdateKeyStatus();

			ClearDrawScreen();
			clsDx();

			sceneManager->Exec();

			sceneManager->Draw();

			ScreenFlip();
		}
	}

	loadTh.join();

	//管理クラスの削除
	Load::DeleteInstance();
	SceneManager::DeleteInstance();
	InputManager::DeleteInstance();

	DxLib_End();	// ＤＸライブラリ使用の終了処理
	return 0;		// ソフトの終了 
}
