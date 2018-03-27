#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H



namespace scene {
	class GameObject {
	public:
		GameObject();
		virtual ~GameObject();

		virtual bool Init();
		virtual void Update();
		virtual void Draw() const;
		virtual bool Shutdown();
	};
}
#endif // GAMEOBJECT_H