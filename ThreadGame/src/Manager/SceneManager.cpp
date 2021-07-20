#include "SceneManager.h"
#include "../Load.h"

SceneID SceneManager::m_NextSceneID = SceneID::Title;

SceneManager::SceneManager()
	:m_pScene(CreateNextScene())
	, isLoading(false)
	, finishedScene(false)
{
}

SceneManager::~SceneManager()
{
	delete m_pScene;
	m_pScene = nullptr;
}

void SceneManager::Exec()
{
	if (m_pScene == nullptr) { return; }

	//ロード中の処理
	if (isLoading)
	{
		count++;
		return;
	}

	m_pScene->Exec();
	if (finishedScene)
	{
		finishedScene = false;
		delete m_pScene;
		m_pScene = CreateNextScene();
	}
}

void SceneManager::Draw()
{
	if (m_pScene == nullptr) { return; }

	//ロード中の描画
	if (isLoading)
	{
		DrawBox(0, 0, Widht, Height, GetColor(count % 256, 0, 0), TRUE);
		DrawString(0, 0, "Loading", GetColor(255, 0, 0));

		return;
	}

	m_pScene->Draw();
}

void SceneManager::SetNextScene(SceneID next_)
{
	m_NextSceneID = next_;
}

void SceneManager::FinishedScene(SceneID next_scene_)
{
	m_NextSceneID = next_scene_;

	finishedScene = true;
}

SceneBase* SceneManager::CreateNextScene()
{
	SceneBase* next = nullptr;
	switch (m_NextSceneID)
	{
	case SceneID::Title:
		next = new TitleScene();
		break;
	case SceneID::InGame:
		next = new GameScene();
		break;
	default:
		break;
	}

	Load::GetInstance()->StartLoading();
	isLoading = true;

	return next;
}
