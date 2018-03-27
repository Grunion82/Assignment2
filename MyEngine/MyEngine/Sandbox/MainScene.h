#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <Scene.h>

class MainScene : public scene::Scene {
public:
	MainScene();
	~MainScene();

	bool Init() override;
	void Update() override;
	void Draw() const override;
	bool Shutdown() override;
};

#endif //MAINSCENE_H
