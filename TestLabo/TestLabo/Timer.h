#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>

class Timer {
public:
    Timer(size_t time, const std::function<void(void)>& f) : time{ std::chrono::milliseconds{time} }, f{ f } {}
    ~Timer() { wait_thread.join(); }

private:
    void wait_then_call()
    {
        std::unique_lock<std::mutex> lck{ mtx };
        for (int i{ 10 }; i > 0; --i) {
            cv.wait_for(lck, time / 10);
        }
        f();
    }
    std::mutex mtx;
    std::condition_variable cv{};
    std::chrono::milliseconds time;
    std::function <void(void)> f;
    std::thread wait_thread{ [this]() {wait_then_call(); } };
};