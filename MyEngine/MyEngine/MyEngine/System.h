#ifndef SYSTEM_H
#define SYSTEM_H



namespace core {

	enum class SystemType : unsigned __int8 {
		WINDOW,
		INPUT,

		TOTAL_SYSTEMS
	};

	class System
	{
	protected:
		const SystemType type;

	public:
		System(SystemType st);
		virtual ~System();

		virtual bool Init();
		virtual void Update();
		virtual void Draw() const;
		virtual bool Shutdown();
	};
}

#endif // SYSTEM_H