#include <iostream>
#include "igrac.h"

using namespace sf;

class FPS
{ 
public:
	/// @brief Constructor with initialization.
	///
	FPS() : mFrame(0), mFps(0) {}

	/// @brief Update the frame count.
	/// 


	/// @brief Get the current FPS count.
	/// @return FPS count.
	unsigned int getFPS() const { return mFps; }

private:
	unsigned int mFrame;
	unsigned int mFps;
	sf::Clock mClock;

public:
	void update();
};