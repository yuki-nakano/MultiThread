#include "TextureManager.h"

#include <sstream>
#include <iomanip>
#include <fstream>

void TextureManager::LoadTextures()
{
	for (int i = 0; i < MaxTexture; i++)
	{
		std::stringstream ss;
		ss << "res/" << std::setfill('0') << std::setw(3) << std::right << std::to_string(i + 1) << ".png";

		textureDate[i] = LoadGraph(ss.str().c_str());
	}
}

void TextureManager::DeleteTextures()
{
	for (int i = 0; i < MaxTexture; i++)
	{
		DeleteGraph(textureDate[i]);
	}
}

int TextureManager::GetTextureDate(int num)
{
	return textureDate[num];
}
