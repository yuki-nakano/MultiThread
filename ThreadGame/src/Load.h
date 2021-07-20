#ifndef LOAD_H
#define LOAD_H

#include "Singleton.h"
#include "Definition.h"

class TextureManager;

//読み込み処理クラス
class Load : public Singleton<Load>
{
public:
	void Exec();

	//読み込み開始関数
	void StartLoading() { isLoading = true; };
	void FinishedGame() { finishedGame = true; };

private:
	TextureManager* textureManager = nullptr;

	//読み込みの終了
	bool isLoading = false;

	//EXEの終了
	bool finishedGame = false;
};

#endif // !LOAD_H
