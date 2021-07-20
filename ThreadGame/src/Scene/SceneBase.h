#ifndef SCENE_BASE_H
#define SCENE_BASE_H

//シーン基底クラス
class SceneBase
{
public:
	SceneBase() {};
	virtual ~SceneBase() {};

	virtual void Exec() = 0;
	virtual void Draw() = 0;
};

#endif // !SCENE_BASE_H
