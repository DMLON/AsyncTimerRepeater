#pragma once
#include "AsyncRepeater.h"
#include <string>
using namespace std;
//Timer ejecuta una funcion luego de X tiempo
template<typename T>
class AsyncTimer : public AsyncRepeater<T> {
public:
	void start() {
		this->m_running = true;
		this->m_thread = std::thread([&]() {
			std::this_thread::sleep_until(std::chrono::steady_clock::now() + std::chrono::milliseconds(this->m_interval));
			try {
				(this->context.*this->m_func)();
				this->stop();
			}
			catch (...) {}
		});
		this->m_thread.detach();
	}
	string getclave() { return to_string(rand()); }
	AsyncTimer(long interval, T* context,void(T::* func)()) :AsyncRepeater<T>(interval, context, func) {
	}

	~AsyncTimer() {
		//this->stop();
	}
};