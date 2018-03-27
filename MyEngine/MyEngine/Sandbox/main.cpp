
#include <stdio.h>
#include <Engine.h>

#include "MainScene.h"

int main(int argc, char* argv[]) {
	using namespace core;

	Engine e(new MainScene());

	if (e.Init() == 0)
		return e.Run();
	

	//getchar();
	return 0;
}