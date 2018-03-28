
#include <stdio.h>
#include <Engine.h>

#include <Level1.h>

int main(int argc, char* argv[]) {
	using namespace core;

	//Pass the correct level to the engine
	Engine e(new scene::Level1());

	if (e.Init() == 0)
		return e.Run();
	

	//getchar();
	return 0;
}