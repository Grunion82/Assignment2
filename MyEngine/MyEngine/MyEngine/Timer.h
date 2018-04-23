#ifndef TIMER_H
#define TIMER_H

namespace core {
	class Timer
	{
	private:
		//"Ticks" keeps track of the amount of time elapsed
		unsigned int prevTicks;
		unsigned int currTicks;

	public:
		Timer();
		~Timer();
		void Start();
		void UpdateFrameTicks();
		float GetDeltaTime() const;
		unsigned int GetSleepTime(const unsigned int fps) const;
	};
}
#endif // TIMER_H