#pragma once

#include <iostream>
#include <chrono>
#include <functional>
#include <thread>
#include <cstdarg> // needed to use ellipsis
#include <string>


/**
 *  Repeater repite una funcion dada cada X tiempo
 *  @param func		Function which sould be executed
 *  @param interval	Interval of time in which function will be executed
 *					(in milliseconds)
 */
template<typename T>
class AsyncRepeater {

public:
	//AsyncRepeater(const long& interval, std::function<void(void)> func) {
	//	m_func = func;
	//	m_interval = interval;
	//}
	AsyncRepeater(long interval,T* context, void(T::* func)()) :context(*context){
		m_func = func;
		m_interval = interval;
	}

	std::string getclave() { return std::to_string(rand()); }
	/**
	 * Starting the timer.
	 */
	virtual void start() {
		m_running = true;
		//(context.*m_func)();
		m_thread = std::thread([&]() {
			while (m_running) {
				try {
					auto delta = std::chrono::steady_clock::now() + std::chrono::milliseconds(m_interval);
					(context.*m_func)();
					std::this_thread::sleep_until(delta);
				}
				catch (...) {}
			}
		});
		m_thread.detach();
	}

	/*
	 *  Stopping the timer and destroys the thread.
	 */
	void stop() {
		m_running = false;
	}

	/*
	 *  Check if timer is running.
	 *
	 *  @returns boolean is running
	 */
	bool isRunning() {
		return m_running;
	}


	///*
	//*  Set the method of the timer after
	//*  initializing the timer instance.
	//*
	//*  @returns boolean is running
	//*  @return  Timer reference of this
	//*/
	//void setFunc(std::function<void(void)> func) {
	//	m_func = func;
	//}

	/*Returns the current set interval in milliseconds.*/
	long getInterval() {
		return m_interval;
	}

	/*
	*  Set a new interval for the timer in milliseconds.
	*  This change will be valid only after restarting
	*  the timer.
	*
	*  @param interval new interval
	*  @return  Timer reference of this
	*/
	void setInterval(const long& interval) {
		m_interval = interval;
	}
	virtual ~AsyncRepeater() {
		stop();
	}

protected:
	// Function to be executed fater interval
	void(T::* m_func)();
	// Timer interval in milliseconds
	long m_interval;
	T& context;

	// Thread timer is running into
	std::thread m_thread;
	// Status if timer is running
	bool m_running = false;
};


