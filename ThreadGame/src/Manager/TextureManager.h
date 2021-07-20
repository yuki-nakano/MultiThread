#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "DxLib.h"
#include "../Definition.h"
#include "../Singleton.h"

const int MaxTexture = 12;

class TextureManager : public Singleton<TextureManager>
{
public:
	//テクスチャデータの初期化
	void LoadTextures();

	//テクスチャデータの削除
	void DeleteTextures();

	//テクスチャデータの取得
	int GetTextureDate(int num);

private:
	int textureDate[MaxTexture];

};

#endif // !TEXTURE_MANAGER_H
