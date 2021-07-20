#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "../Definition.h"
#include "../Singleton.h"
#include "../Scene/SceneBase.h"
#include "../Scene/TitleScene.h"
#include "../Scene/InGameScene.h"

//シーン管理クラス
class SceneManager : public Singleton<SceneManager>
{
public:
	SceneManager();
	~SceneManager();

public:
	void Exec();
	void Draw();

	//次のシーンのセット
	void SetNextScene(SceneID next_);

	//別クラスから呼び出す
	//読み込みの終了
	void FinishedLoading() { isLoading = false; };
	//シーンの終了
	void FinishedScene(SceneID next_scene_);

private:
	//次のシーンのインスタンスの作成
	class SceneBase* CreateNextScene();

private:
	class SceneBase* m_pScene;
	static SceneID m_NextSceneID;

	//読み込み処理中か
	bool isLoading;

	//シーンの終了
	bool finishedScene;

	//スレッド動作確認用
	int count = 0;
};

#endif // !SCENEMANAGER_H
