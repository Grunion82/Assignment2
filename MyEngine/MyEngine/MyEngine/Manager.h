#ifndef MANAGER_H
#define MANAGER_H



namespace core {
	class Manager
	{
	public:
		Manager();
		virtual ~Manager();

		virtual bool Init() = 0;
		virtual void Update() = 0;
		virtual void Draw() const = 0;
		virtual bool Shutdown() = 0;
	};
}

#endif // MANAGER_h