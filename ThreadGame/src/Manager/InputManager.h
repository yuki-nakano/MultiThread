#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "DxLib.h"
#include "../Definition.h"
#include "../Singleton.h"

//キー管理クラス
class InputManager : public Singleton<InputManager>
{
public:
	//毎フレーム呼び出す
	void UpdateKeyStatus();

	//押した瞬間
	bool IsKeyPushed(int key);

	//押している
	bool IsKeyHeld(int key);

	//離した
	bool IsKeyRelesed(int key);

private:
	//現フレームのキーの押下状態
	char keyStatus[256];

	//前フレームのキーの押下状態
	char previousKeyStatus[256];
};

#endif // !INPUT_MANAGER_H
